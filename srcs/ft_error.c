/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:06:33 by gsap              #+#    #+#             */
/*   Updated: 2022/01/05 16:30:29 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *strerr)
{
	ft_putstr_fd(2, strerr);
	return (1);
}

int	ft_clean(t_data data)
{
	int	i;

	if (data.philo)
		free(data.philo);
	if (data.mut.fork)
	{
		i = 0;
		while (i < data.n_philo)
			pthread_mutex_destroy(&data.mut.fork[i++]);
		free(data.mut.fork);
	}
	pthread_mutex_destroy(&data.mut.speak);
	pthread_mutex_destroy(&data.mut.death);
	return (1);
}
