/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:44:52 by daalexan          #+#    #+#             */
/*   Updated: 2018/05/23 19:44:54 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_func_handle.h"
#include "add_func.h"

ssize_t		ft_char_handle(char **format, va_list *arg, t_arg *blanck)
{
	(void)format;
	if (blanck->task == 1)
		return (ft_wchar_handle(format, arg, blanck));
	else
	{
		if (blanck->got_width && !blanck->minus)
			ft_print_space(1, blanck->width, blanck->zero ? '0' : ' ');
		ft_putchar(va_arg(*arg, int));
		if (blanck->got_width && blanck->minus)
			ft_print_space(1, blanck->width, ' ');
		return (blanck->got_width ? FT_MAX(blanck->width, 1) : 1);
	}
}
