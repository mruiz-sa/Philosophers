/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:21:26 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/08/24 17:32:58 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philosophers.h"
#include<stdlib.h>

int	main(int ac, char **av)
{
	t_all	all;

	if (check_args(ac, av) == 1)
	{
		if (convert(&all, av) == 1)
		{
			start_routine(&all);
			constant_checker(&all);
			if (all.philo_nb == 1)
			{
				free_philo(&all);
				return (0);
			}
			else
				join_threads(&all);
			free_philo(&all);
		}
	}
}
