/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 14:12:32 by nmolinel      #+#    #+#                 */
/*   Updated: 2021/12/16 14:12:34 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <ft_printf.h>

int	pf_char(t_data *data)
{
	int	tot;
	int	length;

	tot = 0;
	length = 1;
	put_pad(data, &length, &tot);
	tot += ft_putchar(va_arg(data->args, int));
	put_right_pad(data, &tot);
	return (tot);
}

int	pf_percent(t_data *data)
{
	if (data)
		return (ft_putchar('%'));
	return (0);
}
