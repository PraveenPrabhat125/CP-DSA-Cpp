#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int secHalfBS(vector<int> &A, int low1, int high1, int B){
    // int low1 = btPt +1, high1 = A.size()-1;
    while(low1 <= high1){
        int mid = (low1 + (high1 - low1)/2);

        if(A[mid] == B) return mid;
        
        else if(A[mid] > B){
            low1 = mid +1;
        }
        else{
            high1 = mid -1;
        }
    }
    return -1;
}

int firstHalfBS(vector<int> &A, int low1, int high1, int B){
    // int low1 = btPt +1, high1 = A.size()-1;
    while(low1 <= high1){
        int mid = (low1 + (high1 - low1)/2);

        if(A[mid] == B) return mid;
        else if(A[mid] < B){
            low1 = mid +1;
        }
        else{
            high1 = mid -1;
        }
    }
    return -1;
}


int solve(vector<int> &A, int B) {
    int low = 0, high = A.size();

    int btPt = -1;

    while(low <= high){
        int mid = (low + (high - low)/2);

        if(A[mid] > A[mid -1] && A[mid] > A[mid+1]){
            btPt = mid;
            break;
        }

        else if(A[mid] > A[mid-1] && A[mid] <A[mid+1]){
            low = mid +1;
        }
        else{
            high = mid -1;
        }
    }
    cout<<"btpt: "<<A[btPt]<<endl;


    // now find the ele 

    // btpt = 20, B = 12
    if(A[btPt] < B){
        return -1;
    }

    if(A[btPt] == B){
        return btPt;
    }


    int firstHalf = firstHalfBS(A, 0, btPt, B);
    int secHalf = secHalfBS(A, btPt+1, A.size()-1, B);
    cout<<"first half search: "<<firstHalf<<endl<<"sechalf:" <<secHalf<<endl;

    if(firstHalf == -1){
        return secHalf;
    }
    else{
        return firstHalf;
    }
}

int main(){
    vector<int> A = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11 };
    int  B = 12;

    cout<<"solve" <<solve(A, B);

    return 0;

}
