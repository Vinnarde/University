#pragma warning(disable : 4996)

#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <Windows.h>
#include "resource2.h"

const auto pi = std::acos(-1);
#define MAX_LOADSTRING 128

// Global Variables:
HINSTANCE hInst; // current instance
WCHAR szTitle[MAX_LOADSTRING] = L"Pepega"; // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING] = L"MAIN_CLASS"; // the main window class name

WCHAR szPosX[10];
WCHAR szPosY[10];
WCHAR szN[10];
WCHAR szRadius[10];
COLORREF szColor;
WCHAR szTimertemp[10];
UINT szdTimer;

HWND cur_hwnd;

bool szDialogChange = false;
bool szDialogChangeColor = false;
bool valid = false;

struct FLOWER
{
	int N; // количество лепестков (вид изображения)
	int x, y; // координаты центра цветка (местоположение)
	int r; // радиус цветка, т.е. длина лепестка (размер)
	COLORREF color; // цвет линии (цвет изображения)
};

FLOWER flw{};
// Forward declarations of functions included in this code module:
ATOM RegisterMainWinClass(HINSTANCE);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
void flower(HDC, FLOWER);
bool validate(HWND hWnd);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow)
{
	srand(time(nullptr));
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);


	// Initialize global strings
	//LoadStringW(hInstance, 10, szTitle, MAX_LOADSTRING);
	//LoadStringW(hInstance, 11, szWindowClass, MAX_LOADSTRING);
	//szTitle = L"Lab 6"
	RegisterMainWinClass(hInstance);


	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	std::cout << "This works" << std::endl;

	//HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPI3));

	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		//if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		//{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		if (msg.message == 0x000F)
			std::wcout << L"WM_PAINT" << '\n';
		//}
	}

	return static_cast<int>(msg.wParam);
}


ATOM RegisterMainWinClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = static_cast<HBRUSH>(CreateSolidBrush(RGB(40, 40, 40)));
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDR_MENU_MAIN);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

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

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch (message)
	{
	case WM_TIMER:
	{
		InvalidateRect(hWnd, nullptr, true);
		UpdateWindow(hWnd);
	}
	break;
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case ID_SETVALUE:
		{
			cur_hwnd = hWnd;
			if (DialogBox(hInst, MAKEINTRESOURCEW(IDD_DIALOG_OPTIONS), hWnd, DlgProc) == IDOK)
			{
				InvalidateRect(hWnd, nullptr, true);
				UpdateWindow(hWnd);

				if (valid)
					SetTimer(hWnd, 0, szdTimer, nullptr);
			}
		} break;

		case ID_SETCOLOR:
		{
			CHOOSECOLOR cc;                 // common dialog box structure 
			static COLORREF acrCustClr[16]; // array of custom colors 
			HWND hwnd;                      // owner window
			HBRUSH hbrush;                  // brush handle
			static DWORD rgbCurrent;        // initial color selection

			// Initialize CHOOSECOLOR 
			ZeroMemory(&cc, sizeof(cc));
			//cc.lpfnHook = CCHookProc;
			cc.lStructSize = sizeof(cc);
			cc.hwndOwner = hWnd;
			cc.lpCustColors = (LPDWORD)acrCustClr;
			cc.rgbResult = rgbCurrent;
			cc.Flags = CC_FULLOPEN | CC_RGBINIT ;

			if (ChooseColor(&cc) == TRUE)
			{
				hbrush = CreateSolidBrush(cc.rgbResult);

				szColor = rgbCurrent = cc.rgbResult;
				szDialogChangeColor = true;
				InvalidateRect(hWnd, nullptr, true);
				UpdateWindow(hWnd);
			}
		}break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;

	case WM_CHAR:
	{
		if (wParam == 120)
		{
			InvalidateRect(hWnd, nullptr, true);
			UpdateWindow(hWnd);
		}
	}
	break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);


		RECT client_rect;
		GetClientRect(hWnd, &client_rect);
		const uint16_t width = client_rect.right - client_rect.left;
		const uint16_t height = client_rect.bottom - client_rect.top;

		//flw.color = RGB(255, 255, 255);

		if (szDialogChange || szDialogChangeColor)
		{
			if (szDialogChangeColor)
			{
				flw.color = szColor;
				szDialogChangeColor = false;
			}
			szDialogChange = false;
		}
		else
		{
			flw.N = rand() % 21 + 5;		// 5-25
			flw.r = rand() % 201 + 20;		// 20-220
			flw.x = rand() % (width - 2 * flw.r + 1) + flw.r;
			flw.y = rand() % (height - 2 * flw.r + 1) + flw.r;
			flw.color = RGB(rand() % 256, rand() % 256, rand() % 256);
		}

		std::wstring line1(L"width: " + std::to_wstring(width) + L", height: " + std::to_wstring(height));
		std::wstring line2(
			L"x: " + std::to_wstring(flw.x) + L", y: " + std::to_wstring(flw.y) + L", radius: " +
			std::to_wstring(flw.r));
		std::wstring line3(L"N: " + std::to_wstring(flw.N) + L", Color: ");
		std::wstring line4;
		std::wstring line5;

		SetBkColor(hdc, RGB(40, 40, 40));
		SetTextColor(hdc, RGB(255, 255, 255));

		HFONT hFont = CreateFont(24, 10, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_OUTLINE_PRECIS,
			CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, VARIABLE_PITCH, TEXT("Arial"));
		SelectObject(hdc, hFont);

		//SelectObject(hdc, hpen);

		TextOutW(hdc, 20, 20, line1.c_str(), line1.length());
		TextOutW(hdc, 20, 50, line2.c_str(), line2.length());
		TextOutW(hdc, 20, 80, line3.c_str(), line3.length());

		RECT color_r = { 150, 80, 174, 104 };
		FillRect(hdc, &color_r, CreateSolidBrush(flw.color));

		flower(hdc, flw);
		//Rectangle(hdc, 10, 10, 100, 100);
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
		//case WM_CREATE:
		//hpen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for change position dialog box.
INT_PTR CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
	{
		SetDlgItemTextW(hDlg, IDC_EDIT_X, std::to_wstring(flw.x).c_str());
		SetDlgItemTextW(hDlg, IDC_EDIT_Y, std::to_wstring(flw.y).c_str());
		SetDlgItemTextW(hDlg, IDC_EDIT_N, std::to_wstring(flw.N).c_str());
		SetDlgItemTextW(hDlg, IDC_EDIT_RADIUS, std::to_wstring(flw.r).c_str());
		SetDlgItemTextW(hDlg, IDC_EDIT_TIMER, std::to_wstring(szdTimer).c_str());
		return (INT_PTR)TRUE;
	}
	break;
	case WM_COMMAND:
	{
		if (LOWORD(wParam) == IDOK)
		{
			GetDlgItemTextW(hDlg, IDC_EDIT_X, szPosX, 5);
			GetDlgItemTextW(hDlg, IDC_EDIT_Y, szPosY, 5);
			GetDlgItemTextW(hDlg, IDC_EDIT_N, szN, 3);
			GetDlgItemTextW(hDlg, IDC_EDIT_RADIUS, szRadius, 4);
			GetDlgItemTextW(hDlg, IDC_EDIT_TIMER, szTimertemp, 10);
			szDialogChange = true;

			if (valid = validate(cur_hwnd))
			{

				flw.x = wcstol(szPosX, nullptr, 10);
				flw.y = wcstol(szPosY, nullptr, 10);
				flw.N = wcstol(szN, nullptr, 10);
				flw.r = wcstol(szRadius, nullptr, 10);
				szdTimer = wcstol(szTimertemp, nullptr, 10);
			}


			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	}
	return (INT_PTR)FALSE;
}

void flower(HDC hDC, struct FLOWER flw)
// функция вывода цветка с N лепестками
{
	double rx, ry, x1, x2, x3, x4, x5, x6, y1, y2, y3, y4, y5, y6, f, df;
	rx = flw.r / 2.; // r - длина лепестка, rx - ее половина
	x1 = flw.x + rx;
	y1 = flw.y; // x1, y1 - центр нулевого лепестка
	ry = 2. * pi * rx * 0.7 / static_cast<float>(flw.N);
	ry = ry / 2.;
	// ry - половина ширины лепестка 
	df = 2. * pi / static_cast<float>(flw.N); // df - угол, занимаемый лепестком

	HPEN pen = CreatePen(PS_SOLID, 3, flw.color);
	SelectObject(hDC, pen);


	for (int i = 0; i < flw.N; i++)
		// рисуем очередной лепесток цветка с N лепестками ( 0<=i<N)
	{
		MoveToEx(hDC, flw.x, flw.y, nullptr);
		// сдвинуть начальную позицию вывода в центр 
		// цветка (функция MoveToEx)
		f = static_cast<float>(i) * df; // f - угол поворота для i-того лепестка

		// вывод лепестка, повернутого относительного
		// нулевого на f радиан
		for (x2 = -rx; x2 < rx; x2 += 0.5)
			// вывод первой половины лепестка
		{
			y2 = sqrt((1. - (x2 * x2) / (rx * rx)) * (ry * ry));
			x3 = x1 + x2;
			y3 = y1 - y2;
			x4 = x3 - flw.x;
			y4 = y3 - flw.y;
			x5 = x4 * cos(f) - y4 * sin(f);
			y5 = x4 * sin(f) + y4 * cos(f);
			x6 = x5 + flw.x;
			y6 = y5 + flw.y;

			LineTo(hDC, x6, y6);
		}
		for (x2 = rx; x2 > -rx; x2 -= 0.5)
			// вывод второй половины лепестка
		{
			y2 = sqrt((1. - (x2 * x2) / (rx * rx)) * (ry * ry));
			x3 = x1 + x2;
			y3 = y1 + y2;
			x4 = x3 - flw.x;
			y4 = y3 - flw.y;
			x5 = x4 * cos(f) - y4 * sin(f);
			y5 = x4 * sin(f) + y4 * cos(f);
			x6 = x5 + flw.x;
			y6 = y5 + flw.y;
			// нарисуем очередной фрагмент контура 
			// лепестка (функция LineTo)

			LineTo(hDC, x6, y6);
		}

		LineTo(hDC, flw.x, flw.y);
	}
}

bool validate(HWND hWnd)
{
	auto temp_x = wcstol(szPosX, nullptr, 10);
	auto temp_y = wcstol(szPosY, nullptr, 10);
	auto temp_N = wcstol(szN, nullptr, 10);
	auto temp_radius = wcstol(szRadius, nullptr, 10);
	auto temp_timer = wcstol(szTimertemp, nullptr, 10);

	RECT client_rect;
	GetClientRect(hWnd, &client_rect);

	auto width = client_rect.right - client_rect.left;
	auto height = client_rect.bottom - client_rect.top;

	std::wstring str = L"Invalid value ";

	if (temp_radius < 20 || temp_radius > 220)
	{
		MessageBoxW(hWnd, (str + L"Radius!").c_str(), nullptr, MB_OK);
		return false;
	}

	if (temp_x - temp_radius < 0 || temp_x + temp_radius > width)
	{
		MessageBoxW(hWnd, (str + L"x!").c_str(), nullptr, MB_OK);
		return false;
	}

	if (temp_y - temp_radius < 0 || temp_y + temp_radius > height)
	{
		MessageBoxW(hWnd, (str + L"y!").c_str(), nullptr, MB_OK);
		return false;
	}

	if (temp_N < 5 || temp_N > 25)
	{
		MessageBoxW(hWnd, (str + L"N!").c_str(), nullptr, MB_OK);
		return false;
	}

	if (temp_timer < 20 || temp_timer > 10000)
	{
		MessageBoxW(hWnd, (str + L"dTimer!").c_str(), nullptr, MB_OK);
		return false;
	}

	return true;
}