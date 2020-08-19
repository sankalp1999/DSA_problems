/*
Including snakes in the answer is also necessary since some shortest path might involve snake also. You never know.
I created a map for snakes and ladders and then assign the position manually.
*/
#include <bits/stdc++.h>

using namespace std;

// Complete the quickestWayUp function below.
int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
// I will not build a graph or should I build one?
    unordered_map<int,int> ladderMapper;
    unordered_map<int,int> snakeMapper;
    for(int i = 0; i < (int)ladders.size(); i++)
    {
        ladderMapper[ladders[i][0]] = ladders[i][1];
    }
    for(int i = 0; i < (int)snakes.size(); i++)
    {
        snakeMapper[snakes[i][0]] = snakes[i][1];
    }
    // BFS will do.
    queue<pair<int,int>> q;
    vector<int> visited(100,0);
    q.push({1,0});
    visited[1] = 1; // Don't forget visited array ever
    int min_moves = INT_MAX;

    while(!q.empty())
    {
        pair<int,int> curr = q.front();
        q.pop();
        if(curr.first == 100)
        {
            min_moves = min(min_moves, curr.second);
        }
        for(int i = 1; i <= 6; i++)
        {
            int newposition = curr.first + i;
         
            if(newposition > 100)break;
            if(snakeMapper.find(newposition) != snakeMapper.end())
            {
                newposition = snakeMapper[newposition];
            }
            if(ladderMapper.find(newposition) != ladderMapper.end() )
            {
                newposition = ladderMapper[newposition];
            }
            if(!visited[newposition] || newposition == 100) // If newposition is 100, we will still go otherwise we won't go if already visited.
        {   visited[newposition] = 1;
            q.push({newposition,curr.second + 1});
               }
        }
    }
    if(min_moves == INT_MAX)return -1;
    else return min_moves;


}

/*
Hackerrank Boilerplate below this point
*/
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> ladders(n);
        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> ladders[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> snakes(m);
        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> snakes[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = quickestWayUp(ladders, snakes);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
