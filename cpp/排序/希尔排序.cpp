#include <iostream>
 
using namespace std;
 
int a[] = {78,100,120,25,85,40,90,15,60,35,105,50,30,10,28,12};
void shell_sort(int a[], int n)
{
    int gap;//设定一个哨兵——步长 
    for(gap = 3; gap >0; )//gap--
    {
        for(int i=0; i<gap; i++)//n小于步长 即在步长范围分组，将每一组内进行排序 
        {
            for(int j = i+gap; j<n; j=j+gap)
            {
                if(a[j]<a[j-gap])//如果后面的值小于前面的值 
                {
                    int temp = a[j];//存储后面的值 
                    int k = j-gap;//记录当前的分组序号。。。吧 
                    while(k>=0&&a[k]>temp)//
                    {
                        a[k+gap] = a[k];
                        k = k-gap;
                    }
                    a[k+gap] = temp;
                }
            } 
        }
    }
}
int main()
{
    cout<<"Before Sort: ";
    for(int i=0; i<16; i++)
         cout<<a[i]<<" ";
      cout<<endl;
      shell_sort(a, 16);
   cout<<"After Sort: ";
      for(int i=0; i<16; i++)
          cout<<a[i]<<" ";
      cout<<endl;
     system("pause");
}
 

