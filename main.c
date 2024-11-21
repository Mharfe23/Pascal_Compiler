#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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
}

void Test_Symbole(CODE_LEX cl,CODE_ERROR error){
    if (TokenArr[index_token] == cl){
        index_token++;
    }else{
        DisplayError(error);
    }
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

        switch (c) {
            case ',':
                SYM.Code = VIRG_TOKEN;
                strcpy(SYM.nom,",");
                AfficherToken(SYM);

            case ';':
                SYM.Code = PV_TOKEN;
                strcpy(SYM.nom, ";");
                AfficherToken(SYM);
                break;
            case '.':
                SYM.Code = PT_TOKEN;
                strcpy(SYM.nom, ".");
                AfficherToken(SYM);
                break;
            case '=':
                SYM.Code = EGAL_TOKEN;
                strcpy(SYM.nom, "=");
                AfficherToken(SYM);
                break;
            case '+':
                SYM.Code = PLUS_TOKEN;
                strcpy(SYM.nom,"+");
                AfficherToken(SYM);
                break;
            case '-':
                SYM.Code = MOINS_TOKEN;
                strcpy(SYM.nom, "-");
                AfficherToken(SYM);
                break;
            case '*':
                SYM.Code = MULTI_TOKEN;
                strcpy(SYM.nom, "*");
                AfficherToken(SYM);
                break;
            case '/':
                SYM.Code = DIV_TOKEN;
                strcpy(SYM.nom, "/");
                AfficherToken(SYM);
                break;
            case '(':
                SYM.Code = PRG_TOKEN;
                strcpy(SYM.nom, "(");
                AfficherToken(SYM);
                break;
            case ')':
                SYM.Code = PRD_TOKEN;
                strcpy(SYM.nom, ")");
                AfficherToken(SYM);
                break;
            case '<':
                SYM.Code = INF_TOKEN;
                strcpy(SYM.nom, "<");
                AfficherToken(SYM);
                break;
            case '>':
                SYM.Code = SUP_TOKEN;
                strcpy(SYM.nom, ">");
                AfficherToken(SYM);
                break;

            default:
                SYM.Code = ERR_TOKEN;
                sprintf(SYM.nom, "%c", c);
                AfficherToken(SYM);
                break;
        }

    }
}

void Sym_Suiv(){
    index_token++;
}

void analyseur_syntaxique(){
    TSym_Cour SYM;

    //Program function

    void PROGRAM(){
        Test_Symbole(PROGRAM_TOKEN,PROGRAM_ERROR);
        Test_Symbole(ID_TOKEN,ID_ERROR);
        Test_Symbole(PV_TOKEN,PV_ERROR);
        BLOCK();
        Test_Symbole(PT_TOKEN,PT_ERROR);
    }

    // BLOCK Program


    void BLOCK(){
        CONSTS();
        VARS();
        INSTS();
    }

    //1-CONSTS func
    void CONSTS(){
        switch(SYM.Code){
         case CONST_TOKEN:Sym_Suiv();
             Test_Symbole(ID_TOKEN,ID_ERROR);
             Test_Symbole(EGAL_TOKEN,EGAL_ERROR);
             Test_Symbole(NUM_TOKEN,NUM_ERROR);
             Test_Symbole(PV_TOKEN,PV_ERROR);
             while(SYM.Code == ID_TOKEN){
                Sym_Suiv();
                Test_Symbole(EGAL_TOKEN,EGAL_ERROR);
                Test_Symbole(NUM_TOKEN,NUM_ERROR);
                Test_Symbole(PV_TOKEN,PV_ERROR);
             };break;
        case VAR_TOKEN:break;
        case BEGIN_TOKEN:break;
        default:
         printf("CONST_VAR_BEGIN_ERR \ntriggered from consts function");

        }

    }

//2-VARS func
    void VARS(){
        switch(SYM.Code){
        case VAR_TOKEN:
            Sym_Suiv();
            Test_Symbole(ID_TOKEN,ID_ERROR);
            while (SYM.Code == VIRG_TOKEN){
                Sym_Suiv();
                Test_Symbole(ID_TOKEN,ID_ERROR);
            }
        case CONST_TOKEN:break;
        case BEGIN_TOKEN:break;
        default:
            printf("CONST_VAR_BEGIN_ERR \ntriggered from VARS function");
        }

    }


//3-INSTS func
    void INSTS(){
        Test_Symbole(BEGIN_TOKEN,BEGIN_ERROR);
        INST();
        while(SYM.Code == PV_TOKEN){
            INST();
        }
        Test_Symbole(END_TOKEN,END_ERROR);

    }

    void INST(){
        switch(SYM.Code){
            case BEGIN_TOKEN:INSTS();break;
            case ID_TOKEN:AFFECT();break;
            case IF_TOKEN:SI();break;
            case WHILE_TOKEN:TANTQUE();break;
            case WRITE_TOKEN:ECRIRE();break;
            case READ_TOKEN:LIRE();break;
            default:
                printf("_ERR \ntriggered from INST function");

        }
    }

    void AFFECT(){
        switch(SYM.Code){
            case ID_TOKEN:Sym_Suiv();
                Test_Symbole(AFFECT_TOKEN,AFFECT_ERROR);
                EXPR();break;
            default:
                printf("EXCPECTED ID_TOKEN \nERROR triggered from AFFECT function");
        }
    }

    void SI(){
        switch(SYM.Code){
            case IF_TOKEN:
                COND();
                Test_Symbole(THEN_TOKEN,THEN_ERROR);
                INST();break;
            default:
                printf("EXCPECTED IF_TOKEN \nERROR triggered from SI function");
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
                    S
                }

        }else{
            printf("EXPECTED WRITE \nERROR triggered from ECRIRE function");
        }

    }


}





















int main(){

    FILE* fptr = fopen("testfile.txt","r");

    analyseur_lexical(fptr);
   /**/

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

