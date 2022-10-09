#include<iostream>
using namespace std;

int main(){
    int burst_time[10],wait_time[10],turn_around_time[10],i,n;
    float avg_wait_time,avg_tat_time;
    cout<<"\nEnter the no. of processes--";                             
    cin>>n;
    for(int i =0;i<n;i++){
        cout<<"\nEnter the burst time for the process"<<i<<"--";          
        cin>>burst_time[i];
    }
    wait_time[0] = avg_wait_time = 0;                                   
    turn_around_time[0] = avg_tat_time = burst_time[0];     
    for(i=1;i<n;i++){
        wait_time[i] = wait_time[i-1]+burst_time[i-1];                  
        turn_around_time[i] = turn_around_time[i-1]+burst_time[i];     
        avg_wait_time += wait_time[i];                                  
        avg_tat_time += turn_around_time[i];                            
    }
    cout<<"\tPROCESS\t BURST TIME\t WAITING TIME\t TURNAROUND TIME\n";
    for(i=0;i<n;i++){                                                   
        cout<<"\n\tP"<<i<<"\t\t"<<burst_time[i]<<"\t\t"<<wait_time[i]<<"\t\t"<<turn_around_time[i];
    }
    cout<<"\nAverage Waiting Time --"<<avg_wait_time/n;                 
    cout<<"\nAverage Turnaround Time --"<<avg_tat_time/n;               
    return 0;
}
