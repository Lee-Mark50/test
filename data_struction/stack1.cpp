#include<iostream>
#include<stack>
using namespace std;


void newstack(stack <int> ss){
    stack <int> sg = ss;
    while(!sg.empty()){
        //stack is not null
        cout<<'\n'<<sg.top()<<endl;
        //out print top of element
        sg.pop();
        //delete the top element
    }
    cout<<'\n';
}

int main(){
    stack <int> a;
    for(int i=0;i<10;i++){
        a.push(i);
    }
    cout<<"new stack is:";
    newstack(a);
    cout<<"\n newest.size():"<<a.size();
    cout<<"\n newest.top():"<<a.top();
    a.pop();
    return 0;
}