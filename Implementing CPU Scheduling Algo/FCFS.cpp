#include <bits/stdc++.h>
using namespace std;

class Process
{
 private:
    int processId;
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;

 public:
    int &operator[](string s){
        if(s == "AT")return AT;
        if(s == "BT")return BT;
        if(s == "CT")return CT;
        if(s == "TAT")return TAT;
        if(s == "WT")return WT;
        return processId;
    }
    void update_after_completionTm(){
        TAT = CT - AT;
        WT = TAT - BT;
    }
    void display(){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", processId, AT, BT, CT,TAT, WT);
    }
};


float average(vector<Process> p,string s){
    int total = 0;
    for(auto x : p){
        total += x[s];
    }
    return (float)total/p.size();
}




int main()
{
    int n;
    cin >> n;
    
    int idNum = 0;
    vector<Process> p(n);

    for(auto &x : p){
        x["ID"] = idNum++;
        cin >> x["AT"] >> x["BT"];
    }

    // sort process in increasing order based on arrival time.
    sort(p.begin(),p.end(),[](Process fir,Process sec){
        return fir["AT"] < sec["AT"];
    });
    
    printf("pid\tat\tbt\tct\ttat\twt\n");
    
    /* after sorting we know that our first process will be executed.
    */
    p[0]["CT"] = p[0]["AT"] + p[0]["BT"];
    p[0].update_after_completionTm();
    p[0].display();

    /* Now the remaining process left.
    */
    for(int i = 1 ; i < p.size() ; i++){
        if(p[i]["AT"] < p[i-1]["CT"]){
            // cpu will not be on idle state.
            p[i]["CT"] = p[i-1]["CT"] + p[i]["BT"];
        }else{
            // cpu will be on idle state 
            // printf("curr["AT"] : %d, prev["CT"] : %d\n",P[i]["AT"], P[i - 1]["CT"]);
            p[i]["CT"] = p[i]["AT"] + p[i]["BT"];
        }

        p[i].update_after_completionTm();
        p[i].display();
    }
    
    
    printf("Average Turn Around Time : %f\n", average(p, "TAT"));
    printf("Average Waiting Time : %f\n", average(p, "WT"));



    return 0;
}