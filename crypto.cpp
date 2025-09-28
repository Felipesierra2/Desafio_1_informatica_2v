#include "crypto.h"
#include <cctype>
#include <cstring>


//Funcion auxiliar, para recontruir la cadane
void concatenar(char*& resultado, const char* nueva) {
    int len1 = strlen(resultado);
    int len2 = strlen(nueva);
    char* nuevo = new char[len1 + len2 + 1];
    strcpy(nuevo, resultado);
    strcpy(nuevo + len1, nueva);
    delete[] resultado;
    resultado = nuevo;
}

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

        //Ciclo interno guarda la cantidad de letras en el arreglo
        for (int j = 0; j < cont; j++){
            bufferSalida[pos++] = symbol;
        }
    }

    return bufferSalida;
}

// Función principal: descomprimir LZ78
char* descomprimirLZ78(const char* entrada) {
    int capacidad = 1000; // capacidad inicial del diccionario
    char** diccionario = new char*[capacidad];

    // entrada especial "" en índice 0
    diccionario[0] = new char[1];
    diccionario[0][0] = '\0';
    int sigt = 1; // manejar posición del dicciónario

    // resultado inicial vacío
    char* resultado = new char[1];
    resultado[0] = '\0';

    int i = 0;
    while (entrada[i] != '\0') {
        //leemos el indice
        int indice = 0;
        while (isdigit(entrada[i])) {
            indice = indice * 10 + (entrada[i] - '0');
            i++;//Aumentamos i para pasar al caracter
        }

        // leemos el carácter y aumetanmos i para dejarlo en la posición del indice
        char c = entrada[i];
        i++;

        //construir nueva cadena: dic[indice] + c

        //Revisamos en el diccionario si hay un caracter o si esta vació
        //para el indice seleccionado
        int len = strlen(diccionario[indice]);


        //Aseguramos 2 espacios: el digito y '\n' para fijar el final de la cadena
        char* nueva = new char[len + 2];
        strcpy(nueva, diccionario[indice]);
        nueva[len] = c;
        nueva[len + 1] = '\0';

        // guardamos en diccionario
        if (sigt >= capacidad) {
            // redimensionar
            int nuevaCap = capacidad * 2;
            char** nuevoDic = new char*[nuevaCap];
            for (int j = 0; j < capacidad; j++) {
                nuevoDic[j] = diccionario[j];
            }
            delete[] diccionario;
            diccionario = nuevoDic;
            capacidad = nuevaCap;
        }
        diccionario[sigt] = nueva;
        sigt++;

        // añadimos al resultado
        concatenar(resultado, nueva);
    }

    // limpiar memoria del diccionario (excepto resultado)
    for (int j = 0; j < sigt; j++) {
        delete[] diccionario[j];
    }
    delete[] diccionario;

    return resultado;
}





















