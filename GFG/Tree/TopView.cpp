/*
Print only the first level elements for each horizontal element in the vertical order traversal
*/



void dfs(struct Node* root,  unordered_map<int,map<int,set<int>>>& mapper, int x, int y, int& min_num, int& max_num)
{
    if(root == NULL)
        return ;
    dfs(root->left,mapper,x-1,y+1,min_num,max_num);
    dfs(root->right,mapper,x+1,y+1,min_num,max_num);
    min_num = min(min_num,x); // Leftmost x value
    max_num = max(max_num, x);// RightMost x value
    mapper[x][y].insert(root->data);
}



void topView(struct Node *root)
{
    unordered_map<int,map<int,set<int>>> mapper;
    int min_num, max_num;
    min_num = INT_MAX;
    max_num = INT_MIN;
    dfs(root, mapper, 0, 0, min_num ,max_num);
    
    for(int i = min_num; i <= max_num ; i++)
    {
        auto a_map = mapper[i]; // Get map acc. to horizontal level
        auto it = a_map.begin();
        {
            auto a_set = (*it).second;
            auto it2 = a_set.begin(); 
            cout << *it2 << " ";
        }
    }
}
