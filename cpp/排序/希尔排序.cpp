#include <iostream>
 
using namespace std;
 
int a[] = {78,100,120,25,85,40,90,15,60,35,105,50,30,10,28,12};
void shell_sort(int a[], int n)
{
    int gap;//�趨һ���ڱ��������� 
    for(gap = 3; gap >0; )//gap--
    {
        for(int i=0; i<gap; i++)//nС�ڲ��� ���ڲ�����Χ���飬��ÿһ���ڽ������� 
        {
            for(int j = i+gap; j<n; j=j+gap)
            {
                if(a[j]<a[j-gap])//��������ֵС��ǰ���ֵ 
                {
                    int temp = a[j];//�洢�����ֵ 
                    int k = j-gap;//��¼��ǰ�ķ�����š������� 
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
 

