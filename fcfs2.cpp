#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    vector<pair<int,int>>v;
    int a,b;
    int ct[10],tat[10],wt[10],avg_tat=0,avg_wt=0;
    cout<<"Enter No of process : ";
    cin>>n;
    for(int i=1;i<=n;i++){
    cout<<"Enter Arrival time and Burst Time of process "<<i<<" :";
    cin>>a;
    cin>>b;
    v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    ct[0]=v[0].first;
    for(int i=1;i<=n;i++){

    ct[i]=ct[i-1]+v[i-1].second;
    tat[i]=ct[i]-v[i-1].first;
    avg_tat+=tat[i];
    wt[i]=tat[i]-v[i-1].second;
    avg_wt+=wt[i];

    }
    cout<<"\tP.no\tArrival Time\tBurst Time\tCompletion Time\tTAT\tWT\n";
    for(int i=1;i<=n;i++){
        cout<<"\t"<<i<<"\t   "<<v[i-1].first<<"\t\t    "<<v[i-1].second<<"\t\t\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<"\n";
    }

    cout<<"\n\nAverage TAT :"<<avg_tat*1.0/n;
    cout<<"Average WT :"<<avg_wt*1.0/n;
}
