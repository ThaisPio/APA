#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Time {
    char nome_Time[30];
    int pontos;
};

void trocarTimes(struct Time *a, struct Time *b) {
    struct Time temp = *a;
    *a = *b;
    *b = temp;
}

void ordenarPorPontos(struct Time times[], int inicio, int fim) {
    if (inicio < fim) {
        int indice = fim;
        int i = inicio - 1;
        int j;

        for (j = inicio; j <= fim - 1; j++) {
            if (times[j].pontos > times[indice].pontos) {
                i++;
                trocarTimes(&times[i], &times[j]);
            }
        }

        trocarTimes(&times[i + 1], &times[indice]);
        ordenarPorPontos(times, inicio, i);
        ordenarPorPontos(times, i + 2, fim);
    }
}

int main() {
    int opcao, pontosBusca, i; 
    struct Time tabela[] = {
        {"Palmeiras", 63},
        {"Flamengo", 63},
        {"Botafogo", 62},
        {"Atletico-MG", 60},
        {"Gremio", 59},
        {"Bragantino", 59},
        {"Fluminense", 53},
        {"Atletico - PR", 52},
        {"Cuiba", 48},
        {"Sao Paulo", 47},
        {"Internacional", 46},
        {"Fortaleza", 45},
        {"Cruzeiro", 44},
        {"Corinthians", 44},
        {"Santos", 43},
        {"Vasco", 42},
        {"Bahia", 41},
        {"Goias", 35},
        {"Coritiba", 29},
        {"America-MG", 21}
    };

    do {
        printf("\nMenu de Atividades:\n");
        printf("1. Retornar o Nome e Posicao do Time com base na quantidade de pontos\n");
        printf("2. Exibir os 5 primeiros colocados\n");
        printf("3. Exibir os 5 ultimos colocados\n");
        printf("4. Exibir a diferenca de pontos entre os 5 primeiros\n");
        printf("5. Exibir a diferenca de pontos entre os 5 ultimos\n");
        printf("6. Reordenar a tabela para exibir apenas metade dos times com base na quantidade de pontos\n");
        printf("0. Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe a quantidade de pontos: ");
                scanf("%d", &pontosBusca);

                for (i = 0; i < sizeof(tabela) / sizeof(tabela[0]); i++) {
                    if (tabela[i].pontos == pontosBusca) {
                        printf("Posicao: %d, Time: %s\n", i + 1, tabela[i].nome_Time);
                    }
                }
                break;

            case 2:
                for (i = 0; i < 5; i++) {
                    printf("Posicao: %d, Time: %s, Pontos: %d\n", i + 1, tabela[i].nome_Time, tabela[i].pontos);
                }
                break;

            case 3:
                for (i = sizeof(tabela) / sizeof(tabela[0]) - 5; i < sizeof(tabela) / sizeof(tabela[0]); i++) {
                    printf("Posicao: %d, Time: %s, Pontos: %d\n", i + 1, tabela[i].nome_Time, tabela[i].pontos);
                }
                break;

            case 4:
                printf("Diferenca de pontos entre os 5 primeiros: %d\n", tabela[0].pontos - tabela[4].pontos);
                break;

            case 5:
                printf("Diferenca de pontos entre os 5 ultimos: %d\n", tabela[sizeof(tabela) / sizeof(tabela[0]) - 5].pontos - tabela[sizeof(tabela) / sizeof(tabela[0]) - 1].pontos);
                break;

            case 6:
                ordenarPorPontos(tabela, 0, sizeof(tabela) / sizeof(tabela[0]) - 1);
                int metade = sizeof(tabela) / sizeof(tabela[0]) / 2;

                for (i = 0; i < metade; i++) {
                    printf("Posicao: %d, Time: %s, Pontos: %d\n", i + 1, tabela[i].nome_Time, tabela[i].pontos);
                }
                break;

            case 0:
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
