class Trie {
public:
    
    class Node {
    public:
    char c;
    bool isWord;
    Node* children[26];
    int count;
    
    Node(char c)
    {
        this->c = c;
        isWord = false;
        for(int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        count = 0;
    }
    };
    Node* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node('\0'); // Init with null character
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* curr = root;
        for(char ch: word)
        {   
            // Check if node for current character exists or not.
            if(curr->children[ch - 'a'] == NULL)
            {
                curr->children[ch - 'a'] =  new Node(ch);
                 
            }
            // Now it exists.
            curr->count += 1;
            curr = curr->children[ch - 'a'];
           
        }
        curr->isWord = true; // mark since reached the last character of the word
    }
    
    string getNode(string s){
    string ans = "";
    auto node = root;
    for(char c:s){
        ans += c;
        if(node->children[c-'a']->count == 1){
            break;
        }
        node = node->children[c-'a'];
    }
    return ans;
}
};
vector<string> Solution::prefix(vector<string> &words) {
    
    Trie a;
    for(string word: words)
    {
        a.insert(word);
    }
    vector<string> res;
    for(int i = 0; i < words.size(); i++)
    {
        res.push_back(a.getNode(words[i]));
    }
    return res;
    
}
