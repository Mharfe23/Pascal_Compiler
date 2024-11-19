#include <stdio.h>
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

typedef enum {
    PROGRAM_TOKEN_ERROR,     // Erreur dans la déclaration du programme
    VAR_TOKEN_ERROR,         // Erreur dans la déclaration de la variable
    CONST_TOKEN_ERROR,       // Erreur dans la déclaration de la constante
    PV_TOKEN_ERROR,          // Point-virgule manquant
    ID_TOKEN_ERROR,          // Identifiant non défini ou incorrect
    PRG_TOKEN_ERROR,         // Erreur dans le mot-clé de début de programme (PRG)
    PRD_TOKEN_ERROR,         // Erreur dans le mot-clé de fin de programme (PRD)
    END_TOKEN_ERROR,         // Fin de bloc (END) manquante ou incorrecte
    EGAL_TOKEN_ERROR,        // Erreur dans l'opérateur d'égalité (EGAL)
    BEGIN_TOKEN_ERROR,       // Erreur dans le mot-clé de début de bloc (BEGIN)
    VIRG_TOKEN_ERROR,        // Virgule manquante ou mal placée
    AFFECT_TOKEN_ERROR,      // Erreur dans l'affectation
    THEN_TOKEN_ERROR,        // THEN attendu ou incorrect
    IF_TOKEN_ERROR,          // Erreur dans la syntaxe de la condition (IF)
    WHILE_TOKEN_ERROR,       // Erreur dans la syntaxe de la boucle (WHILE)
    WRITE_TOKEN_ERROR,       // Erreur dans l'instruction d'écriture (WRITE)
    READ_TOKEN_ERROR,        // Erreur dans l'instruction de lecture (READ)
    DO_TOKEN_ERROR,          // DO attendu ou incorrect
    NUM_TOKEN_ERROR,         // Erreur dans le nombre ou format numérique incorrect
    PT_TOKEN_ERROR,          // Point (PT) manquant ou mal placé
    PLUS_TOKEN_ERROR,        // Erreur dans l'opérateur d'addition (+)
    DIFF_TOKEN_ERROR,        // Erreur dans l'opérateur de différence (!=)
    SUP_TOKEN_ERROR,         // Erreur dans l'opérateur de supériorité (>)
    INF_TOKEN_ERROR,         // Erreur dans l'opérateur d'infériorité (<)
    INFEG_TOKEN_ERROR,       // Erreur dans l'opérateur d'infériorité ou égalité (<=)
    SUPEG_TOKEN_ERROR,       // Erreur dans l'opérateur de supériorité ou égalité (>=)
    MOINS_TOKEN_ERROR,       // Erreur dans l'opérateur de soustraction (-)
    MULTI_TOKEN_ERROR,       // Erreur dans l'opérateur de multiplication (*)
    DIV_TOKEN_ERROR,         // Erreur dans l'opérateur de division (/)
    DIEZE_TOKEN_ERROR,       // Caractère non attendu (#)
    ERR_TOKEN                // Token non défini ou erreur de syntaxe générale
} CODE_LEX_ERROR;



typedef struct {
    CODE_LEX Code;
    char nom[20];
} TSym_Cour;


TSym_Cour Sym;

void Test_Symbole(TSym_Cour sym,CODE_LEX_ERROR Erreur){
    if (strcmp(sym.Code,Sym.Code) == 0){

    }
}
