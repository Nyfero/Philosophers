/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:41:56 by gsap              #+#    #+#             */
/*   Updated: 2022/01/10 16:09:53 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_fork(t_data data)
{
	write(1, "4\n", 2);
	if (data.philo[data.i + 1].lfork == 0)
	{
		write(1, "5\n", 2);

		pthread_mutex_lock(&data.mut_fork[data.i]);
		data.philo[data.i].rfork = 1;
	}
	write(1, "4\n", 2);
	if (data.philo[(data.i + data.n_philo - 1) % data.n_philo].rfork == 0)
	{
		pthread_mutex_lock(&data.mut_fork[(data.i + data.n_philo - 1) % data.n_philo]);
		data.philo[data.i].lfork = 1;
		pthread_mutex_lock(&data.mut_speak);
		print_time(data);
		printf(" has taken a fork\n");
		pthread_mutex_unlock(&data.mut_speak);
	}
	else
	{
		pthread_mutex_unlock(&data.mut_fork[data.i]);
		data.philo[data.i].rfork = 0;
	}
}
