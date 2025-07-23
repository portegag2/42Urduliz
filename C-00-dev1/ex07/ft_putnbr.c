#include <unistd.h>
#include "../../index_components.h"

void ft_putnbr(int nb)
{
	char z;
	if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb);
	}else if (nb < 9)
	{
		z = nb + '0';
		write(1, &z, 1);
	}else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int main_putnbr (void)
{
	ft_putnbr(0);
	write(1, "\n", 1);
	ft_putnbr(1);
	write(1, "\n", 1);
	ft_putnbr(-5);
	write(1, "\n", 1);
	ft_putnbr(-123);
	write(1, "\n", 1);
	ft_putnbr(12345);
	write(1, "\n", 1);

	return (0);
}
