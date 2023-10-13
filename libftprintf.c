/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:27:14 by kotkobay          #+#    #+#             */
/*   Updated: 2023/10/08 16:25:19 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	va_start(args, s);
	count = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == 'c')
				count += write(1, &(char){va_arg(args, int)}, 1);
			else if (*s == 'd')
				count += printf_d(va_arg(args, int));
			else if (*s == 'p')
				count += printf_p(va_arg(args, unsigned int));
			else if (*s == 's')
				count += printf_s(va_arg(args, char *));
			else if (*s == 'u')
				count += printf_u(va_arg(args, unsigned int));
			else if (*s == 'x')
				count += printf_x(va_arg(args, int));
			else if (*s == 'X')
				count += printf_capital_x(va_arg(args, int));
			else if (*s == '%')
				count += write(1, "%%", 1);
		}
		else
			count += write(1, s, 1);
		if (*s)
			s++;
	}
	va_end(args);
	return (count);
}

#include <stdio.h>

int	main(void)
{
	char *null_str = NULL;
	char *s = "wadada";
	int count;
	count = printf("this is a %s", null_str);
	printf("%d", count);
	count = 0;
	count = ft_printf("this is a %s", null_str);
	printf("%d", count);
}