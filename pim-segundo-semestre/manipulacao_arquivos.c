#include <stdio.h>
#include <string.h>
#include "obras.h"


// Fun��o para salvar as respostas no arquivo CSV
void salvarRespostas(char obra[], char pergunta[], char resposta) {
    FILE *arquivo;
    arquivo = fopen("respostas.csv", "a"); // Abre o arquivo no modo de adi��o
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }
    fprintf(arquivo, "%s,%s,%c\n", obra, pergunta, resposta); // Escreve os dados separados por v�rgula
    fclose(arquivo);
}

// Fun��o para mostrar as respostas do arquivo CSV separadas por colunas
void mostrarRespostasCSV() {
    FILE *arquivo;
    char linha[100];
    char *obra, *pergunta, *resposta; // Ponteiros para armazenar os dados separados
    arquivo = fopen("respostas.csv", "r"); // Abre o arquivo no modo de leitura
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }
    printf("Conteudo do arquivo respostas.csv:\n");
    while (fgets(linha, sizeof(linha), arquivo)) {
        obra = strtok(linha, ","); // Divide a linha em substrings separadas por v�rgula
        pergunta = strtok(NULL, ","); // Continua a divis�o da linha
        resposta = strtok(NULL, ","); // Continua a divis�o da linha
        printf("Obra: %s\nPergunta: %s\nResposta: %s\n\n", obra, pergunta, resposta); // Imprime os dados separados
    }
    fclose(arquivo);
}
