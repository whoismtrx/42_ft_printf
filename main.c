#include "ft_printf.h"

int main()
{
	int a = 10;
	int i = ft_printf("%01.d", 0);
	printf("\n");
	int j = printf("%01.d", 0);
	printf("\n%d\n%d", i, j);
}