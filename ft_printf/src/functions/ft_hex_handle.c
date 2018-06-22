/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:44:06 by daalexan          #+#    #+#             */
/*   Updated: 2018/05/23 19:44:08 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "ft_func_handle.h"
#include "add_func.h"

ssize_t		ft_hex_handle(char **format, va_list *arg, t_arg *blanck)
{
	uintmax_t	nbr;

	nbr = ft_unsg(arg, blanck);
	if (**format == 'X')
		return (ft_uint_handle(nbr, blanck, "0123456789ABCDEF", "0X"));
	else
		return (ft_uint_handle(nbr, blanck, "0123456789abcdef", "0x"));
}
