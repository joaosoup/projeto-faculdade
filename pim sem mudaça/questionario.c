#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "obra.h"
#include "csv.h"

void realizarQuestionario(struct Obra obras[], int opcao, int *numObras) {
    int opcaoForms = 0;

    printf("Titulo: %s \n\n", obras[opcao - 1].titulo);
    printf("Descricao: %s\n\n", obras[opcao - 1].descricao);

    printf("Voce gostaria de responder um formulario sobre a obra que voce leu agora? Ou ver sobre outra obra?\n 1 - Sim \n 2 - Quero ver outra obra\n 3 - Quero sair do sistema do museu!\n 4 - Mostrar respostas do arquivo CSV\n");
    scanf("%d", &opcaoForms);
    system("cls");

    if (opcaoForms == 1) {
        char resposta1, resposta2, resposta3, resposta4, resposta5, resposta6, resposta7,resposta8, resposta9, resposta10;
        printf("1) Pretende visitar novamente ou recomendaria esta exposiçao a outras pessoas?\n");
    printf("A) Sim\nB) Nao\n");
    scanf(" %c", &resposta1);
    system("cls");

    printf("2) Durante sua visita, esteve satisfeito em relacao ao custo-beneficio em termos de preço do ingresso e qualidade da experiencia?\n");
    printf("A) Sim\nB) Nao\n");
    scanf(" %c", &resposta2);
    system("cls");

    printf("3) Experimentou facilidade na compra de ingressos ou entrada na exposicao?\n");
    printf("A) Sim\nB) Nao\n");
    scanf(" %c", &resposta3);
    system("cls");

    printf("4) Achou as instalacoes limpas e bem cuidadas?\n");
    printf("A) Sim\nB) Nao\n");
    scanf(" %c", &resposta4);
    system("cls");

    printf("5) A exposicao enriqueceu sua compreensao e apreciacao do tema abordado?\n");
    printf("A) Sim\nB) Nao\n");
    scanf(" %c", &resposta5);
    system("cls");

    printf("6) Considera que as informacoes fornecidas durante a exposicao foram esclarecedoras?\n");
    printf("A) Sim\nB) Nao\n");
    scanf(" %c", &resposta6);
    system("cls");

    printf("7) A exposicao proporcionou oportunidades para expressar suas próprias interpretações?\n");
    printf("A) Sim\nB) Nao\n");
    scanf(" %c", &resposta7);
    system("cls");

    printf("8) A exposicao destacou aspectos historicos ou relevantes para o tema?\n");
    printf("A) Sim\nB) Nao\n");
    scanf(" %c", &resposta8);
    system("cls");

    printf("9) A exposição estimulou sua criatividade e pensamento critico?\n");
    printf("A) Sim\nB) Nao\n");
    scanf(" %c", &resposta9);
    system("cls");

    printf("10) Ficou satisfeito(a) com a variedade de obras/temas abordados?\n");
    printf("A) Sim\nB) Nao\n");
    scanf(" %c", &resposta10);
    system("cls");

        salvarRespostasCSV(obras[opcao - 1].titulo, "Pergunta 1", resposta1);
        salvarRespostasCSV(obras[opcao - 1].titulo, "Pergunta 2", resposta2);
        salvarRespostasCSV(obras[opcao - 1].titulo, "Pergunta 3", resposta3);
        salvarRespostasCSV(obras[opcao - 1].titulo, "Pergunta 4", resposta4);
        salvarRespostasCSV(obras[opcao - 1].titulo, "Pergunta 5", resposta5);
        salvarRespostasCSV(obras[opcao - 1].titulo, "Pergunta 6", resposta6);
        salvarRespostasCSV(obras[opcao - 1].titulo, "Pergunta 7", resposta7);
        salvarRespostasCSV(obras[opcao - 1].titulo, "Pergunta 8", resposta8);
        salvarRespostasCSV(obras[opcao - 1].titulo, "Pergunta 9", resposta9);
        salvarRespostasCSV(obras[opcao - 1].titulo, "Pergunta 10", resposta10);

        printf("Obrigado por participar da nossa pesquisa! Suas respostas foram registradas.\n");
    } else if (opcaoForms == 2) {
        printf("Obrigado pela visita a obra! Pode continuar sua visita!\n");
    } else if (opcaoForms == 3) {
        printf("Obrigado pela visita e ate mais!\n");
        exit(0);
    } else if (opcaoForms == 4) {
        printf("Mostrando respostas do arquivo CSV:\n\n");
        mostrarRespostasCSV();
    } else {
        printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
    }
}

