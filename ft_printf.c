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

#include <ft_printf.h>

static int	clean(t_data *data, int	*tot)
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
	t_data			*data;
	int				tot;
	static int		(*refs[256])(t_data*);

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
	return (clean(data, &tot));
}
