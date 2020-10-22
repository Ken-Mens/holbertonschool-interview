
#include "substring.h"

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    char *temp;
    int s_len = strlen(s);
    int *p_mark, dictlen = 0, count = 0, regwordlen = strlen(words[0]);
    char *p=NULL;
    dictlen=regwordlen*nb_words;
    temp = calloc((dictlen+1),sizeof(char));
        
    p_mark = calloc((s_len+1),sizeof(int));
    for(int i = 0; i<= (s_len-dictlen);){
        strncpy(temp, &s[i],dictlen);
        for(int j = 0; j< nb_words; j++){

            for(int k = 0; k<dictlen ;)
            {
                p = strstr(temp+k, words[j]);
                if(p!= NULL && ((p-temp) % regwordlen)==0)
                    break;
                else if(NULL!=p){
                    k = p-temp ++;
                    p = NULL;
                }else if(NULL == p)
                    goto nextseg;       
            }
            
            if(NULL!=p )
                memset(p, '.', regwordlen);
            else
                goto nextseg;           
        }
                
        if(s_len!=0 && dictlen!=0)
            p_mark[count++]=i;
nextseg:
        i++;
    }  
    *n = count;

    return p_mark;
}
