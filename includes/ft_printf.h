/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 13:02:15 by nmolinel      #+#    #+#                 */
/*   Updated: 2021/12/16 14:27:57 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <stdarg.h>

# define DEC_BASE "0123456789"
# define X_LOW_BASE "0123456789abcdef"
# define X_UP_BASE "0123456789ABCDEF"

typedef struct s_data
{
	char	conversion[2000];
	va_list	args;
	int		hex;
	int		width;
	int		precision;
	int		pad;
	int		left_pad;
	int		plus_sign;
	int		format;
}	t_data;

int		ft_printf(const char *s, ...);
void	set_refs(int (*refs[256])(t_data*));
int		jump_to_ref(int (*refs[256])(t_data*), int c, t_data *data);
void	set_params(const char **str, t_data *params);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_isdigit(int c);
int		ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		pf_percent(t_data *data);
int		pf_char(t_data *data);
int		pf_string(t_data *data);
int		pf_integer(t_data *data);
int		pf_unsigned_x(t_data *data);
int		pf_pointer(t_data *data);

void	put_pad(t_data *data, int *length, int *tot);
void	put_right_pad(t_data *data, int *tot);
int		get_prec(t_data *data, int precision, int silent);
int		put_nb(long nb, char *base, int base_len, char *data);
int		put_unb(unsigned long nb, char *base, int base_len, char *data);

#endif