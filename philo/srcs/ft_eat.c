/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:41:56 by gsap              #+#    #+#             */
/*   Updated: 2022/01/13 14:28:10 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Les philosophes impairs essayent de prendre en premier les forks a leurs
**	gauches puis a leurs droites, les pairs font l'inverse : droite puis gauche
*/

void	take_fork(t_philo *vitals, t_data *data)
{
	vitals->now = reset_time();
	if (is_alive(vitals, data))
	{
		if ((vitals->pos % 2) == 1)
		{
			pthread_mutex_lock(&data->mut_fork[(vitals->pos - 1 + data->n_philo)
				% data->n_philo]);
			pthread_mutex_lock(&data->mut_fork[(vitals->pos - 2 + data->n_philo)
				% data->n_philo]);
		}
		else
		{
			pthread_mutex_lock(&data->mut_fork[(vitals->pos - 2 + data->n_philo)
				% data->n_philo]);
			pthread_mutex_lock(&data->mut_fork[(vitals->pos - 1 + data->n_philo)
				% data->n_philo]);
		}
		print_info(*vitals, data, "has taken a fork");
	}
	else
		exit(1);
}

void	eat(t_philo *vitals, t_data *data)
{
	vitals->now = reset_time();
	if (is_alive(vitals, data))
	{
		vitals->last = reset_time();
		print_info(*vitals, data, "is eating");
		vitals->eat++;
		usleep(data->t_eat * 1000);
		vitals->now = reset_time();
	}
	else
		exit(1);
}

/*
**	Pour lacher les forks, les philosophes procedent dans l'ordre inverse de
**	prise des forks
*/

void	drop_fork(t_philo *vitals, t_data *data)
{
	vitals->now = reset_time();
	if (is_alive(vitals, data))
	{
		if ((vitals->pos % 2) == 1)
		{
			pthread_mutex_unlock(&data->mut_fork[(vitals->pos - 2 + data->n_philo)
				% data->n_philo]);
			pthread_mutex_unlock(&data->mut_fork[(vitals->pos - 1 + data->n_philo)
				% data->n_philo]);
		}
		else
		{
			pthread_mutex_unlock(&data->mut_fork[(vitals->pos - 1 + data->n_philo)
				% data->n_philo]);
			pthread_mutex_unlock(&data->mut_fork[(vitals->pos - 2 + data->n_philo)
				% data->n_philo]);
		}
		print_info(*vitals, data, "is sleeping");
		usleep(data->t_sleep * 1000);
		vitals->now = reset_time();
	}
	else
		exit(1);
	if (is_alive(vitals, data))
		print_info(*vitals, data, "is thinking");
	else
		exit(1);
}
