#ifndef BITS_H
#define BITS_H

// Codigos de las fichas (3 bits cada una)
const unsigned char FICHA_A   = 0; // 000
const unsigned char FICHA_B   = 1; // 001
const unsigned char FICHA_C   = 2; // 010
const unsigned char FICHA_D   = 3; // 011
const unsigned char FICHA_E   = 4; // 100
const unsigned char FICHA_F   = 5; // 101
const unsigned char VACIO     = 6; // 110
const unsigned char ESPECIAL  = 7; // 111

// Calcula cuantos bytes se necesitan para almacenar 3*filas*columnas bits
int calcularBytesNecesarios(int filas, int columnas);

// Lee los 3 bits de la ficha en (fila, col) y los devuelve como valor 0-7
unsigned char leerFicha(unsigned char* tablero, int filas, int columnas,
                        int fila, int col);

// Escribe los 3 bits de la ficha en (fila, col)
void escribirFicha(unsigned char* tablero, int filas, int columnas,
                   int fila, int col, unsigned char valor);

#endif