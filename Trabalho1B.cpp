#include<stdio.h>
#include<conio2.h>
#include<windows.h>
#include<string.h>
#include<ctype.h>

#include "ListaDinTAD.h"

void limparLinha(int pos){
	for(int j=13; j< 70; j++){
		gotoxy(j, pos+1);
		printf(" ");
	}
}

void limparTela()
{
	int i,j;
	for(i = 2; i < 80; i++)
	{
		for(j=2; j< 18; j++)
		{
			gotoxy(i,j);
			printf("%c", ' ');
		}
	}
}

void moldura(void){
	int i,j,CF=80, CI=1, LI=1, LF=23;
	gotoxy(1,1);
	printf("%c", 201);
	gotoxy(80,1);
	printf("%c", 187);
	gotoxy(1,23);
	printf("%c", 200);
	gotoxy(80,23);
	printf("%c", 188);
	for(i=CI+1;i<CF;i++){
		gotoxy(i,1);
		printf("%c",205);
		gotoxy(i,23);
		printf("%c",205);
		Sleep(10);
	}
	for(i=LI+1;i<LF;i++){
		gotoxy(1,i);
		printf("%c",186);
		gotoxy(80,i);
		printf("%c",186);
		Sleep(10);
	}
	textcolor(1);
	gotoxy(2,27);
	printf("Pedro Augusto de Lima Cardozo RA:262318989");
	
	textcolor(6);
	gotoxy(23,2);
	printf("F2-ABRIR  F3-SALVAR  F4-SAIR  F5-EXIBIR ");
}

void molduraExibir(int &recEsq, int &recDir, int &priLinha){
	char resp;
	int opcao, novoValor;
	limparTela();
	textcolor(3);
	gotoxy(8,2);
	printf("# # # # # # # # # CONFIGURACAO DE PARAGRAFO # # # # # # # # # #");
	gotoxy(2,4);
	printf("(1)PRIMEIRA LINHA: %d", priLinha);
	gotoxy(2,5);
	printf("(2)RECUO ESQUERDO: %d", recEsq);
	gotoxy(2,6);
	printf("(3)RECUO DIREITO: %d", recDir);
	gotoxy(2,10);
	printf("deseja alterar a configuracao(S/N)");
	resp = getch();
	if(toupper(resp) == 'S'){
		gotoxy(2,11);
		printf("qual configuracao (1, 2 ou 3): ");
		scanf("%d",&opcao);
		if(opcao == 1){
			gotoxy(2,12);
			printf("qual sera a primeira linha: ");
			scanf("%d",&novoValor);
			if(novoValor > 21){
				gotoxy(2, 13);
				printf("valor digitado invalido");
			}
			else{
				priLinha = novoValor;
			}
		}
		else{
			if(opcao == 2){
				gotoxy(2,12);
				printf("qual sera o recuo esquerdo ");
				scanf("%d",&novoValor);
				if(novoValor > 30){
					gotoxy(2, 13);
					printf("valor digitado invalido");
				}
				else{
					recEsq = novoValor;
				}
			}
			else{
				gotoxy(2,12);
				printf("qual sera o recuo direito ");
				scanf("%d",&novoValor);
				if(novoValor < 40){
					gotoxy(2, 13);
					printf("valor digitado invalido");
				}
				else{
					recDir = novoValor;
				}
			}
		}
	}
}

void salvarArquivo(){}

int main(){
	char resp;
	int recEsq=2, recDir=78, priLinha=3, pos[2];  // a posicao 0 do vetor é o eixo X e a posicao 1 é o eixo Y
	listaPrin *L;
	listaPalavra *Letras;
	pos[0] = recEsq; pos[1] = priLinha;
	
	moldura();
	gotoxy(recEsq, priLinha);
	do{
		
		if(resp == 63)
		{ // chama funcao do f5
			molduraExibir(recEsq, recDir, priLinha);
			limparTela();
			gotoxy(18,2);
			printf("F2-ABRIR  F3-SALVAR  F4-SAIR  F5-EXIBIR ");
			gotoxy(pos[0], pos[1]);
		}
		
		if(resp == 61)
		{	//comando do f3
			salvarArquivo();
			limparTela();
			gotoxy(2,4);
			printf("ARQUIVO SALVO COM SUCESSO");
			gotoxy(18,2);
			printf("F2-ABRIR  F3-SALVAR  F4-SAIR  F5-EXIBIR ");
			gotoxy(pos[0], pos[1]);
		}
		
		if(resp == 8)
		{ //comando do backspace
			if(pos[0] > recEsq)
			{
				gotoxy(--pos[0],pos[1]);
				printf(" ");
				gotoxy(--pos[0],pos[1]);
			}
			else
			{
				if(pos[1] > priLinha)
				{
					pos[0]=recDir;
					gotoxy(pos[0], --pos[1]);
					printf(" ");
					gotoxy(--pos[0], pos[1]);
				}
			}
		}
		
		if(pos[0] < recDir)
		{ // controla os recuos direitos e esquerdo
			gotoxy(++pos[0],pos[1]);
		}
		else
		{
			gotoxy(recEsq,++pos[1]);
			pos[0]=recEsq;
		}
		
		resp = getche();
	}while(resp != 62); //f4
	
}
//f4 = 62, f5 = 63
//delete= 83
//Home = 71
//End = 79
//pageUp = 73
//pagedown = 81
//insert = 82
//f10 = 68
