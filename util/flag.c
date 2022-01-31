/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 13:40:42 by nmolinel      #+#    #+#                 */
/*   Updated: 2021/12/16 16:42:45 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_bonus.h>

// put padding left
void	put_pad(t_data *data, int *length, int *tot)
{
	if (data->width && !data->left_pad)
	{
		*length += get_prec(data, data->precision, 1);
		while (*length < data->width)
		{
			*tot += ft_putchar(data->pad);
			*length += 1;
		}
	}
}

// if left pad is active and remains space print pad
void	put_right_pad(t_data *data, int *tot)
{
	if (data->left_pad)
	{
		while (*tot < data->width)
		{
			*tot += ft_putchar(data->pad);
		}
	}
}

// get precision silent mode only return number of precision added only
int	get_prec(t_data *data, int precision, int silent)
{
	int	count;
	int	tot;

	count = 0;
	tot = ft_strlen(data->conversion);
	if (data->pad == '0')
		tot++;
	while (tot < precision)
	{
		if (!silent)
			ft_putchar('0');
		count++;
		precision--;
	}
	return (count);
}

/* Debug flags */
// static void	print_p(t_data *params)
// {
// 	printf("\nhex: %d\n", params->hex);
// 	printf("left_pad: %d\n", params->left_pad);
// 	printf("pad: %c\n", params->pad);
// 	printf("plus_sign: %d\n", params->plus_sign);
// 	printf("width: %d\n", params->width);
// 	printf("precision: %d\n", params->precision);
// }
