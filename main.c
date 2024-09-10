#include "header.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!s2[i] || s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	delay;
	int	grid[9][9] = {
		{ 3, 0, 6, 5, 0, 8, 4, 0, 0 },
		{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
		{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
		{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
		{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
		{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
		{ 0, 0, 5, 2, 0, 6, 3, 0, 0 }
	};
	Sudoku sudoku;

	store_grid(&sudoku, grid);
	delay = 300000;
	if (argc > 1 && ft_strcmp(argv[1], "fast"))
		delay = 10000;
	else if (argc > 1 && ft_strcmp(argv[1], "no_delay"))
		delay = 0;
	if (sudoku_solver(&sudoku, 0, 0, delay))
	{
		display_grid(&sudoku, 1);
		printf("\n    \033[32mSudoku solved!\033[0m\n\n");
	}
	else
		printf("\n    \033[31mInvalid Sudoku grid.\033[0m\n\n");
	return (0);
}
