#include "ft_printf.h"

int main()
{
	int a = 10;
	int i = ft_printf("%010d", 42);
	printf("\n");
	int j = printf("%010d", 42);
	printf("\n%d\n%d", i, j);
}