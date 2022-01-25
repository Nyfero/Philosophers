/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forks_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:06:40 by gsap              #+#    #+#             */
/*   Updated: 2022/01/25 10:36:14 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_left_fork(t_philo *vitals, t_data *data)
{
	pthread_mutex_lock(&data->mut_fork[(vitals->pos - 1 + data->n_philo)
		% data->n_philo]);
	print_info(*vitals, data, "has taken a fork");
	return ;
}

void	take_right_fork(t_philo *vitals, t_data *data)
{
	pthread_mutex_lock(&data->mut_fork[(vitals->pos - 2 + data->n_philo)
		% data->n_philo]);
	print_info(*vitals, data, "has taken a fork");
}

void	drop_left_fork(t_philo *vitals, t_data *data)
{
	pthread_mutex_unlock(&data->mut_fork[(vitals->pos - 1 + data->n_philo)
		% data->n_philo]);
	return ;
}

void	drop_right_fork(t_philo *vitals, t_data *data)
{
	pthread_mutex_unlock(&data->mut_fork[(vitals->pos - 2 + data->n_philo)
		% data->n_philo]);
	return ;
}
