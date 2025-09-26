#ifndef CRYPTO_H
#define CRYPTO_H

#include <cstdint>

//Rotación a la izquierda de un byte
uint8_t rotIz(uint8_t b, int n);

//Rotación a la derecha de un byte
uint8_t rotDe(uint8_t b, int n);

//XOR simple con clave
uint8_t byteXOR(uint8_t b, uint8_t k);

//Funcion para cifrar los bytes
uint8_t cifrarBytes(uint8_t b,uint8_t n,uint8_t k);

//Funcion para decifrar los bytes
uint8_t decifrarBytes(uint8_t b,uint8_t n,uint8_t k);

#endif // CRYPTO_H
