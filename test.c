#include "ft_printf.h"
#include <stdio.h>

int main()
{
	ft_printf("123456\n");
	int	test1;
	test1 = ft_printf("12345 %c\n", '1');
	printf("%i\n", test1);
	//printf("%i", ft_printf("123456\n"));
	printf("%i", ft_printf("123 %c aa\n", 'c'));

	//printf("12345 %c", '\n');
	//printf("12345 %c", '\n');
}

