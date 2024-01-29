#include<bits/stdc++.h>
using namespace std;

// int findSmall(array<int, 9> coins,int val, int n){
//     for(int i=n-1; i>=0; i--){
//         if(coins[i]<=val){
//             return coins[i];
//         }
//     }
// }

// recursive approach (optimal)
int changeCoinRec(int amount, array<int, 9> coins, int n){
    if(amount==0){
        return 0;
    }
    int ans=INT_MAX;
    for(auto coin:coins){
        if(amount-coin>0){
            int subProb=changeCoinRec(amount-coin, coins, n);
            ans=min(ans, subProb+1);
        }
    }
    return ans;
}
int main()
{
    array<int, 9> coins={1,2,5,10,20,50,100,200,500};
    sort(coins.begin(), coins.end());
    int money=458;
    // greedy approach
    // int count=0;
    // while(money>0){
    //     int smaller=findSmall(coins, money, 9);
    //     count+=money/smaller;
    //     money= money - (money/smaller)*smaller;
    // }
    // cout<<count;
    cout<<changeCoinRec(money, coins, 9);
    return 0;
}
