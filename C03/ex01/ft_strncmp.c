/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 12:21:44 by portega-          #+#    #+#             */
/*   Updated: 2025/07/31 16:24:56 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../index_components.h"

/* int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (n == 0)
	{
		return (0);
	}
	while (*s1 == *s2 && *s1 && *s2 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*s1 - *s2);
} */

/* int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int    i;

	i = 0;
    if (n < 1)
    {
        return (i);
    }
    while (i - 1 < n && s1[i] == s2[i] && s1[i])
    {
        //printf("i:%d s1:%c s2:%c \n", i, s1[i], s2[i]);
		i++;
    }
    return (s1[i] - s2[i]);
} */

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int    i;

	//int result_final;

	//result_final = 0;
	i = 0;
    if (n < 1)
    {
        return (i);
    }
	printf("ANTES: i-1:%d n:%d \n", i-1, n);
    //while ((i==0 || i -1 < n) && s1[i] == s2[i] && s1[i])
	while ( i < n && s1[i] == s2[i] && s1[i])
    {
		printf("ENNN   i-1:%d n:%d iiiiii:%d\n", i-1, n, i);
		i++;
    }




	printf("DESPUES: i-1:%d n:%d iiii:%d\n", i-1, n, i);
	//result_final = s1[i] - s2[i];
	if (i == n)
		i--;
    return (s1[i] - s2[i]);
}

int main (void)
{
	char *s1 = "Holaaaaaa";
	char *s2 = "Holabbbbb";
	int result;
	int n = 4;

	result = ft_strncmp(s1, s2, n);
	printf("Devuelvo:%d \n", result);
	result = strncmp(s1, s2, n);
	printf("strncmp devuelvo:%d \n", result);

}

