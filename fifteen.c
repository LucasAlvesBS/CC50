/*****************************************************************************
 * fifteen.c
 *
 * CC50
 * Lucas Alves Batista Santos
 *
 * Implementação do Jogo dos Quinze (generalizado para d x d)
 * 
 * Uso: fifteen d
 * 
 * Observe que 'usleep' é obsoleto, mas oferece mais granularidade do que
 * 'sleep' e é mais simples de usar do que 'nanosleep'.
 ****************************************************************************/
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Constantes
#define DIM_MIN 3
#define DIM_MAX 9

// Tabuleiro
int tabuleiro[DIM_MAX][DIM_MAX];

// Dimensões
int d;

int ladrilho_i;
int ladrilho_j;
int emBranco_i;
int emBranco_j;

// Protótipos
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int ladrilho);
bool won(void);

void search(int ladrilho);
bool legalmove(void);
void swaptile(int ladrilho);

int main(int argc, string argv[])
{
    // Conferir se está sendo usado apenas um argumento na linha de comando
    if (argc != 2)
    {
        printf("Uso: fifteen d\n");
        return 1;
    }

    // Converter o argumento em um inteiro
    d = atoi(argv[1]);
    
    // Sair caso seja digitado dimensões menores ou maiores do que as constantes
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("O tabuleiro deve estar entre %i x %i e %i x %i.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // Abrir registro
    FILE* arquivo = fopen("log.txt", "w");
    if (arquivo == NULL)
    {
        return 3;
    }

    // Cumprimentar o usuário com as instruções
    greet();

    // Inicializar o tabuleiro
    init();

    // Aceitar movimentos até que o jogo acabe
    while (true)
    {
        // Limpar a tela
        clear();

        // Desenhar o estado atual do tabuleiro
        draw();

        // Registrar o estado atual do tabuleiro (para teste)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(arquivo, "%d", tabuleiro[i][j]);
                if (j < d - 1)
                {
                    fprintf(arquivo, "|");
                }
            }
            fprintf(arquivo, "\n");
        }
        fflush(arquivo);

        // Checar vencedores
        if (won())
        {
            printf("Para a vitoria!\n");
            break;
        }

        // Pedir para mover
        int ladrilho = get_int("Ladrilho para mover: ");
        
        // Sair se o usuário digitar 0 (para teste)
        if (ladrilho == 0)
        {
            break;
        }

        // Registrar movimento (para teste)
        fprintf(arquivo, "%d\n", ladrilho);
        fflush(arquivo);

        // Mover se possível, senão reportar ilegalidade
        if (!move(ladrilho))
        {
            printf("\nMovimento ilegal.\n");
            usleep(500000);
        }

        // Tempo de animação
        usleep(500000);
    }
    
    // Fechar registro
    fclose(arquivo);

    // Vitória
    return 0;
}

/**
 * Limpar a tela usando sequências de escape ANSI
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Cumprimentar o jogador
 */
void greet(void)
{
    clear();
    printf("BEM VINDO AO JOGO DOS QUINZE\n");
    usleep(2000000);
}

/**
 * Inicializa o tabuleiro do jogo com os ladrilhos numerados de 1 a d * d - 1
 * (ou seja, preenche a matriz 2D com os valores, mas não os imprime de fato).  
 */
void init(void)
{
    // Conhecer o número de 'slots' necessários
    int n = (d*d) - 1;
    
    // Iterar através da matriz 2D
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            tabuleiro[i][j] = n;
            n--;
        }
        printf("\n");
    }
    
    // Checar se o número de ladrilhos é ímpar. Caso seja, trocar os ladrilhos 1 e 2
    if (((d*d) - 1) % 2 != 0)
    {
        int temporario = tabuleiro[d-1][d-2];
        tabuleiro[d-1][d-2] = tabuleiro[d-1][d-3];
        tabuleiro[d-1][d-3] = temporario;
    }
    
    // Marcar a posição do ladrilho em branco (canto inferior direito)
    emBranco_i = d-1;
    emBranco_j = d-1;
}

/**
 * Imprimir o tabuleiro em seu estado atual
 */
void draw(void)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (tabuleiro[i][j] < 10) 
            {
                // Se o valor for 0, imprimir um sublinhado
                if (tabuleiro[i][j] == 0) 
                {
                    printf(" [_] ");
                }
                else
                {
                printf(" [%d] ", tabuleiro[i][j]);
                }
            }
            else
            {
                printf("[%d] ", tabuleiro[i][j]);
            }
        }
        printf("\n"); 
    }
}

/**
 * Retornar 'true' se o ladrilho faz contado com o espaço vazio
 */
bool move(int ladrilho)
{
    // Checar se o ladrilho atual existe
    if (ladrilho > (d*d)-1 || ladrilho < 1)
        return false;
    
    search(ladrilho);
    
    // Verificar se o ladrilho está em branco
    if (legalmove())
    {
        // Trocar ladrilho por ladrilho em branco
        swaptile(ladrilho);
        return true;
    }
    else
        return false;
    
    return false;
}

/**
 * Retornar 'true' se o jogo for vencido 
 */
bool won(void)
{
    // Verificar se os valores da matriz estão em ordem crescente
    int contador = 1;
    
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (tabuleiro[i][j] == contador)
                contador++;
        } 
    }
    
    if (contador == d*d && tabuleiro[d-1][d-1] == 0)
        return true;
    else
        return false;
}

// Buscar a localização do ladrilho
void search(int ladrilho)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (tabuleiro[i][j] == ladrilho)
            {
                ladrilho_i = i;
                ladrilho_j = j;
            } 
        }
    }
}

// Checar se o ladrilho em branco está próximo ao ladrilho
bool legalmove(void)
{
    // Verificar se está na linha superior
    if (ladrilho_i > 0 && tabuleiro[ladrilho_i - 1][ladrilho_j] == 0)
        return true;
    // Verificar se está na linha inferior
    if (ladrilho_i < d-1 && tabuleiro[ladrilho_i + 1][ladrilho_j] == 0)
        return true;
    // Verificar se está na linha da esquerda
    if (ladrilho_j > 0 && tabuleiro[ladrilho_i][ladrilho_j - 1] == 0)
        return true;
    // Verificar se está na linha da direita
    if (ladrilho_j < d-1 && tabuleiro[ladrilho_i][ladrilho_j + 1] == 0)
        return true;
    else
        return false;
}

// Trocar ladrilhos por ladrilhos em branco
void swaptile(ladrilho)
{
    int temporario = ladrilho;
    tabuleiro[ladrilho_i][ladrilho_j] = tabuleiro[emBranco_i][emBranco_j];
    tabuleiro[emBranco_i][emBranco_j] = temporario;
    
    // Atualizar a localização do ladrilho em branco
    emBranco_i = ladrilho_i;
    emBranco_j = ladrilho_j;
}