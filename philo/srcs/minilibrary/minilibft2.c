/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 06:52:16 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/10 12:08:48 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_memset(t_philo *philo)
{
	memset(philo, 0, (char*)&philo->all - (char*)philo);
}

void	dinner_memset(t_dinner *table)
{
	memset(table, 0, (char*)&table->philo - (char*)&table);
}