/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:47:25 by daalexan          #+#    #+#             */
/*   Updated: 2018/05/23 19:47:26 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func_handle.h"
#include "ft_printf.h"
#include "libft.h"
#include "add_func.h"

ssize_t	ft_null_handle(char **format, va_list *arg, t_arg *blanck)
{
	(void)arg;
	if (blanck->got_width && !blanck->minus)
		ft_print_space(1, blanck->width, blanck->zero ? '0' : ' ');
	ft_putchar(**format);
	if (blanck->got_width && blanck->minus)
		ft_print_space(1, blanck->width, ' ');
	return (blanck->got_width ? FT_MAX(blanck->width, 1) : 1);
}
