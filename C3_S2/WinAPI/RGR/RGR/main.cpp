#pragma warning(disable : 4996)

#include <Windows.h>
#include <cmath>
#include <iostream>

#include "resource.h"

const auto pi = std::acos(-1);
#define MAX_LOADSTRING 128

// Global Variables:
HINSTANCE hInst; // current instance
WCHAR szTitle[MAX_LOADSTRING] = L"RGR_1"; // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING] = L"MAIN_CLASS"; // the main window class name


// Forward declarations of functions included in this code module:
ATOM RegisterMainWinClass(HINSTANCE);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK DlgRectProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK DlgEllipsProc(HWND, UINT, WPARAM, LPARAM);
inline double PercentToRad(double);

struct TSector
{
	double percent;
	COLORREF color;
};

struct MyRect
{
	RECT r;
	COLORREF color;
};


TSector sectors[20];
int sector_count = 0;
int percent_count = 0;
double total_percent = 0.0;

MyRect rect{{20, 20, 220, 220}, RGB(255, 255, 255)};

void printRect(HDC);
void PrintRadPie(HDC, int, int, int, int, double, double, int);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance,
                      _In_ LPWSTR lpCmdLine,
                      _In_ int nCmdShow)
{
	srand(time(nullptr));
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	for (int i = 0; i < 20; i++)
	{
		sectors[i].percent = 0;
		sectors[i].color = 0;
	}

	//Initialize global strings
	//LoadStringW(hInstance, 10, szTitle, MAX_LOADSTRING);
	//LoadStringW(hInstance, 11, szWindowClass, MAX_LOADSTRING);
	//szTitle = L"Lab 6";
	RegisterMainWinClass(hInstance);


	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	//AllocConsole();
	//freopen("CONOUT$", "w", stdout);
	//std::cout << "This works" << std::endl;

	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		if (msg.message == 0x000F)
			std::wcout << L"WM_PAINT" << '\n';
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
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	return RegisterClassExW(&wcex);
}

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

inline double PercentToRad(double percent)
{
	return 2.0 * pi * percent / 100.0;
}

void printRect(HDC hDC)
{
	const auto hpenW1 = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));

	const auto hpenOldPen = static_cast<HPEN>(SelectObject(hDC, hpenW1));

	//Rectangle(hDC, r.r.left, r.r.top, r.r.right, r.r.bottom);

	MoveToEx(hDC, rect.r.left, rect.r.top, nullptr);
	LineTo(hDC, rect.r.right + rect.r.left, rect.r.top);
	MoveToEx(hDC, rect.r.right + rect.r.left, rect.r.top, nullptr);
	LineTo(hDC, rect.r.left + rect.r.right, rect.r.bottom + rect.r.top);
	MoveToEx(hDC, rect.r.left + rect.r.right, rect.r.bottom + rect.r.top, nullptr);
	LineTo(hDC, rect.r.left, rect.r.bottom + rect.r.top);
	MoveToEx(hDC, rect.r.left, rect.r.bottom + rect.r.top, nullptr);
	LineTo(hDC, rect.r.left, rect.r.top);

	SelectObject(hDC, hpenOldPen);
	DeleteObject(hpenW1);
}

void PrintRadPie(HDC hDC, int X0, int Y0, int A, int B, double R1, double R2, int Color)
{
	HBRUSH hBr = CreateSolidBrush(Color);
	HBRUSH hBrOld = static_cast<HBRUSH>(SelectObject(hDC, hBr));

	Pie(hDC, // дескриптор контекста отображения
	    X0, Y0, // координаты верхнего левого угла
	    A + X0, B + Y0, // координаты правого нижнего угла
	    ((A / 2) * cos(R1) + X0 + (A / 2)), (-(B / 2) * sin(R1) + Y0 + (B / 2)), // координаты начала дуги
	    ((A / 2) * cos(R2) + X0 + (A / 2)), (-(B / 2) * sin(R2) + Y0 + (B / 2)) // координаты начала дуги
	);


	SelectObject(hDC, hBrOld);

	DeleteObject(hBr);
}

void PrintRadDiagram(HDC hDC, int X0, int Y0, int A, int B, TSector* sectors, int sector_count)
{
	double R1 = 0;
	for (int i = 0; i < sector_count; i++)
	{
		double R2 = PercentToRad(sectors[i].percent) + R1;
		if (sectors[i].percent >= 1e-3)
		{
			PrintRadPie(hDC, X0, Y0, A, B, R1, R2, sectors[i].color);
		}
		R1 = R2;
	}
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);


			//RECT client_rect;
			//GetClientRect(hWnd, &client_rect);

			printRect(hdc);
			if (sector_count != 0)
				PrintRadDiagram(hdc, rect.r.left, rect.r.top, rect.r.right, rect.r.bottom, sectors, sector_count);

			//Rectangle(hdc, 10, 10, 100, 100);
			EndPaint(hWnd, &ps);
		}
		break;

	case WM_LBUTTONDOWN:
		{
			DialogBox(hInst, MAKEINTRESOURCEW(IDD_DIALOG1), hWnd, DlgRectProc);
			InvalidateRect(hWnd, nullptr, TRUE);
			UpdateWindow(hWnd);
		}
		break;

	case WM_RBUTTONDOWN:
		{
			DialogBox(hInst, MAKEINTRESOURCEW(IDD_DIALOG2), hWnd, DlgEllipsProc);
			InvalidateRect(hWnd, nullptr, TRUE);
			UpdateWindow(hWnd);
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

INT_PTR CALLBACK DlgRectProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
		{
			SetDlgItemInt(hDlg, IDC_EDIT_X, rect.r.left, 0);
			SetDlgItemInt(hDlg, IDC_EDIT_Y, rect.r.top, 0);
			SetDlgItemInt(hDlg, IDC_EDIT_HEIGHT, rect.r.bottom, 0);
			SetDlgItemInt(hDlg, IDC_EDIT_WIDTH, rect.r.right, 0);

			return TRUE;
		}


	case WM_INITDIALOG:
		{
			SetDlgItemInt(hDlg, IDC_EDIT_X, rect.r.left, 0);
			SetDlgItemInt(hDlg, IDC_EDIT_Y, rect.r.top, 0);
			SetDlgItemInt(hDlg, IDC_EDIT_HEIGHT, rect.r.bottom, 0);
			SetDlgItemInt(hDlg, IDC_EDIT_WIDTH, rect.r.right, 0);

			return TRUE;
		}


	case WM_COMMAND:
		{
			switch (wParam)
			{
			case IDOK:
				{
					rect.r.left = GetDlgItemInt(hDlg, IDC_EDIT_X, nullptr, 0);
					rect.r.top = GetDlgItemInt(hDlg, IDC_EDIT_Y, nullptr, 0);
					rect.r.bottom = GetDlgItemInt(hDlg, IDC_EDIT_HEIGHT, nullptr, 0);
					rect.r.right = GetDlgItemInt(hDlg, IDC_EDIT_WIDTH, nullptr, 0);

					EndDialog(hDlg, TRUE);
				}
				break;


			case IDC_BUTTON_CLEAR:
				{
					SetDlgItemInt(hDlg, IDC_EDIT_X, 0, 0);
					SetDlgItemInt(hDlg, IDC_EDIT_Y, 0, 0);
					SetDlgItemInt(hDlg, IDC_EDIT_HEIGHT, 0, 0);
					SetDlgItemInt(hDlg, IDC_EDIT_WIDTH, 0, 0);
				}
				break;

			case IDCANCEL:
				{
					EndDialog(hDlg, TRUE);
				}
				break;


			default: return FALSE;
			}
		}
		break;

	default: return FALSE;
	}

	return TRUE;
}

INT_PTR CALLBACK DlgEllipsProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
		{
			SetDlgItemInt(hDlg, IDC_EDIT_TOTAL, percent_count, 0);
			SetDlgItemInt(hDlg, IDC_EDIT_SECTOR_PERCENTAGE, 0, 0);

			return TRUE;
		}

	case WM_INITDIALOG:
		{
			SetDlgItemInt(hDlg, IDC_EDIT_TOTAL, percent_count, 0);
			SetDlgItemInt(hDlg, IDC_EDIT_SECTOR_PERCENTAGE, 0, 0);
			SetDlgItemInt(hDlg, IDC_EDIT_RED, GetRValue(rect.color), 0);
			SetDlgItemInt(hDlg, IDC_EDIT_GREEN, GetGValue(rect.color), 0);
			SetDlgItemInt(hDlg, IDC_EDIT_BLUE, GetBValue(rect.color), 0);
			SetDlgItemInt(hDlg, IDC_EDIT_SECTOR_PERCENTAGE, percent_count, 0);

			return TRUE;
		}

	case WM_COMMAND:
		{
			switch (wParam)
			{
			case IDOK:
				{
					percent_count = GetDlgItemInt(hDlg, IDC_EDIT_TOTAL, nullptr, 0);
					auto red = GetDlgItemInt(hDlg, IDC_EDIT_RED, nullptr, 0);
					auto green = GetDlgItemInt(hDlg, IDC_EDIT_GREEN, nullptr, 0);
					auto blue = GetDlgItemInt(hDlg, IDC_EDIT_BLUE, nullptr, 0);
					rect.color = RGB(red, green, blue);

					SetDlgItemInt(hDlg, IDC_EDIT_TOTAL, percent_count, 0);

					EndDialog(hDlg, TRUE);
				}
				break;

			case IDC_BUTTON_ADD:
				{
					if (GetDlgItemInt(hDlg, IDC_EDIT_SECTOR_PERCENTAGE, nullptr, 0) + percent_count > 100)
					{
						MessageBox(nullptr, L"Too large percentage", L"Limit exceeded", MB_OK | MB_ICONSTOP);
						return FALSE;
					}
					sectors[sector_count].percent = GetDlgItemInt(hDlg, IDC_EDIT_SECTOR_PERCENTAGE, nullptr, 0);

					percent_count += GetDlgItemInt(hDlg, IDC_EDIT_SECTOR_PERCENTAGE, nullptr, 0);

					sectors[sector_count].color = RGB(
						GetDlgItemInt(hDlg, IDC_EDIT_RED, FALSE, 0),
						GetDlgItemInt(hDlg, IDC_EDIT_GREEN, FALSE, 0),
						GetDlgItemInt(hDlg, IDC_EDIT_BLUE, FALSE, 0)
					);

					sector_count++;
					SetDlgItemInt(hDlg, IDC_EDIT_TOTAL, percent_count, 0);
				}
				break;


			case IDC_BUTTON_REMOVE:
				{
					if (percent_count > 0)
					{
						sector_count--;

						percent_count -= static_cast<int>(sectors[sector_count].percent);

						SetDlgItemInt(hDlg, IDC_EDIT_TOTAL, percent_count, 0);


						sectors[sector_count].percent = 0;

						sectors[sector_count].color = 0;
					}
				}
				break;

			case IDCANCEL:
				{
					EndDialog(hDlg, TRUE);
				}
				break;


			default: return FALSE;
			}
		}
		break;

	default: return FALSE;
	}

	return TRUE;
}
