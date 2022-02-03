#include<windows.h>
#include<time.h>
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
TCHAR szClassWindow[] = TEXT("Framework Windows");
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
    HWND hWnd;
    MSG lpMsg;
    WNDCLASSEX wcl;
    wcl.cbSize = sizeof(wcl);
    wcl.style = CS_HREDRAW | CS_VREDRAW;
    wcl.lpfnWndProc = WindowProc;
    wcl.cbClsExtra = 0;
    wcl.cbWndExtra = 0;
    wcl.hInstance = hInst;
    wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wcl.lpszMenuName = NULL;
    wcl.lpszClassName = szClassWindow;
    wcl.hIconSm = NULL;
    if (!RegisterClassEx(&wcl)) return 0;
    hWnd = CreateWindowEx(
        0,
        szClassWindow,
        TEXT("Ресурсы"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL,
        NULL,
        hInst,
        NULL);
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    while (GetMessage(&lpMsg, NULL, 0, 0))
    {
        TranslateMessage(&lpMsg);
        DispatchMessage(&lpMsg);
    }
    return lpMsg.wParam;
}
static int x = 0;
static int y = 0;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hDC = BeginPaint(hWnd, &ps);
        ::Ellipse(hDC, x, y, x + 100, y + 100);
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_LEFT: 
            x -= 10; 
            break;
        case VK_RIGHT:
            x += 10;
            break;
        case VK_UP:
            y -= 10;
            break;
        case VK_DOWN: 
            y += 10;
            break;
        }
        InvalidateRect(hWnd, nullptr, true);
        break;
    return 0;
}