/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> s;
        s.push(root);
        vector<int> res;
        if(root == NULL)
        {
            return res;
        }
        while(!s.empty())
        {
            auto it = s.top();
            res.push_back(it->val);
            s.pop();
            
            int _size = it->children.size();
            for(int i = _size - 1; i >= 0; i--)
            {
                if(it->children[i] != NULL)
                s.push(it->children[i]);
            }
        }
        return res;
    }
};
