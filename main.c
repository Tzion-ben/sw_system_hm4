#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "frequency.h"
#define WORD 30

int main(int argc, char* const argv[]){
    TrieNode *rootTrie=create();//create the root to be empty node

    //running through file and reading it
    char wordF[WORD] = {'\0'};
    int iRun = 0;
    int ch = 0;
    while ((ch = getchar()) != EOF)
    {
        if ((ch != '\n') && (ch != '\t') && (ch != ' '))
        {
            wordF[iRun] = ch;
            iRun++;
            
        }
        //gut a word so send it to the trie 
        else{
            //printf("%s\n",wordF);
            add(rootTrie, wordF);
            int len=strlen(wordF);
            for(int i=0;i<len;i++){
                wordF[i]='\0';
            }
            iRun=0; 
        }
    }
    static char *str [WORD];
    if((argc>1)&&(*argv[1] == 'r')){  
        reLixi(rootTrie,str,0);
    }
    else if(argc==1)
        upLixi(rootTrie,str,0);
    
    freeAll(rootTrie);
    //free(rootTrie);
    return 0;
}