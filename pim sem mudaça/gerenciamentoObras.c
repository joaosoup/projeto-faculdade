#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "obra.h"

void incluirObra(struct Obra obras[], int *numObras) {
    if (*numObras < MAX_OBRAS) {
        // Inicializa as strings dentro da estrutura Obra
        obras[*numObras].titulo[0] = '\0';
        obras[*numObras].descricao[0] = '\0';

        printf("Digite o titulo da nova obra: ");
        scanf(" %[^\n]", obras[*numObras].titulo);

        printf("Digite a descricao da nova obra: ");
        scanf(" %[^\n]", obras[*numObras].descricao);

        (*numObras)++;
        printf("Obra incluida com sucesso!\n");
    } else {
        printf("Limite de obras atingido. Nao e possivel incluir mais obras.\n");
    }
}

void excluirObra(struct Obra obras[], int *numObras) {
    if (*numObras > 0) {
        int indiceExcluir;
        exibirOpcoes(obras, *numObras);

        printf("Digite o numero da obra que deseja excluir: ");
        scanf("%d", &indiceExcluir);
        printf("\n");

        if (indiceExcluir >= 1 && indiceExcluir <= *numObras) {
            // Desloca as obras para preencher o espaço da obra excluída
            for (int i = indiceExcluir - 1; i < *numObras - 1; i++) {
                memcpy(&obras[i], &obras[i + 1], sizeof(struct Obra));
            }

            (*numObras)--;
            printf("Obra excluida com sucesso!\n\n");
        } else {
            printf("Indice invalido. Nenhuma obra excluida.\n\n");
        }
    } else {
        printf("Nenhuma obra cadastrada para excluir.\n\n");
    }
}


void alterarObra(struct Obra obras[], int numObras) {
    if (numObras > 0) {
        int indiceAlterar;
        exibirOpcoes(obras, numObras);

        printf("Digite o numero da obra que deseja alterar: ");
        scanf("%d", &indiceAlterar);

        if (indiceAlterar >= 1 && indiceAlterar <= numObras) {
            printf("Digite o novo titulo da obra: ");
            scanf(" %[^\n]", obras[indiceAlterar - 1].titulo);

            printf("Digite a nova descricao da obra: ");
            scanf(" %[^\n]", obras[indiceAlterar - 1].descricao);

            printf("Obra alterada com sucesso!\n\n");


        } else {
            printf("Indice invalido. Nenhuma obra alterada.\n\n");


        }
    } else {
        printf("Nenhuma obra cadastrada para alterar.\n\n");

    }
}
