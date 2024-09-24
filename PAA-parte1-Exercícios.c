/*
1) Para cada um dos trechos de código abaixo, analise o tempo estimado de execução no melhor e no pior caso, considerando o modelo RAM. Considere que as variáveis n, m e vetor sejam dados de entrada.

a)
int soma = 0;
for (int i=0; i<n; i++)
soma = soma + i;

Resposta.: O laço for sempre será executado exatamente n vezes, independentemente do valor de n.
Portanto, o tempo de execução no melhor caso é proporcional a n (linear), ou seja, no melhor caso o laço percorre n elementos, então o tempo de execução é O(n).
Assim como no melhor caso, não há condições dentro do laço que possam causar mais iterações. O laço for sempre será executado n vezes, independentemente da entrada, logo o pior caso será Igual ao melhor caso, O(n).

b)
int soma1 = 0;
int soma2 = 0;
for (int i=0; i<n; i++){
soma1 = soma1 + 1;
soma2 = soma2 + i;
}
Resposta.:  O código é sempre executado n vezes, independentemente de valores específicos de n. O laço percorre n elementos, e ambas as somas são incrementadas, logo no melhor caso oempo de execução será O(n).
Como não há condições especiais dentro do laço que possam aumentar o número de iterações. O laço vai sempre executar exatamente n vezes então o pior caso também será O(n).


c)
int soma = 0;
for (int i=0; i<n; i++){
if ( vetor[i] % 2 == 0) //se for par
soma = soma + vetor[i];
}
Resposta.: O laço for precisa percorrer todos os n elementos do vetor para verificar se são pares ou não. O tempo de execução ainda é proporcional a n, pois o laço é executado n vezes, logo tempo no melhor caso será O(n).
No pior caso o tempo de execução ainda é proporcional a n, pois o laço é executado n vezes. No pior cenário o tempo também  é igual a O(n).

d)
int soma1 = 0;
for (int i=0; i<n; i++){
soma1 = soma1 + 1;
}
for (int j=0; j<n;j++){
soma1 = soma1 + j;
}

Resposta.: Melhor caso: Temos dois laços independentes, cada um percorrendo n elementos, então o tempo de execução é O(n).  Ambos os laços percorrem exatamente n vezes e executam operações de tempo constante dentro de cada iteração. O primeiro laço faz uma soma constante, e o segundo faz uma soma usando o valor de j.
Assim como no melhor caso, ambos os laços têm tempo de execução O(n), e como são independentes, o pior caso também  é O(n).


e)
int soma = 0;
for (int i=0; i<n; i++){
for (int j=0; j<n; j++){
soma = soma + 1;
}
}
Resposta.: O laço  sempre será executado n vezes para cada iteração do laço externo, o que significa que o número total de iterações será n×n=n2. Portanto, o tempo de execução no melhor caso: O(n2). E no pior caso o tempo também será O(n2).

f)
int soma = 0;
for (int i=0; i<n; i++){
for (int j=0; j<m; j++){
soma = soma + 1;
}
}
Resposta.: O número total de iterações será n×m, pois o laço interno executa m vezes para cada uma das n iterações do laço externo. Portanto o melhor caso: é O(n×m).
O pior caso também não altera o número de iterações. Assim como no melhor caso, o laço externo sempre será executado n vezes, e o laço interno será executado m vezes para cada uma das n iterações do laço externo. Portanto, o tempo de execução no pior caso também é O(n×m).



g)
int menor = MAIOR-INTEIRO;
for (int i=0; i<n; i++){
if (vetor[i] < menor)
menor = vetor[i];
}
Resposta.: O laço for sempre percorre todos os n elementos do vetor, mesmo que o menor valor esteja no início.
A comparação vetor[i] < menor é feita para cada elemento, e a operação de atribuição menor = vetor[i] é realizada apenas quando um elemento menor é encontrado. Ambas as operações têm tempo constante O(1). Portanto, o tempo de execução no melhor caso é O(n).
Pior caso assim como no melhor caso, o laço ainda precisa percorrer todos os n elementos do vetor para garantir que o menor valor seja encontrado.
O número de iterações e o comportamento do laço não mudam, independentemente da posição do menor valor no vetor. Portanto, o tempo de execução no pior caso também é O(n).

h)
int v[][] = new int[n][n];
for (int i=0; i<n; i++){
for (int j=0; j<n; j++){
v[i][j] = i * j;
}
}
Resposta.: O laço externo percorre n vezes, e para cada valor de i, o laço interno também percorre n vezes, resultando em n×n=n2 iterações no total.
A operação dentro do laço (v[i][j] = i * j) é de tempo constante O(1), então a quantidade de iterações O(n2) determina o tempo de execução.
Portanto, no melhor caso, o tempo de execução é O(n2), já que o código precisa preencher toda a matriz n×n, realizando n2 operações.
O pior caso também não altera o comportamento dos laços. Não importa quais valores estão sendo processados, o código sempre percorre a matriz inteira, realizando exatamente n2 operações. Portanto também é O(n2).


i)
int menor = MAIOR-INTEIRO;
for (int i=0; i<n; i++){
if (vetor[i] < menor)
menor = vetor[i];
}
if (menor < 0){
for (int i=0; i<n; i++){
menor = menor * (i+1);
}
}


Resposta.: Melhor caso: O primeiro laço percorre n elementos, e se o menor for negativo, o segundo laço também executa n vezes. Portanto, o tempo de execução é O(n).
Pior caso: Igual ao melhor caso, O(n).


j)
int menor = MAIOR-INTEIRO;
for (int i=0; i<n; i++){
if (vetor[i] < menor)
menor = vetor[i];
}
if (menor < 0){
for (int i=0; i<n; i++){
menor = menor * (i+1);
}
}else if (menor > 0){
for (int i=0; i<n*n; i++)
printf(“%d\n”, menor);
} else {
printf(“%d\n”, menor);
}

Resposta.: Melhor caso: Se o menor for 0, apenas o printf será executado, resultando em O(1).
Pior caso: Se menor > 0, o laço n^2 será executado, resultando em O(n2).

2) Resposta.: Melhor caso: Se o primeiro elemento da lista for o que estamos buscando, a execução é O(1).
Pior caso: Se o nome não estiver na lista, precisamos percorrer todos os elementos, resultando em O(n).


