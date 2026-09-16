#ifndef TABLERO_H
#define TABLERO_H

// Estado global del tablero
extern unsigned char* tablero;   // bloque dinamico de bytes
extern int filas;
extern int columnas;
extern int capacidadBytes;       // bytes reservados actualmente
extern int bitsUsados;           // 3 * filas * columnas

void inicializarTablero(int f, int c);
void liberarTablero();
unsigned char generarFichaAleatoria();
void generarFichasIniciales();
void aplicarGravedad();
void generarNuevasFichas();

#endif