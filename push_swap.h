/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:38:05 by abdsebba          #+#    #+#             */
/*   Updated: 2025/01/07 00:28:24 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct push_swap
{
	int					content;
	int					index;
	int					flag;
	struct push_swap	*next;
}	t_node;

void	push_swap(t_node **a, t_node **b);
char	**ft_fix_arg(char **s, int ac);
char	**ft_split(const char *s, char c);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	assign_indexes(t_node *head);
t_node	*create_list(char **s, t_node *a);
long	ft_atoi(char *str);
char	*ft_strjoin1(char *s1, char *s2);
char	*ft_strdup(const char *s);
int		not_sorted(t_node *a);
t_node	*find_the_highest(t_node **a);
void	sorted_way(t_node **a);
void	handler_four(t_node **a, t_node **b);
void	handler_five(t_node **a, t_node **b);
void	ft_sec_algorithm(t_node **a, t_node **b);
void	ft_algorithm(t_node **head, t_node **b);

char	*get_next_line(int fd);
char	**ft_fix_args(char **s, int ac);
void	cammond(char *get_line, t_node **a, t_node **b);
int		ft_strcmp(char *s1, char *s2);
void	error_p(t_node **a, t_node **b, char *get_line);
char	*ft_strjoin(char *s1, char *s2);
void	checker_read(t_node *a, t_node *b, char **av, int ac);

int		ft_validarg(char **s, int ac);
int		ft_isdigit(int c);
int		ft_sign(int c);
int		check_duplicate(t_node *a, int nb);
int		check_argument(char *av);

void	push_ar(t_node **a, t_node **b, int flag);
void	ft_reverse_rotate(t_node **head, int flag);
void	rrr(t_node **a, t_node **b, int flag);
void	ft_rotate(t_node **head, int flag);
void	rr(t_node **a, t_node **b, int flag);
void	ft_swap_ar(t_node **head);
void	sa(t_node *a);
void	sb(t_node *b);
void	ss(t_node **a, t_node **b);

t_node	*ft_lstnew(int content, int index, int flag);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_back(t_node **lst, t_node *new);
int		ft_lstsize(t_node *lst);
void	ft_lstadd_front(t_node **lst, t_node *new);

void	ft_lstclear(t_node **lst);
void	free_succ(t_node *a, char **av);
void	free_succ1(t_node *a, t_node *b);
t_node	*error_free(t_node *a);

#endif