#include<iostream>
#include<vector>

using namespace std;

int peakEle(vector<int> &A){
    int n = A.size();
    
    int mn[n], mx[n];
    mx[0] = A[0];
    mn[n-1] = A[n-1];
    
    
    int mxx = A[0], mnn = A[n-1];
    
    for(int i = 1; i<n; i++){
        mxx = max(mxx, A[i]);
        mx[i] = mxx;
    }
    
    for(int i = n-2; i>0; i--){
        mnn = min(mnn, A[i]);
        mn[i] = mnn;
    }
    
    // now if three values are equal then it is peak element else it is not peak ele
    for(int i = 1; i<n-1; i++){
        if(A[i] == mn[i] && A[i] == mx[i]){
            return i;
        }
    }
    return 0;

}
int main(){
    vector<int> a = {1, 2, 3, 4, 5, 4, 3, 2, 3, 10 };
    cout<< "peak ele: "<<peakEle(a)<<endl;

    return 0;
}