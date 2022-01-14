#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// si => source ka konsa character solve ho raha hai
// ti => target ka konsa character solve ho raha hai
int memo(string S, string T, int si, int ti, vector<vector<int>> dp){

    if(ti == T.length()) {
        return 1;
    }

    if(si == S.length()) {
        if(ti == T.length()){
            return 1;
        }
        return 0;
    }
    if(dp[si][ti] != -1){
        return dp[si][ti];
    }
    char fs = S[si];
    char ft = T[ti];

    int cnt = 0;

    if(fs != ft){
        cnt = memo(S, T, si + 1, ti, dp);
    } else{
        
        int a = memo(S, T, si + 1, ti, dp);
        int b = memo(S, T, si + 1, ti + 1, dp);
        cnt=a+b;
    }

    dp[si][ti] = cnt;
    return cnt;
}

int rec(string S, string T, int si, int ti){

    if(ti == T.length()) {
        return 1;
    }

    if(si == S.length()) {
        if(ti == T.length()){
            return 1;
        }
        return 0;
    }

    char fs = S[si];
    char ft = T[ti];

    int cnt = 0;

    if(fs != ft){
        cnt = rec(S, T, si + 1, ti);
    } else{
        
        int a = rec(S, T, si + 1, ti);
        int b = rec(S, T, si + 1, ti + 1);
        cnt=a+b;
    }
    return cnt;
}

void func(string S, string T) {

    int n = S.length();
    vector<vector<int>> dp(n, vector<int>(T.length(), -1));

    cout << memo(S, T, 0, 0, dp) << endl;

    // cout << rec(S, T, 0, 0) << endl;
}
 
 
int main(){
    string s,t;
    cin>>s>>t;
 
    func(s, t);
}
