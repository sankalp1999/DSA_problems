class Solution {
public:
    int flag  = 0;
//     void dfs(vector<vector<int>>& subsets, vector<int>& nums, int i, vector<int>& p)
//     {
//         if( i == nums.size())
//         {
//             subsets.push_back(p);
//             return;
//         }
//         p.push_back(nums[i]);
//         dfs(subsets, nums, i + 1, p);
//         p.pop_back(); // restore

//         // We need the 1+ occurences so they should be put in vector
//         // but in the same level of recursion, we should pick
//         // only the first occurence of the element
//         // That is how we avoid duplicates.
//         while(i + 1 < nums.size() && nums[i] == nums[i+1])i++;
        
//         // Here, we are already at the first occurence.
        
//         // not choosing or moving forward
//         dfs(subsets, nums, i + 1 , p);
//     }
    
      void dfs(vector<vector<int>>& subsets, vector<int>& nums, int ind, vector<int>& temp)
      {
          subsets.push_back(temp); // When i == nums.size(), it will skip for loop
          // so no base case is required.
          for(int i = ind; i < nums.size(); i++)
          {     
              // ALl first occurences are added here. (See i != ind)
              // When we return back and pop() and then go to next iteration
              // Then is the time to avoid
              // the duplicates.
              if(i != ind and nums[i] == nums[i - 1])continue;
              temp.push_back(nums[i]);
              dfs(subsets,nums,i+1,temp);
              temp.pop_back(); // Backtrack to previous state and let the for loop
              // do its job.
          }
      }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> subsets;
        vector<int> p;
        sort(nums.begin(), nums.end());
        dfs(subsets, nums, 0, p);
        return subsets;
    }
};
