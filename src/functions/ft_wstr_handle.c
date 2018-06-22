/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:45:37 by daalexan          #+#    #+#             */
/*   Updated: 2018/05/23 19:45:40 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_func_handle.h"
#include "add_func.h"

static size_t	calc_wstrlen(wchar_t *str, int precision, size_t i)
{
	if (*str == '\0' || precision == 0)
		return (i);
	else if (*str <= 0x7F)
		return (calc_wstrlen(str + 1, precision - 1, i + 1));
	else if (*str <= 0x7FF && precision >= 2)
		return (calc_wstrlen(str + 1, precision - 2, i + 2));
	else if (*str <= 0xFFFF && precision >= 3)
		return (calc_wstrlen(str + 1, precision - 3, i + 3));
	else if (*str <= 0x10FFFF && precision >= 4)
		return (calc_wstrlen(str + 1, precision - 4, i + 4));
	else
		return (i);
}

static size_t	ft_wstrlen(wchar_t *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		str++;
	}
	return (i);
}

ssize_t			ft_wstr_handle(char **format, va_list *arg, t_arg *blanck)
{
	wchar_t	*str;
	size_t	strl;

	(void)format;
	(void)blanck;
	str = va_arg(*arg, wchar_t*);
	if (str == NULL)
		str = L"(null)";
	strl = blanck->got_precision ? calc_wstrlen(str, blanck->precision, 0)
	: ft_wstrlen(str);
	if (blanck->got_width && !blanck->minus)
		ft_print_space(strl, blanck->width, blanck->zero ? '0' : ' ');
	ft_putnwstr(str, strl);
	if (blanck->got_width && blanck->minus)
		ft_print_space(strl, blanck->width, ' ');
	return (blanck->got_width ? FT_MAX(strl, blanck->width) : strl);
}
