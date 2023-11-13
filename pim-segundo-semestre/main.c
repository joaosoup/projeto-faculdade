#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "obras.h"
#include "gerenciamento_obras.h"

int main(void) {
    int opcao = 0;
    int opcaoForms = 0;
    bool sair = false;

    struct Obra obras[4];
    inicializarObras(obras);

    int numObras = 4;

    printf("Bem-vindo ao nosso Cinema multitematico!\n\n");

    while (!sair) {
        exibirOpcoes(obras);
        scanf("%d", &opcao);
        system("cls");

        if (opcao >= 1 && opcao <= 4) {
            printf("Titulo: %s \n\n", obras[opcao - 1].titulo);
            printf("Descricao: %s\n\n", obras[opcao - 1].descricao);
            printf("Voce gostaria de responder um formulario sobre a obra que voce leu agora? Ou ver sobre outra obra?\n 1 - Sim \n 2 - Quero ver outra obra\n 3 - Quero sair do sistema do museu!\n 4 - Mostrar respostas do arquivo CSV\n");
            scanf("%d", &opcaoForms);
            system("cls");

            if (opcaoForms == 1) {
                printf("Pergunta 1: Qual sua opiniao sobre esta obra? (Responda com a letra da alternativa.)\n");
                printf("a) Excelente\nb) Bom\nc) Regular\nd) Ruim\n");
                char resposta1;
                scanf(" %c", &resposta1);
                system("cls");

                printf("Pergunta 2: Voce gostaria que o museu adicionasse mais obras deste tipo? (Responda com a letra da alternativa.)\n");
                printf("a) Sim, com certeza\nb) Talvez\nc) Nao sei\nd) Nao, obrigado\n");
                char resposta2;
                scanf(" %c", &resposta2);
                system("cls");

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
            } else if (opcaoForms == 5) { // Corrigido o teste para opcaoForms
                printf("Obrigado por visitar nosso museu!\n");
                sair = true;
            } else if (opcaoForms == 6) { // Corrigido o teste para opcaoForms
                int opcaoGerenciamento = 0;

                printf("Menu de Gerenciamento de Obras:\n");
                printf("1 - Incluir Obra\n");
                printf("2 - Alterar Obra\n");
                printf("3 - Consultar Obra\n");
                printf("4 - Excluir Obra\n");
                printf("5 - Voltar ao Menu Principal\n");
                scanf("%d", &opcaoGerenciamento);

                switch (opcaoGerenciamento) {
                    case 1:
                        incluirObra(obras, &numObras);
                        break;
                    case 2:
                        alterarObra(obras, numObras);
                        break;
                    case 3:
                        consultarObra(obras, numObras);
                        break;
                    case 4:
                        excluirObra(obras, &numObras);
                        break;
                    case 5:
                        break;
                    default:
                        printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
                }
            } else {
                printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
            }
        } else {
            printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
        }
    }

    return 0;
}
