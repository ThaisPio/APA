/*
1) Para cada um dos trechos de c�digo abaixo, analise o tempo estimado de execu��o no melhor e no pior caso, considerando o modelo RAM. Considere que as vari�veis n, m e vetor sejam dados de entrada.

a)
int soma = 0;
for (int i=0; i<n; i++)
soma = soma + i;

Resposta.: O la�o for sempre ser� executado exatamente n vezes, independentemente do valor de n.
Portanto, o tempo de execu��o no melhor caso � proporcional a n (linear), ou seja, no melhor caso o la�o percorre n elementos, ent�o o tempo de execu��o � O(n).
Assim como no melhor caso, n�o h� condi��es dentro do la�o que possam causar mais itera��es. O la�o for sempre ser� executado n vezes, independentemente da entrada, logo o pior caso ser� Igual ao melhor caso, O(n).

b)
int soma1 = 0;
int soma2 = 0;
for (int i=0; i<n; i++){
soma1 = soma1 + 1;
soma2 = soma2 + i;
}
Resposta.:  O c�digo � sempre executado n vezes, independentemente de valores espec�ficos de n. O la�o percorre n elementos, e ambas as somas s�o incrementadas, logo no melhor caso oempo de execu��o ser� O(n).
Como n�o h� condi��es especiais dentro do la�o que possam aumentar o n�mero de itera��es. O la�o vai sempre executar exatamente n vezes ent�o o pior caso tamb�m ser� O(n).


c)
int soma = 0;
for (int i=0; i<n; i++){
if ( vetor[i] % 2 == 0) //se for par
soma = soma + vetor[i];
}
Resposta.: O la�o for precisa percorrer todos os n elementos do vetor para verificar se s�o pares ou n�o. O tempo de execu��o ainda � proporcional a n, pois o la�o � executado n vezes, logo tempo no melhor caso ser� O(n).
No pior caso o tempo de execu��o ainda � proporcional a n, pois o la�o � executado n vezes. No pior cen�rio o tempo tamb�m  � igual a O(n).

d)
int soma1 = 0;
for (int i=0; i<n; i++){
soma1 = soma1 + 1;
}
for (int j=0; j<n;j++){
soma1 = soma1 + j;
}

Resposta.: Melhor caso: Temos dois la�os independentes, cada um percorrendo n elementos, ent�o o tempo de execu��o � O(n).  Ambos os la�os percorrem exatamente n vezes e executam opera��es de tempo constante dentro de cada itera��o. O primeiro la�o faz uma soma constante, e o segundo faz uma soma usando o valor de j.
Assim como no melhor caso, ambos os la�os t�m tempo de execu��o O(n), e como s�o independentes, o pior caso tamb�m  � O(n).


e)
int soma = 0;
for (int i=0; i<n; i++){
for (int j=0; j<n; j++){
soma = soma + 1;
}
}
Resposta.: O la�o  sempre ser� executado n vezes para cada itera��o do la�o externo, o que significa que o n�mero total de itera��es ser� n�n=n2. Portanto, o tempo de execu��o no melhor caso: O(n2). E no pior caso o tempo tamb�m ser� O(n2).

f)
int soma = 0;
for (int i=0; i<n; i++){
for (int j=0; j<m; j++){
soma = soma + 1;
}
}
Resposta.: O n�mero total de itera��es ser� n�m, pois o la�o interno executa m vezes para cada uma das n itera��es do la�o externo. Portanto o melhor caso: � O(n�m).
O pior caso tamb�m n�o altera o n�mero de itera��es. Assim como no melhor caso, o la�o externo sempre ser� executado n vezes, e o la�o interno ser� executado m vezes para cada uma das n itera��es do la�o externo. Portanto, o tempo de execu��o no pior caso tamb�m � O(n�m).



g)
int menor = MAIOR-INTEIRO;
for (int i=0; i<n; i++){
if (vetor[i] < menor)
menor = vetor[i];
}
Resposta.: O la�o for sempre percorre todos os n elementos do vetor, mesmo que o menor valor esteja no in�cio.
A compara��o vetor[i] < menor � feita para cada elemento, e a opera��o de atribui��o menor = vetor[i] � realizada apenas quando um elemento menor � encontrado. Ambas as opera��es t�m tempo constante O(1). Portanto, o tempo de execu��o no melhor caso � O(n).
Pior caso assim como no melhor caso, o la�o ainda precisa percorrer todos os n elementos do vetor para garantir que o menor valor seja encontrado.
O n�mero de itera��es e o comportamento do la�o n�o mudam, independentemente da posi��o do menor valor no vetor. Portanto, o tempo de execu��o no pior caso tamb�m � O(n).

h)
int v[][] = new int[n][n];
for (int i=0; i<n; i++){
for (int j=0; j<n; j++){
v[i][j] = i * j;
}
}
Resposta.: O la�o externo percorre n vezes, e para cada valor de i, o la�o interno tamb�m percorre n vezes, resultando em n�n=n2 itera��es no total.
A opera��o dentro do la�o (v[i][j] = i * j) � de tempo constante O(1), ent�o a quantidade de itera��es O(n2) determina o tempo de execu��o.
Portanto, no melhor caso, o tempo de execu��o � O(n2), j� que o c�digo precisa preencher toda a matriz n�n, realizando n2 opera��es.
O pior caso tamb�m n�o altera o comportamento dos la�os. N�o importa quais valores est�o sendo processados, o c�digo sempre percorre a matriz inteira, realizando exatamente n2 opera��es. Portanto tamb�m � O(n2).


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


Resposta.: Melhor caso: O primeiro la�o percorre n elementos, e se o menor for negativo, o segundo la�o tamb�m executa n vezes. Portanto, o tempo de execu��o � O(n).
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
printf(�%d\n�, menor);
} else {
printf(�%d\n�, menor);
}

Resposta.: Melhor caso: Se o menor for 0, apenas o printf ser� executado, resultando em O(1).
Pior caso: Se menor > 0, o la�o n^2 ser� executado, resultando em O(n2).

2) Resposta.: Melhor caso: Se o primeiro elemento da lista for o que estamos buscando, a execu��o � O(1).
Pior caso: Se o nome n�o estiver na lista, precisamos percorrer todos os elementos, resultando em O(n).


