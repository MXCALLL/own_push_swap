/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:03:25 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/26 15:37:44 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../mandatory/push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

typedef struct s_op_list
{
	char				*op;
	struct s_op_list	*next;
}	t_op_list;

char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, const char *s2);
char		*ft_strchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		do_operations(t_stack **stack_a, t_stack **stack_b, t_args args);
int			perform_operation(char *op, t_stack **stack_a, t_stack **stack_b);
void		ft_check(char **argv);
int			ft_isdigit(int c);
int			is_valid_op(char *op);
t_op_list	*add_to_list(t_op_list *list, char *op);
void		exec_op(t_stack **stack_a, t_stack **stack_b, t_op_list *list);

#endif