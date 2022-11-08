#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<algorithm>
#include<stack>


using namespace std;

vector<int> FindNsr(vector<int> v){
    vector<int> nsr;
    // {6,2,5,4,4,1,6};
    stack< pair<int, int> > s;
    
    int n = v.size();

    for(int i = n-1; i>=0; i--){
        if(s.size() == 0) nsr.push_back(n);
        else if(s.size() > 0 && s.top().first < v[i]){
            nsr.push_back(s.top().second);
        }
        else if(s.size() > 0 && s.top().first >= v[i]){
            while (s.size() > 0 && s.top().first >= v[i])
            {
                s.pop();
            }
            if(s.size() == 0){
                nsr.push_back(n);
            }
            else{
                nsr.push_back(s.top().second);
            }
        }
        s.push({v[i],i});
    }
    reverse(nsr.begin(), nsr.end());
    return nsr;
}

vector<int> FindNsl(vector<int> v){
    vector<int> nsl;
    // {6,2,5,4,4,1,6};
    stack< pair<int, int> > s;
    
    int n = v.size();

    for(int i = 0; i<n; i++){
        if(s.size() == 0) nsl.push_back(-1);
        else if(s.size() > 0 && s.top().first < v[i]){
            nsl.push_back(s.top().second);
        }
        else if(s.size() > 0 && s.top().first >= v[i]){
            while (s.size() > 0 && s.top().first >= v[i])
            {
                s.pop();
            }
            if(s.size() == 0){
                nsl.push_back(-1);
            }
            else{
                nsl.push_back(s.top().second);
            }
        }
        s.push({v[i],i});
    }
    return nsl;
}

void printFun(vector<int> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    // max area histogram 
    vector<int> v = {6,2,5,4,5,1,6};

    // we need to find the max area formed when it is assumeed as a tower height 
    
    // approach 
    // 1. find nsl and nsr index 
    // then find the width (nsr-nsl)-1
    // then area = height * width 

    vector<int> nsl = FindNsl(v);
    cout<<"nsl index:"<<endl;
    printFun(nsl);
    

    
    vector<int> nsr = FindNsr(v);
    cout<<"nsr index:"<<endl;
    printFun(nsr);


    vector<int> area;
    for(int i = 0; i<nsl.size(); i++){
        area.push_back(((nsr[i] - nsl[i]) - 1)*v[i]);
    }
    printFun(area);

    cout<<"max area: "<<*max_element(area.begin(), are2a.end());

    return 0;

}