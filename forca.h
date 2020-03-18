//assinaturas das funções:
#define TAMANHO_PALAVRA 20

void abertura();
int jaChutou(char letra, char chutes[26], int tentativas);
void desenhaForca(char palavraSecreta[TAMANHO_PALAVRA], char chutes[26], int tentativas);
void escolhePalavra(char palavraSecreta[TAMANHO_PALAVRA]);
int enforcou(int *tentativas, char palavraSecreta[TAMANHO_PALAVRA], char chutes[26]);
int ganhou(char palavraSecreta[TAMANHO_PALAVRA], char chutes[26], int* tentativas);
void adicionaPalavra();
int chutesErrados(int *tentativas, char palavraSecreta[20], char chutes[26]);