/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:42:41 by gsap              #+#    #+#             */
/*   Updated: 2022/01/13 17:46:23 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_info(t_philo vitals, t_data *data, char *str)
{
	long int	time;

	pthread_mutex_lock(&data->mut_death);
	if (data->end == 0)
	{
		time = reset_time() - data->start;
		pthread_mutex_lock(&data->mut_speak);
		printf("%ld %d %s\n", time, vitals.pos, str);
		pthread_mutex_unlock(&data->mut_speak);
	}
	pthread_mutex_unlock(&data->mut_death);
}