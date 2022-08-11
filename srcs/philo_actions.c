/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:21:45 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/08/11 12:27:18 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"
#include<pthread.h>

int	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	if (dead_checker(philo) == 0)
		print_actions(philo, "has taken a fork");
	if (philo->id % 2 == 0)
	{
		if (pthread_mutex_lock(philo->left_fork) != 0)
			return (pthread_mutex_unlock(philo->right_fork));
		if (dead_checker(philo) == 0)
			print_actions(philo, "has taken a fork");
	}
	else
	{
		if (pthread_mutex_lock(philo->right_fork) != 0)
			return (pthread_mutex_unlock(philo->left_fork));
		if (dead_checker(philo) == 0)
			print_actions(philo, "has taken a fork");
	}
	return (0);
}

void	is_eating(t_philo *philo)
{
	print_actions(philo, "is eating");
	pthread_mutex_lock(&philo->all->mutex);
	philo->last_meal = set_time() - philo->all->start_time;
	philo->time_to_die = philo->all->time_to_die + philo->last_meal;
	pthread_mutex_unlock(&philo->all->mutex);
	ft_sleep(philo->all->time_to_eat, philo);
	pthread_mutex_lock(&philo->all->mutex);
	if (philo->meals_nb != -1)
		philo->meals_nb++;
	pthread_mutex_unlock(&philo->all->mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	is_sleeping(t_philo *philo)
{
	print_actions(philo, "is sleeping");
	ft_sleep(philo->all->time_to_sleep, philo);
}

void	is_thinking(t_philo *philo)
{
	print_actions(philo, "is thinking");
}
