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

#include "ft_printf.h"
#include <stdarg.h>

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int temp;

	va_start(args, s);
	temp = 0;
	count = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == 'c')
				temp = write(1, &(char){va_arg(args, int)}, 1);
			else if (*s == 'd')
				temp = printf_d(va_arg(args, int));
			else if (*s == 'p')
				temp = printf_p(va_arg(args, void *));
			else if (*s == 's')
				temp = printf_s(va_arg(args, char *));
			else if (*s == 'u')
				temp = printf_u(va_arg(args, unsigned int));
			else if (*s == 'x')
				temp = printf_x(va_arg(args, unsigned int));
			else if (*s == 'X')
				temp = printf_capital_x(va_arg(args, unsigned int));
			else if (*s == '%')
				temp = write(1, "%%", 1);
		}
		else
			temp = write(1, s, 1);
		if (temp >= 0)
			count += temp;
		else if(temp == -1)
			return (-1);
		temp = 0;
		if (*s)
			s++;
	}
	va_end(args);
	return (count);
}

#include <stdio.h>

int	main(void)
{
	int x = 231315414;
	void *p;
	p = &x;
	int count;
	count = 0;
	count = printf("this is a %X\n", x);
	printf("%d\n", count);
	count = 0;
	count = ft_printf("this is a %X\n", x);
	printf("%d\n", count);
}