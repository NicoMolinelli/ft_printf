/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unsigned.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 14:13:09 by nmolinel      #+#    #+#                 */
/*   Updated: 2021/12/16 14:32:31 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	save_nb(t_data *data, unsigned int num, int *length)
{
	if (data->format == 'u')
		*length += put_unb(num, DEC_BASE, 10, data->conversion);
	else if (data->format == 'X')
		*length += put_unb(num, X_UP_BASE, 16, data->conversion);
	else
		*length += put_unb(num, X_LOW_BASE, 16, data->conversion);
}

static void	put_prefix(t_data *data, int num, int *tot)
{
	if (data->hex && data->format != 'u' && num != 0)
	{
		if (data->format == 'x')
			*tot += ft_putstr("0x");
		else
			*tot += ft_putstr("0X");
	}
}

/*
	For u,x, X.

*/
int	pf_unsigned_x(t_data *data)
{
	unsigned int	num;
	int				tot;
	int				length;

	tot = 0;
	length = 0;
	num = va_arg(data->args, unsigned int);
	save_nb(data, num, &length);
	if (data->hex && data->format != 'u' && num != 0)
		length += 2;
	else if (!num && data->precision == 0)
		length = 0;
	put_pad(data, &length, &tot);
	put_prefix(data, num, &tot);
	if (data->precision != 0 || num != 0)
	{
		tot += get_prec(data, data->precision, 0);
		tot += ft_putstr(data->conversion);
	}
	put_right_pad(data, &tot);
	return (tot);
}

// for p
int	pf_pointer(t_data *data)
{
	unsigned long	num;
	int				tot;
	int				length;

	tot = 0;
	length = 0;
	num = (unsigned long) va_arg(data->args, void *);
	length += put_unb(num, X_LOW_BASE, 16, data->conversion) + 2;
	put_pad(data, &length, &tot);
	tot += ft_putstr("0x");
	tot += get_prec(data, data->precision, 0);
	tot += ft_putstr(data->conversion);
	put_right_pad(data, &tot);
	return (tot);
}
