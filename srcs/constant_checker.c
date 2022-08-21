/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:20:02 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/08/21 19:51:11 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

int	check_last_meal(t_philo *philo)
{
	if (set_time() - philo->all->start_time > philo->time_to_die)
	{
		philo->all->philo_dead = 1;
		printf("%d %d died\n", set_time() - philo->all->start_time, philo->id);
		return (0);
	}
	else
		return (1);
}

int	check_cadavers(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->philo_nb)
	{
		if (check_last_meal(&all->philo[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	*constant_checker(void *arg)
{
	t_all	*check;

	check = (t_all *)arg;
	while (1)
	{
		pthread_mutex_lock(&check->mutex);
		if (check_cadavers(check) == 0)
		{
			usleep(100);
			return (pthread_mutex_unlock(&check->mutex), NULL);
		}
		pthread_mutex_unlock(&check->mutex);
		usleep(200);
	}
}
