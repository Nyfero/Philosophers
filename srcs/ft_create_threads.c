/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:12:37 by gsap              #+#    #+#             */
/*   Updated: 2022/01/10 17:54:14 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_threads(t_data *data)
{
	pthread_t	philo[data->n_philo];

	gettimeofday(&data->time.start, NULL);
	while (data->i < data->n_philo)
	{
		if ((pthread_create(philo + data->i, NULL, &ft_routine, &data)) != 0)
			return (0);
		usleep(10);
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
	//printf("%d\n", data.n_philo);
	/*while (1)
	{
		if ((data.i % 2) != 0)
			usleep(15);
		//mutex de mes forks et display de mes forks
		//ft_take_fork(data);
		//usleep du temps ou je mange et je remet a 0 mon temps de last meal et
		// display que je mange
		//ft_eat();
		//unlock mes mutex de forks et display du drop de mes forks
		//ft_drop_fork();
		//usleep de sleep et display de sleep
		//ft_sleep(data);
	}*/
	return (NULL);
}
