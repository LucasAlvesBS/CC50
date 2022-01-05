/****************************************************************************
 * greedy.c
 *
 * Ciências da Computação 50
 * Lucas Alves Batista Santos
 *
 * Caixa que utiliza a menor quantidade de moedas possivel 
 ***************************************************************************/

#include <cs50.h>
#include <stdio.h>

int
main(void)
{
    // Declaração de variáveis
    int moedaConvertida1 = 25;
    int moedaConvertida2 = 10;
    int moedaConvertida3 = 5;
    int moedaConvertida4 = 1;
    int contadorMoedas = 0;
    int contadorMoeda25 = 0;
    int contadorMoeda10 = 0;
    int contadorMoeda5 = 0;
    int contadorMoeda1 = 0;

    // Apresentação do caixa "guloso" 
    printf("Ola! Sou um caixa que tenta entregar o troco aos clientes com a menor quantidade de moedas possivel. DICA: Palavras, valores com virgulas ou negativos nao sao permitidos.\n");
    
    // Solicitação do valor do troco
    float troco = get_float("Quanto e o troco que voce deve pagar?\nR$");

    // Situação em que o usuário digita um valor negativo
    while (troco < 0) {
        troco = get_float("Valor invalido! Tente de novo.\nR$");
    }
    
    // O troco é convertido para inteiro
    int trocoConvertido = troco * 100;

    // Retirando moedas de 25 centavos
    while (trocoConvertido >= moedaConvertida1) {
        trocoConvertido -= moedaConvertida1;
        contadorMoedas += 1;
        contadorMoeda25 += 1;
    }

    // Retirando moedas de 10 centavos
    while (trocoConvertido >= moedaConvertida2) {
        trocoConvertido -= moedaConvertida2;
        contadorMoedas += 1;
        contadorMoeda10 += 1;
    }

    // Retirando moedas de 5 centavos
    while (trocoConvertido >= moedaConvertida3) {
        trocoConvertido -= moedaConvertida3;
        contadorMoedas += 1;
        contadorMoeda5 += 1;
    }

    // Retirando moedas de 1 centavo
    while (trocoConvertido >= moedaConvertida4) {
        trocoConvertido -= moedaConvertida4;
        contadorMoedas += 1;
        contadorMoeda1 += 1;
    }

    // Total de moedas retiradas
    printf("Total de moedas: %d\n", contadorMoedas);
    // Moedas retiradas de acordo com o valor
    printf("De 25: %d\nDe 10: %d\nDe 5: %d\nDe 1: %d\n", contadorMoeda25, contadorMoeda10, contadorMoeda5, contadorMoeda1);
    return 0;
}