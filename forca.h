//assinaturas das funções:
void abertura();
int jaChutou(char letra, char chutes[26], int tentativas);
void desenhaForca(char palavraSecreta[20], char chutes[26], int tentativas);
void escolhePalavra(char palavraSecreta[20]);
int enforcou(int *tentativas, char palavraSecreta[20], char chutes[26]);
int acertou(char palavraSecreta[20], char chutes[26], int* tentativas);
void adicionaPalavra();