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

int filhoEsq(int p)
{
  return 2*p+1;
}

int filhoDir(int p)
{
  return 2*p+2;
}

int ultimoPai(int n)
{
  return n/2-1;
}

void peneira(int *v, int n, int p)
{
  int maior=p, aux;
  if(filhoEsq(p) < n && v[filhoEsq(p)] > v[maior])
  {
    maior = filhoEsq(p);
  }
  if(filhoDir(p) < n && v[filhoDir(p)] > v[maior])
  {
    maior = filhoDir(p);
  }
  if(maior != p)
  {
    aux = v[maior];
    v[maior] = v[p];
    v[p] = aux;
    peneira(v, n, maior);
  }
}

void constroiHeap(int *v, int n)
{
  int i;
  for(i=ultimoPai(n); i>=0; i--)
    peneira(v, n, i);
}

void removeMax(int *v, int n)
{
  int aux = v[n-1];
  v[n-1] = v[0];
  v[0] = aux;
}

void heapSort(int *v, int n)
{
  int i;
  constroiHeap(v, n);
  for(i=n; i>0; i--)
  {
    removeMax(v, i);
    peneira(v, i-1, 0);
  }
}

int main()
{
  int *v, n;
  scanf("%d", &n);
  
  v = (int *) malloc(n*sizeof(int));
  le_vetor(v, n);
  
  heapSort(v, n);
  
  imprime_vetor(v, n);
  
  return 0;
}
