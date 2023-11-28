#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "obra.h"
#include<conio.h>


#define MAX_OBRAS 10

void incluirObra(struct Obra obras[], int *numObras);
void excluirObra(struct Obra obras[], int *numObras);
void alterarObra(struct Obra obras[], int numObras);


int main()
{
    int opcao = 0;
    bool sair = false;
    int opcaoForms = 0;

    struct Obra obras[4];
    inicializarObras(obras);

    int numObras = 4;


    printf("Bem-vindo ao nosso Cinema multitematico!\n\n");

    while (!sair) {
        printf("Escolha uma opcao:\n");
        printf("1 - Venda de Ingressos\n");
        printf("2 - Gerenciamento de Obras\n");
        printf("3 - Visualizar como Visitante\n");
        printf("4 - Ver Respostas dos Formularios\n");
        printf("5 - Sair\n");

        scanf("%d", &opcao);
        system("cls");

        switch (opcao) {
            case 1:
                compraDeIngresso();
                break;

            case 2:
                printf("Escolha uma opcao de gerenciamento de obras:\n");
                printf("1 - Incluir Obra\n");
                printf("2 - Excluir Obra\n");
                printf("3 - Alterar Obra\n");
                printf("4 - Voltar ao Menu Principal\n");

                scanf("%d", &opcaoForms);
                system("cls");

                switch (opcaoForms) {
                    case 1:
                        incluirObra(obras, &numObras);
                        break;

                    case 2:
                        excluirObra(obras, &numObras);
                        break;

                    case 3:
                        alterarObra(obras, numObras);
                        break;

                    case 4:
                        break;

                    default:
                        printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
                }
                        system("cls");
                    break;

            case 3:
                exibirOpcoes(obras, numObras);
                scanf("%d", &opcao);
                system("cls");

                if (opcao >= 1 && opcao <= numObras) {
                    realizarQuestionario(obras, opcao, &numObras);
                } else {
                    printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
                }
                break;

                if (opcao >= 1 && opcao <= 4) {


                } else {
                    printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
                }
                system("cls");
                break;


            case 4:
                mostrarRespostasCSV();
                contarRespostas('A');
                contarRespostas('B');
                break;

            case 5:
                printf("Obrigado por visitar nosso museu!\n");
                sair = true;
                break;

            default:
                printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
        }
    }
    return 0;
}
