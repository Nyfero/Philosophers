/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:37:00 by gsap              #+#    #+#             */
/*   Updated: 2022/01/06 14:41:10 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int	pos;
	int	time;
	int	count;
	int	lfork;
	int	rfork;
}	t_philo;

typedef struct s_time
{
	struct timeval	start;
	struct timeval	now;
}	t_time;

typedef struct s_mutex
{
	pthread_mutex_t	speak;
	pthread_mutex_t	death;
	pthread_mutex_t	*fork;
}	t_mutex;

typedef struct s_data
{
	t_time	time;
	t_mutex	mut;
	t_philo	*philo;

	int	n_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	n_eat;

	int		i;
}	t_data;

//	philo.c
int			main(int argc, char **argv);

//	ft_init.c
int			ft_isdigit(int c);
int			check_param(int argc, char **argv);
int			init(t_data *data, int argc, char **argv);
void		philo_init(t_data *data);
int			mutex_init(t_data *data);

//  ft_error.c
int			ft_error(char *strerr);
int			ft_clean(t_data data);

//	ft_str_u.tils.c
int			ft_strlen(char *str);
void		ft_putstr_fd(int fd, char *str);

//  ft_atoi.c
long int	long_value(int j, unsigned long long int res);
long int	ft_atoi(const char *str);

//  ft_create_threads.c
int			ft_create_threads(t_data *data);
void		*ft_routine(void *arg);

//	ft_get_time.c
void		print_time(t_data data, int i);

//	ft_sleep.c
void		ft_sleep(t_data data, int i);

//	ft_eat.c
void		ft_take_fork(t_data data);

#endif
