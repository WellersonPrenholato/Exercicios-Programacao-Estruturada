#include <stdio.h>
#include <stdlib.h>
  
  int main(){
      int *p;
      int i,k,n;
      printf ("\nDigite a quantidade de numeros que serao digitados: ");
      //fflush(stdin);
      scanf ("%d",&i);
  
      /* a funcao malloc reserva espaco suficiente para um vetor de inteiros.
      caso sejam digitados 5 elementos serao reservados 20 bytes, pois cada
      inteiro ocupa 4 bytes na memoria */
      p=(int*)malloc(i*sizeof(int));
      if (p==NULL){
          printf ("\nERRO.MEMORIA INSUFICIENTE");
          exit(1);
      }
      for (k=0;k<i;k++){
          printf ("\nDigite o %do valor do vetor: ",k+1);
          //fflush(stdin);
          scanf ("%d",&p[k]);
      }
      printf ("\n\nVETOR.\n");
      for (k=0;k<i;k++)
      printf ("%d\t",p[k]);
  
      printf ("\n\nSeu vetor possui %d elementos.",i);
      printf ("\nDigite um valor positivo para aumentar ao vetor.");
      printf ("\nDigite um valor negativo para diminuir do vetor.");
      printf ("\n\n-->");
      //fflush(stdin);
      scanf ("%d",&n);
      if (!(i+n)){
          printf ("\nSeu vetor possui 0 elementos.\n\n");
          free(p);
          return 0;
          system("pause");
      }
      else if ((i+n)<0){
          printf ("\nSeu vetor possui qtd negativa de elemento.\n\nIMPOSSIVEL ALOCAR MEMORIA.\n\n");
          free(p);
          return 0;
          system("pause");
      }
  
      /* a funcao realloc aumenta (numero positivo) ou diminui (numero negativo), o tamanho do
      vetor dinamicamente. ela recebe o ponteiro para o vetor anterior e retorna o novo espaço alocado */
      p=(int*)(realloc(p,(i+n)*sizeof(int)));
      if (p==NULL){
          printf ("\nERRO DE RE-ALOCACAO.MEMORIA INSUFICIENTE");
          exit(1);
      }
      for (k=0;k<(n+i);k++){
          printf ("\nDigite o %do valor do vetor: ",k+1);
          //fflush(stdin);
          scanf ("%d",&p[k]);
      }
      printf ("\n\nVETOR.\n");
      for (k=0;k<(n+i);k++)
      printf ("%d\t",p[k]);
      free(p);
      printf("\n\n");
      return 0;
  }
