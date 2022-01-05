#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <math.h>

int	ft_putchar(char c)
{
	return(write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int i = 0;
	int printed = 0;

	while (str[i])
	{
		printed += ft_putchar(str[i]);
		i++;
	}
	return (printed);
}

int	ft_putnbrbase(long nbr, char *base, int base_len)
{
	int printed = 0;

	if (nbr < 0)
	{
		nbr = -nbr;
		printed += ft_putchar('-');
	}
	if (nbr < base_len)
	{
		printed += ft_putchar(base[nbr]);
	}
	else
	{
		printed += ft_putnbrbase((nbr / base_len), base, base_len);
		printed += ft_putnbrbase((nbr % base_len), base, base_len);
	}
	return (printed);
}

int	ft_printf(const char *str, ...)
{
	va_list ap;
	long d;
	char *s;
	unsigned long x;
	int i = 0;
	int printed = 0;

	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
			{
				s = va_arg(ap, char *);
				if (s == NULL)
				{
					printed += ft_putstr("(null)");
				}
				else
				{
					printed += ft_putstr(s);
				}
			}
			if (str[i] == 'd')
			{
				d = va_arg(ap, long);
				printed += ft_putnbrbase(d, "0123456789", 10);
			}
			if (str[i] == 'x')
			{
				x = (unsigned long)va_arg(ap, unsigned);
				printed += ft_putnbrbase(x, "0123456789abcdef", 16);
			}
		}
		else
		{
			printed += ft_putchar(str[i]);
		}
		i++;
	}
	return (printed);
}

int main()
{
	ft_printf("mine : %d\n\n", ft_printf("%s \n%d\n%x\n", "louis", -42, -42));
	printf("mine : %d\n\n", printf("%s \n%d\n%x\n", "louis", -42, -42));
	
	ft_printf("mine : %d\n\n", ft_printf("%s \n%d\n%x\n", "louis", 2147483647, 2147483647));
	printf("mine : %d\n\n", printf("%s \n%d\n%x\n", "louis", 2147483647, 2147483647));

	ft_printf("mine : %d\n\n", ft_printf("%s \n%d\n%x\n", "louis", 2147483648, 2147483648));
	printf("mine : %d\n\n", printf("%s \n%ld\n%lx\n", "louis", 2147483648, 2147483648));
}