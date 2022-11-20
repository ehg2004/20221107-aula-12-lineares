#include "utils.h"

/* */
int* process_interval (int *A, int n, int range) {
  int i, j;
  int *C = (int *)malloc((range+1) * sizeof(int)); /*contador*/
  /*Terminar*/
  for(j=0;j<=range;j++)
  {
    C[j]=0;
  }
  for(j=0;j<n;j++)
  {
    C[A[j]]++;
  }
  for(i=1;i<=range;i++)
  {
    C[i]+=C[i-1];
  }
  return C;
}

int query (int *C, int n, int i, int j) 
{
  /*C[i]=numero de elementos de 0 ate i*/
  /*nEl(0) = C[0]*/
  /*nEl(i)=C[i]-C[i-1]*/
  /*nEl(j~i)=C[i]-C[j-1]*/
  if(i<=j)
  {
    if(i==0){return(C[j]);}
    else{return(C[j]-C[i-1]);}
  }
  else{return(-1);}
}

/* */
int main () 
{
  int a, b, n = 15;
  int range = 10;
  int A[] = {9,2,0,8,7,9,3,2,0,7,5,0,2,6,0};
  print (A, n, "Input");
  int *C = process_interval (A, n, range);
  a = 0, b = 3;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 4, b = 8;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 0, b = 0;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 6, b = 6;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  return 0;
}

