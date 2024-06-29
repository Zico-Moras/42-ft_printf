#include "../ft_printf.h"

static	int conversion(const char *s, va_list var)
{
	if (*(s + 1) == 'c')
		return (ft_putchar(va_arg(var, int)));
	else if (*(s + 1) == 's')
	{
		return (ft_putstr(va_arg(var, char *)));
	}
	//else if (*(s + 1) == 'p')
	//	return ;
	//else if (*(s + 1) == 'd')
	//	return ();
	//else if (*(s + 1) == 'i')
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	var;
	int	i;
	int	len;


	i = 0;
	len = 0;
	va_start(var, s);
	while (*s)
	{
		if (*s == '%')
			len += conversion(s++, var);
		else 
			write(1, s, 1);
		s++;
		len++;
	}
	return (len);
}
