int ft_recursive_power(int nb, int power)
{
	int return_val;
	printf("Entrando %d %d \n", nb, power);
	return_val = nb;
	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return 1;
	while (power-- > 1)
		return_val = nb * ft_recursive_power(nb, power);
	return (return_val);
}