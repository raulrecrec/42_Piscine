#include <unistd.h>  // Para usar la función write
#include <stdlib.h>  // Para usar malloc y free
#include <stdio.h>

#define MAX_MATRICES 1000

// Declaración de funciones
void almacenar_matriz(int lista[], int *todas_matrices, int indice);
int es_valido(int lista[], int fila, int columna, int num);
int es_duplicada(int lista[], int *todas_matrices, int indice);
void imprimir_matrices(int *todas_matrices, int total_matrices);
void avanzar_o_retroceder(int *fila, int *columna, int *num, int lista[]);

void generador_latinas(void) {
    int lista[4 * 4] = {0}; 
    int *todas_matrices = malloc(MAX_MATRICES * 4 * 4 * sizeof(int));

    if (todas_matrices == NULL) {
        write(1, "Error al asignar memoria\n", 25);
        return;
    }

    int fila = 0, columna = 0, num, indice = 0;

    while (fila >= 0 && indice < MAX_MATRICES) {
        if (fila == 4) {
            if (!es_duplicada(lista, todas_matrices, indice)) {
                almacenar_matriz(lista, todas_matrices, indice);
                indice++;
            }
            fila--; columna = 3;
        } else if (columna == 4) {
            fila++; columna = 0;
        } else {
            num = lista[fila * 4 + columna] + 1;
            lista[fila * 4 + columna] = 0;
            avanzar_o_retroceder(&fila, &columna, &num, lista);
        }
    }
    imprimir_matrices(todas_matrices, indice);
    free(todas_matrices);
}

void avanzar_o_retroceder(int *fila, int *columna, int *num, int lista[]) {
    while (*num <= 4) {
        if (es_valido(lista, *fila, *columna, *num)) {
            lista[*fila * 4 + *columna] = *num;
            (*columna)++;
            return;
        }
        (*num)++;
    }

    (*columna)--;
    if (*columna < 0) {
        (*fila)--; *columna = 3;
    }
}

int es_valido(int lista[], int fila, int columna, int num) {
    for (int i = 0; i < 4; i++) {
        if (lista[fila * 4 + i] == num || lista[i * 4 + columna] == num)
            return 0;
    }
    return 1;
}

void almacenar_matriz(int lista[], int *todas_matrices, int indice) {
    for (int i = 0; i < 4 * 4; i++) {
        todas_matrices[indice * 4 * 4 + i] = lista[i];
    }
}

int es_duplicada(int lista[], int *todas_matrices, int indice) {
    for (int i = 0; i < indice; i++) {
        int igual = 1;
        for (int j = 0; j < 16; j++) {
            if (lista[j] != todas_matrices[i * 16 + j]) {
                igual = 0;
                break;
            }
        }
        if (igual) return 1;
    }
    return 0;
}

void imprimir_matrices(int *todas_matrices, int total_matrices) {
    char c;
    for (int k = 0; k < total_matrices; k++) {
        for (int fila = 0; fila < 16; fila++) {
            c = todas_matrices[k * 16 + fila] + '0';
            write(1, &c, 1);
            write(1, (fila % 4 == 3) ? "\n" : " ", 1);
        }
        write(1, "\n", 1);
    }
    char buffer[50];
    int len = snprintf(buffer, 50, "Total de matrices: %d\n", total_matrices);
    write(1, buffer, len);
}

int main(void) {
    generador_latinas();
    return 0;
}


