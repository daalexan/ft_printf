/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:51:20 by daalexan          #+#    #+#             */
/*   Updated: 2018/05/23 19:51:22 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADD_FUNC_H
# define ADD_FUNC_H
# include <inttypes.h>
# include "ft_func_handle.h"

unsigned int	ft_nbrstrlen(uintmax_t nbr, char *base,\
	char *pref, t_arg *blanck);
unsigned int	ft_nbrlen(uintmax_t nbr, char *base);
ssize_t			ft_nforcepref(uintmax_t nbr, char *base,\
	t_arg *blanck, char *pref);
void			ft_print_space(int nstrlen, int width, char space);
uintmax_t		ft_unsg(va_list *arg, t_arg *blanck);

#endif
