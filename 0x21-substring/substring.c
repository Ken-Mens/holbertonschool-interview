
#include "substring.h"

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    char *temp;
    int slen = strlen(s);
    int *pmark;
    int dictlen=0, count=0;
    char *p=NULL;
    int regwordlen = strlen(words[0]);
    dictlen=regwordlen*nb_words;
    temp = calloc((dictlen+1),sizeof(char));
        
    pmark = calloc((slen+1),sizeof(int));
    int i=0;
    for(; i<= (slen-dictlen);){
        strncpy(temp, &s[i],dictlen);
        for(int j=0; j< nb_words; j++){
     
            for(int k=0; k<dictlen ;){
                p=strstr(temp+k, words[j]);
                if(p!= NULL && ((p-temp) % regwordlen)==0)
                    break;
                else if(NULL!=p){
                    k=p-temp+1;
                    p=NULL;
                }else if(NULL==p)
                    goto nextseg;
                
            }
            
            if(NULL!=p )
                memset(p, '.', regwordlen);
            else
                goto nextseg;
            
        }
                
        if(slen!=0 && dictlen!=0)
            pmark[count++]=i;
nextseg:
        i++;
    }
   
    *n = count;
    
    return pmark;
}
