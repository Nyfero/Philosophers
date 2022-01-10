/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:42:41 by gsap              #+#    #+#             */
/*   Updated: 2022/01/10 16:44:25 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_time(t_data data)
{
	gettimeofday(&data.time.now, NULL);
	printf("%ld", (data.time.now.tv_usec - data.time.start.tv_usec)
	/ 1000);
	return ;
}
