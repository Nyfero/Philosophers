/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2022/01/10 17:41:25 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!(check_param(argc, argv)))
		return (ft_error("Error: argument\n"));
	if (!(init(&data, argc, argv)))
		return (ft_clean(&data) && ft_error("Error: init\n"));
	printf("%d\n", data.n_philo);
	if (!ft_create_threads(&data))
		return (ft_clean(&data) && ft_error("Error: thread\n"));
	ft_clean(&data);
	write(1, "end\n", 4);
	return (0);
}
