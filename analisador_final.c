#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

// Estrutura para armazenar informações sobre a análise do código
typedef struct {
    int loops;
    int passos; // Contagem de passos
    int chamadas_recursivas;
    bool eh_algoritmo_ordenacao;
    bool eh_probabilistico;
    bool eh_programacao_dinamica;
    bool eh_backtracking;
    bool eh_recursivo;
    bool eh_guloso;
    bool eh_divide_conquista;
    char melhor_caso[20];
    char pior_caso[20];
} AnaliseCodigo;

// Função para inicializar os valores da análise
void inicializar_analise(AnaliseCodigo *analise) {
    analise->loops = 0;
    analise->passos = 0;
    analise->chamadas_recursivas = 0;
    analise->eh_algoritmo_ordenacao = false;
    analise->eh_probabilistico = false;
    analise->eh_programacao_dinamica = false;
    analise->eh_backtracking = false;
    analise->eh_recursivo = false;
    analise->eh_guloso = false;
    analise->eh_divide_conquista = false;
    strcpy(analise->melhor_caso, "N/A");
    strcpy(analise->pior_caso, "N/A");
}

// Função para identificar o tipo de algoritmo e técnica usada
void analisar_codigo(FILE *arquivo, AnaliseCodigo *analise) {
    char linha[256];

    while (fgets(linha, sizeof(linha), arquivo)) {
        // Contagem de loops (for ou while)
        if (strstr(linha, "for") || strstr(linha, "while")) {
            analise->loops++;
            analise->passos++; // Incrementa o número de passos por loop
        }
        
        // Contagem de passos em atribuições e cálculos
        if (strstr(linha, "=") && !strstr(linha, "==")) {
            analise->passos++; // A cada atribuição, contamos um passo
        }

        // Contagem de passos para recursão
        if (strstr(linha, "fibonacci(") || strstr(linha, "collatz(") || strstr(linha, "imprimirSubconjunto(")) {
            analise->chamadas_recursivas++;
            analise->eh_recursivo = true;
            analise->passos++; // Incrementa o número de passos para cada chamada recursiva
        }

        // Identificação de dividir para conquistar (ex: Merge Sort)
        if (strstr(linha, "mergeSort(") || strstr(linha, "merge(")) {
            analise->eh_divide_conquista = true;
            strcpy(analise->melhor_caso, "O(n log n)");
            strcpy(analise->pior_caso, "O(n log n)");
        }

        // Identificação de backtracking (geração de soluções alternativas)
        if (strstr(linha, "imprimirSubconjunto(") || strstr(linha, "solveNQUtil(")) {
            analise->eh_backtracking = true;
            strcpy(analise->melhor_caso, "O(2^n)");
            strcpy(analise->pior_caso, "O(2^n)");
        }

        // Identificação de programação dinâmica (uso de tabelas/matrizes)
        if (strstr(linha, "int f[") || strstr(linha, "double f[") || strstr(linha, "fibonacci") || strstr(linha, "moedas")) {
            analise->eh_programacao_dinamica = true;
            strcpy(analise->melhor_caso, "O(n)");
            strcpy(analise->pior_caso, "O(n^2)");
        }

        // Identificação de algoritmos probabilísticos (uso de probabilidade/aleatoriedade)
        if (strstr(linha, "rand(") || strstr(linha, "probabilidade") || strstr(linha, "p[")) {
            analise->eh_probabilistico = true;
            strcpy(analise->melhor_caso, "O(n)");
            strcpy(analise->pior_caso, "Depende do randomizador");
        }

        // Identificação de programação gulosa (decisões locais ótimas)
        if (strstr(linha, "knapsack(") || strstr(linha, "ratio")) {
            analise->eh_guloso = true;
            strcpy(analise->melhor_caso, "O(n log n)");
            strcpy(analise->pior_caso, "O(n log n)");
        }

        // Identificação de algoritmos de ordenação interna 
        if (strstr(linha, "insertionSort(") || (strstr(linha, "for") && strstr(linha, "j = i"))) {
            analise->eh_algoritmo_ordenacao = true;
            strcpy(analise->melhor_caso, "O(n)");
            strcpy(analise->pior_caso, "O(n^2)");
        }
    }
}

// Função para exibir os resultados da análise e fornecer melhor/pior caso
void exibir_resultados(AnaliseCodigo *analise) {
    printf("\n--- Resultados da Análise ---\n");
    printf("Número de Loops: %d\n", analise->loops);
    printf("Número de Passos: %d\n", analise->passos);
    printf("Número de Chamadas Recursivas: %d\n", analise->chamadas_recursivas);

    // Classificação do tipo de algoritmo
    if (analise->eh_algoritmo_ordenacao) {
        printf("Tipo de Algoritmo: Ordenação Interna\n");
    }
    if (analise->eh_recursivo) {
        printf("Tipo de Algoritmo: Recursão\n");
    }
    if (analise->eh_divide_conquista) {
        printf("Técnica Utilizada: Dividir para Conquistar\n");
    }
    if (analise->eh_backtracking) {
        printf("Técnica Utilizada: Backtracking\n");
    }
    if (analise->eh_programacao_dinamica) {
        printf("Técnica Utilizada: Programação Dinâmica\n");
    }
    if (analise->eh_probabilistico) {
        printf("Técnica Utilizada: Algoritmo Probabilístico\n");
    }
    if (analise->eh_guloso) {
        printf("Técnica Utilizada: Programação Gulosa\n");
    }

    // Exibir melhor e pior caso
    printf("Complexidade Melhor Caso: %s\n", analise->melhor_caso);
    printf("Complexidade Pior Caso: %s\n", analise->pior_caso);

    if (!analise->eh_algoritmo_ordenacao && !analise->eh_recursivo &&
        !analise->eh_backtracking && !analise->eh_programacao_dinamica &&
        !analise->eh_probabilistico && !analise->eh_guloso && !analise->eh_divide_conquista) {
        printf("Técnica Utilizada: Não identificada automaticamente\n");
    }
}

// Função principal para abrir o arquivo e realizar a análise
int main() {
    setlocale(LC_ALL, ""); 

    // Nome do arquivo que será aberto automaticamente
    char nome_do_arquivo[] = "moedas.c";
    
    FILE *arquivo;
    AnaliseCodigo analise;

    // Inicializar a análise
    inicializar_analise(&analise);

    // Abrir o arquivo automaticamente
    arquivo = fopen(nome_do_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s!\n", nome_do_arquivo);
        return 1;
    }

    // Exibir o conteúdo do arquivo
    printf("\n--- Conteúdo do Arquivo %s ---\n", nome_do_arquivo);
    char ch;
    while ((ch = fgetc(arquivo)) != EOF) {
        putchar(ch);
    }
    
    // Voltar o ponteiro para o início do arquivo para realizar a análise
    rewind(arquivo);

    // Analisar o código lido
    analisar_codigo(arquivo, &analise);

    // Fechar o arquivo
    fclose(arquivo);

    // Exibir os resultados da análise
    exibir_resultados(&analise);

    return 0;
}

