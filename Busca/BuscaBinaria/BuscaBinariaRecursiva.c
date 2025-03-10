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

int busca(int *v, int ini, int fim, int x)
{
  int meio;
  if(ini <= fim)
  {
    meio = (ini+fim)/2;
    if(v[meio] == x)
    {
      return meio;
    }
    else if(v[meio] < x)
    {
      return busca(v, meio+1, fim, x);
    }
    else
    {
      return busca(v, ini, meio-1, x);
    }
  }
  return -1;
}

int main()
{
  int *v, n;
  scanf("%d", &n);
  v = (int *) malloc(n*sizeof(int));
  
  le_vetor(v, n);
  
  int x, i;
  scanf("%d", &x);
  i = busca(v, 0, n, x);
  if(i >= 0)
    printf("Elemento %d encontrado na posicao %d\n", x, i);
  else
    printf("Elemento %d nao encontrado\n", x);
    
  return 0;
}
