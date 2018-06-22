/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nforcepref.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:49:10 by daalexan          #+#    #+#             */
/*   Updated: 2018/05/23 19:49:45 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "add_func.h"

ssize_t	ft_nforcepref(uintmax_t nbr, char *base, t_arg *blanck, char *pref)
{
	unsigned	nlen;
	size_t		ncut;

	nlen = ft_nbrstrlen(nbr, base, NULL, blanck) + ft_strlen(pref);
	ncut = ft_strlen(pref);
	if (blanck->got_width && !blanck->minus && !blanck->zero)
	{
		ft_print_space(nlen, blanck->width, ' ');
		ncut += FT_MAX(blanck->width - nlen, 0);
		blanck->got_width = 0;
	}
	else if (blanck->got_width)
		blanck->width -= ft_strlen(pref);
	ft_putstr(pref);
	return (ft_uint_handle(nbr, blanck, base, NULL) + ncut);
}
