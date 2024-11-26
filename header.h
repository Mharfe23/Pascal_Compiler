#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

void analyseur_lexical(FILE* fichier);
void Sym_Suiv();

// Prototypes pour l'analyseur syntaxique
void analyseur_syntaxique();
void BLOCK();
void CONSTS();
void VARS();
void INSTS();


#endif // HEADER_H_INCLUDED
