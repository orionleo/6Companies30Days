#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/combination-sum-iii/
// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

vector<vector<int>> ans;

int sum(vector<int> &comb)
{
    int total = 0;
    for (auto x : comb)
    {
        total += x;
    }
    return total;
}

void helper(int k, int n, vector<int> &comb, int num)
{

    if (k == 0)
    {
        if (sum(comb) == n)
        {
            ans.push_back(comb);
        }
        return;
    }
    // if the number to be added becomes more than 9, than the recursion needs to be stopped.
    if (num > 9)
        return;

    comb.push_back(num); // including num in the sum
    helper(k - 1, n, comb, num + 1);
    comb.pop_back(); // not including num in the sum
    helper(k, n, comb, num + 1);
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<int> comb;
    helper(k, n, comb, 1);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}