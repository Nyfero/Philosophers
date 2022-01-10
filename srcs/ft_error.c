/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:06:33 by gsap              #+#    #+#             */
/*   Updated: 2022/01/10 16:09:26 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *strerr)
{
	ft_putstr_fd(2, strerr);
	return (1);
}

int	ft_clean(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
		pthread_mutex_destroy(&data->mut_fork[i++]);
	pthread_mutex_destroy(&data->mut_speak);
	pthread_mutex_destroy(&data->mut_death);
	return (1);
}
