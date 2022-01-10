/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:33:38 by gsap              #+#    #+#             */
/*   Updated: 2022/01/05 13:52:06 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_data data, int i)
{
	pthread_mutex_lock(&data.mut.speak);
	print_time(data, i);
	printf(" is sleeping\n");
	pthread_mutex_unlock(&data.mut.speak);
	usleep(data.t_sleep);
	return ;
}
