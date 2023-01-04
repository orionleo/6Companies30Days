#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/perfect-rectangle/
//Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle. The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).
// Return true if all the rectangles together form an exact cover of a rectangular region.

bool isRectangleCover(vector<vector<int>> &rectangles)
{
    unordered_map<long long,int> mp;
    const long long N = 1000000;

    for(auto x:rectangles){
        int x1 = x[0];
        int y1 = x[1];
        int x2 = x[2];
        int y2 = x[3];
        //points (x1,y1) and (x2,y2) will be added to the points and accordingly will be cancelled out if some other rectangle corner is overlapping with them
        mp[x1*N+y1]++;
        mp[x1*N+y2]--;
        mp[x2*N+y2]++;
        mp[x2*N+y1]--;
    }

    int n_mark= 0;
    for(auto pr = mp.begin();pr!=mp.end();pr++){
        if(pr->second!=0){
            if(abs(pr->second)!=1) return false;//if a corner has been counted twice , that means there is some overlapping
            n_mark++;
        }
    }

    return n_mark==4;//if the corners are 4, then there is a closed rectangle
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}