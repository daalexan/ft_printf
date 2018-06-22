/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_escape_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:46:26 by daalexan          #+#    #+#             */
/*   Updated: 2018/05/23 19:46:27 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func_handle.h"
#include "libft.h"
#include "add_func.h"

ssize_t	ft_escape_handle(char **format, va_list *arg, t_arg *blanck)
{
	(void)format;
	(void)arg;
	if (blanck->got_width && !blanck->minus)
		ft_print_space(1, blanck->width, blanck->zero ? '0' : ' ');
	ft_putchar('%');
	if (blanck->got_width && blanck->minus)
		ft_print_space(1, blanck->width, ' ');
	return (blanck->got_width ? FT_MAX(blanck->width, 1) : 1);
}
