#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
// Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

// Return the shortest such subarray and output its length.

int findUnsortedSubarray(vector<int> &nums)
{
    int temp = INT_MAX, left = 0,right =0,n = nums.size();

    for (int i = n - 1; i >= 0; i--)
    {
        temp = min(temp,nums[i]);
        if(temp!=nums[i]) left = i;
    }

    temp = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        temp = max(temp,nums[i]);
        if(temp!=nums[i]) right = i;
    }

    return right==left?0:right-left+1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}