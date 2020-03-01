
#include "ft_printf.h"

int		parser_trans(char input, t_flags flags, va_list args)
{
	int rtn;
	int nb;

	rtn = 0;
	nb = 0;
	if (input == 'c')
		rtn = char_trans(flags, args);
	else if (input == 's')
		rtn = str_trans(flags, args);
	else if (input == 'p')
		rtn = pos_trans(flags, args);
	else if (input == 'd' || input == 'i')
		rtn = int_trans(flags, args);
	else if (input == 'u')
		rtn = unsign_trans(flags, args);
	else if (input == 'x')
		rtn = hex_trans(flags, args, "0123456789abcdef");
	else if (input == 'X')
		rtn = hex_trans(flags, args, "0123456789ABCDEF");
	else if (input == '%')
		rtn = percent_trans(flags);
	return (rtn);
}

int		ft_adjust(int width, char c)
{
	int i;

	i = 0;
	while (i < width)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	return (i);
}
