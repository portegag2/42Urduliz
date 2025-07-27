/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_components.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 09:48:54 by portega-          #+#    #+#             */
/*   Updated: 2025/07/27 09:07:03 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int main_03(int argc);

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
	char	*ft_strupcase(char *str);
	char	*ft_strlowcase(char *str);
	char	*ft_strcapitalize(char *str);
	unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
	void	ft_putstr_non_printable(char *str);

	// Funciones de C-03 (añade las que necesites)
	int	ft_strcmp(char *s1, char *s2);
	int	ft_strncmp(char *s1, char *s2, unsigned int n);
	char *ft_strcat(char *dest, char *src);
	char	*ft_strncat(char *dest, char *src, unsigned int nb);
	char	*ft_strstr(char *str, char *to_find);
	unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

#endif

