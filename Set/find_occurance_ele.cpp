#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

int main(){
    int A[] = {2,3,4,2,2,4,5,6,7,5,4,2};
    unordered_map<int, int> ump;

    int n = sizeof(A)/sizeof(A[0]); 
    int i;

    for(i = 0; i<n; i++){
        ump[A[i]]++; //  default value is 0. so once we increase by ++ it will turns the value to 1 against that key
    }

    for(auto x : ump){
        cout<<x.first<< " "<< x.second<<endl;
    }

    int count = 0;
    // count all unique ele in array 
    for (auto x : ump)
    {
        if(x.second == 1){
            count++;
        }
    }

    cout<<"no of ele which are unique is: "<<count<<endl;


    return 0;

}