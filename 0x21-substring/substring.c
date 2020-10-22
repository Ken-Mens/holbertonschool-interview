#include "substring.h"

/**
 * find_substring - find all possible substrings
 * @s: is the string to scan
 * @words: array of substring fragments
 * @nb_words: is the number of elements in the array words
 * @n: holds the address at which to store the number
 * Return: array containing indexes
 */

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	char *temp_o, *foo;
	int slen, dict_len = 0, count = 0, regwordlen, l, m, k;
	int *pos_m = NULL;

	slen = strlen(s);
	regwordlen = strlen(words[0]);
	dict_len = regwordlen * nb_words;
	temp_o = calloc((dict_len + 1), sizeof(char));
	pos_m = calloc((slen + 1), sizeof(char));
    l = 0;
	for (; l <= (slen - dict_len);)
	{
		strncpy(temp_o, &s[l], dict_len);
        m = 0;
		for (; m < nb_words; m++)
		{
            k = 0;
			for (; k < dict_len;)
			{
				foo = strstr(temp_o + k, words[m]);
				if (foo != NULL && ((foo - temp_o) % regwordlen) == 0)
					break;
				else if (foo != NULL)
				{
					k = foo - temp_o + 1;
					foo = NULL;
				}
				else if (foo == NULL)
					goto last;
			}
			if (foo != NULL)
				memset(foo, '.', regwordlen);
			else
				goto last;
		}
		if (slen != 0 && dict_len != 0)
			pos_m[count++] = l;
last:
		l++;
	}
	*n = count;
	return (pos_m);
}
