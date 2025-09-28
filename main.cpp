#include <iostream>
#include <cstdint>
#include "crypto.h"

using namespace std;

void printByte(uint8_t b){
    for (int i = 7; i >= 0; i--)
        cout << ((b >> i) & 1);
}

int main()
{
    int n = validarEntero();
    //Lo primero es pedirle al usuario la cantidad de archvios a ingresar

    //Generamos nombres para los archivos encripatos y pistas
    for (int i = 1; i <= n; i++){
        char arEncriptado[50];
        char arPista[50];

        // Construir los nombres: "EncriptadoX.txt" y "pistaX.txt"
        sprintf(arEncriptado, "Encriptado%d.txt",i);
        sprintf(arPista, "pista%d.txt", i);


        //Variables que guardan tamño del archivoEncriptado y de la pista
        int tamEncriptado,tamPista;

        //funciones que extraen el archvio y validan el tamñao
        char *encriptado = leerEncriptado(arEncriptado, &tamEncriptado);
        char *pista = leerPista(arPista, &tamPista);

        delete[] encriptado;
        delete[] pista;
    }

    uint8_t b = 0b11001010;
    uint8_t k = 0b00101010;
    uint8_t r = rotIz(b, n);
    uint8_t s = rotDe(r, n);
    uint8_t x = byteXOR(b, k);
    uint8_t z = x ^ k;
    uint8_t bC = cifrarBytes(b, n, k);
    uint8_t bD = decifrarBytes(bC,n,k);
    uint8_t buffer[] = {3, 'A', 3, 'B', 4, 'C', 2, 'D', 2, 'A'};
    int longitudE = sizeof(buffer) / sizeof(buffer[0]);
    int longitudS = 0;
    uint8_t *mD = descomprimirRLE(buffer,longitudE,longitudS);


    const char* comprimido = "0A0B1B2A3A4B"; // representa "ABAABABAABAB"
    char* texto = descomprimirLZ78(comprimido);
    std::cout << texto << std::endl;

    delete[] texto;
    delete[] mD;
    mD = nullptr;

    return 0;
}
