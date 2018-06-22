/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:50:22 by daalexan          #+#    #+#             */
/*   Updated: 2018/05/23 19:50:33 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <sys/types.h>
#include <stdarg.h>
#include "ft_func_handle.h"

uintmax_t	ft_unsg(va_list *arg, t_arg *blanck)
{
	uintmax_t	nbr;

	nbr = va_arg(*arg, uintmax_t);
	if (blanck->task == hh)
		nbr = (unsigned char)nbr;
	else if (blanck->task == h)
		nbr = (unsigned short int)nbr;
	else if (blanck->task == l)
		nbr = (unsigned long int)nbr;
	else if (blanck->task == ll)
		nbr = (unsigned long long int)nbr;
	else if (blanck->task == j)
		nbr = (uintmax_t)nbr;
	else if (blanck->task == z)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}
