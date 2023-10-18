#include <stdio.h>
#include "obras.h"

void salvarRespostas(char obra[], char pergunta[], char resposta) {
    FILE *arquivo;
    arquivo = fopen("respostas.csv", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }
    fprintf(arquivo, "%s,%s,%c\n", obra, pergunta, resposta);
    fclose(arquivo);
}

void mostrarRespostasCSV() {
    FILE *arquivo;
    char linha[100];
    arquivo = fopen("respostas.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }
    printf("Conteudo do arquivo respostas.csv:\n");
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }
    fclose(arquivo);
}
