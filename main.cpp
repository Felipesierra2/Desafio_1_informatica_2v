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
    uint8_t b = 0b11001010; // 129 en decimal
    uint8_t k = 0b00101010;
    int n = 3;

    uint8_t r = rotIz(b, n);
    uint8_t s = rotDe(r, n);
    uint8_t x = byteXOR(b, k);
    uint8_t z = x ^ k;
    uint8_t bC = cifrarBytes(b, n, k);
    uint8_t bD = decifrarBytes(bC,n,k);

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
    printByte(byteCifrado);
    cout << " (" << (int)byteCifrado << ")" << endl;

    cout << "operacion byteDecifrado:  ";
    printByte(byteDecifrado);
    cout << " (" << (int)byteDecifrado << ")" << endl;

    return 0;
}
