#include <stdio.h>
#include <stdlib.h>

void le_vetor(int *v, int n)
{
  for(int i=0; i<n; i++)
    scanf("%d", &v[i]);
}

void imprime_vetor(int *v, int n)
{
  for(int i=0; i<n; i++)
    printf("%d%c", v[i], i<n-1 ? ' ':'\n');
}

int busca(int *v, int n, int x)
{
  if(n == 0 || v[n-1] == x)
    return n-1;
  else
    return busca(v, n-1, x);
}

int main()
{
  int *v, n;
  scanf("%d", &n);
  v = (int *) malloc(n*sizeof(int));
  
  le_vetor(v, n);
  
  int i, x;
  scanf("%d", &x);
  
  i = busca(v, n, x);
  if(i >= 0)
    printf("Elemento %d encontrado na posicao %d\n", x, i);
  else
    printf("Elemento %d nao encontrado\n", x);
  
  return 0;
}
