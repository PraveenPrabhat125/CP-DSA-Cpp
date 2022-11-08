#include<iostream>
#include<bits/stdc++.h>
#include<stack>

using namespace std;

void printFun(stack<int> wws){
    while (!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}
int main(){
    // min stack
    cout<<"Stack\n"; 
    stack<int> s;
    stack<int> ss; //suporting stack for track of min ele 
    s.push(12);
    s.push(2);
    s.push(20);
    s.push(22);
    s.push(25);
    printFun(s);
    cout<<"second"<<endl;
    printFun(s);

    return 0;

}