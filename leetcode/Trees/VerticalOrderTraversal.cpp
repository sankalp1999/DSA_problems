/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    
    
    void dfs(TreeNode* root,unordered_map<int,map<int,set<int>>>& mapper, int x, int y, int& min_num, int& max_num)
    {
        if(root == NULL)
            return;
        dfs(root->left, mapper,x - 1, y + 1, min_num, max_num);
        dfs(root->right,mapper,x+1, y + 1,min_num, max_num);
        mapper[x][y].insert(root->val);
        min_num = min(min_num, x);
        max_num = max(max_num,x);
        
    }
    
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // X and Y coordinates are there
        // We need x coordinates for the order of the vectors.
        // Y coordinates for top to bottom.
        // If same x and y, sorted order followed.
        
        // x values : y value from min height to max height
        unordered_map<int,map<int,set<int>>> mapper;
        int min_num = INT_MAX;
         int max_num = INT_MIN;
        vector<vector<int>> res;
        
        dfs(root, mapper,0, 0, min_num, max_num);
        for(int i = min_num; i <= max_num; i++)
        {
            auto pq = mapper[i];
            vector<int> p;
            for(auto it = pq.begin(); it != pq.end(); it++)
            {
                auto myset = (*it).second; // Inside map actually
                for(auto it2 = myset.begin(); it2 != myset.end(); it2++)
                {
                    p.push_back(*it2);
                }
            }
            res.push_back(p);
        }
        return res;
        
    }
};
