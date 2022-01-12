#include "ft_printf.h"

int main()
{
	int a = 10;
	int i = ft_printf("%042.2d", 42000);
	printf("\n");
	int j = printf("%042.2d", 42000);
	printf("\n%d\n%d", i, j);
}