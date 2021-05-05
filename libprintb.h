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
#define printb(type_t, value) ({ \
    type_t endereco = value;\
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
    uint8_t* p = (uint8_t*)n;
    uint8_t numero = *p;
    char str[nbytes * 8];
    for (uint8_t i = 0; i < (nbytes * 8); i++) {
        if (numero & 0x1) {
            str[(nbytes * 8) - 1 - i] = '1';
        } else {
            str[(nbytes * 8) - 1 - i] = '0';
        }
        numero = numero >> 1;
        if ((i % 8) == 7) {
            if (i == (nbytes * 8) - 1){
                continue;
            }
            p++;
            numero = *p;
        }
    }
    str[32] = '\0';
    printf("0b%s", str);
}