/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:21:26 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/08/29 12:03:07 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philosophers.h"
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int	main(int ac, char **av)
{
	t_all	all;

	if (check_args(ac, av) == 1)
	{
		if (convert(&all, av) == 1)
		{
			if (all.philo_nb == 1)
			{
				printf("0 1 has taken a fork\n");
				printf("%d 1 died\n", all.time_to_die + 1);
				free_philo(&all);
				return (0);
			}
			start_routine(&all);
			constant_checker(&all);
			join_threads(&all);
			free_philo(&all);
		}
	}
}
