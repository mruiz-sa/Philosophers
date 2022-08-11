/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 10:45:10 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/08/11 12:41:18 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"
#include<pthread.h>

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->all->philo_dead == 0)
	{
		if (dead_checker(philo) == 1)
			free_and_exit(philo->all);
		take_forks(philo);
		if (dead_checker(philo) == 1)
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			return (0);
		}
		is_eating(philo);
		if (dead_checker(philo) == 1)
			free_and_exit(philo->all);
		is_sleeping(philo);
		if (dead_checker(philo) == 1)
			free_and_exit(philo->all);
		is_thinking(philo);
	}
	return (0);
}

void	start_routine(t_all *all)
{
	int	i;

	i = 0;
	all->start_time = set_time();
	while (i < all->philo_nb)
	{
		pthread_create(&all->philo[i].thread_id, NULL, &routine,
			(void *)&all->philo[i]);
		i++;
	}
	while (i < all->philo_nb)
	{
		pthread_join(all->philo[i].thread_id, NULL);
		i++;
	}
}
