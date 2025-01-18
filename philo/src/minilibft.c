/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:41:56 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/17 20:09:19 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_atoui(char *str)
{
	long	res;
	int		i;

	res = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == 1)
		i++;
	if (!str[i] || '0' > str[i] || str[i] > 9)
		return (-1);
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res > INT_MAX)
			return (-1);
		i++;
	}
	while (ft_isspace(str[i]))
		i++;
	if	(str[i])
		return (-1);
	return (res);
}

int	ft_isspace(char c)
{
	return (c == 32 || (9 <= c && c <= 13));
}

