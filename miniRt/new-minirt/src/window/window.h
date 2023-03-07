#ifndef WINDOW_H
# define WINDOW_H

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*addr;
	int		b;
	int		ll;
	int		end;
}	t_window;

void	ft_my_mlx_pxput(t_window *mlx, int x, int y, int colour);

#endif
