#include <stdio.h>
#include <stdbool.h>
#include "obras.h"

int main() {
    int opcao = 0;
    int opcaoForms = 0;
    bool sair = false;

    struct Obra obras[4];
    inicializarObras(obras);

    printf("Bem-vindo ao nosso Cinema multitematico!\n\n");

    while (!sair) {
        exibirOpcoes(obras);
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 4) {
            printf("Titulo: %s \n\n", obras[opcao - 1].titulo);
            printf("Descricao: %s\n\n", obras[opcao - 1].descricao);
            printf("Voce gostaria de responder um formulario sobre a obra que voce leu agora? Ou ver sobre outra obra?\n 1 - Sim \n 2 - Quero ver outra obra\n 3 - Quero sair do sistema do museu!\n 4 - Mostrar respostas do arquivo CSV\n");
            scanf("%d", &opcaoForms);

            if (opcaoForms == 1) {
                printf("Pergunta 1: Qual sua opiniao sobre esta obra? (Responda com a letra da alternativa.)\n");
                printf("a) Excelente\nb) Bom\nc) Regular\nd) Ruim\n");
                char resposta1;
                scanf(" %c", &resposta1);

                printf("Pergunta 2: Voce gostaria que o museu adicionasse mais obras deste tipo? (Responda com a letra da alternativa.)\n");
                printf("a) Sim, com certeza\nb) Talvez\nc) Nao sei\nd) Nao, obrigado\n");
                char resposta2;
                scanf(" %c", &resposta2);

                salvarRespostas(obras[opcao - 1].titulo, "Pergunta 1", resposta1);
                salvarRespostas(obras[opcao - 1].titulo, "Pergunta 2", resposta2);

                printf("Obrigado por participar da nossa pesquisa! Suas respostas foram registradas.\n");
            } else if (opcaoForms == 2) {
                printf("Obrigado pela visita a obra! Pode continuar sua visita!\n");
            } else if (opcaoForms == 3) {
                printf("Obrigado pela visita e ate mais!\n");
                sair = true;
            } else if (opcaoForms == 4) {
                printf("Mostrando respostas do arquivo CSV:\n\n");
                mostrarRespostasCSV();
            } else {
                printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
            }
        } else if (opcao == 5) {
            printf("Obrigado por visitar nosso museu!");
            sair = true;
        } else {
            printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
        }
    }

    return 0;
}
