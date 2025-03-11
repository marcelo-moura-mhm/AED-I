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

int particiona(int *v, int e, int d)
{
  int i, aux, pm=e-1, chave=v[d];
  for(i=e; i<=d-1; i++)
  {
    if(v[i] <= chave)
    {
      pm++;
      aux = v[pm];
      v[pm] = v[i];
      v[i] = aux;
    }
  }
  pm++;
  v[i] = v[pm];
  v[pm] = chave;
  return pm;
}

void quickSort(int *v, int e, int d)
{
  int m;
  if(e<d)
  {
  m = particiona(v, e, d);
  quickSort(v, e, m-1);
  quickSort(v, m+1, d);
  }
}

int main()
{
  int n;
  scanf("%d", &n);
  
  int *v = (int *) malloc(n*sizeof(int));
  le_vetor(v, n);
  
  quickSort(v, 0, n-1);
  imprime_vetor(v, n);
  
  return 0;
}
