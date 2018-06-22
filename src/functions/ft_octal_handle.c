/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:44:16 by daalexan          #+#    #+#             */
/*   Updated: 2018/05/23 19:44:38 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "ft_func_handle.h"
#include "add_func.h"
#include <stdlib.h>
#include "libft.h"

ssize_t	ft_octal_handle(char **format, va_list *arg, t_arg *blanck)
{
	uintmax_t	nbr;

	(void)format;
	nbr = ft_unsg(arg, blanck);
	if (blanck->sharp && nbr == 0 &&
				blanck->got_precision && blanck->precision == 0)
	{
		if (blanck->got_width && !blanck->minus)
			ft_print_space(1, blanck->width, blanck->zero ? '0' : ' ');
		ft_putstr("0");
		if (blanck->got_width && blanck->minus)
			ft_print_space(1, blanck->width, ' ');
		return (blanck->got_width ? FT_MAX(blanck->width, 1) : 1);
	}
	else if (blanck->sharp && nbr != 0)
	{
		blanck->got_precision = 1;
		blanck->precision = FT_MAX(blanck->precision,\
			ft_nbrlen(nbr, "01234567") + 1);
	}
	return (ft_uint_handle(nbr, blanck, "01234567", NULL));
}
