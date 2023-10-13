/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:49:28 by kotkobay          #+#    #+#             */
/*   Updated: 2023/10/06 19:26:49 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	write_p(char *result)
{
	int	count;

	count = 0;
	while (*result)
	{
		count += write(1, &result, 1);
		result++;
	}
	free(result);
	return (count);
}

int	printf_p(unsigned int num)
{
	char	*result;
	int		i;
	int		count;
	char	*hex;
	int		tmp;

	hex = "0123456789ABCDEF";
	tmp = num;
	count = 1;
	while (tmp / 16)
	{
		tmp /= 16;
		count++;
	}
	i = 0;
	result = (char *)malloc(sizeof(char) * (count + 1));
	while (count >= 0)
	{
		result[i] = hex[num % 16];
		num /= 16;
		i++;
		count--;
	}
	result[i] = '\0';
	return (write_p(result));
}
