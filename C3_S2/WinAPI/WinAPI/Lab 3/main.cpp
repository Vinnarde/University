// --- Обязательный включаемый файл
#include <windows.h>
#include "framework.h"
#include "WINAPI_3.h"
#include "wingdi.h"

#define MAX_LOADSTRING 100
#define BUTTONS_N 3

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM				RegisterMainWindowsClass(HINSTANCE);
ATOM				RegisterPopupWindowsClass(HINSTANCE);
ATOM				RegisterChildWindowsClass(HINSTANCE);
ATOM				RegisterOverlappedWindowsClass(HINSTANCE);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    OverlappedWndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    PopupWndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    ChildWndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

static HPEN hpen;     // handle of dotted pen
static POINT pt;      // x and y coordinates of cursor
Button btns[BUTTONS_N];


void CreateButtons();
void DrawButtons(HDC hdc);
void CheckClickOnButtons(HWND hWnd);

void ShowWindowStyle1();
void ShowWindowStyle2();
void ShowWindowStyle3();


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);


	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WINAPI3, szWindowClass, MAX_LOADSTRING);
	RegisterMainWindowsClass(hInstance);
	RegisterOverlappedWindowsClass(hInstance);
	RegisterPopupWindowsClass(hInstance);
	RegisterChildWindowsClass(hInstance);


	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPI3));

	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}

//  FUNCTION: RegisterMainWindowsClass()
//
//  PURPOSE: Registers the window class.
//
ATOM RegisterMainWindowsClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPI3));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINAPI3);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

ATOM RegisterPopupWindowsClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wcex.lpfnWndProc = PopupWndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPI3));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(CreateSolidBrush(RGB(70, 140, 255)));
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = L"POPUP_WINDOW";
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}


ATOM RegisterChildWindowsClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wcex.lpfnWndProc = ChildWndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPI3));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(CreateSolidBrush(RGB(132, 222, 2)));
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = L"CHILD_WINDOW";
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

ATOM RegisterOverlappedWindowsClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wcex.lpfnWndProc = OverlappedWndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPI3));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(CreateSolidBrush(RGB(255, 0, 0)));
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = L"OVERLAPPED_WINDOW";
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

// Overlapped Window
void ShowWindowStyle1()
{
	HWND hWnd = GetActiveWindow();

	// Создание главного окна
	HWND hWndMain =
		CreateWindow(
			L"OVERLAPPED_WINDOW",
			L"OVERLAPPEDWINDOW",
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT,
			CW_USEDEFAULT, CW_USEDEFAULT,
			hWnd, NULL, hInst, NULL
		);

	if (hWndMain == nullptr)
	{
		MessageBox(hWnd, TEXT("Error!!"), TEXT("MainWindow"), MB_OK | MB_ICONINFORMATION);
		return;
	}
	ShowWindow(hWndMain, SW_SHOW);
	UpdateWindow(hWndMain);
}

// Popup Window
void ShowWindowStyle2()
{
	HWND hWnd = GetActiveWindow();
	// создание временного окна
	HWND hWndPopup =
		CreateWindow(L"POPUP_WINDOW", L"POPUPWINDOW",
			WS_POPUPWINDOW | WS_CAPTION | WS_MINIMIZEBOX |
			WS_MAXIMIZEBOX, 100, 100, 300, 300, hWnd,
			NULL, hInst, NULL);
	if (hWndPopup == nullptr)
	{
		MessageBox(hWnd, TEXT("Error!!"), TEXT("PopupWindow"), MB_OK | MB_ICONINFORMATION);
		return;
	}
	ShowWindow(hWndPopup, SW_SHOW);
	UpdateWindow(hWndPopup);
}

// Child Window
void ShowWindowStyle3()
{
	HWND hWnd = GetActiveWindow();
	// создание дочернего окна
	HWND hWndChild =
		CreateWindow(L"CHILD_WINDOW", L"CHILDWINDOW",
			WS_CHILDWINDOW | WS_CAPTION | WS_MINIMIZEBOX |
			WS_MAXIMIZEBOX, 150, 150, 250, 250, hWnd, NULL,
			hInst, NULL);

	if (hWndChild == nullptr)
	{
		MessageBox(hWnd, TEXT("Error!!"), TEXT("Window"), MB_OK | MB_ICONINFORMATION);
		return;
	}
	ShowWindow(hWndChild, SW_SHOW);
	UpdateWindow(hWndChild);
}


// --- Main window function
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		SelectObject(hdc, hpen);
		DrawButtons(hdc);
		//Rectangle(hdc, 10, 10, 100, 100);
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CREATE:
		hpen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
		CreateButtons();
	case WM_LBUTTONDOWN:
		pt.x = (LONG)LOWORD(lParam);
		pt.y = (LONG)HIWORD(lParam);
		CheckClickOnButtons(hWnd);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0l;
}

LRESULT CALLBACK OverlappedWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_SIZE:
	{
		InvalidateRect(hWnd, NULL, false);
		UpdateWindow(hWnd);
	}

	case WM_MOVE:
	{
		InvalidateRect(hWnd, NULL, false);
		UpdateWindow(hWnd);
	}
	break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		RECT window_rect, client_rect;

		int screen_width = GetSystemMetrics(SM_CXSCREEN);
		int screen_height = GetSystemMetrics(SM_CYSCREEN);

		GetClientRect(hWnd, &client_rect);

		GetWindowRect(hWnd, &window_rect);

		// System metric
		wchar_t line1[100] = { 0 };
		wchar_t line2[100] = { 0 };
		wchar_t line3[100] = { 0 };

		wsprintfW(line1, L"System metric:");
		wsprintfW(line2, L"Screen width: %d", screen_width);
		wsprintfW(line3, L"Screen height: %d", screen_height);

		// Client rect
		wchar_t line4[100] = { 0 };
		wchar_t line5[100] = { 0 };
		wchar_t line6[100] = { 0 };

		wsprintfW(line4, L"Client rect:");
		wsprintfW(line5, L"Client width: %d, height: %d",
			client_rect.right - client_rect.left,
			client_rect.bottom - client_rect.top);
		wsprintfW(line6, L"X: %d, Y: %d", client_rect.left, client_rect.top);

		// Window rect
		wchar_t line7[100] = { 0 };
		wchar_t line8[100] = { 0 };
		wchar_t line9[100] = { 0 };

		int width = window_rect.right - window_rect.left;
		int height = window_rect.bottom - window_rect.top;

		wsprintfW(line7, L"Window rect:");
		wsprintfW(line8, L"Width: %d; Height: %d", width, height);
		wsprintfW(line9, L"X: %d; Y: %d", window_rect.left, window_rect.top);



		TextOut(hdc, 20, 20, line1, 100);
		TextOut(hdc, 30, 40, line2, 100);
		TextOut(hdc, 30, 60, line3, 100);
		TextOut(hdc, 20, 80, line4, 100);
		TextOut(hdc, 30, 100, line5, 100);
		TextOut(hdc, 30, 120, line6, 100);
		TextOut(hdc, 20, 140, line7, 100);
		TextOut(hdc, 30, 160, line8, 100);
		TextOut(hdc, 30, 180, line9, 100);

		EndPaint(hWnd, &ps);
	}
	break;

	case WM_DESTROY:
	case WM_CREATE:
		hpen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
		//CreateButtons();
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

LRESULT CALLBACK PopupWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_SIZE:
	{
		InvalidateRect(hWnd, NULL, false);
		UpdateWindow(hWnd);
	}

	case WM_MOVE:
	{
		InvalidateRect(hWnd, NULL, false);
		UpdateWindow(hWnd);
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		RECT window_rect, client_rect;

		int screen_width = GetSystemMetrics(SM_CXSCREEN);
		int screen_height = GetSystemMetrics(SM_CYSCREEN);

		GetClientRect(hWnd, &client_rect);

		GetWindowRect(hWnd, &window_rect);

		// System metric
		wchar_t line1[100] = { 0 };
		wchar_t line2[100] = { 0 };
		wchar_t line3[100] = { 0 };

		wsprintfW(line1, L"System metric:");
		wsprintfW(line2, L"Screen width: %d", screen_width);
		wsprintfW(line3, L"Screen height: %d", screen_height);

		// Client rect
		wchar_t line4[100] = { 0 };
		wchar_t line5[100] = { 0 };
		wchar_t line6[100] = { 0 };

		wsprintfW(line4, L"Client rect:");
		wsprintfW(line5, L"Client width: %d, height: %d",
			client_rect.right - client_rect.left,
			client_rect.bottom - client_rect.top);
		wsprintfW(line6, L"X: %d, Y: %d", client_rect.left, client_rect.top);

		// Window rect
		wchar_t line7[100] = { 0 };
		wchar_t line8[100] = { 0 };
		wchar_t line9[100] = { 0 };

		int width = window_rect.right - window_rect.left;
		int height = window_rect.bottom - window_rect.top;

		wsprintfW(line7, L"Window rect:");
		wsprintfW(line8, L"Width: %d; Height: %d", width, height);
		wsprintfW(line9, L"X: %d; Y: %d", window_rect.left, window_rect.top);



		TextOut(hdc, 20, 20, line1, 100);
		TextOut(hdc, 30, 40, line2, 100);
		TextOut(hdc, 30, 60, line3, 100);
		TextOut(hdc, 20, 80, line4, 100);
		TextOut(hdc, 30, 100, line5, 100);
		TextOut(hdc, 30, 120, line6, 100);
		TextOut(hdc, 20, 140, line7, 100);
		TextOut(hdc, 30, 160, line8, 100);
		TextOut(hdc, 30, 180, line9, 100);

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
	case WM_CREATE:
		hpen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
		CreateButtons();
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

LRESULT __stdcall ChildWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{

	case WM_SIZE:
	{
		InvalidateRect(hWnd, NULL, false);
		UpdateWindow(hWnd);
	}

	case WM_MOVE:
	{
		InvalidateRect(hWnd, NULL, false);
		UpdateWindow(hWnd);
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		RECT window_rect, client_rect;

		int screen_width = GetSystemMetrics(SM_CXSCREEN);
		int screen_height = GetSystemMetrics(SM_CYSCREEN);

		GetClientRect(hWnd, &client_rect);

		GetWindowRect(hWnd, &window_rect);

		// System metric
		wchar_t line1[100] = { 0 };
		wchar_t line2[100] = { 0 };
		wchar_t line3[100] = { 0 };

		wsprintfW(line1, L"System metric:");
		wsprintfW(line2, L"Screen width: %d", screen_width);
		wsprintfW(line3, L"Screen height: %d", screen_height);

		// Client rect
		wchar_t line4[100] = { 0 };
		wchar_t line5[100] = { 0 };
		wchar_t line6[100] = { 0 };

		wsprintfW(line4, L"Client rect:");
		wsprintfW(line5, L"Client width: %d, height: %d",
			client_rect.right - client_rect.left,
			client_rect.bottom - client_rect.top);
		wsprintfW(line6, L"X: %d, Y: %d", client_rect.left, client_rect.top);

		// Window rect
		wchar_t line7[100] = { 0 };
		wchar_t line8[100] = { 0 };
		wchar_t line9[100] = { 0 };

		int width = window_rect.right - window_rect.left;
		int height = window_rect.bottom - window_rect.top;

		wsprintfW(line7, L"Window rect:");
		wsprintfW(line8, L"Width: %d; Height: %d", width, height);
		wsprintfW(line9, L"X: %d; Y: %d", window_rect.left, window_rect.top);


			
		TextOut(hdc, 20, 20, line1, 100);
		TextOut(hdc, 30, 40, line2, 100);
		TextOut(hdc, 30, 60, line3, 100);
		TextOut(hdc, 20, 80, line4, 100);
		TextOut(hdc, 30, 100, line5, 100);
		TextOut(hdc, 30, 120, line6, 100);
		TextOut(hdc, 20, 140, line7, 100);
		TextOut(hdc, 30, 160, line8, 100);
		TextOut(hdc, 30, 180, line9, 100);

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
	case WM_CREATE:
		hpen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
		CreateButtons();
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

void CreateButtons()
{
	btns[0].init(L"OVERLAPPEDWINDOW", 40, 60, ShowWindowStyle1);
	btns[1].init(L"POPUPWINDOW", 40, 130, ShowWindowStyle2);
	btns[2].init(L"CHILDWINDOW", 40, 200, ShowWindowStyle3);
}

void DrawButtons(HDC hdc)
{
	for (int i = 0; i < BUTTONS_N; i++)
	{
		btns[i].draw(hdc, hpen);
	}
}

void CheckClickOnButtons(HWND hWnd)
{
	for (int i = 0; i < BUTTONS_N; i++)
	{
		if (PtInRect(&btns[i].rect, pt))
		{
			btns[i].callback();
		}
	}
}