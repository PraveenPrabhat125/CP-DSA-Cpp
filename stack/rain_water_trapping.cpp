#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

void printFun(const vector<int> &v){
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<< " ";
    }
    cout<<endl;
}

int main(){
    // find the maximum water traped 
    vector<int> v = {3, 0, 0, 2, 0, 4};
    int n = v.size();
    cout<<"size of vector:"<<n<<endl;

    cout<<"vector"<<endl;
    printFun(v);

    vector<int> mxL;
    vector<int> mxR;

    int mxleft = v[0];
    mxL.push_back(mxleft);
    for(int i = 1; i<n; i++){
        mxL.push_back(max(mxleft, v[i]));
    }

    cout<<"MXL"<<endl;
    printFun(mxL);

    int mxRight = v[n-1];
    mxR.push_back(mxRight);
    for(int i = n-2; i>=0; i--){
        mxR.push_back(max(mxRight, v[i]));
    }
    reverse(mxR.begin(), mxR.end());
    cout<<"MXR"<<endl;
    printFun(mxR);

    vector<int> height;
    for(int i = 0; i<n; i++){
        height.push_back( (min(mxL[i], mxR[i]) - v[i]) );
    }

    cout<<"height"<<endl;
    printFun(height);

    int sum = 0;
    for(int i =0; i<n; i++){
        sum += height[i];
    }
    cout<<"max rain water: "<<sum<<endl;

    return 0;



}