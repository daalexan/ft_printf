/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:49:54 by daalexan          #+#    #+#             */
/*   Updated: 2018/05/23 19:50:13 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_space(int nstrlen, int width, char space)
{
	while (nstrlen < width)
	{
		ft_putchar(space);
		nstrlen++;
	}
}
