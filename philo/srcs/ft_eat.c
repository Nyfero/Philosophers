/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:41:56 by gsap              #+#    #+#             */
/*   Updated: 2022/01/27 17:57:19 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Les philosophes impairs essayent de prendre en premier les forks a leurs
**	gauches puis a leurs droites, les pairs font l'inverse : droite puis gauche
*/

void	take_fork(t_philo *vitals, t_data *data)
{
	if (is_alive(vitals, data))
	{
		if ((vitals->pos % 2) == 1)
		{
			take_left_fork(vitals, data);
			take_right_fork(vitals, data);
			vitals->forks = 1;
		}
		else
		{
			take_right_fork(vitals, data);
			take_left_fork(vitals, data);
			vitals->forks = 1;
		}
	}
	return ;
}

/*
**	Compare le temps actuel moins la derniere fois qu'il a mange avec le temps
**	pour manger. Meme idee pour sleep
*/

void	eat(t_philo *vitals, t_data *data)
{
	if (is_alive(vitals, data))
	{
		vitals->last = reset_time();
		print_info(*vitals, data, "is eating");
		while (is_alive(vitals, data)
			&& (vitals->now - vitals->last) <= data->t_eat)
			usleep(1000);
		if (is_alive(vitals, data))
		{
			vitals->eat++;
			pthread_mutex_lock(&data->mut_death);
			data->eat++;
			pthread_mutex_unlock(&data->mut_death);
		}
	}
}

/*
**	Pour lacher les forks, les philosophes procedent dans l'ordre inverse de
**	prise des forks. Vitals->forks permet d'eviter de unlock des mutexs pas lock
*/

void	drop_fork(t_philo *vitals, t_data *data)
{
	if ((vitals->pos % 2) == 1)
	{
		if (vitals->forks == 1)
		{
			drop_right_fork(vitals, data);
			drop_left_fork(vitals, data);
			vitals->forks = 0;
		}
	}
	else
	{
		if (vitals->forks == 1)
		{
			drop_left_fork(vitals, data);
			drop_right_fork(vitals, data);
			vitals->forks = 0;
		}
	}
}

/*
**	usleep(data->n_philo) permet de recaler les philosophes pour pas que les
**	pairs et impairs se chevauchent
*/

void	sleep_and_think(t_philo *vitals, t_data *data)
{
	if (is_alive(vitals, data))
	{
		vitals->sleep = reset_time();
		print_info(*vitals, data, "is sleeping");
		while (is_alive(vitals, data)
			&& (vitals->now - vitals->sleep) <= data->t_sleep)
			usleep(1000);
		if (is_alive(vitals, data))
		{
			if (vitals->pos % 2 == 1)
				usleep(data->t_die / 2);
			print_info(*vitals, data, "is thinking");
		}
	}
}
