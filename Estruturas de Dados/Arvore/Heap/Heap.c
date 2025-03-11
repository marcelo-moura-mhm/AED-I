#include <stdio.h>
#include <stdlib.h>

struct tHeap
{
  int *dados;
  int quantidade;
  int tam;
};

struct tHeap criaHeap(int n)
{
  struct tHeap h;
  h.dados = (int *) malloc(n*sizeof(int));
  h.quantidade = 0;
  h.tam = n;
  return h;
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

void peneira(struct tHeap *t, int p)
{
  int maior = p, aux;
  if(filhoEsq(p) < t->quantidade && t->dados[filhoEsq(p)] > t->dados[maior])
  {
    maior = filhoEsq(p);
  }
  if(filhoDir(p) < t->quantidade && t->dados[filhoDir(p)] > t->dados[maior])
  {
    maior = filhoDir(p);
  }
  
  if(maior != p)
  {
    aux = t->dados[maior];
    t->dados[maior] = t->dados[p];
    t->dados[p] = aux;
    peneira(t, maior);
  }
}

void constroiHeap(struct tHeap *t)
{
  int i;
  for(i=ultimoPai(t->quantidade); i>=0; i--)
  {
    peneira(t, i);
  }
}

void insereHeap(struct tHeap *t, int x)
{
  if(t->quantidade < t->tam)
  {
    t->dados[t->quantidade] = x;
    t->quantidade++;
  }
}

void removeHeap(struct tHeap *t)
{
  int aux;
  if(t->quantidade > 0)
  {
    aux = t->dados[0];
    t->dados[0] = t->dados[t->quantidade-1];
    t->dados[t->quantidade-1] = aux;
    t->quantidade--;
    peneira(t, 0);
  }
}

void imprimeHeap(struct tHeap t)
{
  int i;
  for(i=0; i<t.quantidade; i++)
    printf("%d%c", t.dados[i], i<t.quantidade-1 ? ' ':'\n');
}

int main()
{
  int n;
  scanf("%d", &n);
  struct tHeap t = criaHeap(n);
  
  int opc, chave;
  do
  {
    printf("Escolha uma opcao: \n");
    printf("1 - Inserir Elemento\n");
    printf("2 - Remover Elemento\n");
    printf("3 - Construir Heap\n");
    printf("4 - Mostrar Heap\n");
    printf("5 - Sair\n");
    printf("==>");
    
    scanf("%d", &opc);
    
    switch(opc)
    {
      case 1: printf("Informe a chave: ");
              scanf("%d", &chave);
              insereHeap(&t, chave);
              break;
      case 2: removeHeap(&t);
              break;
      case 3: constroiHeap(&t);
              break;
      case 4: imprimeHeap(t);
              break;
    }
    
  }while(opc != 5);
  
  printf("programa terminado\n");
  
  return 0;
}
