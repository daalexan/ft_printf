/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:46:16 by daalexan          #+#    #+#             */
/*   Updated: 2018/05/23 19:46:17 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func_handle.h"
#include "add_func.h"
#include "libft.h"
#include <wchar.h>

ssize_t	ft_str_handle(char **format, va_list *arg, t_arg *blanck)
{
	char	*str;
	size_t	strlen;

	if (blanck->task == l)
		return (ft_wstr_handle(format, arg, blanck));
	else
	{
		str = va_arg(*arg, char*);
		if (str == NULL)
			str = "(null)";
		strlen = blanck->got_precision ? ft_nstrlen(str, blanck->precision) :
				ft_strlen(str);
		if (blanck->got_width && !blanck->minus)
			ft_print_space(strlen, blanck->width, blanck->zero ?
					'0' : ' ');
		ft_putnstr(str, strlen);
		if (blanck->got_width && blanck->minus)
			ft_print_space(strlen, blanck->width, ' ');
		return (blanck->got_width ? FT_MAX(strlen, blanck->width) : strlen);
	}
}
