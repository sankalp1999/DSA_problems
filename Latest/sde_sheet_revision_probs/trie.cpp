


// class Trie
// {

//     Trie()
//     {
//         root = new node('\0');
//     }
//     public void insert(string& word)
//     {
//         node curr = root;
//         for(char c : word)
//         {
//             if(curr->children[c - 'a'] == NULL) // children are nodes.
//             {
//                 curr->children[c - 'a'] = new node(c);
//             }
//             // node already created now.
//             curr = curr->children[c - 'a']; // go down the children and keep inserting
//         }
//         curr.isWord = true;
//     }
    
//     public bool search(string word)
//     {
//         node temp = getNode(word);
//         return temp != NULL && temp.isWord;
//     }

//     public bool startsWith(string prefix)
//     {
//         node temp = getNode(word);
//         return temp != NULL;
//     }

//     public Node getNode(string& word)
//     {
//         node curr = root;
//         for (int i = 0; i < word.length; i++)
//         {
//             char c = word[i];
//             if(curr->children[c - 'a'] == NULL)
//             {
//                 return NULL; 
//             }
//             curr = curr->children[c - 'a'];
//         }
//         return curr; // that particular word is present if you come to this point.
//     }
// };


// class node()
// {   
//     char c;
//     node children[26];
//     bool isWord = true;
    
//     public node(char c)
//     {
//         this.c = c;
//         isWord = false;
//         children = new node[26];
//     }
// }


#include <bits/stdc++.h>
using namespace std;

class Trie{
    public:
    class TrieNode
    {   
        public:
        char c;
        TrieNode* children[26];
        bool isWord;
        TrieNode(char c)
        {
            isWord = false;
            this->c  = c;
            for(int i = 0; i < 26; i++)
            {
            children[i] = NULL;
            }
        }
    };
    TrieNode* root;
    Trie()
    {
        root = new TrieNode('*');
    }
    
    void insert(string word)
    {
        TrieNode* curr = root;
        for(char ch : word)
        {
            if(curr->children[ch - 'a'] == NULL)
            {
                curr->children[ch - 'a'] = new TrieNode(ch);
            }
            curr = curr->children[ch - 'a'];
        }
        curr->isWord = true;
    }
    
    TrieNode* getlastnode(string word)
    {
        TrieNode* curr = root;
        for(char ch : word)
        {
            if(curr->children[ch - 'a']  == NULL)
            {
                return NULL;
            }
            curr = curr->children[ch - 'a'];
        }
        return curr;
    }
    
    
    void recurse(string& temp, TrieNode* curr)
    {
       
        
        for(int i = 0; i < 26; i++)
        {
            if(curr->children[i])
            {
                curr = curr->children[i];
                temp.push_back(curr->c);
                recurse(temp, curr);
            }
        }
    }
    
    vector<string> give_word(string prefix)
    {
        TrieNode* temp =  getlastnode(prefix);
        TrieNode* curr = temp;
        
        vector<string> answer;
        for(int i = 0; i < 26; i++)
        {
            if(curr->children[i])
            {
                string could_be = prefix;
                recurse(could_be, temp);
                answer.push_back(could_be);
            }
        }
        return answer;
        
    }
    
    
};