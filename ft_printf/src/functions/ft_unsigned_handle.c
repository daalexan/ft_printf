/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_handle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:47:34 by daalexan          #+#    #+#             */
/*   Updated: 2018/05/23 19:47:51 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "ft_func_handle.h"
#include <stddef.h>
#include "add_func.h"

ssize_t	ft_unsigned_handle(char **format, va_list *arg, t_arg *blanck)
{
	uintmax_t	nbr;

	(void)format;
	nbr = ft_unsg(arg, blanck);
	return (ft_uint_handle(nbr, blanck, "0123456789", NULL));
}
