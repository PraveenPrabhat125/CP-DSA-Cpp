#include<iostream>
#include<vector>

using namespace std;
void printFun(vector<int> v){
    for (int  i = 0; i < v.size(); i++)
    {
        cout<<v[i]<< " ";
    }
    cout<<endl;
}


int main(){
    // stock sapn 
    vector<int> v = {100, 80, 60, 70, 60, 75, 85};
    printFun(v);
    // brut force : dry solution 
    int count = 1;

    vector<int> ans;
    ans.push_back(1);

    for(int i = 1; i<v.size(); i++){
        count = 1;
        for(int j = i-1; j>=0; j--){
            if(v[j] < v[i]){
                count++;
            }
            else{
                break;
            }
        }
        ans.push_back(count);
    }

    printFun(ans);


    return 0;

    

}