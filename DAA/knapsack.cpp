#include<bits/stdc++.h>
using namespace std;

vector<int>weight,cost;
// maximize the cost, and weight does not exceed max weight
vector<vector<int>>dp;

int solve(int idx,int n,int maxi,int curr_wt){
    if(idx>=n){
        return 0;
    }
    if(dp[idx][curr_wt]!=-1) return dp[idx][curr_wt];
    int pick=0;
    if(curr_wt + weight[idx] <= maxi){
        pick=cost[idx]+solve(idx+1,n,maxi,curr_wt + weight[idx]);
    }
    int not_pick = solve(idx+1,n,maxi,curr_wt);
    return dp[idx][curr_wt]=max(pick,not_pick);
}


int main(){
    int n;
    cout<<"Enter number of items: ";
    cin>>n;
    weight=vector<int>(n,0);
    cost=vector<int>(n,0);
    dp=vector<vector<int>>(n,vector<int>(1e5,-1));
    int maxi;
    cout<<"Max weight allowed: ";
    cin>>maxi;
    for(int i=0;i<n;i++){
        cout<<"Enter weight and cost of item (space separated): ";
        cin>>weight[i]>>cost[i];
    }
    cout<<"Max cost acheived: "<<solve(0,n,maxi,0);

}