# Get Next Line

El proyecto `get_next_line` es una implementación de una función en C que lee una línea de un descriptor de archivo y la devuelve sin el carácter de nueva línea.

## Contenido

1. [Introducción](#introducción)
2. [Uso](#uso)
3. [Compilación](#compilación)
4. [Calificación](#calificacion)


## Introducción

El objetivo de `get_next_line` es leer líneas de un archivo, un descriptor de archivo o la entrada estándar (`stdin`) sin perder información entre las llamadas a la función.

## Uso

Para utilizar `get_next_line` en un proyecto, se debe incluir la función en los archivos fuente y compilarlos junto con la librería estándar de C. Se puede utilizar de la siguiente manera:

```c
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("archivo.txt", O_RDONLY);
    while (get_next_line(fd, &line) > 0)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return 0;
}
```
Hay que asegurarse de manejar adecuadamente la memoria y de incluir el archivo de encabezado (get_next_line.h) en los archivos fuente.

#compilación
Este proyecto lo he incluido luego en Libft y lo compilo con el Makefile de la misma modificado para incluir los archivos correspondientes.


#Estructura de carpetas
La estructura de carpetas del proyecto es la siguiente:
Están incluidos los archivos del bonus que consta en desarrollar get_next_line() con una sola variable estática.
El get_next_line es capaz de gestionar múltiples fd a la vez.

#calificcación

<img width="882" alt="Captura de pantalla 2024-01-22 a las 20 19 06" src="https://github.com/AgustinaHeredia/getnextline_42/assets/119814051/dd6846ad-15b8-43a6-876a-d7f350cde1ac">

Puedes seguir mi progreso en 42 en https://profile.intra.42.fr/users/agheredi
