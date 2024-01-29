// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int t=0;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         vector<int> load(n);
//         vector<int> presum(n,0);
//         for(int i=0; i<n; i++){
//             cin>>load[i]; 
//         }
//         presum[0]=load[0];
//         for(int i=1; i<n; i++){
//             presum[i]=presum[i-1]+load[i];
//         }
//         for(int i=0; i<n; i++){
//             cout<<load[i]<<" "<<presum[i]<<endl;
//         }
//         int avg=(presum[n-1]+load[n-1])/n;
//         int ans=INT_MIN;
//         for(int i=0; i<n; i++){
//             int leftsum=((i>0) ? presum[i-1] : 0);
//             int leftneed=(i+1)*avg;
//             int tempansleft=(leftsum>leftneed ? 0 : leftneed-leftsum);
//             int rightsum=presum[n-1]-presum[i];
//             int rightneed=(n-1-i)*avg;
//             int tempansright=(rightsum>rightneed ? 0 : rightneed-rightsum);
//             ans=max(ans, max(tempansleft, tempansright));
//         }
//         cout<<ans;
//     }   
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
 
int main() { 
    int n;
    while(true){
        cin >> n;
        if(n==-1){return 0;}
        vector<int>arr;
        for(int i = 0 ; i < n;i++){
            int data;
            while(true){
                cin >> data;
                if(data=='\n'){
                    break;
                }
                arr.push_back(data);
            }
        }
        vector<int>prefixSum(n,0);
        vector<int>equalSum(n,0);
        prefixSum[0] = arr[0];
        
        for(int i = 1 ; i < n;i++){
            prefixSum[i] = prefixSum[i-1] + arr[i]; 
        }
        equalSum[0] = prefixSum[n-1]/n;
        
        for(int i = 1; i < n;i++){
            equalSum[i] = equalSum[i-1] + (prefixSum[n-1]/n);
        }
        
        
        int maxi  = INT_MIN;
        for(int i = 0 ; i < n-1;i++){
        int upperLeftSum = prefixSum[i];
        int upperRightSum = prefixSum[n-1] - upperLeftSum;
        int lowerLeftSum = equalSum[i];
        int lowerRightSum = equalSum[n-1] - lowerLeftSum;
        
        int netChange = max(abs(upperRightSum - lowerRightSum),abs(upperLeftSum - upperLeftSum)); 
        maxi = max(maxi,netChange);
        }
        cout<<maxi<<"\n";
    }
}


have a look for input reading