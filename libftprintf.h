/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:55:05 by kotkobay          #+#    #+#             */
/*   Updated: 2023/10/06 18:47:07 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		printf_d(int n);
int		printf_p(unsigned int num);
int		printf_s(char *s);
int		printf_u(int n);
int		printf_x(int num);
int		printf_capital_x(int num);
char	*ft_itoa(int n);
int		ft_printf(const char *s, ...);
int		digit_count(unsigned int n);

#endif