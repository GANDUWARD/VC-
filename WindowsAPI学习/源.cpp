#include <windows.h>

//2.���ڴ�����(�Զ��壬������Ϣ)
LRESULT CALLBACK WndProc(HWND hWnd, UINT msgID, WPARAM wParam, LPARAM IParam)
{
    return DefWindowProc(hWnd, msgID, wParam, IParam);
}

//1.��ں���
int main()
{
    //3.ע�ᴰ����
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
    RegisterClass(&wc);//���������и�ֵȫ��д�����ϵͳ

    //4.���ڴ洴������
    HWND hWnd = CreateWindow("Main", "window", WS_OVERLAPPEDWINDOW, 100, 100, 500, 500, NULL, NULL, NULL, NULL);

    //5.��ʾ����
    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);

    //6.��Ϣѭ��
    MSG nMsg = { 0 };
    while (GetMessage(&nMsg, NULL, 0, 0))
    {
        TranslateMessage(&nMsg);
        DispatchMessage(&nMsg);//����Ϣ�������ڴ�����������
    }

    return 0;
}