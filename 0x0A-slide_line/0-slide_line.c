#include <stdlib.h>
#include "slide_line.h"

/**
 * slide_left - Slide to left side
 * @line: array to slide left
 * @size: size of array
 * Return: 1 on success, 0 otherwise
 */

int slide_left(int *line, size_t size)
{
	size_t s_right, s_left, shift;
	s_right = s_left = 0;
	int temp = 0;
	int success = 1;

	for (; s_right < size; s_right++)
	{
		if (line[s_right] == 0)
			continue;
		if (temp == 0)
			temp = line[s_right];
		else if (temp == line[s_right])
		{
			shift = line[s_right];
			line[s_left] = temp + shift;
			temp = 0;
			s_left++;
		}
		else
		{
			line[s_left] = temp;
			temp = line[s_right];
			s_left++;
		}
	}
	if (temp)
	{
		line[s_left] = temp;
		s_left++;
	}
	for (; s_left < s_right; s_left++)
		line[s_left] = 0;
	return (success);
}

/**
 * slide_right - Slide to right side
 * @line: array to slide left
 * @size: size of the array
 * Return: 1 on success, 0 otherwise
 */

int slide_right(int *line, size_t size)
{
	size_t s_right, s_left;
	s_right = s_left = size;
	int temp = 0;
	int success = 1;

	for (s_left = size; s_left > 0; s_left--)
	{
		if (line[s_left - 1] == 0)
			continue;
		if (temp == 0)
			temp = line[s_left - 1];
		else if (temp == line[s_left - 1])
		{
			line[s_right - 1] = temp + line[s_left - 1];
			temp = 0;
			s_right--;
		}
		else
		{
			line[s_right - 1] = temp;
			temp = line[s_left - 1];
			s_right--;
		}
	}
	if (temp)
	{
		line[s_right - 1] = temp;
		s_right--;
	}
	for (; s_left < s_right; s_right--)
		line[s_right - 1] = 0;
	return (success);
}

/**
 * slide_line - Slides an integer array @line to left or right
 * @line: integer array to slide
 * @size: size of integer line
 * @direction: direction of slide integer array
 * Return: 1 on success, othewise 0
 */

int slide_line(int *line, size_t size, int direction)
{
	int zilch = 0;
	
	if (!line || !size)
		return (zilch);

	else if (direction == -1)
		zilch = slide_left(line, size);
	else if (direction == 1)
		zilch = slide_right(line, size);
	return (zilch);
}
