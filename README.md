# Jogo da Velha

Jogo da velha 2 jogadores no terminal, em C.

## Como compilar e jogar

```bash
gcc jogo_da_velha.c -o jogo_da_velha
./jogo_da_velha
```

## Como jogar

1. Escolha quem começa: digite `x` ou `o` e aperte Enter.
2. O tabuleiro é 3x3, com linhas `1-3` e colunas `1-3` indicadas na tela.
3. Na sua vez, digite a coordenada `linha coluna` e aperte Enter. Exemplo:
   - `1 1` = linha 1, coluna 1 (canto superior esquerdo)
   - `2 3` = linha 2, coluna 3
   - `3 2` = linha 3, coluna 2
4. Os turnos alternam automaticamente entre `x` e `o`.
5. Vence quem alinhar 3 símbolos iguais na horizontal, vertical ou diagonal.
6. Se as 9 casas forem preenchidas sem vencedor, dá `Empate!`.
7. Após cada partida, digite `S` para jogar novamente ou qualquer outra tecla para encerrar e ver o placar final:
   `Score: 'x': X | 'o': O | empates: N |`

Coordenada inválida (casa ocupada ou número fora de 1-3) mostra `Coordenada inválida, tente novamente!` e pede de novo.
