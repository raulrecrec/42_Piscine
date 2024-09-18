/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generador_matrices_latinas.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:30:01 by rexposit          #+#    #+#             */
/*   Updated: 2024/08/17 20:36:30 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>  // Para usar la función write
#include <stdlib.h>  // Para usar malloc y free
#include <stdio.h>

#define MAX_MATRICES 1000

// Declaración de funciones
void almacenar_matriz(int lista[], int *todas_matrices, int indice);
int es_valido(int lista[], int fila, int columna, int num);
int es_duplicada(int lista[], int *todas_matrices, int indice);

void generador_latinas(void) {
    int lista[4 * 4] = {0};  // Lista de 16 elementos (para la matriz 4x4)
    int *todas_matrices;     // Puntero para almacenar las matrices en memoria dinámica
    todas_matrices = (int *)malloc(MAX_MATRICES * 4 * 4 * 4);  // Asignar memoria

    if (todas_matrices == NULL) {  // Comprobar si la memoria se asignó correctamente
        write(1, "Error al asignar memoria\n", 25);
        return;
    }

    int fila = 0, columna = 0;
    int num = 1;
    int indice = 0;  // Para contar cuántas matrices latinas se almacenan

    // Bucle para generar todas las matrices latinas posibles
    while (fila >= 0 && indice < MAX_MATRICES) {
        if (fila == 4) {
            // Hemos completado una matriz latina, verificar si es duplicada
            if (!es_duplicada(lista, todas_matrices, indice)) {
                almacenar_matriz(lista, todas_matrices, indice);
                indice++;  // Incrementamos el índice para la próxima matriz
            }
            fila--;  // Retrocedemos para explorar más combinaciones
            columna = 3;  // Última columna de la fila anterior
            continue;
        }

        if (columna == 4) {  // Si completamos una fila, pasamos a la siguiente
            fila++;
            columna = 0;
            continue;
        }

        num = lista[fila * 4 + columna] + 1;  // Continuar con el siguiente número
        lista[fila * 4 + columna] = 0;  // Reiniciar el valor en esta posición

        while (num <= 4) {
            if (es_valido(lista, fila, columna, num)) {
                lista[fila * 4 + columna] = num;
                columna++;  // Avanzamos a la siguiente columna
                break;
            }
            num++;
        }

        if (num > 4) {  // Si no encontramos un número válido, retrocedemos
            columna--;
            if (columna < 0) {
                fila--;  // Retrocedemos a la fila anterior
                if (fila < 0) break;  // Si retrocedemos más allá de la primera fila, salimos
                columna = 3;  // Retrocedemos a la última columna de la fila anterior
            }
        }
    }

    // Imprimir todas las matrices almacenadas utilizando write
    int k = 0;
    int matrices_imprimidas = 0;  // Contador total de matrices imprimidas

    while (k < indice) {
        fila = 0;
        while (fila < 4 * 4) {
            char c = todas_matrices[k * 4 * 4 + fila] + '0';  // Convertir número a carácter
            write(1, &c, 1);  // Imprimir número como carácter
            if ((fila + 1) % 4 == 0) {
                write(1, "\n", 1);  // Saltar a la nueva línea
            } else {
                write(1, " ", 1);  // Separar números con un espacio
            }
            fila++;
        }
        write(1, "\n", 1);  // Separar las matrices con una nueva línea extra
        matrices_imprimidas++;
        k++;
    }

    // Imprimir el total de matrices imprimidas
    char buffer[50];
    int len = snprintf(buffer, 50, "Total de matrices imprimidas: %d\n", matrices_imprimidas);
    write(1, buffer, len);

    free(todas_matrices);  // Liberar la memoria dinámica
}

// Función para verificar si un número puede colocarse en la matriz
int es_valido(int lista[], int fila, int columna, int num) {
    int i;

    // Verificar fila
    i = 0;
    while (i < 4) {
        if (lista[fila * 4 + i] == num)
            return 0;
        i++;
    }

    // Verificar columna
    i = 0;
    while (i < 4) {
        if (lista[i * 4 + columna] == num)
            return 0;
        i++;
    }

    return 1;
}

// Función para copiar la matriz actual en la lista de matrices latinas
void almacenar_matriz(int lista[], int *todas_matrices, int indice) {
    int i = 0;
    while (i < 4 * 4) {
        todas_matrices[indice * 4 * 4 + i] = lista[i];
        i++;
    }
}

// Función para verificar si la matriz generada es duplicada
int es_duplicada(int lista[], int *todas_matrices, int indice) {
    int i, j;
    for (i = 0; i < indice; i++) {
        int es_igual = 1;  // Asumimos que son iguales
        for (j = 0; j < 4 * 4; j++) {
            if (lista[j] != todas_matrices[i * 4 * 4 + j]) {
                es_igual = 0;  // Encontramos una diferencia
                break;
            }
        }
        if (es_igual) {
            return 1;  // La matriz es duplicada
        }
    }
    return 0;  // La matriz no es duplicada
}

int main(void) {
    generador_latinas();
    return 0;
}

