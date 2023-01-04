#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/course-schedule/
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

bool canFinish(int n, vector<vector<int>> &pre)
{
    vector<vector<int>> adj(n,vector<int>());

    vector<int> deg(n,0);

    for(auto &p:pre){
        adj[p[1]].push_back(p[0]);
        deg[p[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if(deg[i]==0) q.push(i);
    }

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        n--;
        for(auto next:adj[curr]){
            if(--deg[next]==0) q.push(next);
        }
    }
    

    return n==0;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}