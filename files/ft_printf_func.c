#include "../ft_printf.h"

int	ft_putchar(int	c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	len;
	len = ft_strlen(s);
	write (1, s, len);
	return (len);
}

int	ft_hexlen(unsigned long nbr)
{
	int	len;

	len = 0;
	while (nbr)
	{
		nbr /= 16;
		len++;
	}
	return (len);

}

void	ft_printpointer(unsigned long pointer);
{

}
//int	ft_putpointer(unsigned long pointer)
//{
//	int	len;
//	
//	if (!pointer)
//	{
//		write(1, "(nil)", 5);
//		return (5);
//	}
//
//
//}

