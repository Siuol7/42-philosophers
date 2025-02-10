/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:01:44 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/10 15:53:13 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

size_t	current(void)
{
	struct timeval	time;
	if (gettimeofday(&time, NULL) < 0)
	{
		write(2, "Get time error\n", 19);
		return (-1);
	}
	return (time.tv_sec * 1000 + time.tv_usec/1000);
}

void	system_print(t_philo *philo, char *noti)
{
	lock_mutex(philo->all->print_key);
	if (!find_death(philo))
		exit(1);
	printf("%zu %d %s", current(), philo->id, noti);
	unlock_mutex(philo->all->print_key);
}
