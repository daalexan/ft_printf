/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:45:22 by daalexan          #+#    #+#             */
/*   Updated: 2018/05/23 19:45:29 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_func_handle.h"
#include "add_func.h"
#include <stdint.h>

ssize_t	ft_ptr_handle(char **format, va_list *arg, t_arg *blanck)
{
	char		*base;
	uintmax_t	nbr;

	(void)format;
	blanck->task = z;
	if (blanck->got_precision)
		blanck->zero = 0;
	base = "0123456789abcdef";
	nbr = ft_unsg(arg, blanck);
	return (ft_nforcepref(nbr, base, blanck, "0x"));
}
