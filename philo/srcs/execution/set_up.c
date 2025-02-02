/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 02:48:19 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/01 16:12:53 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	set_up(t_dinner *table, char **av)
{
	table->philo_cnt = av[1];
	table->fork_cnt = av[1];
	table->time_to_die = av[2];
	table->time_to_eat = av[3];
	table->time_to_sleep = av[4];
	table->meals_cnt = -1;
	if (av[5])
		table->meals_cnt = av[5];
	table->philo = malloc(table->philo_cnt*sizeof(t_philo));
	table->forks_lst = malloc(table->fork_cnt*(sizeof(pthread_mutex_t)));
	if (!table->philo || !table->forks_lst)
		return(setup_error(table));
}
