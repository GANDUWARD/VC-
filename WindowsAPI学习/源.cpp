#include <windows.h>

//2.窗口处理函数(自定义，处理消息)
LRESULT CALLBACK WndProc(HWND hWnd, UINT msgID, WPARAM wParam, LPARAM IParam)
{
    return DefWindowProc(hWnd, msgID, wParam, IParam);
}

//1.入口函数
int main()
{
    //3.注册窗口类
    WNDCLASS wc = { 0 };
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = NULL;
    wc.hIcon = NULL;
    wc.hInstance = NULL;
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = "Main";
    wc.lpszMenuName = NULL;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&wc);//将以上所有赋值全部写入操作系统

    //4.在内存创建窗口
    HWND hWnd = CreateWindow("Main", "window", WS_OVERLAPPEDWINDOW, 100, 100, 500, 500, NULL, NULL, NULL, NULL);

    //5.显示窗口
    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);

    //6.消息循环
    MSG nMsg = { 0 };
    while (GetMessage(&nMsg, NULL, 0, 0))
    {
        TranslateMessage(&nMsg);
        DispatchMessage(&nMsg);//将消息交给窗口处理函数来处理
    }

    return 0;
}