/****************************************************************************
 * vigenere.c
 *
 * Ciências da Computação 50
 * Lucas Alves Batista Santos
 *
 * Criptografia de texto utilizando a Cifra de Vigenère
 ***************************************************************************/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int
main(int argc, string argv[])
{
    printf("Ola! Digite o texto a ser criptografado.\n\n");
    
    // Checkar se o usuário forneceu apenas um argumento de linha de comando
    if (argc != 2)
    {
        printf("Invalido! Digite o nome do programa e forneca um argumento.\n");
        return 1;
    }

    // Bloquear a entrada de caractere não-alfabético
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Erro! Digite apenas letras.\n");
            return 1;
        }
    }

    // Texto fornecido pelo usuário
    string text = get_string("p: ");
    printf("\nCriptografando...\n\n");
    printf("c: ");
    

    int j = 0;

    // Hora de criptografar
    for (int i = 0, n = strlen(text); i < n; i++)
    {
       // Reutilização cíclica da chave fornecida pelo usuário
       j = j % strlen(argv[1]);

       // Verificar se há letras 
       if (isalpha(text[i]))
       {
           // As diferentes combinações que podem ocorrer entre letras maiúsculas e minúsculas
           if (islower(text[i]) && islower(argv[1][j]))
           {
               printf("%c", (((text[i] - 97) + (argv[1][j] - 97)) % 26) + 97);
           }
           else if (isupper(text[i]) && islower(argv[1][j]))
           {
               printf("%c", (((text[i] - 65) + (argv[1][j] - 97)) % 26) + 65);
           }
           else if (islower(text[i]) && isupper(argv[1][j]))
           {
               printf("%c", (((text[i] - 97) + (argv[1][j] - 65)) % 26) + 97);
           }
           else if (isupper(text[i]) && isupper(argv[1][j]))
           {
               printf("%c", (((text[i] - 65) + (argv[1][j] - 65)) % 26) + 65);
           }
           j++;
       } 
       // Se não houver letras no texto, o caractere permanece imodificado 
       else
       {
           printf("%c", text[i]);
       }
    }
    printf("\n\nCriptografado!\n");
    return 0;
}