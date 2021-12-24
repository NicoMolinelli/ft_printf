/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 14:12:53 by nmolinel      #+#    #+#                 */
/*   Updated: 2021/12/16 14:19:35 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_bonus.h>

// get real conversion output length
// if extra space remains print padding
static void	put_str_pad(t_data *data, char *str, int *tot)
{
	int	count;

	if (data->width && !data->left_pad)
	{
		count = 0;
		while (str[count] && count < data->precision)
		{
			count++;
		}
		while (count < data->width)
		{
			*tot += ft_putchar(data->pad);
			count++;
		}
	}
}

int	pf_string(t_data *data)
{
	char	*s;
	int		tot;

	tot = 0;
	if (data->precision == -1)
		data->precision = INT_MAX;
	s = va_arg(data->args, char *);
	if (!s)
	{
		ft_strlcpy(data->conversion, "(null)", 7);
		s = (data->conversion);
	}
	put_str_pad(data, s, &tot);
	while (*s && data->precision--)
	{
		tot += ft_putchar(*s++);
	}
	put_right_pad(data, &tot);
	return (tot);
}
