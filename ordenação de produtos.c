#include <stdio.h>
#include <string.h>
void bubbleSort(char arr[][50], int n) {

int i, j;
char temp[50];

for (i = 0; i < n-1; i++)
{
for (j = 0; j < n-i-1; j++)
{
  if (strcmp(arr[j], arr[j+1]) > 0)
{
 
  strcpy(temp, arr[j]);
strcpy(arr[j], arr[j+1]);
  strcpy(arr[j+1], temp);
}
}
 }
 }
 int main() {
 
 int n, i;
  printf("Digite o numero de produtos: ");
  scanf("%d", &n);
  char produtos[n][50];
  printf("Digite os nomes dos produtos:\n");
  for (i = 0; i < n; i++)
  {
  scanf("%s", produtos[i]);
  }
  bubbleSort(produtos, n);
  printf("\n\nProdutos ordenados em ordem alfabetica:\n");
   for (i = 0; i < n; i++)
   {
    printf("%s\n", produtos[i]);
   }
    return 0;
}

