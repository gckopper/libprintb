/**
 * @file libprintb.h
 * @author Gabriel Kopper (gabrielkopper@gmail.com)
 * @brief Cria uma função para 'printar' um número binário
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdint.h>

/**
 * @brief Converte variaveis para binário e as 'printa'
 * 
 * @code .c
 * #include "libprintb.h"
 * int main (void) {
 *  float a = 69.69;
 *  printb(float, a);
 *  printf("\n");
 * }
 * @endcode
 * 
 * 
 * @param type_t tipo do valor enviado no outro parametro
 * @param value valor para ser convertido para binário
 */
// Define uma função printb que leva os parâmetros type_t e valor
// valor é um valor para ser convertido para binário e type_t é o tipo do valor para que o programa saiba o tamanho desse valor em bytes
// Caso seja necessário usar uma quantidade especial de bytes é recomendado o uso da função nprintb
#define printb(type_t, valor) ({ \
    type_t endereco = valor; \
    nprintb(sizeof(type_t), &endereco);\
})

/**
 * @brief 
 * @code .c
 * #include "libprintb.h"
 * int main (void) {
 *  float a = 69.69;
 *  nprintb(32, &a);
 *  printf("\n");
 * }
 * @endcode
 * @param nbytes numero de bytes 
 * @param n ponteiro para o valor
 */
void nprintb (uint8_t nbytes, void* n) {
    uint8_t* p = (uint8_t*)n; // Copiando o ponteiro n para manipulá-lo
    uint8_t numero = *p; // Passando os primeiros 8 bits para a variavel numero
    char str[nbytes * 8]; // Criando um array com o número de bits necessário para a representação binária do número
    for (uint8_t i = 0; i < (nbytes * 8); i++) { // Loop por todos os bits do array
        if (numero & 0x1) { // Teste para ver se o bit menos significativo é 1
            str[(nbytes * 8) - 1 - i] = '1'; // Começando pelo último slot do array, adiciona um 1
        } else {
            str[(nbytes * 8) - 1 - i] = '0'; // Começando pelo último slot do array, adiciona um 0
        }
        numero = numero >> 1; // Transforma o segundo bit menos significativo no primeiro bit menos significativo
        if ((i % 8) == 7) { // A cada 8 bits o código entra nessa condicional
            if (i == (nbytes * 8) - 1){ // Verifica se é o último bit do array e caso positivo ele finaliza esse ciclo (que é o último) do loop
                continue;
            }
            p++; // Pula para o próximo conjunto de 8 bits do ponteiro
            numero = *p; // Coloca o valor do ponteiro na variavel numero
        }
    }
    str[32] = '\0'; // Fecha a string tornando seu último bit um bit nulo
    printf("0b%s", str); // Escreve na tela o valor em binário
}