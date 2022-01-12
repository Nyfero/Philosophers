/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:41:56 by gsap              #+#    #+#             */
/*   Updated: 2022/01/12 18:11:16 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Les philosophes impairs essayent de prendre en premier les forks a leurs
**	gauches puis a leurs droites, les pairs font l'inverse : droite puis gauche
*/

void	take_fork(t_philo vitals, t_data *data)
{
	if (vitals.last - data->start < data->t_die)
	{
		if ((vitals.pos % 2) == 1)
		{
			pthread_mutex_lock(&data->mut_fork[(vitals.pos - 1 + data->n_philo)
				% data->n_philo]);
			pthread_mutex_lock(&data->mut_fork[(vitals.pos - 2 + data->n_philo)
				% data->n_philo]);
		}
		else
		{
			pthread_mutex_lock(&data->mut_fork[(vitals.pos - 2 + data->n_philo)
				% data->n_philo]);
			pthread_mutex_lock(&data->mut_fork[(vitals.pos - 1 + data->n_philo)
				% data->n_philo]);
		}
		print_fork(vitals, data);
	}
	else
		print_dead(vitals, data);
}

void	eat(t_philo vitals, t_data *data)
{
	if (vitals.last - data->start < data->t_die)
	{
		gettimeofday(&vitals.time.now, NULL);
		vitals.last = ((vitals.time.now.tv_sec * 1000000
			+ vitals.time.now.tv_usec) / 1000);
		print_eat(vitals, data);
		vitals.count++;
		usleep(data->t_eat * 1000);
	}
	else
		print_dead(vitals, data);
}

/*
**	Pour lacher les forks, les philosophes procedent dans l'ordre inverse de
**	prise des forks
*/

void	drop_fork(t_philo vitals, t_data *data)
{
	if (vitals.last - data->start < data->t_die)
	{
		if ((vitals.pos % 2) == 1)
		{
			pthread_mutex_unlock(&data->mut_fork[(vitals.pos - 2 + data->n_philo)
				% data->n_philo]);
			pthread_mutex_unlock(&data->mut_fork[(vitals.pos - 1 + data->n_philo)
				% data->n_philo]);
		}
		else
		{
			pthread_mutex_unlock(&data->mut_fork[(vitals.pos - 1 + data->n_philo)
				% data->n_philo]);
			pthread_mutex_unlock(&data->mut_fork[(vitals.pos - 2 + data->n_philo)
				% data->n_philo]);
		}
		print_sleep(vitals, data);
		usleep(data->t_sleep * 1000);
	}
	if (vitals.last - data->start < data->t_die)
		print_think(vitals, data);
}
