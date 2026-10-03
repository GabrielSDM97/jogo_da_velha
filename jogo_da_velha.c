#include <stdio.h>

int rodada, empates = 0, X = 0, O = 0;

void limparBuffer() {
  char limpar;
  do { 
    limpar = getchar();
  } while (limpar != '\n');
}

void imprimirJogo(char matrizJogo[][3]) {
    printf("\n\t  1     2     3 <- Colunas\n");
    for (int linha = 0; linha < 3; linha++) {
      printf("Linha %d ", linha+1);
      for (int coluna = 0; coluna < 3; coluna++) {
        coluna % 2 == 0 ? printf("  %c  ", matrizJogo[linha][coluna]) : printf("|  %c  |", matrizJogo[linha][coluna]);
      }
      if (linha < 2)
        printf("\n\t-----------------");
      printf("\n");
    }
    printf("\n");
}

char análiseRound(char matrizJogo[][3], char jogador) {
  // Linha e Coluna
  for (int índice = 0; índice < 3; índice++) { 
    if (matrizJogo[índice][0] == jogador && matrizJogo[índice][1] == jogador && matrizJogo[índice][2] == jogador)
      return jogador;
    else if (matrizJogo[0][índice] == jogador && matrizJogo[1][índice] == jogador && matrizJogo[2][índice] == jogador)
      return jogador;
  }

  // Diagonal Principal e Secundária
  if (matrizJogo[0][0] == jogador && matrizJogo[1][1] == jogador && matrizJogo[2][2] == jogador)
    return jogador;
  else if (matrizJogo[0][2] == jogador && matrizJogo[1][1] == jogador && matrizJogo[2][0] == jogador)
    return jogador;

  // Última rodada sem vencedores (Empate)
  if (rodada == 9)
    return 'e';
  
  return ' ';
}

char resultadoRound(char matrizJogo[][3], char jogador) {
  char vencedor;

  imprimirJogo(matrizJogo);
  vencedor = análiseRound(matrizJogo, jogador);

  // Sistema de pontuação (vitória/empate)
  if (vencedor == 'x')
    X++;
  else if (vencedor == 'o')
    O++;
  else if (vencedor == 'e')
    empates++;

  // Limpa a matriz quando houver um vencedor ou empate.
  if (vencedor != ' ')
    for (int linha = 0; linha < 3; linha++)
      for (int coluna = 0; coluna < 3; coluna++)
        matrizJogo[linha][coluna] = ' ';

  return vencedor;
}

void coordenadaJogador(char matrizJogo[][3], char jogador) {
  int coordLinha = 0, coordColuna = 0, erro;
  
  do {
    erro = 0;
    printf("\nDigite a coordenada de '%c': ", jogador);
    scanf("%d%d", &coordLinha, &coordColuna);
    limparBuffer();
    if (matrizJogo[coordLinha-1][coordColuna-1] == 'x' || matrizJogo[coordLinha-1][coordColuna-1] == 'o' || (coordLinha < 1 || coordLinha > 3) || (coordColuna < 1 || coordColuna > 3)) {
      printf("Coordenada inválida, tente novamente!\n");
      erro = 1;
    }
    else {
      // Cai nessa condição quando dois valores válidos entre 1 e 3 referentes à linha e à coluna forem inseridos, exemplo: 1 2.
      matrizJogo[coordLinha - 1][coordColuna - 1] = jogador;
    }
  } while (erro == 1);
}

void sistemaRounds(char matrizJogo[][3], char jogador) {
  char vencedor = ' ';
  rodada = 0;

  while (vencedor == ' ') {
    rodada++;
    coordenadaJogador(matrizJogo, jogador);
    vencedor = resultadoRound(matrizJogo, jogador);
    if (jogador == 'x')
      jogador = 'o';
    else if (jogador == 'o')
      jogador = 'x';
  }

  if (vencedor == 'e')
    printf("Empate!\n\n");
  else if (vencedor != ' ')
    printf("Jogador '%c' venceu!\n\n", vencedor);
}

void inícioJogo() {
  char matrizJogo[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} }, jogador = ' ';

  while (jogador != 'x' && jogador != 'o') {
    printf("\nDeseja iniciar com 'x' ou 'o'? ");
    scanf("%c", &jogador);
    limparBuffer();
    if (jogador != 'x' && jogador != 'o') {
      printf("Opção inválida, tente novamente!\n");
    }
  }
  printf("\n");

  imprimirJogo(matrizJogo);
  sistemaRounds(matrizJogo, jogador);
}

int main() {
  char continuar;

  do {
    inícioJogo();

    printf("Deseja jogar novamente? [S]Sim: ");
    scanf("%c", &continuar);
    limparBuffer();
  } while (continuar == 'S' || continuar == 's');

  printf("\n---------------------------------------\n");
  printf("| Score: 'x': %d | 'o': %d | empates: %d |", X, O, empates);
  printf("\n---------------------------------------\n");

  return 0;
}
