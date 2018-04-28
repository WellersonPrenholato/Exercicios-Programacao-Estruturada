//FUNÇÃO QUE CALCULA O PRODUTO ENTRE DUAS MATRIZES ALOCADAS DINAMICAMENTE 
//Autor: Wellerson Prenholato

#include<stdio.h>
#include<stdlib.h>
//Funcao que realiza operacao de multiplicação entre matrizes
int **produto( int linha1, int p, int coluna2, int **v1 ,int **v2){
	int i, j, soma=0, k;
	int **v3;
	v3 = (int**)malloc(linha1*sizeof(int*));
	for(i=0; i<linha1;i++){
		v3[i]= (int*)malloc(coluna2*sizeof(int));
		for(j=0; j<coluna2; j++){
			soma =0;
			for(k=0; k< p; k++){
				soma = soma + v1[i][k] * v2[k][j];
				v3[i][j] = soma;
			}
		}
	}
	return v3;
}

int main (){
	//Declaracao de Variaveis
	int **resultado; 
	int **mat1, **mat2, l1, p, c2, **mat3;
	int i, j;
	
	//Chamada da matriz 1
	printf("*** PRODUTO ENTRE DUAS MATRIZES ***\n");
	printf("Insira as linhas da matriz 1: ");
	scanf("%d", &l1);
	printf("Insira as colunas da matriz 1: ");
	scanf("%d", &p);
	printf("*** MATRIZ 1 ***\n");
	
	mat1 = (int**)malloc(l1*sizeof(int*));
	for(i=0; i<l1;i++){
		mat1[i]= (int*)malloc(p*sizeof(int));
		printf("\n");
		for(j=0; j<p; j++){
			printf("Matriz %d %d: ", i,j);
			scanf("%d", &mat1[i][j]);
		}
	}
	printf("\n");
	
	//Chamada da matriz 2
	printf("Insira as linhas da matriz 2: %d\n", p);
	printf("Insira as colunas da matriz 2: ");
	scanf("%d", &c2);
	
	printf("*** MATRIZ 2 ***\n");
	mat2 = (int**)malloc(p*sizeof(int*));
	for(i=0; i<p;i++){
		mat2[i]= (int*)malloc(c2*sizeof(int));
		printf("\n");
		for(j=0; j<c2; j++){
			printf("Matriz %d %d: ", i,j);
			scanf("%d", &mat2[i][j]);
		}
	}
	printf("\n");
	//Reliza Operacao
	mat3 = produto(l1, p, c2, mat1, mat2);
	
	//Impressao Matriz resultado
	printf("MATRIZ RESULTADO:\n");
	printf("*** Matriz 3 ***\n");
	for(i=0; i<l1;i++){
		printf("\n");
		for(j=0; j<c2; j++){
			printf("%d ", mat3[i][j]);
		}
	}
	
	return 0;
}
