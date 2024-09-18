#include <unistd.h>

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

int main() {
    int lista[4 * 4] = {0};  // Lista de 16 elementos (para la matriz 4x4)
    int fila = 0;
    int columna = 0;
    int num = 1;

    // Bucle para generar la matriz latina en la lista
    while (fila < 4) {
        while (columna < 4) {
            num = 1;

            // Intentar encontrar un número válido
            while (num <= 4) {
                if (es_valido(lista, fila, columna, num)) {
                    lista[fila * 4 + columna] = num;
                    columna++;
                    break;
                }
                num++;
            }

            if (num > 4) {  // Si no encontramos un número válido, retrocedemos
                columna--;
                if (columna < 0) {
                    columna = 4 - 1;
                    fila--;
                }
                num = lista[fila * 4 + columna] + 1;
                lista[fila * 4 + columna] = 0;
            }
        }

        fila++;
        columna = 0;
    }

    // Imprimir la lista utilizando write
    fila = 0;
    while (fila < 4 * 4) {
        char c = lista[fila] + '0';  // Convertir número a carácter
        write(1, &c, 1); // Imprimir número como carácter
        if ((fila + 1) % 4 == 0) {
            char newline = '\n';
            write(1, &newline, 1);  // Saltar a la nueva línea
        } else {
            char space = ' ';
            write(1, &space, 1);  // Separar números con un espacio
        }
        fila++;
    }

    return 0;
}

