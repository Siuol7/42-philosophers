/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 02:48:19 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/14 13:51:04 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	set_up_2d_mutex(t_dinner *table)
{
	int	i;

	i = 0;
	table->mutexes = 3;
	while (i < table->fork_cnt)
	{
		if (pthread_mutex_init(table->forks_key[i], NULL))
			return (total_mutex_clear(table, i));
		table->mutexes = 4;
		i++;
	}
	i = 0;
	while (i < table->fork_cnt)
	{
		if (pthread_mutex_init(table->philo[i].philo_key, NULL))
			return (total_mutex_clear(table, i));
		table->mutexes = 5;
		i++;
	}
	return (1);
}

static int	set_up_mutex(t_dinner *table)
{
	if (pthread_mutex_init(table->total_meals_key, NULL))
	{
		table->mutexes = 0;
		return (total_mutex_clear(table, 0));
	}
	table->mutex_key[0] = &table->total_meals_key;
	if (pthread_mutex_init(table->status_key, NULL))
	{
		table->mutexes = 1;
		return (total_mutex_clear(table, 0));
	}
	table->mutex_key[1] = &table->status_key;
	if (pthread_mutex_init(table->print_key, NULL))
	{
		table->mutexes = 2;
		return (total_mutex_clear(table, 0));
	}
	table->mutex_key[2] = &table->print_key;
	return (1);
}

static void	set_up_philo(t_dinner *table)
{
	int	i;
	int	right;
	int	left;

	i = 0;
	while (i < table->philo_cnt)
	{
		right = (i + 1) % table->philo_cnt;
		left = (i - 1 + table->philo_cnt) % table->philo_cnt;
		table->philo[i].id = i;
		table->philo[i].next_meal = 0;
		table->philo[i].last_meal = 0;
		table->philo[i].eaten = 0;
		table->philo[i].left_key = table->forks_key[i];
		table->philo[i].right_key = table->forks_key[right];
		table->philo[i].all = table;
		table->philo[i].left_philo = &table->philo[left];
		table->philo[i].right_philo = &table->philo[right];
		i++;
	}
}

int	set_up(t_dinner *table, char **av)
{
	table->philo_cnt = ft_atoui(av[1]);
	table->fork_cnt = ft_atoui(av[1]);
	table->time_to_die = ft_atoui(av[2]);
	table->time_to_eat = ft_atoui(av[3]);
	table->time_to_sleep = ft_atoui(av[4]);
	table->meals_cnt = -1;
	if (av[5])
		table->meals_cnt = ft_atoui(av[5]);
	table->philo = malloc(table->philo_cnt*sizeof(t_philo));
	table->forks_key = malloc(table->fork_cnt*sizeof(pthread_mutex_t));
	table->mutex_key = malloc(3*sizeof(pthread_mutex_t));
	if (!table->philo || !table->forks_key || !table->mutex_key)
		return (setup_error(table));
	dinner_memset(table);
	philo_memset(table->philo);
	if (!set_up_mutex(table))
		return (setup_error(table));
	if (!set_up_2d_mutex(table))
		return (setup_error(table));
	set_up_philo(table);
}
