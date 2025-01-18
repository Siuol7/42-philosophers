/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_management.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 03:10:32 by caonguye          #+#    #+#             */
/*   Updated: 2025/01/18 04:20:11 by caonguye         ###   ########.fr       */
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

int	av_parsing(int ac, char **av, t_philo *philo, t_dinner *table)
{
	memset(philo, 0, sizeof(t_dinner));
	if (!av_validation(ac, av))
		return (0);
	table->philo_cnt = ft_atoui(av[1]);
	philo->time_to_die = ft_atoui(av[2]);
	philo->time_to_eat = ft_atoui(av[3]);
	philo->time_to_sleep = ft_atoui(av[4]);
	if (ac == 6)
		philo->meals_cnt = ft_atoui(av[5]);
	return (1);
}
