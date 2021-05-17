// --- ������������ ���������� ����
#include <windows.h>

#include "Resource.h"

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

// --- �������� ������� �������� ����
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// --- ���������� ����������
HINSTANCE hInst; 		// ���������� ���������� ����������
wchar_t ClassName[] = L"Window"; 		// �������� ������ ����
wchar_t AppTitle[] = L"Application Win32"; 	// ��������� �������� ����

// --- ������� WinMain
int APIENTRY WINAPI wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow
)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	
	WNDCLASS wc; 	// ��������� ��� ���������� � ������ ����
	HWND hWnd; 	// ���������� �������� ���� ����������
	MSG msg; 	// ��������� ��� �������� ���������
// ��������� ���������� ���������� ���������� � ����������
// ����������, ����� ��� ������������� ��������������� �� �
// ������� ����.
	hInst = hInstance;

	LoadStringW(hInstance, IDS_APP_TITLE, AppTitle, 100);
	LoadStringW(hInstance, IDC_WINAPI3, ClassName, 100);
	
	// --- ���������, ���� �� ���������� �������� �����.
	// ������������� �������� FindWindow, ������� ���������
	// ����� ���� �������� 
	// ������ �� ����� ������ ��� �� ��������� ����:
	// HWND FindWindow(LPCTSTR lpClassName,
	// LPCTSTRlpWindowName);
	// ����� �������� lpClassName ���������� ��������� ��
	// ��������� ������, � ������� ���������� �������� ���
	// ������ �������� ����. �� ���� ������ � ���� �� ������ 
	// ����� ������� ��������� ����. ���� ���������� ����� 
	// ���� � �������� ����������, �� ��� ��������� �������
	// �������� ����� �������� lpWindowName. ���� �� �������� 
	// ����� ����, �� �������� lpWindowName ����� �����
	// �������� NULL.
	if ((hWnd = FindWindow(ClassName, NULL)) != NULL)
	{
		// ������������ ����� �� �������, ����� ���������� ���
		// ��������, � ����� ���. ����� �� ��������� ����������, 
		// �� �������, ��� �� ������ �������� ��� ������� ����.
		// �������, ���� ���������� ���� �������� �����,
		// ������������� �������������� � ��������� �� ��������
		// ���� ��� ������� ����. ��� ������ ��, � ���� ������������
		// ������������.
		if (IsIconic(hWnd)) ShowWindow(hWnd, SW_RESTORE);
		SetForegroundWindow(hWnd);

		// ������� ���������� ����� - ������ ����� �����
		// ������������.
		return FALSE;
	}

	// --- ���������� ����� �� ������� - ������� WinMain
	// ���������� � �������������. ���������� ���������
	// WNDCLASS ��� ����������� ������ ����.
	memset(&wc, 0, sizeof(wc));
	wc.lpszClassName = ClassName;		// ��� ������ ����
	wc.lpfnWndProc = (WNDPROC)WndProc;
	// ����� ������� �������
	wc.style = CS_HREDRAW | CS_VREDRAW;	// ����� ������ 
	wc.hInstance = hInstance;		// ��������� ����������
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	// ����������� ��� ����
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	// ������ ���� ��� ����
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	// ����� ��� ����
	wc.lpszMenuName = MAKEINTRESOURCEW(IDC_WINAPI3);			// ������ ���� ����
	wc.cbClsExtra = 0;			// �������������� ������
	wc.cbWndExtra = 0;			// �������������� ������
	// P���������� ������ ����.
	RegisterClass(&wc);

	// ������� ������� ���� ����������.
	hWnd = CreateWindow(
		ClassName, 			// ��� ������ ����
		AppTitle,			// ��������� ���� 
		WS_OVERLAPPEDWINDOW, 		// ����� ����
		CW_USEDEFAULT,			// X-���������� 
		CW_USEDEFAULT,			// Y-���������� 
		CW_USEDEFAULT,			// ������ ����
		CW_USEDEFAULT,			// ������ ����
		NULL,			// ���������� ����-��������
		NULL,			// ���������� ���� ����
		hInst,		// ���������� ���������� ����������
		NULL);		// �������������� ����������
	if (!hWnd)
	{
		// ���� �� �������, ������ ��������������.
		MessageBox(NULL,
			L"Create: error", AppTitle, MB_OK | MB_ICONSTOP);
		return FALSE;
	}

	// ���������� ����.
	ShowWindow(hWnd, nCmdShow);

	// ��������� ���������� ���������� ������� ����.
	UpdateWindow(hWnd);

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPI3));
	
	// ��������� ���� ��������� ������� ���������.
	// ������� GetMessage �������� ��������� �� �������, 
	// ������ false ��� ������� �� ������� ��������� WM_QUIT
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return msg.wParam;
}

// --- ������� ����
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//wchar_t str[] = L"First Windows aplication";

	switch (msg)
	{
		// ���������� �������� ���������� ���������� ������� ����.
	case WM_PAINT:
	{
		HDC hDC;
		PAINTSTRUCT ps;

		hDC = BeginPaint(hWnd, &ps);
		// �������� �������� ����
		//TextOut(hDC, 20, 20, str, wcslen(str));
		// ���������� �����
		EndPaint(hWnd, &ps);
		// ���������� �������� ����
	}; break;

	// ������ ����� ������� ���� � ���������� ������� ����.
	case WM_LBUTTONDOWN:
	{
		/*MessageBox(hWnd, L"32-bit aplication", L"Window",
			MB_OK | MB_ICONINFORMATION);*/
		RECT rect;
		GetWindowRect(hWnd, &rect);
		rect.top += 100;
		rect.bottom -= 100;
		rect.left += 100;
		rect.right -= 100;
		ClipCursor(&rect);
	}; break;

	case WM_MOUSEMOVE:
	{
		// ��������� ������ ����
		UINT fwKeys = wParam;
		// �������������� ������� �������
		int xPos = LOWORD(lParam);
		// ������������ ������� �������
		int yPos = HIWORD(lParam);

		if (fwKeys & MK_LBUTTON || fwKeys & MK_SHIFT)
		{
			HDC hDC = GetDC(hWnd);
			SetPixel(hDC, xPos, yPos, RGB(0, 0, 0));
			ReleaseDC(hWnd, hDC);
		}
	}; break;
	// ������ ������ ������� ���� � ���������� ������� ����.
	case WM_RBUTTONDOWN:
	{
		RECT rect;
		GetWindowRect(hWnd, &rect);
		//ClipCursor(&rect);
		SetCursorPos(rect.left + 8, rect.top + 32);

	}break;

	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_LEFT:
		{
			POINT pos;
			GetCursorPos(&pos);
			pos.x -= 1;
			SetCursorPos(pos.x, pos.y);
		}break;
		case VK_RIGHT:
		{
			POINT pos;
			GetCursorPos(&pos);
			pos.x += 1;
			SetCursorPos(pos.x, pos.y);
		}break;

		case VK_UP:
		{
			POINT pos;
			GetCursorPos(&pos);
			pos.y -= 1;
			SetCursorPos(pos.x, pos.y);
		}break;
		case VK_DOWN:
		{
			POINT pos;
			GetCursorPos(&pos);
			pos.y += 1;
			SetCursorPos(pos.x, pos.y);
		}break;

		}
	}break;

	case WM_CREATE:
	{

	}; break;

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
			return DefWindowProc(hWnd, msg, wParam, lParam);
		}
	}
	break;

	// ������������ ������ ����.
	case WM_DESTROY:
	{
		// ���� ������ ������� �������� ������� ��������
		// �������� ����, �� ������� � ������� ���������
		// ���������� ������� ��������� WM_QUIT 
		PostQuitMessage(0);
	}; break;

	// �������������� ��������� �������� � �����������
	// ������� ��������� ��������� �� ���������.
	default: return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0l;
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