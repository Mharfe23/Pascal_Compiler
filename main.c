#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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
            while (isalpha( (c = fgetc(fichier)) ) && i < 19){
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




int main(){

    FILE* fptr = fopen("testfile.txt","r");

    analyseur_lexical(fptr);
    printf("Voici le resultat du tableau");

    int j=0;
    printf("\n");
    for (int k=0;k<1024;k++){
        if (strcmp(getTokenString(TokenArr[j]),"END_TOKEN") == 0)break;
        printf("%s\n",getTokenString(TokenArr[j]));
        j++;
    }


    return 0;

}
