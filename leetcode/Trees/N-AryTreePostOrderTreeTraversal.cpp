

class Solution {
public:
    vector<int> postorder(Node* root) {
        
        
        stack<Node*> s;
        vector<int> res;
        
        if(root == NULL)return res;
        
        s.push(root);
        
        // Postorder is like doing preorder with first adding right and then left
        // And then reversign that sequence
        
        while(!s.empty())
        {
            auto it = s.top();
            s.pop();
            
            res.push_back(it->val);
            
            int _size = it->children.size();
            
            // Left to right will become right to left on reversing.
            for(int i = 0; i < _size; i++)
            {
                if(it->children[i])
                s.push(it->children[i]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};
