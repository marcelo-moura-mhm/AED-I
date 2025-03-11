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

void intercala(int *v, int e, int m, int d)
{
  int *aux, i, fim_esq=m-1, tam=d-e+1;
  aux = (int *) malloc(tam*sizeof(int));
  for(i=0; e<=fim_esq && m<=d; i++)
  {
    if(v[e] < v[m])
    {
      aux[i] = v[e];
      e++;
    }
    else
    {
      aux[i] = v[m];
      m++;
    }
  }
  for(; e<=fim_esq; e++, i++)
    aux[i] = v[e];
  for(; m<=d; m++, i++)
    aux[i] = v[m];
  for(i=tam-1; i>=0; i--, d--)
    v[d] = aux[i];
  free(aux);
}

void mergeSort(int *v, int e, int d)
{
  int meio;
  if(e<d)
  {
    meio = (e+d)/2;
    mergeSort(v, e, meio);
    mergeSort(v, meio+1, d);
    intercala(v, e, meio+1, d);
  }
}

int main()
{
  int n;
  scanf("%d", &n);
  
  int *v = (int *) malloc(n*sizeof(int));
  le_vetor(v, n);
  
  mergeSort(v, 0, n-1);
  imprime_vetor(v, n);
  
  return 0;
}
