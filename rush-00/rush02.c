/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 09:39:52 by marvin            #+#    #+#             */
/*   Updated: 2025/07/22 19:06:35 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

char ft_decidir_caracter(int i, int j, int x, int y, int modulo)
{
    // 0 esquina superior izquierda
    // 1 esquina superior derecha
    // 2 esquina inferior izquierda
    // 3 esquina inferior derecha
    // 4 relleno linea superior
    // 5 relleno linea inferior
    // 6 relleno columna izquierda
    // 7 relleno columna derecha
    // 8 relleno area interior

    char *modulos_caracteres[] = {
        "",   // caso 1
        "AACCBBBB ",
        "",
        ""   // caso 2
    };
    int posicion_matriz_coordenadas;
    //modulos_caracteres[2] = {'A', 'A', 'C', 'C', 'B', 'B', 'B', 'B', ' '}; //modulo 2
    //modulos_caracteres[2] = "AACCBBBB "; //modulo 2
    if (i == 1 && j == 1)
        posicion_matriz_coordenadas = 0;
    else if (i == 1 && j == x)
        posicion_matriz_coordenadas = 1;
    else if (i == y && j == 0)
        posicion_matriz_coordenadas = 2;
    else if (i == y && j == x)
        posicion_matriz_coordenadas = 3;
    else if (i == 1 && (j > 1 && j < x))
        posicion_matriz_coordenadas = 4;
    else if (i == y && (j > 1 && j < x))
        posicion_matriz_coordenadas = 5;
    else if ((i > 1 && i < y) && j == 1)
        posicion_matriz_coordenadas = 6;
    else if ((i > 1 && i < y) && j == x)
        posicion_matriz_coordenadas = 7;
    else
        posicion_matriz_coordenadas = 8;

    return modulos_caracteres[modulo][posicion_matriz_coordenadas];
}

void	rush(int x, int y)
{
    int	i;
    int	j;

    if (x <= 0 || y <= 0)
        write(1, "Invalid dimensions\n", 20);
    i = 1;
    while (i <= y)
    {
        j = 1;
        while (j <= x)
        {
            ft_putchar(ft_decidir_caracter(i, j, x, y, 2));
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}

int	main(void)
{
    rush(0, 0);
    rush(1, 1);
    rush(1, 5);
    rush(2, 2);
    rush(3, 2);
    rush(4, 2);
    rush(5, 3);
    return (0);
}
