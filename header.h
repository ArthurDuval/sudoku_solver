#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>

typedef struct
{
	int	grid1[9][9];
	int	grid2[9][9];
	int	grid3[9][9];
} Sudoku;

void	store_grid(Sudoku *s, int (*grid)[9]);
void	display_grid(Sudoku *s, int is_finished);
void	display_process(Sudoku *s, int delay);
int	is_not_in_row(Sudoku *s, int r, int v);
int	is_not_in_col(Sudoku *s, int c, int v);
int	is_not_in_subgrid(Sudoku *s, int r, int c, int v);
int	can_be_placed(Sudoku *s, int r, int c, int v);
int	sudoku_solver(Sudoku *s, int r, int c, int delay);

#endif
