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

#include "ft_printf.h"

char	*hex(unsigned int num, char *hex)
{
	char			*result;
	int				i;
	int				count;
	unsigned int	tmp;

	tmp = num;
	count = 1;
	while (tmp /= 16)
		count++;
	result = malloc((count + 1));
	if(!result)
		return (NULL);
	result[count] = '\0';
	while (count-- > 0)
	{
		result[count] = hex[num % 16];
		num /= 16;
	}
	return (result);
}

int	printf_x(unsigned int num)
{
	char	*hexd;
	char	*result;
	int		count;

	count = 0;
	hexd = "0123456789abcdef";
	result = hex(num, hexd);
	if(!result)
		return (-1);
	count = write(1, result, ft_strlen(result));
	free(result);
	return (count);
}

int	printf_capital_x(unsigned int num)
{
	char	*hexd;
	char	*result;
	int		count;

	count = 0;
	hexd = "0123456789ABCDEF";
	result = hex(num, hexd);
	if (!result)
		return (-1);
	count = write(1, result, ft_strlen(result));
	free(result);
	return (count);
}
