#include <windows.h>
#include <iostream>
using namespace std;

bool P_continue = true; // 控制程序结束
HANDLE R_semaphore;     // 用于读互斥
HANDLE W_semaphore;     // 用于写互斥
DWORD WINAPI Reader(LPVOID); // 读者线程
DWORD WINAPI Writer(LPVOID); // 写者线程
int readcount;
const unsigned short size_buff = 1;
int buffer[size_buff] = {1};


//读
void READUNIT()
{
    cout << "Reading "<< buffer[0] <<"Succeed" << endl;
}

//写
void WRITEUNIT()
{
    cout << "Writing " << " ... ";
    buffer[0] = 1 + rand() % (10 - 1 + 1);
    cout << buffer[0] << "...";
    cout << "Succeed" << endl;
}

//读者——参考winapi&微软Synchapi.h 注解
DWORD WINAPI Reader(LPVOID thread1)
{
    while (P_continue)
    {
        /*WaitForSingleObject作用：等待一个指定的对象——检查读信号量的状态*/
        WaitForSingleObject(R_semaphore, INFINITE);//超时间隔设置无限，仅当发出对象信号时，该函数才会返回
        readcount++;//序列+1
        if(readcount == 1)
            WaitForSingleObject(W_semaphore, INFINITE);
        ReleaseSemaphore(R_semaphore, 1, NULL);//存储 并接收读信号量计数状态增加1
        cout<<"step:1"<<endl;
        Sleep(500);
        READUNIT();//打印读
        WaitForSingleObject(R_semaphore, INFINITE);
        readcount--;
        if(readcount == 0)
            ReleaseSemaphore(W_semaphore, 1, NULL);
        ReleaseSemaphore(R_semaphore, 1, NULL);
        cout<<"step:3"<<endl;
    }
    return 0;
}

//写者
DWORD WINAPI Writer(LPVOID thread1)
{
    while (P_continue) 
    {
        WaitForSingleObject(W_semaphore, INFINITE);
        Sleep(1000);
        WRITEUNIT();
        ReleaseSemaphore(W_semaphore, 1, NULL);
        cout << "Writing " << endl;
    }

    return 0;
}

int main()
{
    R_semaphore = CreateSemaphore(NULL, 1, 3, NULL);
    W_semaphore = CreateSemaphore(NULL, 1, 5, NULL);
    const int Reader_count = 3; // 读者个数
    const int Writer_count = 5; // 写者个数
    const int Number = Reader_count + Writer_count; // 总的线程数
    HANDLE hThreads[Number];
    DWORD readerID[Reader_count];
    DWORD writerID[Writer_count];

    // 创建读者线程
    for (int i = 0; i < Reader_count; i++)
    {
        hThreads[i] = CreateThread(NULL, 0, Reader, NULL, 0, &readerID[i]);
        if (hThreads[i] == NULL)
            return -1;
    }

    // 创建写者进程
    for (int i = 0; i < Writer_count; i++)
    {
        hThreads[Reader_count + i] = CreateThread(NULL, 0, Writer, NULL, 0, &writerID[i]);
        if (hThreads[i] == NULL)
            //CloseHandle();
            return -1;
    }

    while (P_continue)
    {
        if (getchar())
        {
            // 按回车后终止程序执行
            P_continue = false;
        }
    }
    return 0;
}
