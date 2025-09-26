#include "crypto.h"

uint8_t rotIz(uint8_t b, int n) {
    uint8_t izqIz = b << n; //Desplazamos los bits a la izquierda
    uint8_t izqDe = b >> (8 - n);//Rotamos los bits que se pierden en el paso anterior
    return izqIz | izqDe;//Cominamos ambas variables para reconstruir el numero rotado
}

uint8_t rotDe(uint8_t b, int n) {
    uint8_t derDe = b >> n;//Desplazamos los bits a la derecha
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

uint8_t *descomprimirRLE(const uint8_t* buffer,int longitudE,int &longitudS){
    int total = 0;

    //Ciclo para encontrar el tamaño original de la cadena desencriptada
    for (int i = 0; i < longitudE; i+=2){
        uint8_t cont = buffer[i];
        total+= cont;
    }

    //Arreglo que vamos a retornar con la palabra decodificada
    longitudS = total;
    uint8_t *bufferSalida = new uint8_t[longitudS];
    int pos = 0;

    //Ciclo principal, para tomar cantidad de letrar y la letra
    for (int i = 0; i < longitudE; i+=2){
        uint8_t cont = buffer[i];
        uint8_t symbol = buffer[i + 1];

        //Ciclo interno para imprimir y guardar la cantidad de letrar en el arreglo dinamico
        for (int j = 0; j < cont; j++){
            bufferSalida[pos++] = symbol;
        }
    }

    return bufferSalida;
}






















