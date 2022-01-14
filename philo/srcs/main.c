/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2022/01/14 10:54:08 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!(check_param(argc, argv)))
		return (ft_error("Error: argument\n"));
	if (!(init(&data, argc, argv)))
		return (clean(&data) && ft_error("Error: init\n"));
	if (!create_threads(&data))
		return (clean(&data) && ft_error("Error: thread\n"));
	clean(&data);
	write(1, "end\n", 4);
	return (0);
}
