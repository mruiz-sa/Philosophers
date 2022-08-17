/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:21:26 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/08/09 16:41:18 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philosophers.h"

int	main(int ac, char **av)
{
	t_all	all;

	if (check_args(ac, av) == 1)
	{
		if (convert(&all, av) == 1)
		{
			start_routine(&all);
			constant_checker(&all);
			join_threads(&all);
			free_philo(&all);
		}
	}
}
