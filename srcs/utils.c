/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:02:20 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/08/09 19:08:27 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"
#include<sys/time.h>
#include<stdlib.h>
#include<pthread.h>

void	print_actions(t_philo *philo, char *str)
{
	if (dead_checker(philo) == 0)
	{
		pthread_mutex_lock(&philo->all->mutex);
		printf("%d %d %s\n", set_time() - philo->all->time, philo->id, str);
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

void	free_and_exit(t_all *all)
{
	free(all->philo);
	free(all->fork_mutex);
	exit(0);
}

int	main(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
