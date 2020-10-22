#include "substring.h"

/**
 * find_substring - finds possible substrings
 * @s: is the string to scan
 * @words: array of substring must be concatenated
 * @nb_words: number of elements in array words
 * @n: holds address to store number of elements
 * Return: array containing indexes
 */

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    char *temp = NULL, *p = NULL;
    int *p_mark, dict_len = 0, count = 0, regwordlen = strlen(words[0]), s_len = strlen(s);;
    dict_len =regwordlen*nb_words;
    temp = calloc((dict_len+1),sizeof(char));       
    p_mark = calloc((s_len+1),sizeof(int));
    for(int i = 0; i <= (s_len-dict_len);){
        strncpy(temp, &s[i],dict_len);
        for(int j = 0; j< nb_words; j++)
        {
            for(int k = 0; k<dict_len ;)
            {
                p = strstr(temp+k, words[j]);
                if(p!= NULL && ((p-temp) % regwordlen)==0)
                    break;
                else if(NULL!=p){
                    k = p-temp ++;
                    p = NULL;
                }else if(NULL == p)
                    goto foo;       
            }          
            if(NULL != p )
                memset(p, '.', regwordlen);
            else
                goto foo;           
        }
                
        if(s_len!=0 && dict_len!=0)
            p_mark[count++]=i;
foo:
        i++;
    }  
    *n = count;

    return p_mark;
}
