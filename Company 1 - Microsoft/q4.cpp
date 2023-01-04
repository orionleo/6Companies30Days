#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/rotate-function/
// You are given an integer array nums of length n.

// Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:

// F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
// Return the maximum value of F(0), F(1), ..., F(n-1).


int maxRotateFunction(vector<int> &nums)
{
    long long sum = 0, fn = 0;

    long long len = nums.size();

    for (int i = 0; i < len; i++)
    {
        sum += nums[i];
        fn += (i * nums[i]);
    }

    long long l = 1, r;
    long long newfn = fn;

    while(l<len){
        r = l+len-1;
        long removed = (l-1)*nums[l-1];
        long added = r*nums[r%len];

        newfn = newfn - removed + added - sum;

        fn = max(fn,newfn);
        l++;
    }

    return (int)fn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}