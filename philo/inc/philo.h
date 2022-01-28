/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:37:00 by gsap              #+#    #+#             */
/*   Updated: 2022/01/28 11:20:50 by gsap             ###   ########.fr       */
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

struct	s_data;

typedef struct s_time
{
	struct timeval	now;
}	t_time;

typedef struct s_philo
{
	int				pos;
	int				forks;
	long int		now;
	long int		last;
	long int		eat;
	long int		sleep;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	t_time			time;
	long int		start;

	pthread_mutex_t	mut_speak;
	pthread_mutex_t	mut_death;
	pthread_mutex_t	*mut_fork;
	t_philo			*vitals;

	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;

	size_t			eat;
	int				end;
	int				i;
}	t_data;

//	main.c
int			main(int argc, char **argv);

//	ft_init.c
int			check_param(int argc, char **argv);
int			init(t_data *data, int argc, char **argv);
t_philo		*philo_init(t_data *data);
int			mutex_init(t_data *data);

//  ft_error.c
int			ft_error(char *strerr);
int			clean(t_data *data);

//	ft_utils.c
long int	long_value(int j, unsigned long long int res);
long int	ft_atoi(const char *str);
int			ft_strlen(char *str);
void		ft_putstr_fd(int fd, char *str);
int			ft_isdigit(int c);

//  ft_create_threads.c
int			create_threads(t_data *data);
void		*routine(void *arg);

//	ft_display.c
void		print_info(t_philo vitals, t_data *data, char *str);
void		print_dead(t_philo vitals, t_data *data);

//	ft_eat.c
void		take_fork(t_philo *vitals, t_data *data);
void		eat(t_philo *vitals, t_data *data);
void		drop_fork(t_philo *vitals, t_data *data);
void		sleep_and_think(t_philo *vitals, t_data *data);

//	ft_eat_utils.c
long int	reset_time(void);
int			is_alive(t_philo *vitals, t_data *data);
void		*one_philo(t_philo *vitals, t_data *data);

//	ft_forks_utils.c
void		take_left_fork(t_philo *vitals, t_data *data);
void		take_right_fork(t_philo *vitals, t_data *data);
void		drop_left_fork(t_philo *vitals, t_data *data);
void		drop_right_fork(t_philo *vitals, t_data *data);

#endif
