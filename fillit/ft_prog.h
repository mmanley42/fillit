/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prog.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:54:10 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/07 14:17:35 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROG_H
# define FT_PROG_H

typedef	struct		s_forme
{
	char			**tab;
	char			myletter;
	size_t			xaxis;
	size_t			yaxis;
	size_t			content_size;
	struct s_forme	*next;
}					t_forme;
typedef	struct		s_coor
{
	unsigned int y;
	unsigned int x;
}					t_coor;
typedef	struct		bs_coor
{
	t_coor	sec_elem;
	t_coor	third_elem;
	t_coor	fourth_elem;
}					b_coor;
t_forme	*alpha_swap(int lettre, t_forme *elem);
//char		**backtrack_debut(t_forme **ptr_lst, int sizex, int sizey);
int		check_tetri(char *str, int start);
t_coor	check_pos_possible(t_forme *ptr);
t_forme	*coor_search(int test, t_forme *elem);
void	ft_lstadd_end(t_forme **alst, t_forme *new);
t_forme	*ft_lstmapi_f(t_forme *lst, t_forme *(*f)(int i, t_forme *elem), int i);
t_forme	*ft_lstnew_re(char **content, size_t content_size);
void	ft_lst_print(t_forme **alst);
char	**pos_tetri(t_forme **ptr_lst, char **tab, int xt, int yt, t_coor offset);
int		square_checker(char *s, int line, int col, int nbr);
int		square_checks(char *s, int line, int col, t_forme **ptr_lst);
t_coor	*tab_x_search(t_forme *elem);
t_coor	*tab_y_search(t_forme *elem);
int		tab_x_size(char **tab);
int		tab_y_size(char **tab);
int		whole_file_checking(char *str, int size);

#endif
