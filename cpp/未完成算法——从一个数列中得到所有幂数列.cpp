#include<iostream>
using namespace std;

int sort(int a){
	if(a==1){
		char arr[]="1234";
		for(int o=0;o<sizeof(arr);o++){
			cout<<arr[o]<<endl;
		}
	}
	else {//在取得一个定下来的数后，将除去该数的新数组再次sort，直到选择出下一个数，然后拼接即可 
	char arr[]="1234";
		for(int i=0;i<sizeof(arr);i++){//定一个数 
			for(int l=0;l!=i;l++){
				char arr1[]="1234";
				cout<<arr[l]<<arr1[i]<<endl;
			}	
		}
	} 
} 
int main(){
	sort(4);
}
/*void count(int len, int flag, int[] out) {
		int j;
		for ( j = flag; j >0) {
				if(out[flag] <= out[flag-1]) {
					continue;
				}
			}
			if(flag == k-1 ) {
				for(int i=0; i<out.length; i++) {
					cout<<out[i] <<", ";
				}
				cout<<"       ";
			}
			else {
				int newflag = flag+1;
				count(len, newflag, out);
				cout<<endl;
			}
		}
		*/
