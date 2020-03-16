#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void abertura() {
  printf("/****************/\n");
  printf("/ Jogo de Forca */\n");
  printf("/****************/\n\n");
}

void chuta(char chutes[26], int tentativas) {
  char chute;
  printf("Qual letra? \n");
  scanf(" %c", &chute);

  chutes[tentativas] = chute;
}

int main() {

  char palavraSecreta[20];
  sprintf(palavraSecreta, "MELANCIA");

  int acertou = 0;
  int enforcou = 0;

  char chutes[26];
  int tentativas = 0;

  do {
    // imprime a palavra secreta
    for (int i = 0; i < strlen(palavraSecreta); i++) {
      int achou = 0;

      // verifica se a letra já foi chutada
      for (int j = 0; j < tentativas; j++) {
        if (chutes[j] == palavraSecreta[i]) {
          achou = 1;
          break;
        }
      }

      if (achou) {
        printf("%c ", palavraSecreta[i]);
      } else {
        printf("_ ");
      }
    }
    printf("\n");

    // captura o próximo chute
    chuta(chutes, tentativas);
    tentativas++;
  } while (!acertou && !enforcou);

  return 0;
}