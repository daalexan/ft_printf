/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_handle.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:51:29 by daalexan          #+#    #+#             */
/*   Updated: 2018/05/23 19:51:31 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FUNC_HANDLE_H
# define FT_FUNC_HANDLE_H

# define FT_MAX(x, y)  ((x > y || x == y) ? x : y)
# include <stdarg.h>
# include "ft_printf.h"
# include <stdint.h>
# include <stdlib.h>
# include <sys/types.h>

typedef struct		s_aruments
{
	int				sharp : 1;
	int				zero : 1;
	int				minus : 1;
	int				plus : 1;
	int				space : 1;
	int				got_width : 1;
	int				got_precision : 1;
	unsigned int	width;
	unsigned int	precision;
	enum
	{
		none,
		hh,
		h,
		l,
		ll,
		j,
		z
	}				task;
}					t_arg;

typedef ssize_t		(*t_handler)(char**, va_list*, t_arg*);
ssize_t				ft_bin_handle(char **format, va_list *arg, t_arg *blanck);
ssize_t				ft_char_handle(char **format, va_list *arg, t_arg *blanck);
ssize_t				ft_chrwrite_handle(char **format, va_list *arg,\
	t_arg *blanck);
ssize_t				ft_escape_handle(char **format, va_list *arg,\
	t_arg *blanck);
ssize_t				ft_hex_handle(char **format, va_list *arg, t_arg *blanck);
t_handler			ft_init_handler(char c);
ssize_t				ft_int_handle(char **format, va_list *arg, t_arg *blanck);
ssize_t				ft_long_handle(char **format, va_list *arg, t_arg *blanck);
ssize_t				ft_null_handle(char **format, va_list *arg, t_arg *blanck);
ssize_t				ft_octal_handle(char **format, va_list *arg, t_arg *blanck);
ssize_t				ft_ptr_handle(char **format, va_list *arg, t_arg *blanck);
ssize_t				ft_str_handle(char **format, va_list *arg,\
	t_arg *blanck);
ssize_t				ft_uint_handle(uintmax_t nbr, t_arg *blanck,\
	char *base, char *pref);
ssize_t				ft_unsigned_handle(char **format, va_list *arg,\
	t_arg *blanck);
ssize_t				ft_wchar_handle(char **format, va_list *arg, t_arg *blanck);
ssize_t				ft_wstr_handle(char **format, va_list *arg, t_arg *blanck);

#endif
