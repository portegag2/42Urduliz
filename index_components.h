#ifndef INDEX_COMPONENTS_H
#define INDEX_COMPONENTS_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Funciones main de cada lección
int main_00(int argc);
int main_01(int argc);
int main_02(int argc);

// Funciones auxiliares comunes
void ft_putchar(char c);
void ft_putstr(char *str);

// Funciones de C-00 (añade las que necesites)
void ft_print_alphabet(void);
void ft_print_reverse_alphabet(void);
void ft_print_numbers(void);
void ft_is_negative(int n);
void ft_print_comb(void);
void ft_print_comb2(void);
void ft_putnbr(int nb);

// Funciones de C-01 (añade las que necesites)
void ft_ft(int *nbr);
void ft_ultimate_ft(int *********nbr);
void ft_swap(int *a, int *b);
void ft_div_mod(int a, int b, int *div, int *mod);
void ft_ultimate_div_mod(int *a, int *b);
int ft_strlen(char *str);

// Funciones de C-02 (añade las que necesites)
char *ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int ft_str_is_alpha(char *str);
int	ft_str_is_numeric(char *str);
int	ft_str_is_lowercase(char *str);
int	ft_str_is_uppercase(char *str);
int ft_str_is_printable(char *str);

#endif

