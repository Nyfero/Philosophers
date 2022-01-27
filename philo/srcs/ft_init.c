/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:35:20 by gsap              #+#    #+#             */
/*   Updated: 2022/01/27 17:14:34 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_param(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit((int)argv[i][j]) == 0)
				return (0);
			j++;
		}
		if (ft_atoi(argv[i]) > 2147463647)
			return (0);
		i++;
	}
	if (argc != 5 && argc != 6)
		return (0);
	return (1);
}

int	init(t_data *data, int argc, char **argv)
{
	data->n_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->n_eat = -1;
	data->eat = 0;
	if (argc == 6)
		data->n_eat = ft_atoi(argv[5]);
	data->i = 0;
	data->end = 0;
	if (!(mutex_init(data)))
		return (0);
	gettimeofday(&data->time.now, NULL);
	data->start = (data->time.now.tv_sec * 1000000
			+ data->time.now.tv_usec) / 1000;
	data->vitals = philo_init(data);
	if (!data->vitals)
		return (0);
	return (1);
}

t_philo	*philo_init(t_data *data)
{
	t_philo	*vitals;
	int		i;

	i = 0;
	vitals = (t_philo *)malloc(sizeof(t_philo) * data->n_philo);
	if (!vitals)
		return (NULL);
	while (i < data->n_philo)
	{
		vitals[i].pos = i + 1;
		vitals[i].eat = 0;
		vitals[i].data = data;
		vitals[i].last = data->start;
		vitals[i].now = data->start;
		vitals[i].sleep = data->start;
		vitals[i].forks = 0;
		i++;
	}
	return (vitals);
}

int	mutex_init(t_data *data)
{
	int	i;

	pthread_mutex_init(&data->mut_speak, NULL);
	pthread_mutex_init(&data->mut_death, NULL);
	i = 0;
	while (i < data->n_philo)
		pthread_mutex_init(&data->mut_fork[i++], NULL);
	return (1);
}
