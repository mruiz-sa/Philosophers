/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 10:45:10 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/08/09 13:58:29 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"
#include<pthread.h>

void	*routine(t_philo *philo)
{
	while (philo->all->philo_dead == 0)
	{
		if (dead_checker(philo) == 1)
			free_and_exit(philo->all);
	}
}

void	start_routine(t_all *all)
{
	int	i;

	i = 0;
	all->time = set_time();
	while (i < all->philo_nb)
	{
		pthread_create(&all->philo[i].thread_id, NULL, &routine,
			&all->philo[i]);
		i++;
	}
	while (i < all->philo_nb)
	{
		pthread_join(all->philo[i].thread_id, NULL);
		i++;
	}
}
