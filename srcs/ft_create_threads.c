/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:12:37 by gsap              #+#    #+#             */
/*   Updated: 2022/01/06 14:45:35 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_threads(t_data *data)
{
	pthread_t	philo[data->n_philo];

	write(1, "0\n", 2);
	gettimeofday(&data->time.start, NULL);
	write(1, "0\n", 2);
	while (data->i < data->n_philo)
	{
		write(1, "1\n", 2);
		if ((pthread_create(philo + data->i, NULL, &ft_routine, &data)) != 0)
			return (0);
		write(1, "2\n", 2);
		usleep(10);
		write(1, "3\n", 2);
		data->i++;
	}
	while (data->i < data->n_philo)
	data->i = 0;
	{
		if ((pthread_join(philo[data->i], NULL)) != 0)
			return (0);
		data->i++;
	}
	return (1);
}

void	*ft_routine(void *arg)
{
	t_data		data;

	data = *(t_data*)arg;
	while (1)
	{
		if ((data.i % 2) != 0)
			usleep(15);
		//mutex de mes forks et display de mes forks
		ft_take_fork(data);
		//usleep du temps ou je mange et je remet a 0 mon temps de last meal et
		// display que je mange
		//ft_eat();
		//unlock mes mutex de forks et display du drop de mes forks
		//ft_drop_fork();
		//usleep de sleep et display de sleep
		ft_sleep(data, data.i + 1);
	}
	return (NULL);
}
