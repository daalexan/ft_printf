/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:48:22 by daalexan          #+#    #+#             */
/*   Updated: 2018/05/23 19:48:24 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <sys/types.h>
#include "libft.h"

unsigned int	ft_nbrlen(uintmax_t nbr, char *base)
{
	size_t			nbr_base;
	unsigned int	i;

	nbr_base = ft_strlen(base);
	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= nbr_base;
		i++;
	}
	return (i);
}
