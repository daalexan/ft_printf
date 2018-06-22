/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:46:47 by daalexan          #+#    #+#             */
/*   Updated: 2018/05/23 19:47:07 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <sys/types.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_func_handle.h"
#include "add_func.h"

static void	ft_printnbr(uintmax_t nbr, char *base, t_arg *blanck, unsigned nlen)
{
	if (blanck->got_precision)
		ft_print_space(nlen, blanck->precision, base[0]);
	if (nbr == 0 && blanck->got_precision && blanck->precision == 0)
		return ;
	else
		ft_putnbrbase(nbr, base);
}

ssize_t		ft_uint_handle(uintmax_t nbr, t_arg *blanck, char *base, char *pref)
{
	unsigned int	nlen;
	unsigned int	nstrlen;

	if (blanck->got_precision)
		blanck->zero = 0;
	nlen = ft_nbrlen(nbr, base);
	if (blanck->got_width && !blanck->minus && blanck->zero)
	{
		if (blanck->got_precision)
			blanck->precision = FT_MAX(blanck->width, blanck->precision);
		else
			blanck->precision = FT_MAX(blanck->width, nlen);
		blanck->got_precision = 1;
		blanck->got_width = 0;
	}
	nstrlen = ft_nbrstrlen(nbr, base, pref, blanck);
	if (blanck->got_width && !blanck->minus)
		ft_print_space(nstrlen, blanck->width, ' ');
	if (blanck->sharp && pref != NULL && nbr != 0)
		ft_putstr(pref);
	ft_printnbr(nbr, base, blanck, nlen);
	if (blanck->got_width && blanck->minus)
		ft_print_space(nstrlen, blanck->width, ' ');
	return (blanck->got_width ? FT_MAX(nstrlen, blanck->width) : nstrlen);
}
