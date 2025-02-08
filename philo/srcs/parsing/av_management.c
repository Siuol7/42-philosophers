/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_management.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 03:10:32 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/08 22:45:11 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	av_validation(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoui(av[i]) == -1)
			return (0);
		i++;
	}
	return (1);
}

int	av_parsing(int ac, char **av)
{
	if (!av_validation(ac, av))
		return (0);
	return (1);
}
