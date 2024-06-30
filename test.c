#include "ft_printf.h"
#include <stdio.h>

int main()
{
	//printf("%i\n", test1);
	//printf("%i", ft_printf("123456\n"));
	//printf("%i", ft_printf("123 %c aa\n", 'c'));
	//printf("%i", printf("123 %c aa\n", 'c'));
	//printf("%i", ft_printf("123 %s aa\n", "123"));
	int	address = 42;
	int	*pointer = &address;
	printf("%p\n", (void *)pointer);
	printf("%p\n", pointer);
	printf("%zd\n", sizeof(long long));
	printf("%i\n", ft_hexlen(512));

}

