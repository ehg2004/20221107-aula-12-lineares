#include "utils.h"

/* */
void counting_sort (FILE *f, int range) 
{
  int i, j, total = 0;
  int *C = (int *)malloc((range+1) * sizeof(int));
  /*contador*/
  /*Terminar*/
  /*Imprimir no final desta função as frequências das letras!*/
  char ch = '\0';
  for(i=0;i<=range;i++)
  {
    C[i]=0;
  }
  while(!feof(f))
  {
    fscanf(f,"%c", &ch);
    ch=tolower(ch);
    if(isalpha(ch)){C[ch-'a']++;total++;}
  }
  print(C,range+1,"AAA \n");
  printf("Letra    Contagem   Frequencia \n");
  for(i=0;i<=range;i++)
  {
    printf("letra: %c  %d  %.4f  \n",'a'+i,C[i],(float)C[i]/(float)total);
  }
}

/* */
int main (int argc, char *argv[]) 
{
  if (argc < 2) 
  {
    printf("run: %s file.txt\n", argv[0]);
    exit(1);
  }

  FILE *f = fopen(argv[1], "r");

  int range = 25; /*número de letras do alfabeto (a-z)*/

  counting_sort (f, range);
  
  fclose (f);

  return 0;
}

