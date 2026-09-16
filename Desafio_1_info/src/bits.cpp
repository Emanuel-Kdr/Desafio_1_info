#include "bits.h"

// Cada ficha ocupa 3 bits. Los bits validos empiezan en el bit menos
// significativo del primer byte. Si sobran bits, van a la izquierda del ultimo.
int calcularBytesNecesarios(int filas, int columnas) {
    int bitsTotales = 3 * filas * columnas;
    return (bitsTotales + 7) / 8; // redondeo hacia arriba
}

unsigned char leerFicha(unsigned char* tablero, int filas, int columnas,
                        int fila, int col) {
    // 1. Indice logico dentro del arreglo de fichas
    int indice = fila * columnas + col;

    // 2. Posicion del primer bit de esa ficha
    int bitInicial = indice * 3;
    int byteIndex  = bitInicial / 8;
    int offset     = bitInicial % 8;

    // 3. Extraer 3 bits a partir de 'offset' del byte actual
    unsigned int valor = (tablero[byteIndex] >> offset);

    // 4. Si los 3 bits cruzan al siguiente byte, traer los bits faltantes
    if (offset > 5) {
        valor |= ((unsigned int)tablero[byteIndex + 1]) << (8 - offset);
    }

    // 5. Enmascarar con 0x07 (0000 0111) para quedarnos con 3 bits
    return (unsigned char)(valor & 0x07);
}

void escribirFicha(unsigned char* tablero, int filas, int columnas,
                   int fila, int col, unsigned char valor) {
    int indice     = fila * columnas + col;
    int bitInicial = indice * 3;
    int byteIndex  = bitInicial / 8;
    int offset     = bitInicial % 8;

    unsigned char v = valor & 0x07;

    // 1. Limpiar los 3 bits en el byte actual
    tablero[byteIndex] &= (unsigned char)(~(0x07 << offset));

    // 2. Limpiar los bits que correspondan en el byte siguiente
    if (offset > 5) {
        tablero[byteIndex + 1] &= (unsigned char)(~(0x07 >> (8 - offset)));
    }

    // 3. Escribir los bits en el byte actual
    tablero[byteIndex] |= (unsigned char)((v << offset) & 0xFF);

    // 4. Escribir los bits que caen en el byte siguiente
    if (offset > 5) {
        tablero[byteIndex + 1] |= (unsigned char)(v >> (8 - offset));
    }
}