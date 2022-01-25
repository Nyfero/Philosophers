/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:41:56 by gsap              #+#    #+#             */
/*   Updated: 2022/01/25 11:07:58 by gsap             ###   ########.fr       */
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
		}
		else
		{
			take_right_fork(vitals, data);
			take_left_fork(vitals, data);
		}
	}
	return ;
}

void	eat(t_philo *vitals, t_data *data)
{
	if (is_alive(vitals, data))
	{
		vitals->last = reset_time();
		print_info(*vitals, data, "is eating");
		usleep(data->t_eat * 1000);
		if (is_alive(vitals, data))
			vitals->eat++;
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
		drop_right_fork(vitals, data);
		drop_left_fork(vitals, data);
	}
	else
	{
		drop_left_fork(vitals, data);
		drop_right_fork(vitals, data);
	}
}

void	sleep_and_think(t_philo *vitals, t_data *data)
{
	if (is_alive(vitals, data))
	{
		print_info(*vitals, data, "is sleeping");
		usleep(data->t_sleep * 1000);
		if (is_alive(vitals, data))
		{
			if (vitals->pos % 2 == 1)
				usleep(data->t_die / 4);
			print_info(*vitals, data, "is thinking");
		}
	}
}
