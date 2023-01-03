#include <bits/stdc++.h>
using namespace std;

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