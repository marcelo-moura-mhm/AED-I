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

void selectionSort(int *v, int n)
{
  int iMenor, aux;
  for(int i=0; i<n; i++)
  {
    iMenor = i;
    for(int j=i+1; j<n; j++)
    {
      if(v[j] < v[iMenor])
      {
        iMenor = j;
      }
    }
    aux = v[i];
    v[i] = v[iMenor];
    v[iMenor] = aux;
  }
}

int main()
{
  int *v, n;
  scanf("%d", &n);
  
  v = (int *) malloc(n*sizeof(int));
  le_vetor(v, n);
  
  selectionSort(v, n);
  imprime_vetor(v, n);
  
  return 0;
}
