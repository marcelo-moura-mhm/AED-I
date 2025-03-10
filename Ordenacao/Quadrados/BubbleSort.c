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

void bubbleSort(int *v, int n)
{
  int aux;
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n-i-1; j++)
    {
      if(v[j] > v[j+1])
      {
        aux = v[j];
        v[j] = v[j+1];
        v[j+1] = aux;
      }
    }
  }
}

int main()
{
  int *v, n;
  scanf("%d", &n);
  
  v = malloc(n*sizeof(int));
  le_vetor(v, n);
  
  bubbleSort(v, n);
  
  imprime_vetor(v, n);
  
  return 0;
}
