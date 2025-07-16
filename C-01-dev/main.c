

#include <stdio.h>
#include <stdlib.h>

// Declaraciones de las funciones
void	ft_ft(int *nbr);
void    ft_ultimate_ft(int *********nbr);
void    ft_swap(int *a, int *b);
void    ft_div_mod(int a, int b, int *div, int *mod);
void    ft_ultimate_div_mod(int *a, int *b);
void	ft_putstr(char *str);

void main00 (void)
{
	int	num;
	int	*nbr;

	num = 10;
	nbr = &num;
	printf("el puntero apunta: %d \n", *nbr);
	ft_ft(nbr);
	printf("Tras la llamada el puntero apunta: %d", *nbr);

}

void main01 (void)
{
	int	num;
	int	*ptr1;
	int **ptr2;
	int ***ptr3;
	int ****ptr4;
	int *****ptr5;
	int ******ptr6;
	int *******ptr7;
	int ********ptr8;
	int *********ptr9;
	
	num = 10;
	ptr1 = &num;
	ptr2 = &ptr1;
	ptr3 = &ptr2;
	ptr4 = &ptr3;
	ptr5 = &ptr4;
	ptr6 = &ptr5;
	ptr7 = &ptr6;
	ptr8 = &ptr7;
	ptr9 = &ptr8;
	printf("el puntero 9 finalmente contiene el valor: %d \n", *********ptr9);
	ft_ultimate_ft(ptr9);
	printf("el puntero 9 finalmente contiene el valor: %d", *********ptr9);
}

void main02 (void)
{
	int	num1;
	int num2;
	int	*a;
	int *b;

	num1 = 10;
	num2 = 34;
	a = &num1;
	b = &num2;
	printf("Antes llamada a y b: %d - %d \n", *a, *b);
	ft_swap(a, b);
	printf("Despues llamada a y b: %d - %d \n", *a, *b);
}

void main03 (void)
{
	int	num1;
	int num2;
	int quot;
	int rem;	
	int	*ptr_quot;
	int *ptr_rem;

    
	num1 = 75;
	num2 = 13;
	quot = 0;
	rem = 0;
	ptr_quot = &quot;
	ptr_rem = &rem;
	printf("Antes llamada quot y rem: %d - %d \n", *ptr_quot, *ptr_rem);
    printf("Dividir de %d entre %d: \n", num1, num2);
	ft_div_mod(num1, num2, ptr_quot, ptr_rem);
	printf("Despues llamada quot y rem: %d - %d \n", *ptr_quot, *ptr_rem);
}

void main04 (void)
{
	int	num1;
	int num2;	
	int	*ptr_quot;
	int *ptr_rem;

	num1 = 80;
	num2 = 6;
	ptr_quot = &num1;
	ptr_rem = &num2;
	printf("Antes llamada quot y rem: %d - %d \n", *ptr_quot, *ptr_rem);
	printf("Antes de la llamada a y b: %d - %d \n", num1, num2);
    ft_ultimate_div_mod(ptr_quot, ptr_rem);
	printf("Despues llamada quot y rem: %d - %d \n", *ptr_quot, *ptr_rem);
	printf("Finalmente a y b: %d - %d \n", num1, num2);
}

void main05 (void)
{
	char palabra[] = "Hola mundo";
	char *ptr_palabra;

	ptr_palabra = palabra;
	printf("Finalmente a y b: %d \n", *ptr_palabra);
	ft_putstr(ptr_palabra);
	
}

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
            main00();
            break;
        
        case 2:
            printf("=== Ejercicio 2 ===\n");
            main01();
            break;
        case 3:
            printf("=== Ejercicio 3 ===\n");
            main02();
            break;
        case 4:
            printf("=== Ejercicio 4 ===\n");
            main03();
            break;
        case 5:
            printf("=== Ejercicio 5 ===\n");
            main04();
            break;
		case 6:
            printf("=== Ejercicio 6 ===\n");
            main05();
            break;

        default:
            printf("Error: Ejercicio %d no existe\n", ejercicio);
            return (1);
    }
    
    return (0);
}

