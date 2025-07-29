/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:09:50 by portega-          #+#    #+#             */
/*   Updated: 2025/07/28 22:16:12 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_local_base_digits(char *base)
{
	int	ptr_check;

	ptr_check = 0;
	while (*base)
	{
		ptr_check = 1;
		while (base[ptr_check] != '\0')
		{
			if (base[ptr_check] == *base)
				return (0);
			ptr_check++;
		}
		base++;
	}
	return (1);
}

int	ft_local_base_ok(char *base)
{
	int	base_ok;
	int	count;

	base_ok = 0;
	count = 0;
	while (base[count] != '\0')
	{
		if (base[count] == '+' || base[count] == '-')
			return (0);
		count++;
	}
	if (count < 2)
		return (0);
	if (ft_local_base_digits(base))
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count ++;
		str++;
	}
	return (count);
}

void	ft_putnbr(int nb, char *base)
{
	int	mod;
	int	base_val;

	mod = 0;
	base_val = ft_strlen(base);
	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			write(1, "2", 1);
			nb = 147483648;
		}
		else
			nb = nb * -1;
	}
	mod = nb % base_val;
	if (nb / base_val > 0)
	{
		ft_putnbr(nb / base_val, base);
	}
	mod = (nb % base_val);
	write (1, &base[mod], 1);
}

int	ft_atoi_base(char *str, char *base)
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
	final_val = final_val * signo;
	if (ft_local_base_ok(base))
	{
		ft_putnbr(final_val, base);
	}
}
