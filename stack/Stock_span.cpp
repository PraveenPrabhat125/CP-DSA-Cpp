#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void printFun(vector<int> v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;   
}

int main(){
    // stock span 
    vector<int> v = {100, 80, 60, 70, 60, 75, 85};

    // steps:
    // 1. we have to sote the NGL index 
    // 2. then i - index[NGL]

    vector<int> index;
    stack< pair<int, int> > s;

    for(int i = 0; i<v.size(); i++){
        if(s.size() == 0){
            index.push_back(-1);
        }
        else if(s.size() > 0 && s.top().first > v[i]){
            index.push_back(s.top().second);
        }
        else if(s.size() > 0 && s.top().first <= v[i]){
            while(s.size() > 0 && s.top().first <= v[i]){
                s.pop();
            }
            if(s.size() == 0){
                index.push_back(-1);
            }
            else{
                index.push_back(s.top().second);
            }
        }
        s.push({v[i], i});
    }
    printFun(v);
    printFun(index);

    // 2. we just i - index[i]
    vector<int> ans;
    for(int i = 0; i<index.size(); i++){
        ans.push_back(i-index[i]);
    }

    cout<<"stock span: "<<endl;
    printFun(ans);

    return 0;


}