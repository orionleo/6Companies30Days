#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/largest-divisible-subset/
// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    int n = nums.size();
    if(n==0) return nums;
    vector<int> ans;
    
    //sort the nums arr to compare only bigger elements to smaller elements
    sort(nums.begin(),nums.end());
    
    //to store the elements to insert in the subset array
    int maxx = 1;
    
    //dp arr to store the maximum size of the subset
    vector<int> dp(n+1,1);

    
    for(int i = 1;i<n;i++){
        for(int j = 0;j<i;j++){
            //dp arr -     1 1 1 1
            // given arr - 1 2 4 8
            //now let's compare 2 and 1, 2 is divisble by 1 and 1+dp[0]>dp[1], thus dp[1] = 1+dp[0]
            //dp[1] = 2, which is bigger than maxx, thus replacing the max value
            if(nums[i]%nums[j]==0&&1+dp[j]>dp[i]){
                dp[i]=1+dp[j];
                if(maxx<dp[i]){
                    maxx = dp[i];
                }
            }
        }
    }

    int prev = -1;//prev is the element which will be compared against as we go from right to left in the array
    for(int i = n-1;i>=0;i--){
        //if the element is -1 or divides the prev value, and the number of elements left to be inserted in the sub array is equal to the dp value, it will be inserted
        if(dp[i]==maxx&&(prev%nums[i]==0||prev==-1)){
            ans.push_back(nums[i]);
            maxx-=1;
            prev = nums[i];
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