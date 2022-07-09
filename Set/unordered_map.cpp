#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

int main(){
    unordered_map<string, int> ump;

    ump["Praveen"] = 46;
    ump["Prabhat"] = 56;
    ump["PP"] = 16;

    // printing the map 
    // for(auto it = ump.begin(); it != ump.end(); it++){
    //     cout<< it.first<< " "<< it.second <<endl;
    // }
    
    for(auto x : ump){
        cout<<x.first << " "<<x.second<<endl;
    }
    
    ump.insert(make_pair("laptop", 1000000));
    for(auto x : ump){
        cout<<x.first << " "<<x.second<<endl;
    }
    string key = "laptop";
    if(ump.find(key) != ump.end()){
        cout<<"key is found"<<endl;
    }
    else{
        cout<<"key is not found"<<endl;
        
    }
    ump.erase(key);   
    for(auto x : ump){
        cout<<x.first << " "<<x.second<<endl;
    }

    
    
    /*
    auto temp = ump.find(key);
    cout<<temp.first << " "<<temp.second<<endl;
    */
    
    

}