#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "forca.h"

void abertura() {
  printf("/****************/\n");
  printf("/ Jogo de Forca */\n");
  printf("/****************/\n\n");
}

void chuta(char chutes[26], int *tentativas) {
  char chute;
  printf("Qual letra? \n");
  scanf(" %c", &chute);

  chutes[(*tentativas)] = chute;
  (*tentativas)++;
}

int jaChutou(char letra, char chutes[26], int tentativas) {
  int achou = 0;

  for (int j = 0; j < tentativas; j++) {
    if (chutes[j] == letra) {
      achou = 1;
      break;
    }
  }
  return achou;
}

void desenhaForca(char palavraSecreta[20], char chutes[26], int tentativas) {
  for (int i = 0; i < strlen(palavraSecreta); i++) {
    int achou = jaChutou(palavraSecreta[i], chutes, tentativas);
    if (achou) {
      printf("%c ", palavraSecreta[i]);
    } else {
      printf("_ ");
    }
  }
  printf("\n");
}

void adicionaPalavra(){
	char resposta;
	printf("Voce deseja adicionar uma palavra ao jogo? (S/N)\n");
	fflush(stdin);
	scanf("%c",&resposta);
	fflush(stdin);
	if(resposta == 'S'){
		char novaPalavra[20];
		printf("Qual a nova palavra? (no maximo 20 letras)\n");
		scanf("%s", novaPalavra);

		FILE*  f;

		f = fopen("palavras.txt", "r+");
		if(f == 0){
			printf("ERRO! Banco de dados de palavras nao disponivel!\n");
			exit(1);
		}

		int quantidade;
		fscanf(f, "%d", &quantidade);
		quantidade++;

		fseek(f, 0, SEEK_SET);
		fprintf(f, "%d", quantidade);

		fseek(f, 0, SEEK_END);
		fprintf(f, "\n%s", novaPalavra);
	}
}

void escolhePalavra(char palavraSecreta[20]) {
	FILE* f;

	f = fopen("palavras.txt", "r");
	if(f == 0){
		printf("ERRO! Banco de dados de palavras nao disponivel!\n");
		exit(1);
	}
	int qtdPalavras;
	fscanf(f,"%d", &qtdPalavras);

	srand(time(0));
	int randomico = rand() % qtdPalavras;

	for(int i = 0; i <= randomico; i++){
		fscanf(f, "%s", palavraSecreta);
	}

	fclose(f);
}

int enforcou(int *tentativas, char palavraSecreta[20], char chutes[26]) {
  int erros = 0;
  for (int i = 0; i < (*tentativas); i++) {
    int existe = 0;

    for (int j = 0; j < strlen(palavraSecreta); j++) {
      if (chutes[i] == palavraSecreta[j]) {
        existe = 1;
        break;
      }
    }

    if (!existe) {
      erros++;
    }
  }
  return erros >= 5;
}

int acertou(char palavraSecreta[20], char chutes[26], int* tentativas) {
  for (int i = 0; i < strlen(palavraSecreta); i++)
    if (!jaChutou(palavraSecreta[i], chutes, (*tentativas)))
      return 0;
  return 1;
}

int main() {
  char palavraSecreta[20];
  char chutes[26];
  int tentativas = 0;

  escolhePalavra(palavraSecreta);
  abertura();

  do {

    desenhaForca(palavraSecreta, chutes, tentativas);
    chuta(chutes, &tentativas);

  } while (!acertou(palavraSecreta, chutes, &tentativas) && !enforcou(&tentativas, palavraSecreta, chutes));
	adicionaPalavra();
  return 0;
}