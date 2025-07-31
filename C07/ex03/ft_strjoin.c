/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:43:26 by portega-          #+#    #+#             */
/*   Updated: 2025/07/31 17:03:14 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_len_sep	(char *sep)
{
	int count;

	count = 0;
	while (*(sep++))
		count++;
	return (count);
}

/* char	*ft_strcat(char *dest, char *src)
{
	char *ptr_begin;

	printf("%s \n", dest);
	printf("%s \n", src);
	ptr_begin = dest;
	while (*dest != '\0')
		dest++;
	printf("FIN DEST %s \n", dest);
	while (*src)
	{
		printf("WHILE DEST %s \n", dest);
		printf("WHILE SRC %s \n", src);
		*dest = *src;
		printf("WHILE DEST %s \n", dest);
		dest++;
		src++;
		printf("WHILE DEST %s \n", dest);
		//printf("%s", ptr_begin);
	}
	return (ptr_begin);
}
 */
char	*ft_strcat(char *dest, char *src)
{
	char	*ptr_dest;

	ptr_dest = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ptr_dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*return_val;

	if (size == 0)
	{
		return_val = malloc(sizeof(char) * 1);
		*return_val = '\0';
		return (return_val);
	}
	else
		return_val = malloc(sizeof(char) * (size + ft_len_sep(sep) + 1));

	return "c";

}



int main (void)
{
	char	*return_val;

	return_val = malloc(sizeof(char) * 50);
	return_val = "hola mundo";
	ft_strcat(return_val, "felix");
	//printf("Finalmente:%s \n", ft_strcat(return_val, "felix"));
	// printf("Longitud:%d \n", ft_len_sep("Hola mundo"));
	// printf("Longitud:%d \n", ft_len_sep("asdfñaskljasadh klahsdk ljhasdf"));
	return (0);
}
