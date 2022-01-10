/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:33:38 by gsap              #+#    #+#             */
/*   Updated: 2022/01/10 16:10:03 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_data data)
{
	pthread_mutex_lock(&data.mut_speak);
	print_time(data);
	printf(" is sleeping\n");
	pthread_mutex_unlock(&data.mut_speak);
	usleep(data.t_sleep);
	return ;
}
