/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:48:31 by daalexan          #+#    #+#             */
/*   Updated: 2018/05/23 19:48:32 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include "libft.h"
#include "ft_func_handle.h"
#include "add_func.h"

unsigned int	ft_nbrstrlen(uintmax_t nbr, char *base,\
	char *pref, t_arg *blanck)
{
	unsigned int	nlen;
	unsigned int	nstrlen;

	nlen = ft_nbrlen(nbr, base);
	if (nbr == 0 && blanck->got_precision && blanck->precision == 0)
		nstrlen = 0;
	else if (blanck->got_precision)
		nstrlen = FT_MAX(nlen, blanck->precision);
	else
		nstrlen = nlen;
	if (blanck->sharp && pref != NULL && nbr != 0)
		nstrlen = ft_strlen(pref);
	return (nstrlen);
}
