

#include <stdio.h>
#include <stdlib.h>

// Declaraciones de las funciones
void ft_uno(void);
void ft_dos(void);
void ft_tres(void);

int main(int argc, char *argv[])
{
    int ejercicio;
    
    // Si no se pasa argumento, usar valor por defecto
    if (argc == 1)
    {
        ejercicio = 1;  // Valor por defecto
        printf("Sin argumentos, ejecutando ejercicio %d por defecto\n", ejercicio);
    }
    else if (argc == 2)
    {
        ejercicio = atoi(argv[1]);
    }
    else
    {
        printf("Uso: %s [número_ejercicio]\n", argv[0]);
        printf("Ejercicios disponibles: 1, 2, 3\n");
        return (1);
    }
    
    // Resto del código igual...
    switch (ejercicio)
    {
        case 1:
            printf("=== Ejercicio 1 ===\n");
            ft_uno();
            break;
        case 2:
            printf("=== Ejercicio 2 ===\n");
            ft_dos();
            break;
        case 3:
            printf("=== Ejercicio 3 ===\n");
            ft_tres();
            break;
        default:
            printf("Error: Ejercicio %d no existe\n", ejercicio);
            return (1);
    }
    
    return (0);
}