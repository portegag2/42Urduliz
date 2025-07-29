/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:52:10 by portega-          #+#    #+#             */
/*   Updated: 2025/07/28 19:26:36 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int		signo;
	int		final_val;

	final_val = 0;
	signo = 1;
	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signo = signo * -1;
		str++;
	}
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	while (*str && (*str >= '0' && *str <= '9'))
	{
		final_val = (final_val * 10) + (*str - '0');
		str++;
	}
	return (final_val * signo);
}
