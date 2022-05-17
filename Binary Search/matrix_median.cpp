#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main(){
    // find the median of matrix which is odd 
    vector< vector< int> > v = {{1,3,5}, {2,6,9}, {3,6,9}};
    int r = v.size();
    int c = v[0].size();

    int reqMid = (r*c + 1)/2; // this is the median postion 

    // we have to apply bs 
    int minm = INT_MAX, maxm= INT_MIN;

    for(int i = 0; i<r; i++){
        minm = min(minm,v[i][0]);
        maxm = max(maxm, v[i][c-1]);
    }

    // apply bs
    while (minm < maxm)
    {
        int mid = (minm + (maxm - minm)/2);

        int count = 0;
        for(int i = 0; i<r; i++){
            count += upper_bound(v[i].begin(), v[i].end(), mid) - v[i].begin();
        }
        
        if(count < reqMid){
            minm = mid + 1;
        }
        else{
            maxm = mid;
        }
    }
    cout<<"minm: "<<minm<<endl;
    return 0;

}