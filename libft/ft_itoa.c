/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:14:48 by ooz               #+#    #+#             */
/*   Updated: 2022/01/03 12:14:48 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*r;
	int		tmp;
	int		a;

	a = 1;
	tmp = n;
	while (tmp && a++)
		tmp /= 10;
	r = (char *)malloc(sizeof(char) * ((n < 0) + a + (n == 0)));
	if (!r)
		return (NULL);
	r += (n < 0) + a - 1 + (n == 0);
	*r = '\0';
	if (n == 0)
		*(--r) = '0';
	a = (n >= 0) * 2 - 1;
	while (n)
	{
		*(--r) = (n % (10 * a)) * a + '0';
		n /= 10;
	}
	if (a < 0)
		*(--r) = '-';
	return (r);
}
