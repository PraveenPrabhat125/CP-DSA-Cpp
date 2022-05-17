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
    // nearest smallest to left 
    vector<int> v = {4,5,2,10,8};
                // ans {-1, 1, 1, 2}
    
    stack<int> s;
    vector<int> ans;

    // for first ele it will be -1 
    // {1,3,2,4};
    // s[]
    // ans[]
    for(int i = 0; i<v.size(); i++){
        if(s.size() == 0){
            ans.push_back(-1);
        }
        else if(s.size() > 0 && s.top() < v[i]) {
            ans.push_back(s.top());
        }
        else if(s.size() > 0 && s.top() >= v[i]){
            while (s.size() > 0 && s.top() >= v[i]){
                s.pop();
            }
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

    return 0;

}