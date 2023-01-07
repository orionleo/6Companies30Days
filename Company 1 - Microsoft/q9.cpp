#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-pairs-satisfying-inequality/
//  You are given two 0-indexed integer arrays nums1 and nums2, each of size n, and an integer diff. Find the number of pairs (i, j) such that:

// 0 <= i < j <= n - 1 and
// nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.
// Return the number of pairs that satisfy the conditions.

void checkCount(vector<int> &nums, int start, int mid, int end, int diff, long long &count)
{
    int l = start, r = mid + 1;
    while (l <= mid && r <= end)
    {
        if (nums[l] <= nums[r] + diff)
        {
            //the elements which are on the left of right are the number of pairs satisfying the inequality
            count += (end - r + 1);
            l++;
        }
        else
        {
            r++;
        }
    }

    sort(nums.begin() + start, nums.begin() + end + 1);
    return;
}

void mergeSort(vector<int> &nums, int start, int end, int diff, long long &count)
{
    if(start == end) return;
    int mid = start + (end-start)/2;

    mergeSort(nums,start,mid,diff,count);
    mergeSort(nums,mid+1,end,diff,count);

    checkCount(nums,start,mid,end,diff,count);
    return;
}

long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff)
{
    long long count = 0;
    int n = nums1.size();
    vector<int> dif(n, 0);
    for (int i = 0; i < n; i++)
    {
        //create a new array with c[i]=a[i]-b[i], which comes after rearranging the inequality
        dif[i] = nums1[i] - nums2[i];
    }

    mergeSort(dif,0,n-1,diff,count);
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}