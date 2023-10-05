#include<iostream>
#include<bits/stdc++.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

void heart1(){
    cout<<"    ^               ^"<<endl;
    cout<<"   /-\             /-\ "<<endl;
    cout<<"  /---\           /---\ "<<endl;
    cout<<" (_____________________)"<<endl;
    cout<<" ----------------------"<<endl;
    cout<<"   ------------------ "<<endl;
    cout<<"     -------------- "<<endl;
    cout<<"       ---------- "<<endl;
    cout<<"          ---"<<endl;
    cout<<"           v"<<endl;
}

void heart2(){
    //爱心：
    int i,j,k,l,m;
    char c='/*'; 
    cout<<endl;
    for (i=1;i<=3;i++){ 
    for (j=1;j<=32-2*i;j++)
      cout<<" ";
    for (k=1;k<=4*i+1;k++)
      cout<<c;
    for (l=1;l<=13-4*i;l++)
      cout<<" ";
    for (m=1;m<=4*i+1;m++)
      cout<<c;
    cout<<endl;
}
    for (i=1;i<=3;i++){ 
         for (j=1;j<=24+1;j++)
              cout<<" ";
        for (k=1;k<=29;k++)
              cout<<c;
        cout<<endl; 
    }
    for (i=7;i>=1;i--){ 
        for (j=1;j<=40-2*i;j++)
              cout<<" ";
        for (k=1;k<=4*i-1;k++)
              cout<<c;
        cout<<endl; 
  }
    for (i=1;i<=39;i++)
        cout<<" "; 
    cout<<c<<endl;  
}

void heart3(){
    float x,y,a;
    for (y=1.5;y>-1.5;y-=0.1){
        for (x=-1.5;x<1.5;x+=0.05){
            a=x*x+y*y-1;
            putchar(a * a * a - x * x * y * y * y <= 0.0 ? '*' : ' ');
        }
        system("color 0c");
        putchar('\n');
    }

}

int main(){
    //heart1();
    //heart2();
    heart3();
}