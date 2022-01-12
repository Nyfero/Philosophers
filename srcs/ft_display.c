/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:42:41 by gsap              #+#    #+#             */
/*   Updated: 2022/01/12 17:10:35 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_fork(t_philo vitals, t_data *data)
{
	pthread_mutex_lock(&data->mut_speak);
	print_time(data);
	printf(" %d has taken a fork\n", vitals.pos);
	pthread_mutex_unlock(&data->mut_speak);
	return ;
}

void	print_eat(t_philo vitals, t_data *data)
{
	pthread_mutex_lock(&data->mut_speak);
	print_time(data);
	printf(" %d is eating\n", vitals.pos);
	pthread_mutex_unlock(&data->mut_speak);
	return ;
}

void	print_sleep(t_philo vitals, t_data *data)
{
	pthread_mutex_lock(&data->mut_speak);
	print_time(data);
	printf(" %d is sleeping\n", vitals.pos);
	pthread_mutex_unlock(&data->mut_speak);
	return ;
}

void	print_think(t_philo vitals, t_data *data)
{
	pthread_mutex_lock(&data->mut_speak);
	print_time(data);
	printf(" %d is thinking\n", vitals.pos);
	pthread_mutex_unlock(&data->mut_speak);
	return ;
}

void	print_dead(t_philo vitals, t_data *data)
{
	pthread_mutex_lock(&data->mut_speak);
	print_time(data);
	printf(" %d died\n", vitals.pos);
	pthread_mutex_unlock(&data->mut_speak);
	return ;
}

void	print_time(t_data *data)
{
	long int	now;

	gettimeofday(&data->time.now, NULL);
	now = ((data->time.now.tv_sec * 1000000 + data->time.now.tv_usec)
			/ 1000) - data->start;
	printf("%ld", now);
	return ;
}
