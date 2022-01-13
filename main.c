#include "ft_printf.h"

int main()
{
	int a = 10;
	int i = ft_printf("%020.10d", -42000);
	printf("\n");
	int j = printf("%020.10d", -42000);
	printf("\n%d\n%d", i, j);
}