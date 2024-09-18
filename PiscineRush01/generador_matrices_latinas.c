/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generador_matrices_latinas.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:30:01 by rexposit          #+#    #+#             */
/*   Updated: 2024/08/18 20:05:01 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>  // Para usar la función write
#include <stdlib.h>  // Para usar malloc y free
#include <stdio.h>

#define MAX_MATRICES 1000

void almacenar_matriz(int lista[], int *todas_matrices, int indice);
int es_valido(int lista[], int fila, int columna, int num);
int es_duplicada(int lista[], int *todas_matrices, int indice);

void	generador_latinas(void) {
	int	lista[4 * 4] = {0};
	int	*todas_matrices;
	todas_matrices = (int *)malloc(MAX_MATRICES * 4 * 4 * sizeof(int));

    if (todas_matrices == NULL) 
    {
        write(1, "Error al asignar memoria\n", 25);
        return;
    }

    int    fila = 0, columna = 0;
    int    num = 1;
    int    indice = 0;

    while (fila >= 0 && indice < MAX_MATRICES) 
    {
        if (fila == 4) 
	{
            if (!es_duplicada(lista, todas_matrices, indice)) 
	    {
                almacenar_matriz(lista, todas_matrices, indice);
                indice++;
            }
            fila--;
            columna = 3;
            continue;
        }
        if (columna == 4) 
	{
            fila++;
            columna = 0;
            continue;
        }
        num = lista[fila * 4 + columna] + 1;
        lista[fila * 4 + columna] = 0;
        while (num <= 4) 
	{
            if (es_valido(lista, fila, columna, num)) 
	    {
                lista[fila * 4 + columna] = num;
                columna++;
                break;
            }
            num++;
        }

        if (num > 4) 
	{
            columna--;
            if (columna < 0) 
	    {
                fila--;
                if (fila < 0) break;
                columna = 3;
            }
        }
    }
    int k = 0;
    int matrices_imprimidas = 0;

    while (k < indice) 
    {
        fila = 0;
        while (fila < 4 * 4) 
	{
            char c = todas_matrices[k * 4 * 4 + fila] + '0';
            write(1, &c, 1);
            if ((fila + 1) % 4 == 0) 
	    {
                write(1, "\n", 1);
            } else 
	    {
		write(1, " ", 1);
	    }
            fila++;
        }
        write(1, "\n", 1);
        matrices_imprimidas++;
        k++;
    }
    char buffer[50];
    int len = snprintf(buffer, 50, "Total de matrices imprimidas: %d\n", matrices_imprimidas);
    write(1, buffer, len);
    free(todas_matrices);
}

int es_valido(int lista[], int fila, int columna, int num) {
    int i;

    i = 0;
    while (i < 4) 
    {
        if (lista[fila * 4 + i] == num)
            return (0);
        i++;
    }
    i = 0;
    while (i < 4) 
    {
        if (lista[i * 4 + columna] == num)
            return (0);
        i++;
    }
    return (1);
}

void almacenar_matriz(int lista[], int *todas_matrices, int indice) {
    int i = 0;
    while (i < 4 * 4) 
    {
        todas_matrices[indice * 4 * 4 + i] = lista[i];
        i++;
    }
}

int es_duplicada(int lista[], int *todas_matrices, int indice) {
    int i, j;
    for (i = 0; i < indice; i++) 
    {
        int es_igual = 1;
        for (j = 0; j < 4 * 4; j++) 
	{
            if (lista[j] != todas_matrices[i * 4 * 4 + j]) 
	    {
                es_igual = 0;
                break;
            }
        }
        if (es_igual) 
	{
            return (1);
        }
    }
    return (0);
}

int main(void) {
    generador_latinas();
    return (0);
}

