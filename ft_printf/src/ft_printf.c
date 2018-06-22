/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:43:13 by daalexan          #+#    #+#             */
/*   Updated: 2018/06/06 22:27:43 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_func_handle.h"
#include "ft_handle_parse.h"

static ssize_t	argum_handle(char **format, va_list *arg, t_arg *blanck)
{
	ssize_t		output;
	t_handler	handle;

	if ((*(++*format)) == '\0')
		return (0);
	if (ft_parse_flags(format, blanck) == NULL)
		return (-1);
	if (ft_parse_width(format, arg, blanck) == NULL)
		return (-1);
	if (ft_parse_precision(format, arg, blanck) == NULL)
		return (-1);
	if (ft_pasre_task(format, blanck) == NULL)
		return (-1);
	if (**format == '\0')
		return (0);
	if (ft_init_handler(**format) == NULL)
		handle = ft_null_handle;
	else
		handle = ft_init_handler(**format);
	output = handle(format, arg, blanck);
	(*format)++;
	return (output);
}

static int		ft_input_printf(const char *format, va_list *arg, size_t chr)
{
	t_arg		blanck;
	char		*next_argum;
	ssize_t		handler_len;

	next_argum = ft_strchr(format, '%');
	if (*format == '\0')
		return (chr);
	if (next_argum == NULL)
	{
		ft_putstr((char*)format);
		return (chr + ft_strlen((char*)format));
	}
	else if (next_argum > format)
	{
		ft_putnstr(format, (next_argum - format));
		return (ft_input_printf(next_argum, arg, chr + (next_argum - format)));
	}
	else
	{
		ft_bzero(&blanck, sizeof(blanck));
		if ((handler_len = argum_handle((char**)&format, arg, &blanck)) == -1)
			return (-1);
		else
			return (ft_input_printf(format, arg, chr + handler_len));
	}
}

int				ft_printf(const char *format, ...)
{
	va_list		arg;
	int			done;

	va_start(arg, format);
	done = ft_input_printf(format, &arg, 0);
	va_end(arg);
	return (done);
}
