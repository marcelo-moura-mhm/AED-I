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

void insertionSort(int *v, int n)
{
  int chave, j;
  for(int i=1; i<n; i++)
  {
    chave = v[i];
    j = i-1;
    while(j>=0 && v[j] >= chave)
    {
      v[j+1] = v[j];
      v[j] = chave;
      j--;
    }
  }
}

int main()
{
  int *v, n;
  scanf("%d", &n);
  
  v = (int *) malloc(n*sizeof(int));
  le_vetor(v, n);
  
  insertionSort(v, n);
  
  imprime_vetor(v, n);
  
  return 0;
}
