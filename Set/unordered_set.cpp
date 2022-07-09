#include <iostream>
#include<unordered_set>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    unordered_set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(20);
    
    // print this set ele 
    for(auto it = s.begin(); it != s.end(); it++){
        cout<<(*it)<<endl;
    }
    
    // size of set
    cout<<"size of set: "<<s.size()<<endl;
    
    // no duplicates are allowed 
    s.insert(20);
    cout<<"size of set: "<<s.size()<<endl;
    
    // frid 
    int key = 20;
    if(s.find(key) == s.end())
    {
        // we reaches to end but couldn't find the key
        cout<<"key is not found"<<endl;
    }
    else{
        // s.find(key) != s.end(); this case we intrupted in between the find of key : means before we reached to send
        cout<<"key is found "<<endl;
    }
    
    // erase
    // s.erase(key);
    // cout<<"size of set: "<<s.size()<<endl;
    
    // or we can erase like this
    auto it = s.find(key);
    cout<<"this vale will be erase: "<<(*it)<<endl;
        s.erase(it);
    
    cout<<"size of set: "<<s.size()<<endl;
    
    
    

    return 0;
}
