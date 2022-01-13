/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:41:56 by gsap              #+#    #+#             */
/*   Updated: 2022/01/13 17:47:19 by gsap             ###   ########.fr       */
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
			print_info(*vitals, data, "has taken a fork");
			pthread_mutex_lock(&data->mut_fork[(vitals->pos - 2 + data->n_philo)
				% data->n_philo]);
			print_info(*vitals, data, "has taken a fork");
		}
		else
		{
			pthread_mutex_lock(&data->mut_fork[(vitals->pos - 2 + data->n_philo)
				% data->n_philo]);
			print_info(*vitals, data, "has taken a fork");
			pthread_mutex_lock(&data->mut_fork[(vitals->pos - 1 + data->n_philo)
				% data->n_philo]);
			print_info(*vitals, data, "has taken a fork");
		}
	}
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
}

/*
**	Pour lacher les forks, les philosophes procedent dans l'ordre inverse de
**	prise des forks
*/

void	drop_fork(t_philo *vitals, t_data *data)
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
	vitals->now = reset_time();
	if (is_alive(vitals, data))
	{
		print_info(*vitals, data, "is sleeping");
		usleep(data->t_sleep * 1000);
		vitals->now = reset_time();
		if (is_alive(vitals, data))
			print_info(*vitals, data, "is thinking");
	}
}

/*
**	Retourne le temps actuel en milliseconde
*/

long int	reset_time(void)
{
	t_time		time;
	long int	tmp;

	gettimeofday(&time.now, NULL);
	tmp = ((time.now.tv_sec * 1000000 + time.now.tv_usec) / 1000);
	return (tmp);
}

int	is_alive(t_philo *vitals, t_data *data)
{
	if (vitals->now - vitals->last < data->t_die)
		return (1);
	else
	{
		print_info(*vitals, data, "died");
		pthread_mutex_lock(&data->mut_death);
		data->end = 1;
		pthread_mutex_unlock(&data->mut_death);
		return (0);
	}
}
