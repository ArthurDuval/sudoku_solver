#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct
{
	int	grid1[9][9];
	int	grid2[9][9];
	int	grid3[9][9];
} Sudoku;

Sudoku*	file_handler(char *file_path);
void	store_grid(Sudoku *s, int (*grid)[9]);
void	display_grid(Sudoku *s, int is_finished);
int	sudoku_solver(Sudoku *s, int r, int c, int delay);

#endif
