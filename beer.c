/****************************************************************************
 * beer.c
 *
 * Ciências da Computação 50
 * Lucas Alves Batista Santos
 *
 * Canção de bar 'Garrafas de Cerveja no muro'
 ***************************************************************************/

#include <cs50.h>
#include <stdio.h>

int
main(void)
{
    printf("Ola! Cantarei para voce essa versao da musica 'Garrafas de Cerveja no muro'.\n");

    // Contabilizando quantidade de cervejas no muro
    for (int i = 9; i >= 0; i--) 
    {
        // Palavra 'garrafa' no plural
        if (i <= 9 && i > 1) 
        {
            printf("%d garrafas de cerveja no muro, bebo uma, jogo no lixo, %d garrafas no muro...\n", i + 1, i);
        }
        // Caso em que há uma palavra no plural e outra no singular
        else if (i > 0 && i < 2) 
        {
            printf("%d garrafas de cerveja no muro, bebo uma, jogo no lixo, %d garrafa no muro...\n", i + 1, i);
        }
        // Por fim, apenas palavras no singular
        else 
        {
            printf("%d garrafa de cerveja no muro, bebo uma, jogo no lixo, nenhuma garrafa no muro...\n", i + 1);
        }
    }
    return 0;
}