#ifndef OBRAS_H_INCLUDED
#define OBRAS_H_INCLUDED

#define MAX_OBRAS 10

struct Obra {
    char titulo[100];
    char descricao[500];
};

void inicializarObras(struct Obra obras[]);
void exibirOpcoes(struct Obra obras[], int numObras);
void responderQuestionario(char titulo[]);

#endif // OBRAS_H_INCLUDED
