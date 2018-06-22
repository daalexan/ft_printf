/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:44:45 by daalexan          #+#    #+#             */
/*   Updated: 2018/05/23 19:44:46 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_func_handle.h"
#include "add_func.h"

ssize_t	ft_wchar_handle(char **format, va_list *arg, t_arg *blanck)
{
	wchar_t		wchr;
	unsigned	wchr_len;

	(void)format;
	wchr = (wchar_t)va_arg(*arg, wint_t);
	if (wchr <= 0x7F)
		wchr_len = 1;
	else if (wchr <= 0x7FF)
		wchr_len = 2;
	else if (wchr <= 0xFFFF)
		wchr_len = 3;
	else if (wchr <= 0x10FFFF)
		wchr_len = 4;
	else
		wchr_len = 0;
	if (blanck->got_width && !blanck->minus)
		ft_print_space(wchr_len, blanck->width, blanck->zero ? '0' : ' ');
	ft_putwchar(wchr);
	if (blanck->got_width && blanck->minus)
		ft_print_space(wchr_len, blanck->width, blanck->zero ? '0' : ' ');
	return (blanck->got_width ? FT_MAX(wchr_len, blanck->width) : wchr_len);
}
