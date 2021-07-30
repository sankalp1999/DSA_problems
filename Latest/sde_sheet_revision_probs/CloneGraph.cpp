/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // 13 min first logic attempt
        unordered_map<Node*,Node*> graphMap;
        queue<Node*> q;
        Node* curr = node;
        if(node == NULL)
            return node;
        q.push(curr);
        // s.insert(curr);
        graphMap[curr] = new Node(curr->val);
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            for(auto it : node->neighbors)
            {
                if(graphMap.find(it) == graphMap.end())
                {
                    graphMap[it] = new Node(it->val);
                    q.push(it);
                }
                Node* temp = graphMap[it];
                temp->neighbors.push_back(graphMap[node]);
            }
            // How am i going to add curr node to it's neighbour
        }
        return graphMap[curr];
    }
};
