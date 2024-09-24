#include <stdio.h>

int main() {
    int n;
    
    // L� o n�mero de moedas
    printf("Informe o numero de moedas:\n");
    scanf("%d", &n);
    
    // Vetor para armazenar as probabilidades de cada moeda dar cara
    double p[n + 1];
    
    // L� as probabilidades de cada moeda
    int i;
    printf("Informe as probabilidades de cada moeda dar cara:\n");
    for (i = 1; i <= n; i++) {
        scanf("%lf", &p[i]);
    }
    
    // Vetor de programa��o din�mica para armazenar as probabilidades
    double f[n + 1][n + 1];
    
    // Inicializa��o: 0 moedas e 0 caras tem probabilidade 1
    f[0][0] = 1.0;
    
    // Calcula a probabilidade f(n, h) 
    int h;
    for (i = 1; i <= n; i++) {//Percorre de 1 at� n, e i representa o n�mero de moedas que foram jogadas.
        f[i][0] = f[i - 1][0] * (1.0 - p[i]);  // Probabilidade de 0 caras todas as moedas ca�rem coroa)
        for (h = 1; h <= i; h++) { //Percorre de 1 at� i, e h representa o n�mero de caras que foram obtidas.
            f[i][h] = f[i - 1][h - 1] * p[i] + f[i - 1][h] * (1.0 - p[i]);//calculando a probabilidade de cair cara ou cora
        }
    }
    
    // Soma as probabilidades de termos mais caras que coroas
    double ans = 0.0; //A vari�vel ans vai acumular as probabilidades.
    for (h = n / 2 + 1; h <= n; h++) {
        ans += f[n][h];
    }
    
    // Imprime a resposta com 9 casas decimais
    printf("A probabilidade de obter mais caras que coroas eh: %.9lf\n", ans);
    
    return 0;
}

