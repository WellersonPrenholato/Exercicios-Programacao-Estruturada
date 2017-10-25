/*JOGO DA VELHA SIMPLES NA LINGUAGEM C - (Não contém tratamento de erros, futuramente pretendo implementá-los)
  Autor: Wellerson Prenholato
  Ano: 2013*/
  
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include <time.h>

int main(){
	//Declaracao de variaveis
	char nome1[10],nome2[10], jogador;
	char Matriz[3][3];
	char O='O', X='X';
	int pontuacao1=0,pontuacao2=0;

	printf(" JOGO DA VELHA \n");
	printf(" INSIRA O NOME DO JOGADOR 1: ");
	scanf("%s",&nome1);//Guarda o nome do jogador 1
	
	printf("\n DESEJA IR CONTRA O PROGRAMA? [S]IM OU [N]AO\n");
	scanf("%s",&jogador);

	if(jogador=='N' || jogador=='n'){// Se nao for contra o programa jogará com o jogador 2
		printf("\n INSIRA O NOME DO JOGADOR 2: ");
		scanf("%s",&nome2);//Guarda o nome do jogador 2
	}

do{
	int l=0,j,i;
	
		for(i=0;i<3;i++) //i eh a posição da linha
			for(j=0;j<3;j++) //j eh a posiçao da coluna
				Matriz[i][j]=' ';//Todas as celulas da tabela 3x3 ficam com o caracter espaço
	
	while(l<9){//O l varia de 0 a 8,
		system("clear||cls"); //Limpa tela
		printf(" JOGO DA VELHA \n");
		for(i=0;i<3;i++){
			printf("\t\t  %c %c %c %c %c\n",Matriz[i][0],186,Matriz[i][1],186,Matriz[i][2]);
			/*Duas barras verticais com dupla
			  linha,o %c refere-se ao numero
			  decimal 186 na tabela ASCII
			  ou ao caracter na matriz
			  tabela se encontra*/
		if(i<2){
			printf("\t\t %c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,206,205,205,205,206,205,205,205);
			/*duas barras horizontais
			  com dupla linha, o %c refere-se ao
			  numero decimal 206 ou 205 na tabela ASCII*/
			}
		}
		
		printf("\nPONTOS DE %s: %d",nome1,pontuacao1); //Pontos jogador 1
		if(jogador=='N' || jogador == 'n'){
			printf("\nPONTOS DE %s: %d",nome2,pontuacao2); //Pontos jogador 2
		}else{
			printf("\nPONTOS DO COMPUTADOR: %d",pontuacao2); //Pontos jogador 2
		}
			printf("\nPARTIDA : %d",1+(pontuacao1+pontuacao2)/10);
	
			printf("\n\n\n\n\n\n\n\nINSIRA AS COORDENADAS, ");
		if(l%2){
			printf("%s\nLINHA: ",nome2);
			/*O l diz a vez de quem joga, o resto da divisao de l por 2
			  sempre sera um numero 0 quando o dividendo for par e 1 quando o dividendo for impar
			  o numero 1 entra na condição if*/
			if(jogador=='N' || jogador == 'n'){//jogador 1 versus jogador 2
				scanf("%d",&i); //Guarda a posiçao da linha q eh de 1 a 3
				printf("COLUNA: ");
				scanf("%d",&j);//Guarda a posição da coluna q eh de 1 a 3
				
			}else{//Jogador 1 versus programa
				srand(time(NULL));//otimiza a funçao rand(), quando precisar criar mais de um processo no mesmo segundo, os números gerados pela função rand() são os mesmo quando comparados com os gerados pelos outros processos.
				i=rand() % 3+1;//gera numero aleatorio de 0 a 2 e soma 1
				j=rand() % 3+1;//gera numero aleatorio de 0 a 2 e soma 1
			}
			}else {
				printf("%s\nLINHA: ",nome1);
				scanf("%d",&i);
				printf("COLUNA: ");
				scanf("%d",&j);
			}
	
		if(Matriz[i-1][j-1]==' '&&i<=3&&j<=3&&i>=0&&j>=0){
			/*A matriz { {0,0},{0,1},{0,2} em c representa a matriz { {1,1},{1,2},{1,3}
			 			 {1,0},{1,1},{1,2}							  {2,1},{2,2},{2,3}
			 			 {2,0},{2,1},{2,2} } 						  {3,1},{3,2},{3,3} }
		   	 em sua forma original por isso o -1
			 so pode colocar X ou O se tiver o caracter espaço guardado na matriz
			 tanto a linha como a coluna pode ser de 0 a 3*/
	
		if(l%2)
			Matriz[i-1][j-1]=X; //l eh o marcador da vez aqui, ele eh responsavel por colocar O ou X
		else Matriz[i-1][j-1]=O;
			l++;//
		}
	
	//As formas de ganhar no jogo
	if((Matriz[0][0]==O && Matriz[0][1]==O && Matriz[0][2]==O)||
	//{ {O},{O},{O}
	// { },{ },{ }
	// { },{ },{ } }
	
	(Matriz[1][0]==O && Matriz[1][1]==O && Matriz[1][2]==O)||
	//{ { },{ },{ }
	// {O},{O},{O}
	// { },{ },{ } }
	
	(Matriz[2][0]==O && Matriz[2][1]==O && Matriz[2][2]==O)||
	//{ { },{ },{ }
	// { },{ },{ }
	// {O},{O},{O} }
	
	(Matriz[0][0]==O && Matriz[1][0]==O && Matriz[2][0]==O)||
	//{ {O},{ },{ }
	// {O},{ },{ }
	// {O},{ },{ } }
	
	(Matriz[0][1]==O && Matriz[1][1]==O && Matriz[2][1]==O)||
	//{ { },{O},{ }
	// { },{O},{ }
	// { },{O},{ } }
	
	(Matriz[0][2]==O && Matriz[1][2]==O && Matriz[2][2]==O)||
	//{ { },{ },{O}
	// { },{ },{O}
	// { },{ },{O} }
	
	(Matriz[0][0]==O && Matriz[1][1]==O && Matriz[2][2]==O)||
	//{ {O},{ },{ }
	// { },{O},{ }
	// { },{ },{O} }
	
	(Matriz[0][2]==O && Matriz[1][1]==O && Matriz[2][0]==O) 
	//{ { },{ },{O}
	// { },{O},{ }
	// {O},{ },{ } }
	){
		printf("\n\a\t\t%s, VOCE VENCEU!!!",nome1);
		pontuacao1+=10;
		break;
	}
		//Do mesmo jeito citado anteriormente eh feito para o X
		if((Matriz[0][0]==X && Matriz[0][1]==X && Matriz[0][2]==X)||
		(Matriz[1][0]==X && Matriz[1][1]==X && Matriz[1][2]==X)||
		(Matriz[2][0]==X && Matriz[2][1]==X && Matriz[2][2]==X)||
		(Matriz[0][0]==X && Matriz[1][0]==X && Matriz[2][0]==X)||
		(Matriz[0][1]==X && Matriz[1][1]==X && Matriz[2][1]==X)||
		(Matriz[0][2]==X && Matriz[1][2]==X && Matriz[2][2]==X)||
		(Matriz[0][0]==X && Matriz[1][1]==X && Matriz[2][2]==X)||
		(Matriz[0][2]==X && Matriz[1][1]==X && Matriz[2][0]==X))
	{
		printf("\n\n\n\n\a\t\t%s, VOCE VENCEU!!!",nome2);
		pontuacao2+=10;
		break;
	}
	
	if(l==9){
		printf("PARTIDA EMPATADA!");//Se passar 9 rodadas e ninguem ganhar sera empate
		break;
	}
	
	}
		printf("\n\t\aDESEJA JOGAR NOVAMENTE? [S]IM OU [N]AO\n");

}while(getchar()!='N' || getchar()!='n');//getchar guarda uma tecla, se ela for S ou s continuarar o programa
	return(0);
}
