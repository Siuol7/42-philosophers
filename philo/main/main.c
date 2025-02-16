/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:50:15 by caonguye          #+#    #+#             */
/*   Updated: 2025/02/16 18:12:27 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int ac, char **av)
{
	int	res;

	res = utilities(ac, av);
	if (res == ERROR_PARSING)
	{
		printf("Invalid Arguments\n");
		return (1);
	}
	if (res == ERROR)
		return (1);
	return (0);
}
