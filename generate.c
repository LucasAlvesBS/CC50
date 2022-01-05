/***************************************************************************
 * generate.c
 *
 * CC50
 * Lucas Alves Batista Santos
 *
 * Gerar números pseudoaleatórios entre [0, LIMIT], um por linha.
 *
 * Uso: generate n [s]
 *
 * Em que 'n' é o número de números psudoaleatórios a serem impressos
 * e 's' é uma semente opcional
 ***************************************************************************/
       
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 65536

int
main(int argc, char *argv[])
{
    // Sair do programa caso o usuário digite diferente de 2 ou 3 argumentos na linha de comando
    if (argc != 2 && argc != 3)
    {
        printf("Uso: %s n [s]\n", argv[0]);
        return 1;
    }

    // Converter o argumento obrigatório em um inteiro
    int n = atoi(argv[1]);

    // Converter o argumento opcional em número inteiro pseudoaleatório
    if (argc == 3)
        // Ignorar os valores negativos 
        srand((unsigned int) atoi(argv[2]));
    else
        // Mudar semente com o tempo
        srand((unsigned int) time(NULL));

    // Em cada iteração, printar um número pseudoaleatório entre [0, 65535]
    for (int i = 0; i < n; i++)
        printf("%d\n", rand() % LIMIT);

    // Sucesso
    return 0;
}
