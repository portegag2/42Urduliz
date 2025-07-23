
#include "../../index_components.h"

void ft_combi_array (int a)
{
	char combi[5];
	if (a < 9)
	{
		combi[0] = '0';
	}
	else
		combi[0] = (a / 10) + '0';
	combi[1] = (a % 10) + '0';

	write (1, combi, 2);
}

void ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	while ( a<100 )
	{
		b = a+1;
		while (b<100)
		{
			ft_combi_array(a);
			write (1, " ", 1);
			ft_combi_array(b);
			if (a != 98 || b != 99)
				write (1, ", ", 2);
			b++;
		}
		a++;
	}
}
