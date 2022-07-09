#include<iostream>
#include<bits/stdc++.h>

using namespace std;
const int maxi = 20;
// step -1 create an 2d array as we are having ele from +max to  - max 
bool hashTable[maxi][2];

bool searchFun(int x){
    //if found return true else false 
    if(x >= 0){
        // +ve no if found then check first row corresponding to that index
        if(hashTable[x][0] == 1){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        // -ve ele 
        if(hashTable[abs(x)][1] == 1){
            return true;
        }
        else{
            return false;
        }
    }
}

void printHashTable(){
    int n = 2, i, j, c = maxi;
    for(i = 0; i<n; i++){ // row traversing 
        for(j = 0; j<maxi; j++){
            cout<<hashTable[i][j]<<" ";
        }
        cout<<endl;
    }
}

void insert(int A[], int n ){
    int i;
    for(i = 0; i<n; i++){
        if(A[i] >= 0)// positive ele then put it into first row
        {
            hashTable[A[i]][0] = 1;
        }
        else{ // -ve ele in second row 
            hashTable[abs(A[i])][1] = 1;
        }
    }
}

int main(){
    // create a array and check if particular ele is present or not
    int A[]= {1,2,3,4,6,-1,-2,-9,-11,7};

    int n = sizeof(A)/sizeof(A[0]);

    insert(A,n);

    printHashTable();

    int key = -6;
    if(searchFun(key)){
        cout<<" ele is found "<<endl;
    }
    else{
        cout<<" ele is not found"<<endl;
    }

}