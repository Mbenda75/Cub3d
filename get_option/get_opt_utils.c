#include "option.h"

int count(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	return (count);
}