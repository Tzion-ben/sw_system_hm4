#ifndef frequency
#define frequency
#define NUM_LETTERS ((int)26)
#define WORD 300

typedef enum {FALSE=0, TRUE=1} boolean;

typedef struct TrieNode {
    char letter;
    long unsigned int count;
    int childrenNum;
    struct  TrieNode* children[NUM_LETTERS];
    boolean isWord;//if some node is last letter at the word then true
} TrieNode;

TrieNode *create();
void add(TrieNode *trieNode, char inWord []);
int letterLocation(char ch);
void upLixi(TrieNode *RootTrieNode,char *str,int index);
void delete (TrieNode *trieNode);
void isWord(TrieNode *trieNode,int i);
void reLixi(TrieNode *RootTrieNode,char *str,int index);
void freeAll(TrieNode *RootTrieNode);

#endif //frequency