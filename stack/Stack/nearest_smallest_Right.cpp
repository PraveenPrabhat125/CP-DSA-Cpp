#include<iostream>
#include<vector>
#include<stack>
#include<bits/stdc++.h>

using namespace std;

void printFun(vector<int> v){
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    // nearest smallest to right 
    // vector<int> v = {1,3,2,4};
                // ans {-1,2,-1,-1}
    
    vector<int> v = {4,5,2,10,8};
    stack<int> s;
    vector<int> ans;

    // for first ele it will be -1 
    // {1,3,2,4};
    // s[4,]
    // ans[-1,]
    for (int  i = v.size()-1; i >= 0; i--)
    {
        if(s.size() == 0){
            ans.push_back(-1);
        }
        else if(s.size() > 0 && s.top() < v[i]){
            ans.push_back(s.top());
        }
        else if(s.size() > 0 && s.top() >= v[i]){
            while (s.size() > 0 && s.top() >= v[i])
            {
                s.pop();
            }
            // two condition to terminate 
            // 1. stack gets empty 
            // 2. s.top <v[i]
            if(s.size() == 0){
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top());
            }
        }
        s.push(v[i]);
    }
    

    printFun(v);
    printFun(ans);

    reverse(ans.begin(), ans.end());
    printFun(ans);

    return 0;

}