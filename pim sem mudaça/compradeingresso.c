#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

void compraDeIngresso(int opcao, int I, int meia) {
    int maxDia = 50;
    int valor = 40;
    int totalIngressos = 0;

    printf("***************************\nDigite a forma do ingresso\n***************************\n");
    printf("1 - Para inteira\n");
    printf("2 - Para meia\n");
    scanf("%d", &opcao);

    if (opcao == 1) {
        printf("O valor  do ingresso e R$40,00\n");
        printf("Digite a quantidade de ingressos: ");
        scanf("%d", &I);

        if (totalIngressos + I > maxDia) {
            printf("Desculpe, excedeu o limite de ingressos disponiveis para hoje.\n");
        } else {
            totalIngressos += I;
            I = I * valor;
            printf("Valor do seu pedido: R$ %d,00\n", I);
            printf("O total de ingressos restantes e %d.", maxDia - totalIngressos);
        }
    } else if (opcao == 2) {
        printf("O valor  do ingresso e R$20,00\n");
        printf("Digite a quantidade de ingresso: ");
        scanf("%d", &meia);

        if (totalIngressos + meia > maxDia) {
            printf("Desculpe, excedeu o limite de ingressos disponíveis para hoje.\n");
        } else {
            totalIngressos += meia;
            meia = (meia * valor) / 2;
            printf("Valor do seu pedido: R$ %d,00.\n", meia);
        }
        printf("O total de ingressos restantes e %d.", maxDia - totalIngressos);
    }
    getch();
    system("cls");
}
