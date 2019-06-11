#include <iostream>
using namespace std;

bool exist(string *sett, string a){
    for(int i=0;i<6;i++){
        if(sett[i]==a)
            return true;
    }
    return false;
}

string newtmp(int *parent, string *lw, string cons,int t){
    int a=0;
    do{
        a=a+lw[t].length();
        t=parent[t];
    }while(t!=-1);
    return cons.erase(0,a);
}

void findcost(string s, string *lw, int *parent, int *cost, string*sett, int i){
    if(i==s.length())
        return;
    string tmp;
    tmp.insert(0,s,0,i+1);
    string con=tmp;
    int t=-1;
    //cout<<"tmp "<<tmp<<endl;

    while(t++<i){
        if(exist(sett,tmp)){
            parent[i]=t-1;
            if(parent[i]==-1)
                cost[i]=1;
            else
                cost[i]=cost[parent[i]]+1;
            //cout<<"par "<<parent[i]<<endl;
            //cout<<"cost"<<cost[i]<<endl;
            lw[i]=tmp;
            break;
        }
        if('tmp'==s[i])
            break;
        tmp=newtmp(parent,lw,con,t);
        //cout<<tmp<<endl;
    }
    findcost(s,lw,parent,cost,sett,i+1);
}

int main(){
    string sett[6]={"a","ala","lama","lam","la","kot"};
    string s;
    cin>>s;
    string lastw[s.size()];
    int cost[s.length()]={0};
    int par[s.size()];
    for(int i=0;i<s.size();i++)
        par[i]=-1;

    string tmp;
    tmp.insert(0,s,0,1);
    if(exist(sett,tmp)){
         cost[0]=1;
         lastw[0]=tmp;
    }
    else
        cost[0]=2000;


    findcost(s,lastw,par,cost,sett,1);
    cout<<"cost "<<cost[s.size()-1]<<endl;
    int t=s.size()-1;
    while(t!=-1){
        cout<<lastw[t]<<" ";
        t=par[t];
    }

}
