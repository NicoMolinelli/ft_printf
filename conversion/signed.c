/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signed.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 14:12:40 by nmolinel      #+#    #+#                 */
/*   Updated: 2021/12/16 14:18:43 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	put_sign(t_data *data, int num, int *tot)
{
	if ((num >= 0 && data->plus_sign))
		*tot += ft_putchar(data->plus_sign);
	else if (num < 0)
		*tot += ft_putchar('-');
}

int	pf_integer(t_data *data)
{
	int	num;
	int	tot;
	int	length;

	tot = 0;
	length = 0;
	num = va_arg(data->args, int);
	length += put_nb(num, DEC_BASE, 10, data->conversion);
	if ((num >= 0 && data->plus_sign) || num < 0)
		length++;
	else if (!num && data->precision == 0)
		length = 0;
	put_pad(data, &length, &tot);
	put_sign(data, num, &tot);
	if (data->precision != 0 || num != 0)
	{
		tot += get_prec(data, data->precision, 0);
		tot += ft_putstr(data->conversion);
	}
	put_right_pad(data, &tot);
	return (tot);
}
