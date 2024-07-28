#include "../ft_printf.h"

int	ft_putchar(int	c)
{
	char a;

	a = c;
	write(1, &a, 1);
	return (1);
}

int	ft_putstr(char *string)
{
	int	len;
	if (!string)
		return (write(1, "(null)", 6));
	len = ft_strlen(string);
	while (*string)
		write(1, string++, 1);
	return (len);
}

int	ft_putnbr(int n)
{
	int	i;
	int	divisor;
	char	c;

	i = 0;
	divisor = 1;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		n = -n;
		i = write(1, "-", 1);
	}
	while (n / divisor >= 10)
		divisor *= 10;
	while (divisor)
	{
		c = '0' + n / divisor;
		i += write(1, &c, 1);
		n %= divisor;
		divisor /= 10;
	}
	return (i);
}
int	ft_putun(unsigned int n)
{
	int	i;
	int	divisor;
	char	c;

	i = 0;
	divisor = 1;

	while (n / divisor >= 10)
		divisor *= 10;
	while (divisor)
	{
		c = '0' + n / divisor;
		i += write(1, &c, 1);
		n %= divisor;
		divisor /= 10;
	}
	return (i);
}
