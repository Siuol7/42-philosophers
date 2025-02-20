/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 07:38:45 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/19 04:06:47 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	philo_thinks(t_philo *philo)
{
	if (!system_print(philo, "is thinking"))
		return (0);
	return (1);
}

static int	philo_eats(t_philo	*philo)
{
	if (!eating(philo))
		return (0);
	return (1);
}

static int	philo_sleeps(t_philo *philo)
{
	if (!system_print(philo, "is sleeping"))
		return (0);
	return (processing(philo->all->time_to_sleep, philo));
}

void	*routine(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	while (current() < philo->all->start_time + 5000)
		usleep(100);
	if (philo->id % 2 != 0)
		usleep(philo->all->time_to_eat/2 *1000);
	//printf("START AT %zu\n", current());
	while (1)
	{
		if (!philo_thinks(philo))
			break ;
		if (!philo_eats(philo))
			break ;
		if (!philo_sleeps(philo))
			break ;
		if (find_death(philo) || dinner_done(philo))
			break ;
	}
	return (NULL);
}
