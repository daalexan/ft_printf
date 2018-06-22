/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parses.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:42:54 by daalexan          #+#    #+#             */
/*   Updated: 2018/06/06 17:58:48 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include "ft_func_handle.h"

const char	*ft_parse_flags(char **format, t_arg *blnk)
{
	if (**format == '#' || **format == '0' || **format == '-' ||
	**format == '+' || **format == ' ')
	{
		if (**format == '#')
			blnk->sharp = 1;
		else if (**format == '0')
			blnk->zero = 1;
		else if (**format == '-')
			blnk->minus = 1;
		else if (**format == '+')
			blnk->plus = 1;
		else if (**format == ' ')
			blnk->space = 1;
		(*format)++;
		if (blnk->minus)
			blnk->zero = 0;
		return (ft_parse_flags(format, blnk));
	}
	else
		return (*format);
}

const char	*ft_parse_width(char **format, va_list *arg, t_arg *blnk)
{
	int		cont;

	blnk->width = 0;
	if (**format == '*' || ft_isdigit(**format))
	{
		if (**format == '*')
		{
			(*format)++;
			cont = va_arg(*arg, int);
			if (cont < 0)
				blnk->minus = 1;
			blnk->width = cont < 0 ? -cont : cont;
			blnk->got_width = 1;
		}
		if (ft_isdigit(**format))
		{
			blnk->width = 0;
			blnk->got_width = 1;
			while (ft_isdigit(**format))
			{
				blnk->width = (blnk->width * 10 + (*(*format)++ - '0'));
			}
		}
	}
	return (*format);
}

const char	*ft_parse_precision(char **format, va_list *arg, t_arg *blnk)
{
	int		var;

	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			(*format)++;
			if ((var = va_arg(*arg, int)) >= 0)
			{
				blnk->got_precision = 1;
				blnk->precision = var;
			}
			return (*format);
		}
		else
		{
			while (ft_isdigit(**format))
				blnk->precision = (blnk->precision * 10) + (*(*format)++ - '0');
			blnk->got_precision = 1;
			return (*format);
		}
	}
	else
		return (*format);
}

const char	*ft_pasre_task(char **format, t_arg *blnk)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		blnk->task = hh;
		return (*format += 2);
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		blnk->task = ll;
		return (*format += 2);
	}
	else if (**format == 'h' || **format == 'l' || **format == 'j'
		|| **format == 'z')
	{
		if (**format == 'h')
			blnk->task = h;
		else if (**format == 'l')
			blnk->task = l;
		else if (**format == 'j')
			blnk->task = j;
		else if (**format == 'z')
			blnk->task = z;
		return ((*format)++);
	}
	else
		return (*format);
}
