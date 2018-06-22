/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:46:36 by daalexan          #+#    #+#             */
/*   Updated: 2018/05/23 19:46:39 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func_handle.h"
#include "ft_printf.h"
#include "libft.h"

ssize_t		ft_long_handle(char **format, va_list *arg, t_arg *blanck)
{
	blanck->task = l;
	return (ft_init_handler(ft_tolower(**format))(format, arg, blanck));
}
