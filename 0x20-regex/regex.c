#include "regex.h"

/**
* regex_match - matches patterns with string
* @str: string
* @pattern: pattern which contains alphabetic chars, wildcard, and '.'
* Return: 1 if true, 0 if false
*/
int regex_match(char const *str, char const *pattern)
{
	int zilch = 0;

	if (!str)
		return (zilch);
	if (!*str)
	{
		if (*(pattern + 1) == '*')
			return (regex_match(str, pattern + 2));
		return (!*pattern);
	}
	if (*(pattern + 1) == '*')
	{
		if (*pattern == '.' || *pattern == *str)
			return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
		return (regex_match(str, pattern + 2));
	}
	if (*pattern == '.' || *pattern == *str)
	{
		return (regex_match(str + 1, pattern + 1));
	}
	return (zilch);
}
