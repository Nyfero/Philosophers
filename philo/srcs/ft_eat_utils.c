/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:30:08 by gsap              #+#    #+#             */
/*   Updated: 2022/01/26 14:11:10 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	pthread_mutex_lock(&data->mut_death);
	vitals->now = reset_time();
	if (vitals->now - vitals->last < data->t_die)
	{
		pthread_mutex_unlock(&data->mut_death);
		return (1);
	}
	else
	{
		print_dead(*vitals, data);
		data->end = 1;
		pthread_mutex_unlock(&data->mut_death);
		return (0);
	}
}

void	*one_philo(t_philo *vitals, t_data *data)
{
	take_left_fork(vitals, data);
	while (is_alive(vitals, data))
		usleep(100);
	drop_left_fork(vitals, data);
	return (NULL);
}

void	split_eating_time(t_philo *vitals, t_data *data)
{
	int	i;

	i = 0;
	while (is_alive(vitals, data) && i != data->t_eat / 5)
	{
		usleep(5000);
		i++;
	}
	return ;
}

void	insomnia(t_philo *vitals, t_data *data)
{
	int	i;

	i = 0;
	while (is_alive(vitals, data) && i != data->t_sleep / 5)
	{
		usleep(5000);
		i++;
	}
	return ;
}
