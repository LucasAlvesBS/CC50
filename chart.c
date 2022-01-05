/****************************************************************************
 * chart.c
 *
 * Ciências da Computação 50
 * Lucas Alves Batista Santos
 *
 * Gráfico de barras do 'i saw you Harvard'
 ***************************************************************************/

#include <cs50.h>
#include <stdio.h>

int
main(void) 
{
    // Apresentação
    printf("Ola, usuario! Digite 4 numeros inteiros nao negativos para que um grafico de barras seja exibido.\n\n");
    
    // Recebendo valores inteiros não negativos do usuário 
    int mProcuraF = get_int("M procurando F: ");
        while (mProcuraF < 0) {
            mProcuraF = get_int("M procurando F: ");
        }
    int fProcuraM = get_int("F procurando M: ");
        while (fProcuraM < 0) {
            fProcuraM = get_int("F procurando M: ");
        }
    int fProcuraF = get_int("F procurando F: ");
        while (fProcuraF < 0) {
            fProcuraF = get_int("F procurando F: ");
        }
    int mProcuraM = get_int("M procurando M: ");
        while (mProcuraM < 0) {
            mProcuraM = get_int("M procurando M: ");
        }
    
    // Soma dos valores recebidos
    int soma = mProcuraF + fProcuraM + fProcuraF + mProcuraM;
    
    // Proporção de cada valor de acordo com a soma
    int proporcaoMprocuraF = (mProcuraF * 100) / soma;   
    int proporcaoFprocuraM = (fProcuraM * 100) / soma;
    int proporcaoFprocuraF = (fProcuraF * 100) / soma;
    int proporcaoMprocuraM = (mProcuraM * 100) / soma;
   
    // Quantidade de 'hashtags' para gerar o gráfico de barras
    int graficoMF = (proporcaoMprocuraF * 80) / 100;
    int graficoFM = (proporcaoFprocuraM * 80) / 100;
    int graficoFF = (proporcaoFprocuraF * 80) / 100;
    int graficoMM = (proporcaoMprocuraM * 80) / 100;
    
    printf("\nQuem procura quem?\n\n");

    // Barra do M procurando F
    printf("M procurando F\n");
    for (int i = 0; i < graficoMF; i++) {
       printf("#");
    }
    printf("\n");

    // Barra do F procurando M
    printf("F procurando M\n");
    for (int i = 0; i < graficoFM; i++) {
       printf("#");
    }
    printf("\n");

    // Barra do F procurando F
    printf("F procurando F\n");
    for (int i = 0; i < graficoFF; i++) {
       printf("#");
    }
    printf("\n");

    // Barra do M procurando M
    printf("M procurando M\n");
    for (int i = 0; i < graficoMM; i++) {
       printf("#");
    }
    printf("\n");
    return 0;
}