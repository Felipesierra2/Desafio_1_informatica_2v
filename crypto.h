#ifndef CRYPTO_H
#define CRYPTO_H

#include <cstdint>

//Desplazamos a la izquierda los byte
uint8_t rotIz(uint8_t b, int n);

//Desplazamos a la derecha los bytes
uint8_t rotDe(uint8_t b, int n);

//XOR simple con clave
uint8_t byteXOR(uint8_t b, uint8_t k);

//Funcion para cifrar los bytes
uint8_t cifrarBytes(uint8_t b,uint8_t n,uint8_t k);

//Funcion para decifrar los bytes
uint8_t decifrarBytes(uint8_t b,uint8_t n,uint8_t k);

//Funcion descompresion RLE
uint8_t *descomprimirRLE(const uint8_t *buffer,int longitudE,int &longitudS);

#endif // CRYPTO_H
