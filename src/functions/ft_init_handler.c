/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:45:06 by daalexan          #+#    #+#             */
/*   Updated: 2018/05/23 19:45:13 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func_handle.h"
#include "libft.h"

static void	ft_init(t_handler *hndlr)
{
	hndlr['%'] = &ft_escape_handle;
	hndlr['s'] = &ft_str_handle;
	hndlr['S'] = &ft_wstr_handle;
	hndlr['p'] = &ft_ptr_handle;
	hndlr['d'] = &ft_int_handle;
	hndlr['i'] = &ft_int_handle;
	hndlr['D'] = &ft_long_handle;
	hndlr['o'] = &ft_octal_handle;
	hndlr['O'] = &ft_long_handle;
	hndlr['U'] = &ft_long_handle;
	hndlr['u'] = &ft_unsigned_handle;
	hndlr['x'] = &ft_hex_handle;
	hndlr['X'] = &ft_hex_handle;
	hndlr['C'] = &ft_char_handle;
	hndlr['c'] = &ft_wchar_handle;
	hndlr['b'] = &ft_bin_handle;
	hndlr['n'] = &ft_chrwrite_handle;
}

t_handler	ft_init_handler(char c)
{
	static t_handler	*hndlr;
	static t_handler	res;

	hndlr = NULL;
	if (hndlr == NULL)
		if ((hndlr = ft_memalloc(sizeof(*hndlr) * 256)))
			ft_init(hndlr);
	res = hndlr[(int)c];
	free(hndlr);
	return (res);
}
