/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 07:38:45 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/09 09:54:24 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	death_found(t_dinner *table, t_philo *philo)
{
	int	i;

	i = -1;
	while (i++ < table->philo_cnt)
	{
		if (next_meal > current)
		{
			table->philo_death = 1;
			return (1);
		}
	}
	return (1)
}

void	philo_thinks(t_dinner *table, t_philo *philo)
{

}

void	routine(table, philo)
{
	philo_thinks(table, philo);
	philo_eats(table, philo);
	philo_sleeps(table, philo);
}
