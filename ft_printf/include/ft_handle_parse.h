/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_parse.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:52:00 by daalexan          #+#    #+#             */
/*   Updated: 2018/05/23 19:52:02 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HANDLE_PARSE_H
# define FT_HANDLE_PARSE_H
# include "ft_func_handle.h"

char	*ft_parse_flags(char **format, t_arg *blanck);
char	*ft_parse_width(char **format, va_list *arg, t_arg *blanck);
char	*ft_parse_precision(char **format, va_list *arg, t_arg *blanck);
char	*ft_pasre_task(char **format, t_arg *arg);

#endif
