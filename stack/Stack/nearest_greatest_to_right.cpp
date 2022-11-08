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
    // nearest greatest to right
     
    vector<int> v = {1,3,2,4};
    
    stack<int> s;
    vector<int> ans;

    for(int i = v.size()-1; i>= 0; i--){
        if(s.size() == 0){
            ans.push_back(-1);
        }
        else if(s.size() > 0 && s.top() > v[i]){
            ans.push_back(s.top());
        }
        else if(s.size() > 0 && s.top() <= v[i]){
            while(s.size() > 0 && s.top() <= v[i]){
                s.pop();
            }
            // this is terminating condition 
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