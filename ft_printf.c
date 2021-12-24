/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 13:01:52 by nmolinel      #+#    #+#                 */
/*   Updated: 2021/12/16 13:30:22 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_bonus.h>

/* Debug flags */
// static void	print_p(t_data *params)
// {
// 	printf("hex: %d\n", params->hex);
// 	printf("left_pad: %d\n", params->left_pad);
// 	printf("pad: %c\n", params->pad);
// 	printf("plus_sign: %d\n", params->plus_sign);
// 	printf("width: %d\n", params->width);
// 	printf("precision: %d\n", params->precision);
// }

static int	bye(t_data *data, int	*tot)
{
	if (data)
	{
		va_end(data->args);
		free(data);
	}
	return (*tot);
}

int	ft_printf(const char *s, ...)
{
	t_data	*data;
	int		tot;
	int		(*refs[254])(t_data*);

	tot = 0;
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	va_start(data->args, s);
	set_refs(refs);
	while (*s)
	{
		if (*s == '%')
		{
			set_params(&s, data);
			tot += jump_to_ref(refs, *s, data);
		}
		else
			tot += ft_putchar(*s);
		s++;
	}
	return (bye(data, &tot));
}
