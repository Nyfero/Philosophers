/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:12:37 by gsap              #+#    #+#             */
/*   Updated: 2022/01/11 18:01:50 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_threads(t_data *data)
{
	pthread_t	philo[data->n_philo];

	gettimeofday(&data->time.start, NULL);
	while (data->i < data->n_philo)
	{
		if ((pthread_create(philo + data->i, NULL, &ft_routine,
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

void	*ft_routine(void *arg)
{
	t_data		*data;
	t_philo		vitals;

	vitals = *(t_philo*)arg;
	data = vitals.data;
	if ((vitals.pos % 2) == 1)
	usleep(100);
	//while (1)
	//{
		//mutex de mes forks et display de mes forks
		pthread_mutex_lock(&data->mut_speak);
		printf("philo[%d]:\n", vitals.pos);
		printf("\t%d\n", data->n_philo);
		printf("\t%d\n", data->t_die);
		printf("\t%d\n", data->t_eat);
		printf("\t%d\n", data->t_sleep);
		printf("\t%d\n", data->n_eat);
		printf("\t%d\n", vitals.time);
		printf("\t%d\n", vitals.count);
		printf("\t%d\n", vitals.lfork);
		printf("\t%d\n", vitals.rfork);
		printf("\n-----\n");
		pthread_mutex_unlock(&data->mut_speak);
		//ft_take_fork(data);
		//usleep du temps ou je mange et je remet a 0 mon temps de last meal et
		// display que je mange
		//ft_eat();
		//unlock mes mutex de forks et display du drop de mes forks
		//ft_drop_fork();
		//usleep de sleep et display de sleep
		//ft_sleep(data);
	//}
	return (NULL);
}
