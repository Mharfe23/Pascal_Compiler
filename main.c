#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

#ifndef FICHIER_H
#define FICHIER_H


void FACT();
void TERM();
void EXPR();
void COND();
 void LIRE();
void ECRIRE();
void TANTQUE();
void SI();
void AFFECT();
void INST();
void INSTS();
void VARS();
void CONSTS();
void BLOCK();

#endif

//Code_Lex ENUM
typedef enum {
    PROGRAM_TOKEN,
    VAR_TOKEN,
    CONST_TOKEN,
    PV_TOKEN,
    ID_TOKEN,
    PRG_TOKEN,
    PRD_TOKEN,
    END_TOKEN,
    EGAL_TOKEN,
    BEGIN_TOKEN,
    VIRG_TOKEN,
    AFFECT_TOKEN,
    THEN_TOKEN,
    IF_TOKEN,
    ELSE_TOKEN,
    WHILE_TOKEN,
    WRITE_TOKEN,
    READ_TOKEN,
    DO_TOKEN,
    NUM_TOKEN,
    PT_TOKEN,
    PLUS_TOKEN,
    DIFF_TOKEN,
    SUP_TOKEN,
    INF_TOKEN,
    INFEG_TOKEN,
    SUPEG_TOKEN,
    MOINS_TOKEN,
    MULTI_TOKEN,
    DIV_TOKEN,
    DIEZE_TOKEN,
    ERR_TOKEN  // For undefined or error tokens
} CODE_LEX;


//CODE_ERROR
typedef enum {
    PROGRAM_ERROR,
    VAR_ERROR,
    CONST_ERROR,
    PV_ERROR,
    ID_ERROR,
    PRG_ERROR,
    PRD_ERROR,
    END_ERROR,
    EGAL_ERROR,
    BEGIN_ERROR,
    VIRG_ERROR,
    AFFECT_ERROR,
    THEN_ERROR,
    IF_ERROR,
    ELSE_ERROR,
    WHILE_ERROR,
    WRITE_ERROR,
    READ_ERROR,
    DO_ERROR,
    NUM_ERROR,
    PT_ERROR,
    PLUS_ERROR,
    DIFF_ERROR,
    SUP_ERROR,
    INF_ERROR,
    INFEG_ERROR,
    SUPEG_ERROR,
    MOINS_ERROR,
    MULTI_ERROR,
    DIV_ERROR,
    DIEZE_ERROR,
    ERR_ERROR  // For undefined or error tokens
} CODE_ERROR;


typedef struct {
    CODE_LEX Code;
    char nom[20];
} TSym_Cour;

CODE_LEX TokenArr[1024];
int index_token = 0;

char* getTokenString(CODE_LEX token) {
    static const char* tokenStrings[] = {
        "PROGRAM_TOKEN",
        "VAR_TOKEN",
        "CONST_TOKEN",
        "PV_TOKEN",
        "ID_TOKEN",
        "PRG_TOKEN",
        "PRD_TOKEN",
        "END_TOKEN",
        "EGAL_TOKEN",
        "BEGIN_TOKEN",
        "VIRG_TOKEN",
        "AFFECT_TOKEN",
        "THEN_TOKEN",
        "IF_TOKEN",
        "ELSE_TOKEN",
        "WHILE_TOKEN",
        "WRITE_TOKEN",
        "READ_TOKEN",
        "DO_TOKEN",
        "NUM_TOKEN",
        "PT_TOKEN",
        "PLUS_TOKEN",
        "DIFF_TOKEN",
        "SUP_TOKEN",
        "INF_TOKEN",
        "INFEG_TOKEN",
        "SUPEG_TOKEN",
        "MOINS_TOKEN",
        "MULTI_TOKEN",
        "DIV_TOKEN",
        "DIEZE_TOKEN",
        "ERR_TOKEN"
    };

    if (token >= 0 && token <= ERR_TOKEN) {
        return tokenStrings[token];
    }
    return "UNKNOWN_TOKEN";
}


//------------------------------------------------------------------------------
// AfficherToke: affiche le token reconnu, sa valeur et sa classe lexicale
// cette fonction n'est pas necesaire. Elle est là, juste pour tester
//l'ablyseur lexicale
//------------------------------------------------------------------------------
void AfficherToken0(TSym_Cour SYM){
    //SYM.cls
	switch(SYM.Code){
	   case	PROGRAM_TOKEN:   printf("%s          %s\n",SYM.nom,"PROGRAM_TOKEN "); break;
	   case VAR_TOKEN:       printf("%s          %s\n",SYM.nom,"VAR_TOKEN ");     break;
	   case CONST_TOKEN:     printf("%s          %s\n",SYM.nom,"CONST_TOKEN ");   break;
	   case PV_TOKEN:        printf("%s          %s\n"," ;     ","PV_TOKEN ");    break;
	   case ID_TOKEN:        printf("%s          %s\n",SYM.nom,"ID_TOKEN");       break;
	   case PRG_TOKEN:       printf("%s          %s\n"," (     ","PRG_TOKEN ");   break;
	   case PRD_TOKEN:       printf("%s          %s\n","  )    ","PRD_TOKEN");    break;
	   case END_TOKEN:       printf("%s          %s\n",SYM.nom,"END_TOKEN");      break;
	   case EGAL_TOKEN:      printf("%s          %s\n","  =    ","EGAL_TOKEN");   break;
	   case BEGIN_TOKEN:     printf("%s          %s\n",SYM.nom,"BEGIN_TOKEN");    break;
	   case VIRG_TOKEN:      printf("%s          %s\n","  ,    ","VIRG_TOKEN");   break;
	   case AFFECT_TOKEN:    printf("%s          %s\n","  :=   ","AFFECT_TOKEN"); break;
	   case THEN_TOKEN:      printf("%s          %s\n",SYM.nom,"THEN_TOKEN");     break;
	   case IF_TOKEN:        printf("%s          %s\n",SYM.nom,"IF_TOKEN");       break;
	   case ELSE_TOKEN:      printf("%s          %s\n",SYM.nom,"ELSE_TOKEN");     break;
	   case WHILE_TOKEN:     printf("%s          %s\n",SYM.nom,"WHILE_TOKEN ");   break;
	   case WRITE_TOKEN:     printf("%s          %s\n",SYM.nom,"WRITE_TOKEN ");   break;
	   case READ_TOKEN:      printf("%s          %s\n",SYM.nom,"READ_TOKEN ");    break;
	   case DO_TOKEN:        printf("%s          %s\n",SYM.nom,"DO_TOKEN");       break;
	   case NUM_TOKEN:       printf("%s          %s\n",SYM.nom,"NUM_TOKEN");      break;
	   case PT_TOKEN:        printf("%s          %s\n","  .    ","PT_TOKEN");     break;
	   case PLUS_TOKEN:      printf("%s          %s\n","  +    ","PLUS_TOKEN");   break;
	   case DIFF_TOKEN:      printf("%s          %s\n","  <>   ","DIFF_TOKEN");   break;
	   case SUP_TOKEN:       printf("%s          %s\n","  >    ","SUP_TOKEN");    break;
	   case INF_TOKEN:       printf("%s          %s\n","  <    ","INF_TOKEN");    break;
	   case INFEG_TOKEN:     printf("%s          %s\n","  <=   ","INFEG_TOKEN");  break;
	   case SUPEG_TOKEN:     printf("%s          %s\n","  >=   ","SUPEG_TOKEN");  break;
	   case MOINS_TOKEN:     printf("%s          %s\n","  -    ","MOINS_TOKEN");  break;
	   case MULTI_TOKEN:     printf("%s          %s\n","  *    ","MULTI_TOKEN");  break;
	   case DIV_TOKEN:       printf("%s          %s\n","  /    ","DIV_TOKEN");    break;
	   case DIEZE_TOKEN:     printf("%s          %s\n","  EOF  ","DIEZE_TOKEN");  break;
	   default:              printf("%s","ERR_TOKEN");                            break;
	}


}

void AfficherToken(TSym_Cour SYM) {
    TokenArr[index_token] = SYM.Code;
    index_token++;
}


void DisplayError(CODE_ERROR error) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    switch(error) {
        case PROGRAM_ERROR:   printf("PROGRAM_ERROR\n"); break;
        case VAR_ERROR:       printf("VAR_ERROR\n");     break;
        case CONST_ERROR:     printf("CONST_ERROR\n");   break;
        case PV_ERROR:        printf("PV_ERROR\n");      break;
        case ID_ERROR:        printf("ID_ERROR\n");      break;
        case PRG_ERROR:       printf("PRG_ERROR\n");     break;
        case PRD_ERROR:       printf("PRD_ERROR\n");     break;
        case END_ERROR:       printf("END_ERROR\n");     break;
        case EGAL_ERROR:      printf("EGAL_ERROR\n");    break;
        case BEGIN_ERROR:     printf("BEGIN_ERROR\n");   break;
        case VIRG_ERROR:      printf("VIRG_ERROR\n");    break;
        case AFFECT_ERROR:    printf("AFFECT_ERROR\n");  break;
        case THEN_ERROR:      printf("THEN_ERROR\n");    break;
        case IF_ERROR:        printf("IF_ERROR\n");      break;
        case ELSE_ERROR:      printf("ELSE_ERROR\n");      break;
        case WHILE_ERROR:     printf("WHILE_ERROR\n");   break;
        case WRITE_ERROR:     printf("WRITE_ERROR\n");   break;
        case READ_ERROR:      printf("READ_ERROR\n");    break;
        case DO_ERROR:        printf("DO_ERROR\n");      break;
        case NUM_ERROR:       printf("NUM_ERROR\n");     break;
        case PT_ERROR:        printf("PT_ERROR\n");      break;
        case PLUS_ERROR:      printf("PLUS_ERROR\n");    break;
        case DIFF_ERROR:      printf("DIFF_ERROR\n");    break;
        case SUP_ERROR:       printf("SUP_ERROR\n");     break;
        case INF_ERROR:       printf("INF_ERROR\n");     break;
        case INFEG_ERROR:     printf("INFEG_ERROR\n");   break;
        case SUPEG_ERROR:     printf("SUPEG_ERROR\n");   break;
        case MOINS_ERROR:     printf("MOINS_ERROR\n");   break;
        case MULTI_ERROR:     printf("MULTI_ERROR\n");   break;
        case DIV_ERROR:       printf("DIV_ERROR\n");     break;
        case DIEZE_ERROR:     printf("DIEZE_ERROR\n");   break;
        default:              printf("ERR_ERROR\n");     break;
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}






void analyseur_lexical(FILE* fichier){
    char c;
    if(fichier == NULL){
        printf("The file is not opened. The program will now exit.");
        exit(0);
    }
    TSym_Cour SYM;


    while((c = fgetc(fichier)) != EOF){

        if(isspace(c)) continue;
        if (c == ':'){
            if ( (c=fgetc(fichier)) == '='){
                strcpy(SYM.nom,":=");
                SYM.Code = AFFECT_TOKEN;
                AfficherToken(SYM);
                continue;

            }else{
            ungetc(c,fichier);
            }

        }
        if (c == '<'){
            if ( (c=fgetc(fichier)) == '='){
                strcpy(SYM.nom,"<=");
                SYM.Code = INFEG_TOKEN;
                AfficherToken(SYM);
                continue;

            }else{
            ungetc(c,fichier);
            }

        }
        if (c == '>'){
            if ( (c=fgetc(fichier)) == '='){
                strcpy(SYM.nom,">=");
                SYM.Code = SUPEG_TOKEN;
                AfficherToken(SYM);
                continue;

            }else{
            ungetc(c,fichier);
            }

        }
        if (c == '<'){
            if ( (c=fgetc(fichier)) == '>'){
                strcpy(SYM.nom,"<>");
                SYM.Code = DIFF_TOKEN;
                AfficherToken(SYM);
                continue;

            }else{
            ungetc(c,fichier);
            }

        }

        switch (c) {
            case ',':
                SYM.Code = VIRG_TOKEN;
                strcpy(SYM.nom,",");
                AfficherToken(SYM);continue;

            case ';':
                SYM.Code = PV_TOKEN;
                strcpy(SYM.nom, ";");
                AfficherToken(SYM);
                continue;
            case '.':
                SYM.Code = PT_TOKEN;
                strcpy(SYM.nom, ".");
                AfficherToken(SYM);
                continue;
            case '=':
                SYM.Code = EGAL_TOKEN;
                strcpy(SYM.nom, "=");
                AfficherToken(SYM);
                continue;
            case '+':
                SYM.Code = PLUS_TOKEN;
                strcpy(SYM.nom,"+");
                AfficherToken(SYM);
                continue;
            case '-':
                SYM.Code = MOINS_TOKEN;
                strcpy(SYM.nom, "-");
                AfficherToken(SYM);
                continue;
            case '*':
                SYM.Code = MULTI_TOKEN;
                strcpy(SYM.nom, "*");
                AfficherToken(SYM);
                continue;
            case '/':
                SYM.Code = DIV_TOKEN;
                strcpy(SYM.nom, "/");
                AfficherToken(SYM);
                continue;
            case '(':
                SYM.Code = PRG_TOKEN;
                strcpy(SYM.nom, "(");
                AfficherToken(SYM);
                continue;
            case ')':
                SYM.Code = PRD_TOKEN;
                strcpy(SYM.nom, ")");
                AfficherToken(SYM);
                continue;
            case '<':
                SYM.Code = INF_TOKEN;
                strcpy(SYM.nom, "<");
                AfficherToken(SYM);
                continue;
            case '>':
                SYM.Code = SUP_TOKEN;
                strcpy(SYM.nom, ">");
                AfficherToken(SYM);
                continue;

            /*default:
                SYM.Code = ERR_TOKEN;
                sprintf(SYM.nom, "%c", c);
                AfficherToken(SYM);
                break;*/
        }

        if(isalpha(c)){

            int i = 0;
            SYM.nom[i++] = c;
            while (isalpha( (c = fgetc(fichier)) ) && i < 20){
                SYM.nom[i++] = c;
            }
            SYM.nom[i]='\0';

            ungetc(c,fichier);

            if (strcmp(SYM.nom,"program") == 0)SYM.Code = PROGRAM_TOKEN;
            else if (strcmp(SYM.nom, "var") == 0) SYM.Code = VAR_TOKEN;
            else if (strcmp(SYM.nom, "const") == 0) SYM.Code = CONST_TOKEN;
            else if (strcmp(SYM.nom, "begin") == 0) SYM.Code = BEGIN_TOKEN;
            else if (strcmp(SYM.nom, "end") == 0) SYM.Code = END_TOKEN;
            else if (strcmp(SYM.nom, "read") == 0) SYM.Code = READ_TOKEN;
            else if (strcmp(SYM.nom,"if")==0) SYM.Code = IF_TOKEN;
            else if (strcmp(SYM.nom,"else")==0) SYM.Code = ELSE_TOKEN;
            else if (strcmp(SYM.nom,"then")==0) SYM.Code = THEN_TOKEN;
            else if (strcmp(SYM.nom,"while")==0) SYM.Code = WHILE_TOKEN;
            else if (strcmp(SYM.nom,"do")==0) SYM.Code = DO_TOKEN;
            else if (strcmp(SYM.nom,"write")==0) SYM.Code = WRITE_TOKEN;

            else SYM.Code = ID_TOKEN;

            AfficherToken(SYM);
            continue;
        }

        if (isdigit(c)){
            int i = 0;
            SYM.nom[i++] = c;
            while(isdigit(c = fgetc(fichier) )&& i < 19){
                SYM.nom[i++] = c;
            }
            SYM.nom[i] = '\0';
            SYM.Code = NUM_TOKEN;
            ungetc(c,fichier);
            AfficherToken(SYM);
            continue;
        }
        SYM.Code = ERR_TOKEN;
        printf(SYM.nom, "%c", c);
        AfficherToken(SYM);

    }
}

TSym_Cour SYM;
void Sym_Suiv(){

    index_token++;
    SYM.Code = TokenArr[index_token];
    printf("Sym_Suiv called, current token: %s\n", getTokenString(TokenArr[index_token]));
}

void Test_Symbole(CODE_LEX cl, CODE_ERROR error) {
    printf("Test_Symbole: Expecting %s, got %s\n", getTokenString(cl), getTokenString(TokenArr[index_token]));
    if (TokenArr[index_token] == cl) {

        Sym_Suiv();
    } else {
        DisplayError(error);
    }
}


void PROGRAM() {
    index_token =0;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("Entering PROGRAM function\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);


    Test_Symbole(PROGRAM_TOKEN, PROGRAM_ERROR);

    Test_Symbole(ID_TOKEN, ID_ERROR);

    Test_Symbole(PV_TOKEN, PV_ERROR);

    BLOCK();
    Test_Symbole(PT_TOKEN, PT_ERROR);

    printf("Exiting PROGRAM function\n");
}

    // BLOCK Program


    void BLOCK() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("Entering BLOCK function\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    CONSTS();
    VARS();
    INSTS();
    printf("Exiting BLOCK function\n");
}

    //1-CONSTS func
    void CONSTS() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("Entering CONSTS function with SYM.Code = %s\n", getTokenString(SYM.Code));
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    switch (SYM.Code) {
        case CONST_TOKEN:

            Sym_Suiv();
            Test_Symbole(ID_TOKEN, ID_ERROR);
            Test_Symbole(EGAL_TOKEN, EGAL_ERROR);
            Test_Symbole(NUM_TOKEN, NUM_ERROR);
            Test_Symbole(PV_TOKEN, PV_ERROR);
            while (SYM.Code == ID_TOKEN) {
                printf("CONST declaration found\n");
                Sym_Suiv();
                Test_Symbole(EGAL_TOKEN, EGAL_ERROR);
                Test_Symbole(NUM_TOKEN, NUM_ERROR);
                Test_Symbole(PV_TOKEN, PV_ERROR);
            }
            break;
        case VAR_TOKEN:break;
        case BEGIN_TOKEN:
            break;
        default:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("Error: Unexpected token in CONSTS function\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    printf("Exiting CONSTS function\n");
}


//2-VARS func
    void VARS(){
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf("Entering VARS function with SYM.Code = %s\n", getTokenString(SYM.Code));
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);


        switch(SYM.Code){
        case VAR_TOKEN:
            Sym_Suiv();
            Test_Symbole(ID_TOKEN,ID_ERROR);
            while (SYM.Code == VIRG_TOKEN){
                Sym_Suiv();
                Test_Symbole(ID_TOKEN,ID_ERROR);
            }
        Test_Symbole(PV_TOKEN,PV_ERROR);
        case CONST_TOKEN:break;
        case BEGIN_TOKEN:break;
        default:
             SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("CONST_VAR_BEGIN_ERR \ntriggered from VARS function\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }

    }


//3-INSTS func
   void INSTS() {
       HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
       SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("Entering INSTS function\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    Test_Symbole(BEGIN_TOKEN, BEGIN_ERROR);

    INST();
    while (SYM.Code == PV_TOKEN) {

        Sym_Suiv();
        INST();
    }
    Test_Symbole(END_TOKEN, END_ERROR);

    printf("Exiting INSTS function\n");
}

    void INST(){
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf("Entering INST function with SYM.Code = %s\n", getTokenString(SYM.Code));
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        switch(SYM.Code){
            case BEGIN_TOKEN:INSTS();break;
            case ID_TOKEN:AFFECT();break;
            case IF_TOKEN:SI();break;
            case WHILE_TOKEN:TANTQUE();break;
            case WRITE_TOKEN:ECRIRE();break;
            case READ_TOKEN:LIRE();break;
            case END_TOKEN:break;
            default:
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("_ERR \ntriggered from INST function\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        }
    }

    void AFFECT() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf("Entering AFFECT function with SYM.Code = %s\n", getTokenString(SYM.Code));
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    switch (SYM.Code) {
        case ID_TOKEN:

            Sym_Suiv();
            Test_Symbole(AFFECT_TOKEN, AFFECT_ERROR);

            EXPR();
            break;
        default:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("Error: Expected ID_TOKEN in AFFECT function\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    printf("Exiting AFFECT function\n");
}

    void SI(){
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        switch(SYM.Code){
            case IF_TOKEN:
                COND();
                Test_Symbole(THEN_TOKEN,THEN_ERROR);
                INST();break;
            default:
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("EXCPECTED IF_TOKEN \nERROR triggered from SI function\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
    }

    void TANTQUE(){
        if (SYM.Code == WHILE_TOKEN){
            COND();
            Test_Symbole(DO_TOKEN,DO_ERROR);
            INST();
        }else{
            printf("EXCPECTED WHILE_TOKEN \nERROR triggered from TANTQUE function");
        }
    }

    void ECRIRE(){
        if (SYM.Code == WRITE_TOKEN){
                Sym_Suiv();
                Test_Symbole(PRG_TOKEN,PRG_ERROR);
                EXPR();                                    //ATENTION SUIVANT OU PAS
                while(SYM.Code == VIRG_TOKEN){
                    EXPR();
                    Sym_Suiv();
                }
                Test_Symbole(PRD_TOKEN,PRD_ERROR);

        }else{
            printf("EXPECTED WRITE \nERROR triggered from ECRIRE function");
        }

    }
    void LIRE(){
        if (SYM.Code == READ_TOKEN){
            Sym_Suiv();
            Test_Symbole(PRG_TOKEN,PRG_ERROR);
            Test_Symbole(ID_TOKEN,ID_ERROR);
            while (SYM.Code == VIRG_TOKEN){
                Sym_Suiv();
                Test_Symbole(ID_TOKEN,ID_ERROR);
            }
            Test_Symbole(PRD_TOKEN,PRD_ERROR);

        }else{
            printf("EXPECTED READ \nERROR triggered from LIRE function");
        }
    }

    void COND(){
        Sym_Suiv();
        EXPR();
        switch (SYM.Code){
            case EGAL_TOKEN:Sym_Suiv();EXPR();break;
            case DIFF_TOKEN:Sym_Suiv();EXPR();break;
            case INF_TOKEN:Sym_Suiv();EXPR();break;
            case SUP_TOKEN:Sym_Suiv();EXPR();break;
            case INFEG_TOKEN:Sym_Suiv();EXPR();break;
            case SUPEG_TOKEN:Sym_Suiv();EXPR();break;
            default:
                printf("EXPECTED [=| <>| < | >| <=| >=] \nERROR triggered from COND function");
        }

    }

    void EXPR(){
        TERM();
        while (SYM.Code == PLUS_TOKEN ||SYM.Code == MOINS_TOKEN){
            Sym_Suiv();
            TERM();
        }

    }

    void TERM(){
        FACT();
         while (SYM.Code == MULTI_TOKEN ||SYM.Code == DIV_TOKEN){
            Sym_Suiv();
            FACT();
        }
    }

    void FACT(){
        switch (SYM.Code){
            case ID_TOKEN:break;
            case NUM_TOKEN:break;
            case PRG_TOKEN:
                Sym_Suiv();
                EXPR();
                Test_Symbole(PRD_TOKEN,PRD_ERROR);break;
            default:
                printf("EXPECTED ID | NUM | (EXPR) TOKEN | \nERROR triggered from FACT function");

        }
        Sym_Suiv();
    }

void analyseur_syntaxique(){

    SYM.Code = TokenArr[index_token];
    //Program function
    PROGRAM();
}





















int main(){

    FILE* fptr = fopen("testfile.txt","r");

    analyseur_lexical(fptr);
   /**/
   analyseur_syntaxique();





    return 0;

}



/* printf("Voici le resultat du tableau");

    int j=0;
    printf("\n");
    for (int k=0;k<1024;k++){
        if (strcmp(getTokenString(TokenArr[j]),"END_TOKEN") == 0)break;
        printf("%s\n",getTokenString(TokenArr[j]));
        j++;
    }
*/

