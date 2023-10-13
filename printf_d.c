/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:37:56 by kotkobay          #+#    #+#             */
/*   Updated: 2023/10/06 19:29:07 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int	printf_d(int n)
{
	char	*num;
	int		len;
	int		count;

	count = 0;
	len = digit_count(n);
	num = ft_itoa(n);
	num[len] = '\0';
	while (*num++)
		count += write(1, &num, 1);
	free(num);
	return (count);
}
