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
