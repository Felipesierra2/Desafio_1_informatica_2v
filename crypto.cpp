#include "crypto.h"

uint8_t rotIz(uint8_t b, int n) {
    uint8_t izqIz = b << n; //Rotamos los bits a la izquierda
    uint8_t izqDe = b >> (8 - n);//Rotamos los bits que se pierden en el paso anterior
    return izqIz | izqDe;//Cominamos ambas variables para reconstruir el numero rotado
}

uint8_t rotDe(uint8_t b, int n) {
    uint8_t derDe = b >> n;//Rotamos los bits a la derecha
    uint8_t derIz = b << (8 - n); // Nuevamente recuperamos los bits que se pierden en el desplazamient
    return derDe | derIz; //Cominamos ambas variables para reconstruir el numero rotado
}

uint8_t byteXOR(uint8_t b, uint8_t k) {
    return b ^ k;
}

uint8_t cifrarBytes(uint8_t b,uint8_t n,uint8_t k){
    uint8_t izq = rotIz(b,n); //Llamamos la función que nos rota los bits a la izquierda
    return byteXOR(izq,k); //Aplicamos
}

uint8_t decifrarBytes(uint8_t b,uint8_t n,uint8_t k){
    uint8_t bXOR = byteXOR(b,k);//Aplicamos nuevamente XOR(revertimos lo aplicado en el paso final del cifrado)
    uint8_t der = rotDe(bXOR,n);//Revertimos rotIz(devolviendo lo bits a la derecha)
    return der; //Aplicamos
}
