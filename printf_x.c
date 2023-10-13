/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:36:23 by kotkobay          #+#    #+#             */
/*   Updated: 2023/10/06 19:28:28 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*hex(int num, char *hex)
{
	char			*result;
	int				i;
	int				count;
	unsigned int	tmp;

	tmp = num;
	count = 1;
	while (tmp / 16)
	{
		tmp /= 16;
		count++;
	}
	if (num < 0)
		count++;
	i = 0;
	result = malloc(sizeof(char) * (count + 1));
	while (count >= 0)
	{
		result[i] = hex[num % 16];
		num /= 16;
		i++;
		count--;
	}
	result[i] = '\0';
	return (result);
}

int	printf_x(int num)
{
	char	*hexd;
	char	*result;
	int		count;

	count = 0;
	hexd = "0123456789abcdef";
	result = hex(num, hexd);
	while (*result)
	{
		count += write(1, &result, 1);
		result++;
	}
	free(result);
	free(hex);
	return (count);
}

int	printf_capital_x(int num)
{
	char	*hexd;
	char	*result;
	int		count;

	count = 0;
	hexd = "0123456789ABCDEF";
	result = hex(num, hexd);
	while (*result)
	{
		count += write(1, &result, 1);
		result++;
	}
	free(result);
	free(hex);
	return (count);
}
