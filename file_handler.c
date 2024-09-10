#include <fcntl.h>
#include "header.h"

#include <stdio.h>

int	open_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	return (fd);
}

char*	read_file(int fd)
{
	int	length;
	int	sz;
	char	*file_content;

	length = 18 * 9;
	file_content = (char*)malloc(length * sizeof(char));
	sz = read(fd, file_content, length);
	if (sz < 0)
	{
		free(file_content);
		return (NULL);
	}
	file_content[length - 1] = '\0';
	return (file_content);
}

int	close_file(int fd)
{
	return (close(fd));
}

Sudoku* str_to_grid(char *fc)
{
	int	i;
	int	j;
	int	k;
	Sudoku	*s;

	s = (Sudoku*)malloc(sizeof(Sudoku));
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (fc[k])
	{
		if (fc[k] == '\n')
		{
			i++;
			j = 0;		
		}
		else if (fc[k] != ' ')
		{
			s->grid1[i][j] = fc[k] - 48;
			s->grid2[i][j] = fc[k] - 48;
			s->grid3[i][j] = fc[k] - 48;
			j++;
		}
		k++;
	}
	return (s);
}

Sudoku*	file_handler(char *file_path)
{
	int	fd;
	char	*file_content;
	Sudoku	*s;

	fd = open_file(file_path);
	if (fd == -1)
		return (0);
	file_content = read_file(fd);
	close_file(fd);
	if (!file_content)
		return (0);
	s = str_to_grid(file_content);
	free(file_content);
	return (s);
}
