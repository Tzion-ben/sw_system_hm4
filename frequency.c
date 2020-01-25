#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "frequency.h"

/**
 * this method create at new trie node
 */
TrieNode *create()
{
    TrieNode *newTrieNode = (TrieNode*)malloc(sizeof(TrieNode));
    if (newTrieNode)
    {
        newTrieNode->letter = '\0';
        newTrieNode->count = 0;
        newTrieNode->childrenNum = 0;
        for (int i = 0; i < NUM_LETTERS; i++)
            newTrieNode->children[i] = NULL;
        newTrieNode->isWord = FALSE;
    }
    return newTrieNode;
} // end create

/**
  *this method puts the words at the trie
  */
void add(TrieNode *RootTrieNode, char inWord[])
{
    TrieNode *newTrie = RootTrieNode; //hold a reference to the root
    int length=strlen(inWord);
    for (int i = 0; i < length; i++)
    {
        //gets the location of the letter between 0 to 25
        int indexOfLetter = letterLocation(inWord[i]);
        if (indexOfLetter != -1)
        {
            if (!newTrie->children[indexOfLetter])//if(....==NULL)
            {
                TrieNode *tempNode=create();
                newTrie->children[indexOfLetter] = tempNode;
                //free(tempNode);

                newTrie->children[indexOfLetter]->letter=inWord[i];
                newTrie->childrenNum++;
            }
            //else //(....!=NUll)
            newTrie = newTrie->children[indexOfLetter];
        } //end if

        if (i == (length - 1))
        {
            newTrie->isWord = TRUE; //end of the word
            newTrie->count++;       //coubting the number of the words
        }// end if
    }//end for loop


} //end add

/*
    *if it is a small letter , else if it a bid letter convert it to same
    *location as a the same small' letter and ta the end if it is wrong
    *character it ignore it and returns -1
    */
int letterLocation(char ch)
{
    int askiOfLetter = ch;
    int index = 0;
    if (ch > 96 && ch < 123) //if it's a small letter
        index = askiOfLetter - 97;
    else if (ch > 64 && ch < 91) //else, conver it to small letter
        index = askiOfLetter - 65;
    else //else, the charcter is wornd input so ignore it and return -1
        return -1;

    return index;
} //end letterLocation

/**
*this method printing the words at the trie in lexicographly
*/
void upLixi(TrieNode *RootTrieNode,char *str,int index) {
    if(RootTrieNode->childrenNum==0){
        if(RootTrieNode->isWord==TRUE){
            str[index]='\0';
            printf("%s\t",str);
            printf("%ld\n",RootTrieNode->count);
            return;
        }
    }
    int i;
    for (i=0;i<NUM_LETTERS;i++){
        if (RootTrieNode->children[i]!=NULL) {
            str[index]=RootTrieNode->children[i]->letter;
            upLixi(RootTrieNode->children[i],str,index+1);
        }
    }
}

/**
*this method printing the words at the trie in reverse lexicographly
*/
void reLixi(TrieNode *RootTrieNode,char *str,int index) {
      if(RootTrieNode->childrenNum==0){
        if(RootTrieNode->isWord==TRUE){
            str[index]='\0';
            printf("%s\t",str);
            printf("%ld\n",RootTrieNode->count);
            return;
        }
    }
    int i;
    for (i=NUM_LETTERS-1;i>=0;i--){
        if (RootTrieNode->children[i]!=NULL) {
            str[index]=RootTrieNode->children[i]->letter;
            reLixi(RootTrieNode->children[i],str,index+1);
        }
    }
}


/**
*this method free all the trie
*/
void freeAll(TrieNode *RootTrieNode){
    int i;
    if(RootTrieNode->childrenNum==0){
            free(RootTrieNode);
            return;
    }
    else{
        for (i=0;i<NUM_LETTERS;i++){
            if (RootTrieNode->children[i]!=NULL) {
                freeAll(RootTrieNode->children[i]);
                RootTrieNode->childrenNum--;

            }
        }
        freeAll(RootTrieNode);
    }
}

