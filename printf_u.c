/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:57:56 by kotkobay          #+#    #+#             */
/*   Updated: 2023/10/06 19:27:38 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	printf_u(int n)
{
	char	*num;
	int		len;
	int		count;

	count = 0;
	len = digit_count(n);
	num = ft_itoa((unsigned int)n);
	num[len] = '\0';
	while (*num)
	{
		count += write(1, &num, 1);
		num++;
	}
	free(num);
	return (count);
}
