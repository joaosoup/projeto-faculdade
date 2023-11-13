#include <stdio.h>
#include <stdlib.h>
#include "gerenciamento_obras.h"

void incluirObra(struct Obra obras[], int *numObras) {
    if (*numObras < MAX_OBRAS) {
        printf("Digite o titulo da nova obra: ");
        scanf(" %[^\n]", obras[*numObras].titulo);

        printf("Digite a descricao da nova obra: ");
        scanf(" %[^\n]", obras[*numObras].descricao);

        (*numObras)++;
        printf("Obra incluida com sucesso!\n");
    } else {
        printf("Limite de obras atingido. Impossivel incluir mais obras.\n");
    }
}

void alterarObra(struct Obra obras[], int numObras) {
    int indice;

    printf("Digite o numero da obra que deseja alterar: ");
    scanf("%d", &indice);

    if (indice >= 1 && indice <= numObras) {
        printf("Digite o novo titulo da obra: ");
        scanf(" %[^\n]", obras[indice - 1].titulo);

        printf("Digite a nova descricao da obra: ");
        scanf(" %[^\n]", obras[indice - 1].descricao);

        printf("Obra alterada com sucesso!\n");
    } else {
        printf("Obra nao encontrada. Operacao cancelada.\n");
    }
}

void consultarObra(struct Obra obras[], int numObras) {
    int indice;

    printf("Digite o numero da obra que deseja consultar: ");
    scanf("%d", &indice);

    if (indice >= 1 && indice <= numObras) {
        printf("Titulo: %s\n", obras[indice - 1].titulo);
        printf("Descricao: %s\n", obras[indice - 1].descricao);
    } else {
        printf("Obra nao encontrada. Operacao cancelada.\n");
    }
}

void excluirObra(struct Obra obras[], int *numObras) {
    int indice;

    printf("Digite o numero da obra que deseja excluir: ");
    scanf("%d", &indice);

    if (indice >= 1 && indice <= *numObras) {
        for (int i = indice - 1; i < *numObras - 1; i++) {
            obras[i] = obras[i + 1];
        }
        (*numObras)--;
        printf("Obra excluida com sucesso!\n");
    } else {
        printf("Obra nao encontrada. Operacao cancelada.\n");
    }
}
