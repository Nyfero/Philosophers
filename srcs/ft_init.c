/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:35:20 by gsap              #+#    #+#             */
/*   Updated: 2022/01/10 17:53:34 by gsap             ###   ########.fr       */
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
	if (argc == 6)
		data->n_eat = ft_atoi(argv[5]);
	data->i = 0;
	if (!(mutex_init(data)))
		return (0);
	philo_init(data);
	return (1);
}

void	philo_init(t_data *data)
{
	t_philo	philo[data->n_philo];
	int		i;

	i = 0;
	while (i < data->n_philo)
	{
		philo[i].pos = i + 1;
		philo[i].time = 0;
		philo[i].count = 0;
		philo[i].lfork = 0;
		philo[i].rfork = 0;
		i++;
	}
	return ;
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
