/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:29:05 by portega-          #+#    #+#             */
/*   Updated: 2025/07/30 18:14:45 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_print_params(int argc, char **argv)
{
	if (argc > 1)
	{
		while (argc-- > 1 && **(++argv))
		{
			while (**argv)
				write(1, (*(argv))++, 1);
			write (1, "\n", 1);
		}
	}
}

int	main(int argc, char **argv)
{
	int		count_argc;
	int		count_comp;
	char	*temp;

	count_argc = 0;
	while (count_argc++ < argc)
	{
		count_comp = count_argc;
		while (++count_comp < argc)
		{
			if (ft_strcmp(*(argv + count_argc), *(argv + count_comp)) > 0)
			{
				temp = *(argv + count_argc);
				*(argv + count_argc) = *(argv + count_comp);
				*(argv + count_comp) = temp;
				count_argc--;
				break ;
			}
		}
	}
	ft_print_params(argc, argv);
}
