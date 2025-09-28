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
    uint8_t b = 0b11001010;
    uint8_t k = 0b00101010;
    int n = 3;
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




    cout << "Original: ";
    printByte(b);
    cout << " (" << (int)b << ")" << endl;

    cout << "RotL(1):  ";
    printByte(r);
    cout << " (" << (int)r << ")" << endl;

    cout << "RotR(1):  ";
    printByte(s);
    cout << " (" << (int)s << ")" << endl;

    cout << "K(1):  ";
    printByte(k);
    cout << " (" << (int)k << ")" << endl;

    cout << "operacionXOR(1):  ";
    printByte(x);
    cout << " (" << (int)x << ")" << endl;

    cout << "operacionXOR OR XOR(1):  ";
    printByte(z);
    cout << " (" << (int)z << ")" << endl;

    cout << "operacion byteCifrado:  ";
    printByte(bC);
    cout << " (" << (int)bC << ")" << endl;

    cout << "operacion byteDecifrado:  ";
    printByte(bD);
    cout << " (" << (int)bD << ")" << endl;

    for (int i = 0; i < longitudS;i++){
        cout << mD[i];
    }

    delete[] mD;
    mD = nullptr;

    return 0;
}
