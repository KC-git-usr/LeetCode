//memoziation

//fibonacci
#include <iostream>
#include <string>
#include <set>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

std::map<int, int> cache;

int fib(int n)
{
    if(n<=1)
        return n;
    if(cache.find(n)!=cache.end())
        return cache[n];
    else
        cache[n] = (fib(n-1)+fib(n-2));
        return cache[n];
}


int main()
{
    cout<<fib(4);
    return 0;
}


//Longest Common Sub-Sequence
#include <iostream>
#include <string>

int LCS(string s1, string s2)
{
    int m = s1.length(), n = s2.length();
    int dp[m+1][n+1]={0};

    for (int i = m-1; i >= 0; i--)
    {
        for (int j = n-1; j >= 0; j--)
        {
            if(s1[i]==s2[j])
                dp[i][j] = 1+dp[i+1][j+1];
            else
                dp[i][j] = dp[i][j+1]>dp[i+1][j]?dp[i][j+1]:dp[i+1][j];
        }
    }

    return dp[0][0];
}

int main(int argc, char const *argv[])
{
    cout<<LCS("abc", "abc");
    return 0;
}