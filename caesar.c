/****************************************************************************
 * caesar.c
 *
 * Ciências da Computação 50
 * Lucas Alves Batista Santos
 *
 * Criptografia de texto utilizando a Cifra de César
 ***************************************************************************/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char *argv[])
{
    printf("Ola! Digite o texto a ser criptografado.\n\n");
    
    // Checkar se o usuário forneceu apenas um argumento de linha de comando
    if (argc != 2) 
    {
        printf("Invalido! Digite o nome do programa e forneca um argumento.\n");
        return 1;
    }
    
    // Converter o número em uma string em um verdadeiro inteiro 
    int k = atoi(argv[1]);

    // Bloquear números inteiros negativos
    if (k < 0) 
    {
        printf("Erro! Digite apenas numeros inteiros positivos.\n");
        return 1; 
    }
    else 
    {
        // Texto fornecido pelo usuário
        string p = get_string("p: ");
        printf("\nCriptografando...\n\n");
        printf("c: "); 

        for (int i = 0, n = strlen(p); i < n; i++) 
        {
            // Verificar se as letras são maiúsculas ou minúsculas
            if (islower(p[i])) 
            {
                printf("%c", (((p[i] + k) - 97) % 26) + 97);
            }
            else if (isupper(p[i]))
            {
                printf("%c", (((p[i] + k) - 65) % 26) + 65);
            }
            // Se não houver letras no texto, o caractere permanece imodificado 
            else 
            {
                printf("%c", p[i]);
            }
        }
        printf("\n\nCriptografado!\n");
        return 0;
    }
}
