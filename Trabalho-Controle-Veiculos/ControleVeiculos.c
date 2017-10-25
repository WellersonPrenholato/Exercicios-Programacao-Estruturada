//Trabalho realizado utilizando o Sistema Operacional: Windows
//Ano: 2016
//DECLARACAO DAS BIBLIOTECAS UTILIZADAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//DEFINICAO DA STRUCT COMO SOLICITADA NO PROBLEMA
struct veiculos{
	char proprietario[71];
	char chassi[18];
	char modelo[21];
	char marca[16];
	char cor[21];
	char combustivel[11];
	int ano_fabricacao;
	char placa[7];
};

//INICIO DA FUNCAO MAIN
int main(){
	int numero_v;//Numero de carros que o usuario quer inserir 
	int contL,contN; //Contadores de elementos da placa contL-> Contador de Letras, contN -> Contador de Numeros
	int qtdCarros=0; //QUANTIDADE DE CARROS INSERIDOS NO SISTEMA
	int opcao; //Variavel utilizada para acessar o switch...case 
	int tamplaca;//Variavel que mostra o tamanho de caracteres da placa
	int tamchassi; //Variavel que mostra o tamanho de caracteres do chassi
    int j, p, y, l, t, a;//Variaveis usadas nos for's para variar o indice
    char buscachassi[18], buscaproprietario[71], buscacor[21]; //Variaveis usadas para busca
    int ano_inicio, ano_fim; 
    
    do{
		printf("Digite o Numero de Veiculos que deseja cadastrar maior que zero: ");
		scanf("%d",&numero_v);//Quantidade de carros a ser inserido
	}while(numero_v<=0);
	printf("\n");
	struct veiculos veic[numero_v]; //Vetor de Carros
	
	do {
		printf("1)Insira um novo veiculo no sistema\n");
		printf("2)Quantidade de veiculos cadastrados e todas as informacoes de todos os veiculos cadastrados\n");
		printf("3)Pra remover o veiculo do sistema, digite a chave de identificacao do chassi\n");
		printf("4)Informe a marca e 2 anos de fabricacao para receber todos os carros da marca informada\n");
		printf("5)Informe o nome de um proprietario para receber as informacoes de seu(s) veiculos\n");
		printf("6)Encerrar programa\n");
		printf("\nEntre com a opcao que desejada:\n");
        scanf("%d", &opcao);
		switch(opcao){
			case 1:
				if (qtdCarros<numero_v){
                    printf("Digite o nome do Proprietario do carro %d:\n", qtdCarros+1);
                    fflush(stdin);
                    gets(veic[qtdCarros].proprietario); //Insercao do nome do proprietario
                    fflush(stdin);
                    
                    do{//	VERIFICACAO DO TAMANHO DO CHASSI
						printf("Informe o Chassi do veiculo (Menor que 17 caracteres) %d:\n", qtdCarros+1);
	                    gets(veic[qtdCarros].chassi); //Insercao do chassi do veiculo
	                    fflush(stdin);
						tamchassi = strlen(veic[qtdCarros].chassi);
						if (tamchassi >17){//Verifica se o chassi tem tamanho 17
							printf("Chassi Invalido!\nInsira novamente.\n");//Mensagem caso o chassi seja invalido
						}    
                	}while (tamchassi >17);//O usuario fica inserindo chassi até que ele seja valido
                	
                    printf("Digite o Modelo do carro %d:\n", qtdCarros+1);
                    gets(veic[qtdCarros].modelo);  //Insercao do modelo do veiculo
                    fflush(stdin);
                    printf("Digite a Marca do carro %d:\n", qtdCarros+1);
                    gets(veic[qtdCarros].marca);  //Insercao da marca do veiculo
                    fflush(stdin);
                    printf("Digite a Cor do carro %d:\n", qtdCarros+1);
                    gets(veic[qtdCarros].cor);  //Insercao da cor do veiculo
                    fflush(stdin);
                    printf("Informe o tipo de Combustivel do carro %d:\n", qtdCarros+1);
                    gets(veic[qtdCarros].combustivel); //Insercao do combustivel do veiculo
                    fflush(stdin);

                    do{ //VERIFICACAO E INSERCAO DO ANO DE FABRICACAO
                        printf("Digite o ano de fabricacao do carro %d entre 1980 e 2017: \n", qtdCarros+1);
                        scanf("%d",&veic[qtdCarros].ano_fabricacao);//Insercao de ano de fabricacao
                        if(veic[qtdCarros].ano_fabricacao>=1980 && veic[qtdCarros].ano_fabricacao<=2017){//VERIFICA SE O ANO ESTA ENTRE OS INTERVALOS DE 1980 Á 2017
                            printf("Ano Valido!\n");//MENSAGEM DE CONFIRMACAO PARA ANO VÁLIDO
                        }else{
                        	printf("Ano Invalido!\nInsira novamente.\n");//Informa que o ano é invalido. Sucessivamente o usuario deve informar um novo valor ao ano
						}
                    }while(veic[qtdCarros].ano_fabricacao<1980 || veic[qtdCarros].ano_fabricacao>2017); //O ano deve ser maior que 1980 e menor que 2017, caso contrário é considerada invalido. Sucessivamente pede ao usuario para inserir um novo ano até que ele seja válido

				do{//VERIFICA A INSERCAO DO PLACA DO VEICULO
                    printf("Digite a placa do carro %d (Ex. ABC123):\n", qtdCarros+1);
                    fflush(stdin);
                    gets(veic[qtdCarros].placa); //Insercao da placa
                    fflush(stdin);
                    tamplaca =0;//Tamanho de caracteres da placa
                    contL =0; //Contador de Letras na placa
                    contN = 0; //Contador de Numeros na placa
                    tamplaca = strlen(veic[qtdCarros].placa); //tamplaca RECEBE A QUANTIDADE DE CARACTERES DA PLACA
                    for(j=0;j<3;j++){	//PERCORRE OS 3 PRIMEIROS ELEMENTOS DA PLACA
                        if(veic[qtdCarros].placa[j]>=65 && veic[qtdCarros].placa[j]<=90){ //VERIFICA SE OS 3 PRIMEIROS ELEMENTOS DA PLACA SÃO LETRAS
                            contL++; //CONTADOR PARA LETRAS DA PLACA
                        }
                    }
                    for(j=3; j<6 ;j++){//PERCORRE OS 3 ULTIMOS ELEMENTOS DA PLACA
                        if(veic[qtdCarros].placa[j]>=48 && veic[qtdCarros].placa[j]<=57){//VERIFICA SE OS 3 ULTIMOS ELEMENTOS DA PLACA SAO NÚMEROS 
                            contN++;//CONTADOR DE NUMEROS DA PLACA
                        }
                    }
                    if (contL == 3 && contN==3 && tamplaca==6){//Verifica se existe realmente 3 Letras nas 3 primeiras posicoes e 3 numeros nas tres posiçoes sequentes
                    	printf("Placa Valida!");//Informa que a placa é valida
                    	break; //Para o verificador de placa caso a placa seja valida
					}else{
						printf("Placa Invalida!\nInsira novamente.\n");//Informa que a placa é invalida. Em seguida é pedido uma nova placa
					}
                }while(1); //Caso os contadores sejam diferentes de 3, ele ficará pedindo uma nova placa até que ela seja válida
                qtdCarros++;
                printf("\nCARRO CADASTRADO COM SUCESSO!\n\n");//Mensagem mostrando que o cadastro do veículo foi realizado com sucesso
                printf("\n----------------------------------------------------------\n");
        	}
				break;
				
			case 2:
				printf("\nA Quantidade de Veiculos Cadastrados e %d\n\n", qtdCarros); //Informa a quantidade de carros cadastrados
				
				//Apresenta as informaçoes de todos os carros cadastrados
				for(p=0; p<qtdCarros; p++){//Percorrer o vetor "veic" informando todos os carros cadastrados
					printf("Proprietario do veiculo: %s\n", veic[p].proprietario);
					printf("Chassi do veiculo: %s\n", veic[p].chassi);
					printf("Modelo do veiculo: %s\n",veic[p].modelo);
					printf("Marca do veiculo: %s\n", veic[p].marca);
					printf("Cor do veiculo: %s\n",veic[p].cor);
					printf("Combustivel do veiculo: %s\n",veic[p].combustivel);
					printf("Placa do veiculo: %s\n",veic[p].placa);
					printf("Ano de Fabricacao do veiculo: %d\n",veic[p].ano_fabricacao);
					printf("\n----------------------------------------------------------\n");
				}
			break;
			
			case 3:
				printf("\nInforme o Chassi: ");
				fflush(stdin);
				gets(buscachassi);//Chassi que deseja ser buscado
				fflush(stdin);
				
				for(l=0; l<qtdCarros; l++){//Percorre todo vetor "veic"
					if (strcmp(veic[l].chassi, buscachassi)==0){//Comparador de Chassi
						strcpy(veic[l].proprietario,"NULL");//Copia o valor de NULL para veic[l].proprietario
						strcpy(veic[l].chassi,"NULL"); //Copia o valor NULL para veic[l].chassi
						strcpy(veic[l].modelo,"NULL"); //Copia o valor NULL para veic[l].modelo
						strcpy(veic[l].marca,"NULL"); //Copia o valor NULL para veic[l].marca
						strcpy(veic[l].cor,"NULL"); //Copia o valor NULL para veic[l].cor
						strcpy(veic[l].combustivel,"NULL"); //Copia o valor NULL para veic[l].combustivel
						veic[l].ano_fabricacao = 0; //Atribui o valor zero a veic[l].ano_fabricacao
						strcpy(veic[l].placa,"NULL"); //Copia o valor NULL para veic[l].placa
						//Dessa forma conseguimos remover as informaçoes de um determinado veículo
						
						printf("\nVEICULO REMOVIDO COM SUCESSO!\n\n"); //Mensagem informando que o veículo foi removido com sucesso
						qtdCarros--;//Logo, diminuimos a quantidade de carros
						printf("\n----------------------------------------------------------\n");
					}
				}
				break;
			case 4:
				printf("Informe a Cor desejada: \n");
				fflush(stdin);
				gets(buscacor);//Cor que que deseja ser buscada
				fflush(stdin);
				printf("Insira o intervalo de anos que deseja pesquisar no sistema:\n");
				printf("Insira o ano de inicio de fabricacao (Ex. 1980):\n");
				scanf("%d", &ano_inicio); //Primeiro ano inserido no intervalo
				fflush(stdin);
				printf("Entre com o ano de fim de fabricacao(Ex. 2017):\n");
				scanf("%d", &ano_fim); //Segundo ano inserido no intervalo
				fflush(stdin);

				for(t=0;t<qtdCarros; t++){//Percorre o vetor de carros cadastrados
					if(veic[t].ano_fabricacao>=ano_inicio && veic[t].ano_fabricacao <=ano_fim){//Verifica se os carros estao nos intervalos inseridos
					
						if(strcmp(veic[t].cor, buscacor)==0){//Verifica se existe algum veiculo com a cor que deseja ser buscada
							printf("O Nome do Proprietario e: %s \n", veic[t].proprietario);
							printf("O Chassi do veiculo e: %s  \n", veic[t].chassi);
							printf("O Modelo do veiculo e: %s \n", veic[t].modelo);
							printf("A Marca do veiculo e: %s \n", veic[t].marca);
							printf("O Combustivel do veiculo e: %s \n", veic[t].combustivel);
							printf("A Cor do veiculo e: %s \n", veic[t].cor);
							printf("A Placa do veiculo e: %s \n", veic[t].placa);
							printf("O Ano do veiculo e: %d \n", veic[t].ano_fabricacao);
							printf("\n----------------------------------------------------------\n");
						}
					}
				}
			break;
				
			case 5:
				printf("\nEntre com o nome do Proprietario: \n");
				fflush(stdin);
				gets(buscaproprietario); //Proprietario que deseja ser buscado
				fflush(stdin);
				for(a=0; a<qtdCarros; a++){//Percorre todo os vetores do carro registrados
					if(strcmp(veic[a].proprietario,buscaproprietario)==0){
							printf("\n O Nome do Proprietario e: %s \n", veic[a].proprietario);
							printf("O Chassi do veiculo e: %s \n", veic[a].chassi);
							printf("O Modelo do veiculo e: %s \n", veic[a].modelo);
							printf("A Marca do veiculo e: %s \n", veic[a].marca);
							printf("O Combustivel do veiculo e: %s \n", veic[a].combustivel);
							printf("A Cor do veiculo e: %s \n", veic[a].cor);
							printf("A Placa do veiculo e: %s \n", veic[a].placa);
							printf("O Ano do veiculo e: %d \n", veic[a].ano_fabricacao);
							printf("\n----------------------------------------------------------\n");
					}
				}
				break;
		}
}while(opcao!=6);
return 0;
}
//Obs.: O "fflush(stdin)" ultilizado para limpeza de buffer.
