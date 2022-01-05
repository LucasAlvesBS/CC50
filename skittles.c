/****************************************************************************
 * skittles.c
 *
 * Ciências da Computação 50
 * Lucas Alves Batista Santos
 *
 * Máquina de doce que escolhe aleatoriamente o número de skittles 
 ***************************************************************************/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main (void) 
{
    // seed do PRNG
    srand(time(NULL));

    // escolhe número pseudoaleatório entre [0, 1023]
    int skittles = rand() % 1024;
    
    // Apresentação da máquina de balas
    printf("Cof cof! Ola, dignissimo! Sou uma maquina de balas e te desafio a tentar descobrir quantos skittles tem dentro de mim. DICA: esta entre 0 e 1023. Vamos la?\n");
    
    int tentativa;

    // Comparação da tentativa e do número real de skittles
    while (tentativa != skittles) {
        // Número digitado pelo usuário 
        int tentativa = get_int("Digite um numero: ");
        // Número digitado fora da faixa estabelecida pela DICA
        if (tentativa < 0 || tentativa > 1023) {
            printf("Voce ta de brincation with me? Observe a DICA, jovem gafanhoto!\n");
        }
        // Tentativa é menor que os skittles com uma diferença maior que 20  
        else if (tentativa < skittles && (tentativa - skittles) < -20) {
            printf("HAHAHA! Que isso mermao!? Tenho muito mais skittles do que isso. Tente novamente!\n");    
        }
        // Tentativa é menor que os skittles com uma diferença maior ou igual que 20 
        else if (tentativa < skittles && (tentativa - skittles >= -20)) {
            printf("QUAAAAAASE! Aumente mais um pouco! Voce esta muito proximo.\n");
        }
        // Tentativa é maior que os skittles com uma diferença maior que 20 
        else if (tentativa > skittles && (tentativa - skittles) > 20) {
            printf("Calma la, nao tenho isso tudo. Tente novamente!\n");
        }
        // Tentativa é maior que os skittles com uma diferença maior ou igual que 20 
        else if (tentativa > skittles && (tentativa - skittles) <= 20) {
            printf("ESTA QUENTE! Que tal diminuir um pouco? Voce esta muito proximo.\n");
        }
        // Tentativa igual à quantidade de skittles
        else {
            printf("Woooow, voce ACERTOU! Nhom nhom nhom.\n");
            return 0;
        }
    }
}