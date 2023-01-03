#include <bits/stdc++.h>
using namespace std;

// You are playing the Bulls and Cows game with your friend.

// You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

// The number of "bulls", which are digits in the guess that are in the correct position.
// The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
// Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

// The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

string getHint(string secret, string guess)
{
    int aCnt = 0;
    int bCnt = 0;
    vector<int> s(10,0),g(10,0);

    if(secret.size()!=guess.size()||secret.empty()) return "0A0B";

    for (int i = 0; i < guess.size(); i++)
    {
        char c1 = secret[i],c2 = guess[i];
        if(c1==c2) aCnt++;
        else{
            ++s[c1-'0'];
            ++g[c2-'0'];
        }
    }

    for(int i = 0;i<10;i++){
        bCnt+=min(s[i],g[i]);
    }
    
    return to_string(aCnt)+'A'+to_string(bCnt)+'B';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}