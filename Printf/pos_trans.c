
#include "ft_printf.h"

int	pos_minus(t_flags flags, int len, char *str)
{
	int	rtn;

	rtn = 0;
	if (flags.minus)
	{
		rtn += ft_putstr_fd("0x", 1);
		rtn += ft_putstr_fd(str, 1);
		rtn += ft_adjust(flags.width - (len + 2), ' ');
	}
	else if (!flags.minus)
	{
		rtn += ft_adjust(flags.width - (len + 2), ' ');
		rtn += ft_putstr_fd("0x", 1);
		rtn += ft_putstr_fd(str, 1);
	}
	return (rtn);
}

int	pos_trans(t_flags flags, va_list args)
{
	char				*str;
	int					len;
	int					rtn;
	unsigned long long	nb;

	nb = va_arg(args, unsigned long long);
	if (!nb)
		str = ft_strdup("0");
	else
		str = ft_ulltoa_base(nb, "0123456789abcdef");
	len = ft_strlen(str);
	rtn = 0;
	rtn += pos_minus(flags, len, str);
	free(str);
	return (rtn);
}
