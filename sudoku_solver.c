#include <unistd.h>
#include "header.h"

void	store_grid(Sudoku *s, int (*grid)[9])
{
	int	i;
	int	j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			s->grid1[i][j] = grid[i][j];
			s->grid2[i][j] = grid[i][j];
			s->grid3[i][j] = grid[i][j];
			j++;
		}
		i++;
	}
}

void	display_grid(Sudoku *s, int is_finished)
{
	int	i;
	int	j;

	printf("\033[2J");
	printf("\033[H");
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (s->grid3[i][j] != 0)
			{
				if (s->grid1[i][j] == s->grid3[i][j])
					printf("%i", s->grid1[i][j]);
				else if (is_finished)
					printf("\033[32m%i\033[0m", s->grid3[i][j]);
				else
					printf("\033[33m%i\033[0m", s->grid3[i][j]);
			}
			else
			{
				if (s->grid2[i][j] != 0)
					printf("\033[31m.\033[0m");
				else
					printf(".");
			}
			if (j == 2 || j == 5)
				printf(" | ");
			else if (j != 8)
				printf(" ");
			else
				printf("\n");
			j++;
		}
		if (i == 2 || i == 5)
			printf("------+-------+------\n");
		i++;
	}
}

void	display_process(Sudoku *s, int delay)
{
	if (delay)
		display_grid(s, 0);
	usleep(delay);
}

int	is_not_in_row(Sudoku *s, int r, int v)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (s->grid3[r][i] == v)
			return (0);
		i++;
	}
	return (1);
}

int	is_not_in_col(Sudoku *s, int c, int v)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (s->grid3[i][c] == v)
			return (0);
		i++;
	}
	return (1);
}

int	is_not_in_subgrid(Sudoku *s, int r, int c, int v)
{
	int	subgrid_row;
	int	subgrid_col;
	int	i;
	int	j;

	subgrid_row = (r / 3) * 3;
	subgrid_col = (c / 3) * 3;
	i = subgrid_row;
	while (i < (subgrid_row + 3))
	{
		j = subgrid_col;
		while (j < (subgrid_col + 3))
		{
			if (s->grid3[i][j] == v)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	can_be_placed(Sudoku *s, int r, int c, int v)
{
	if (is_not_in_row(s, r, v) && is_not_in_col(s, c, v)
					&& is_not_in_subgrid(s, r, c, v))
		return (1);
	return (0);
}

int	sudoku_solver(Sudoku *s, int r, int c, int delay)
{
	int	i;

	if (r == 9)
		return (1);
	else if (c == 9)
		return (sudoku_solver(s, r + 1, 0, delay));
	else if (s->grid3[r][c] != 0)
		return (sudoku_solver(s, r, c + 1, delay));
	else
	{
		i = 1;
		while (i <= 9)
		{
			if (can_be_placed(s, r, c, i))
			{
				s->grid2[r][c] = s->grid3[r][c];
				s->grid3[r][c] = i;
				display_process(s, delay);
				if (sudoku_solver(s, r, c + 1, delay))
					return (1);
				s->grid2[r][c] = s->grid3[r][c];
				s->grid3[r][c] = 0;
				display_process(s, delay);
			}
			i++;
		}
	}
	return (0);
}
