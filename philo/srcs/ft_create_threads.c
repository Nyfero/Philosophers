/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:12:37 by gsap              #+#    #+#             */
/*   Updated: 2022/01/27 13:37:16 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_data *data)
{
	pthread_t	philo[200];

	while (data->i < data->n_philo)
	{
		if ((pthread_create(philo + data->i, NULL, &routine,
					&data->vitals[data->i++])) != 0)
			return (0);
	}
	data->i = 0;
	while (data->i < data->n_philo)
	{
		if ((pthread_join(philo[data->i], NULL)) != 0)
			return (0);
		data->i++;
	}
	return (1);
}

void	*routine(void *arg)
{
	t_data		*data;
	t_philo		vitals;

	vitals = *(t_philo *)arg;
	data = vitals.data;
	if (data->n_philo == 1)
		return (one_philo(&vitals, data));
	if ((vitals.pos % 2) == 1)
		usleep(150);
	while (1)
	{
		pthread_mutex_lock(&data->mut_death);
		if (data->end == 1 || (vitals.eat >= data->n_eat
				&& data->eat >= (size_t)(data->n_eat * data->n_philo)))
		{
			pthread_mutex_unlock(&data->mut_death);
			return (NULL);
		}
		pthread_mutex_unlock(&data->mut_death);
		take_fork(&vitals, data);
		eat(&vitals, data);
		drop_fork(&vitals, data);
		sleep_and_think(&vitals, data);
	}
	return (NULL);
}
