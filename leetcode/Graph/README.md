### Detect A cycle in undirected graph
- All vertices will be covered in one dfs traversal. If we encounter an already visited node and it is 
  not the parent node, then we have got a cycle.
``` 
  if(visited[child] && child != node)
  {
    return true;
  }
```
### Detecting a cycle in Directed [graph](https://www.youtube.com/watch?v=Zuwp40mT66c&list=PLgUwDviBIf0rJ-OmpsTZTrv5dfGLR5eQS&index=6)
- All vertices may not be visited in one dfs(if the graph is not strongly connected)
- When you come across a vertex again in the current dfs traversal, then you have got a backedge and thus, a cycle.
  So, we maintain two visited arrays namely visited and recur array which keeps track of current dfs traversal visits.
