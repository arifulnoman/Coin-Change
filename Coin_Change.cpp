#include<bits/stdc++.h>
using namespace std;
int dp[100];
void initialize(int n)
{
    int i;
    for(i = 0;i < n;i++)
    {
        dp[i] = -1;
    }
}
bool change_coin(int coins[],int n,int target)
{
    if(target == 0)
    {
        return true;
    }
    if(n == 0)
    {
        return false;
    }
    else
    {
        if(coins[n-1] > target)
        {
            return change_coin(coins,n-1,target);
        }
        else
        {
            if(dp[n-1] != -1)
            {
                return dp[n-1];
            }
            else
            {
                return dp[n-1] = change_coin(coins,n,target-coins[n-1]) || change_coin(coins,n-1,target);
            }
        }
    }
}
int main()
{
    int i,n;
    cout << "Enter total number of coins: ";
    cin >> n;
    int coins[n];
    initialize(n);
    cout << "Enter the coins: ";
    for(i = 0;i < n;i++)
    {
        cin >> coins[i];
    }
    cout << "Enter the target: ";
    int target;
    cin >> target;
    bool result = change_coin(coins,n,target);
    if(result == true)
    {
        cout << "Possible";
    }
    else
    {
        cout << "Impossible";
    }
    return 0;
}