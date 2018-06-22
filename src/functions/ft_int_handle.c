/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:46:07 by daalexan          #+#    #+#             */
/*   Updated: 2018/05/23 19:46:08 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_func_handle.h"
#include "add_func.h"
#include <stdint.h>

static intmax_t	ft_custtype(va_list *arg, t_arg *blanck)
{
	intmax_t	nbr;

	nbr = va_arg(*arg, intmax_t);
	if (blanck->task == hh)
		nbr = (char)nbr;
	else if (blanck->task == h)
		nbr = (short)nbr;
	else if (blanck->task == l)
		nbr = (long int)nbr;
	else if (blanck->task == ll)
		nbr = (long long int)nbr;
	else if (blanck->task == j)
		nbr = (intmax_t)nbr;
	else if (blanck->task == z)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

ssize_t			ft_int_handle(char **format, va_list *arg, t_arg *blanck)
{
	char		*pref;
	intmax_t	val;

	(void)format;
	if (blanck->got_precision)
		blanck->zero = 0;
	val = ft_custtype(arg, blanck);
	if (val < 0 || blanck->plus || blanck->space)
	{
		if (val < 0)
		{
			val = -val;
			pref = "-";
		}
		else if (blanck->plus)
			pref = "+";
		else if (blanck->space)
			pref = " ";
		else
			pref = "";
		return (ft_nforcepref(val, "0123456789", blanck, pref));
	}
	else
		return (ft_uint_handle(val, blanck, "0123456789", NULL));
}
