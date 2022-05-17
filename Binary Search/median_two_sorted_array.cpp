#include<iostream>
#include<vector>
// #include<math.h>
#include<bits/stdc++.h>

using namespace std;
    // vector<int> A = {1,4,5};
    // vector<int> B = {2,3};
double findMedianSortedArrays(const vector<int> &A, const vector<int> &B){
    // partition we have to use 
    if(A.size() > B.size()) return findMedianSortedArrays(B,A);

    int n1 = A.size();
    int n2 = B.size();

    // range of bs is from first array 
    int low = 0;
    int high = n1; 

    while (low <= high)
    {
        int cut1 = (low + (high-low)/2);
        int cut2 = (n1 + n2 + 1)/2 - cut1;

        int l1 = cut1 == 0 ? INT_MIN : A[cut1 -1];
        int l2 = cut2 == 0 ? INT_MIN : B[cut2 -1];

        int r1 = cut1 == n1 ? INT_MAX : A[cut1];
        int r2 = cut2 == n2 ? INT_MAX : B[cut2];

        if(l1 <= r2 && l2 <= r1){
            // correct partition 
            if((n1 + n2)%2 == 0)// even
            {
                return ( (max(l1, l2)) + min(r1, r2) )/2.0;
            }
            else {
                // odd
                return max(l1, l2);
            }
        }
        else if(l1 > r2){
            // 7 <= 3
        high = cut1 - 1;
        }
        else{
            low = cut1 + 1;
        }
    }
    return 0.0;
    
}
int main(){
    // find median of two sorted array in log(n,m) TC
    vector<int> A = {1,4,5};
    vector<int> B = {2,3};

    cout<<"mdeian: "<<findMedianSortedArrays(A, B);
    return 0;


}