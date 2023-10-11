#include <windows.h>
#include <stdio.h>

HANDLE gWriteFinishedEvent;//写者线程写完成信号
HANDLE writeThreadHandle;
HANDLE readThreadHandle;

DWORD WINAPI ReadThreadProc(LPVOID);
DWORD WINAPI WriteThreadProc(LPVOID);

void CreateEventsAndReadThreads(void)
{
    // 创建一个 manual-reset 事件对象. The write thread sets this
    gWriteFinishedEvent = CreateEvent(
        NULL,               // 事件使用默认安全属性
        //是否需要人工ResetEvent重置为无信号状态：
        //1 是，当该事件为有信号状态时，所有等待该信号的线程都变为可调度线程。
        //      并且，需要手动调用ResetEvent为无信号状态；
        //2 否，当该事件为有信号状态时，只有一个线程变为可调度线程。
        //      并且，系统自动调用ResetEvent将该对象设置为无信号状态；
        FALSE,
        FALSE,//初始状态:无信号状态
        TEXT("WriteFinishedEvent")  // 事件对象名称
    );
    writeThreadHandle = CreateThread(
        NULL,              // default security
        0,                 // default stack size
        WriteThreadProc,        // name of the thread function
        NULL,              // no thread parameters
        0,                 // default startup flags
        nullptr);
    readThreadHandle = CreateThread(
        NULL,              // default security
        0,                 // default stack size
        ReadThreadProc,        // name of the thread function
        NULL,              // no thread parameters
        0,                 // default startup flags
        nullptr);
}
DWORD WINAPI ReadThreadProc(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    while (true)
    {
        printf("读者线程 %d 正在等待写事件...\n", GetCurrentThreadId());
        //等待信号
        DWORD dwWaitResult = WaitForSingleObject(gWriteFinishedEvent, INFINITE);// 无限等待
        printf("读者线程 %d 等到了写完成事件\n", GetCurrentThreadId());

        switch (dwWaitResult)
        {
            //所请求的对象是有信号状态
        case WAIT_OBJECT_0:
            printf("读者线程 %d 读缓冲区完成\n\n", GetCurrentThreadId());
            break;
        // An error occurred
        default:
            printf("Wait error (%d)\n", GetLastError());
            return 0;
        }
    }
    return 1;
}
DWORD WINAPI WriteThreadProc(LPVOID lpParam)
{
    while (true)
    {
        printf("写者线程 写共享缓冲区完成\n");
        //发出写完成信号，让读者线程读
        SetEvent(gWriteFinishedEvent);
        Sleep(2 * 1000);
    }
    return 0;
}

int main(void)
{
    DWORD dwWaitResult;
    CreateEventsAndReadThreads();
    printf("main正在等待所有读者线程退出...\n");
    HANDLE handleArr[] = { writeThreadHandle , readThreadHandle };
    dwWaitResult = WaitForMultipleObjects(2, handleArr, TRUE, INFINITE);

    switch (dwWaitResult)
    {
    case WAIT_OBJECT_0:
        printf("所有线程都已经退出, 正在为应用程序退出做清理工作...\n");
        break;
        // An error occurred
    default:
        printf("WaitForMultipleObjects failed (%d)\n", GetLastError());
        return 1;
    }
    // 关闭事件
    CloseHandle(gWriteFinishedEvent);

    return 0;
}