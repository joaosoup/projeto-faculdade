#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "obra.h"
#include "csv.h"

void salvarRespostasCSV(char obra[], char pergunta[], char resposta) {
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
    char *obra, *pergunta, *resposta;

    arquivo = fopen("respostas.csv", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("Conteudo do arquivo respostas.csv:\n");
    while (fgets(linha, sizeof(linha), arquivo)) {
        // Usar strdup para alocar memória para as strings
        obra = strdup(strtok(linha, ","));
        pergunta = strdup(strtok(NULL, ","));
        resposta = strdup(strtok(NULL, ","));

        // Remover caracteres de nova linha (\n) das strings
        obra[strcspn(obra, "\n")] = '\0';
        pergunta[strcspn(pergunta, "\n")] = '\0';
        resposta[strcspn(resposta, "\n")] = '\0';

        printf("Obra: %s\nPergunta: %s\nResposta: %s\n\n", obra, pergunta, resposta);

        // Liberar a memória alocada para as strings
        free(obra);
        free(pergunta);
        free(resposta);
    }

    fclose(arquivo);
}

void contarRespostas(char respostaProcurada) {
    FILE *arquivo;
    arquivo = fopen("respostas.csv", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[100];
    int totalRespostas = 0;
    int respostasA = 0;
    int respostasB = 0;

    // Ler cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo)) {
        char resposta = toupper(linha[strlen(linha) - 2]);  // Converter para maiúscula e obter o último caractere da linha (resposta)
        (totalRespostas)++;

        if (resposta == respostaProcurada) {
            if (resposta == 'A' || resposta == 'a') {
                respostasA++;
            } else if (resposta == 'B' || resposta == 'b') {
                respostasB++;
            }
        }
    }

    fclose(arquivo);

    float porcentagemA = (float)respostasA / totalRespostas * 100;
    float porcentagemB = (float)respostasB / totalRespostas * 100;

    printf("Total de respostas: %d\n\n", totalRespostas);
    printf("Respostas 'A': %d, e a porcentagem de escolha dessa alternativa foi:  (%.2f%%)\n\n", respostasA, porcentagemA);
    printf("Respostas 'B': %d, e a porcentagem de escolha dessa alternativa foi:  (%.2f%%)\n\n", respostasB, porcentagemB);
}


