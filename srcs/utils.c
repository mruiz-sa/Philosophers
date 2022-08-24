/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:02:20 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/08/24 18:43:56 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<stdio.h>

void	ft_sleep(int time_to_eat, t_philo *philo)
{
	int	start;

	start = set_time();
	while ((set_time() - start) < time_to_eat
		&& dead_checker(philo) == 0)
		usleep(100);
}

void	print_actions(t_philo *philo, char *str)
{
	if (dead_checker(philo) == 0)
	{
		pthread_mutex_lock(&philo->all->mutex);
		printf("%d %d %s\n", set_time() - philo->all->start_time,
			philo->id, str);
		pthread_mutex_unlock(&philo->all->mutex);
	}
}

int	dead_checker(t_philo *philo)
{
	pthread_mutex_lock(&philo->all->mutex);
	if (philo->all->philo_dead == 1)
	{
		pthread_mutex_unlock(&philo->all->mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->all->mutex);
	return (0);
}

void	free_philo(t_all *all)
{
	free(all->philo);
	free(all->fork_mutex);
}
