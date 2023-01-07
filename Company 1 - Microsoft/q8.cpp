#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/most-profitable-path-in-a-tree/
//  There is an undirected tree with n nodes labeled from 0 to n - 1, rooted at node 0. You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

// At every node i, there is a gate. You are also given an array of even integers amount, where amount[i] represents:

// the price needed to open the gate at node i, if amount[i] is negative, or,
// the cash reward obtained on opening the gate at node i, otherwise.
// The game goes on as follows:

// Initially, Alice is at node 0 and Bob is at node bob.
// At every second, Alice and Bob each move to an adjacent node. Alice moves towards some leaf node, while Bob moves towards node 0.
// For every node along their path, Alice and Bob either spend money to open the gate at that node, or accept the reward. Note that:
// If the gate is already open, no price will be required, nor will there be any cash reward.
// If Alice and Bob reach the node simultaneously, they share the price/reward for opening the gate there. In other words, if the price to open the gate is c, then both Alice and Bob pay c / 2 each. Similarly, if the reward at the gate is c, both of them receive c / 2 each.
// If Alice reaches a leaf node, she stops moving. Similarly, if Bob reaches node 0, he stops moving. Note that these events are independent of each other.
// Return the maximum net income Alice can have if she travels towards the optimal leaf node

bool DFS(int src,int time,unordered_map<int,int> &path,vector<bool> &visited,vector<vector<int>> &graph)
{
    //this is the DFS of the path by bob, to indicate at what time would bob reach a node upto the root of the tree
    path[src] = time;

    visited[src] = true;

    if(src == 0 ){
        return true;
    }

    for(auto adj:graph[src]){
        if(!visited[adj]){
            if(DFS(adj,time+1,path,visited,graph)){
                return true;
            }
        }
    }

    //if this path is not considered then the node is removed
    path.erase(src);
    return false;
}

int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
{
    int n = edges.size() + 1;
    vector<vector<int>> graph(n);
    for (auto edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    // an unordered map to note the path taken by bob along with the time taken by bob to reach a particular node
    unordered_map<int, int> path;
    vector<bool> visited(n, false);

    DFS(bob, 0, path, visited, graph);

    queue<vector<int>> q;
    q.push({0, 0, 0});

    visited.assign(n,false);

    int ans = INT_MIN;
    while (!q.empty())
    {
        int src = q.front()[0];
        int time = q.front()[1];
        int income = q.front()[2];

        q.pop();

        visited[src] = true;

        if (path.find(src) == path.end())
        {
            income += amount[src];
        }

        else
        {
            if (time < path[src])
            {
                income += amount[src];
            }
            else if (time == path[src])
            {
                income += (amount[src] / 2);
            }
        }

        if (graph[src].size() == 1 && src != 0)
        {
            ans = max(ans, income);
        }

        for (auto adj : graph[src])
        {
            if (!visited[adj])
            {
                q.push({adj, time + 1, income});
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}