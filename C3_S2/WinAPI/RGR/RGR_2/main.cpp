#pragma warning(disable : 4996)

#include <Windows.h>
#include <cmath>
#include <iostream>
#include <string>
#include "resource.h"

//#define IDM_TEXT_REGULAR 1
//#define IDM_TEXT_BOLD 2
//#define IDM_TEXT_ITALIC 3
//#define IDM_TEXT_BOLD_ITALIC 4
//
//#define IDM_ALIGN_LEFT 5
//#define IDM_ALIGN_CENTER 6
//#define IDM_ALIGN_RIGHT 7


int activeText = IDM_TEXT_REGULAR;
int activeAlign = IDM_ALIGN_CENTER;

HMENU hMenuFont; // Font
HMENU hMenuAlign;

const auto pi = std::acos(-1);
#define MAX_LOADSTRING 128

// Global Variables:
HINSTANCE hInst; // current instance
WCHAR szTitle[MAX_LOADSTRING] = L"Pepega"; // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING] = L"MAIN_CLASS"; // the main window class name
HWND hwndText;

// Forward declarations of functions included in this code module:
ATOM RegisterMainWinClass(HINSTANCE);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void AddMenus(HWND hwnd);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance,
                      _In_ LPWSTR lpCmdLine,
                      _In_ int nCmdShow)
{
	srand(time(nullptr));
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	RegisterMainWinClass(hInstance);


	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
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
	//wcex.lpszMenuName = MAKEINTRESOURCEW(IDR_MENU1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	return RegisterClassExW(&wcex);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
                         WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:

		AddMenus(hwnd);
		//SendMessage(hwnd, WM_COMMAND, LOWORD(1337), NULL);
		break;

	case WM_COMMAND:

		switch (LOWORD(wParam))
		{
		case IDM_TEXT_REGULAR:
			CheckMenuRadioItem(hMenuFont, IDM_TEXT_REGULAR, IDM_TEXT_BOLD_ITALIC,
			                   IDM_TEXT_REGULAR, MF_BYCOMMAND);
			activeText = IDM_TEXT_REGULAR;
			break;

		case IDM_TEXT_BOLD:
			CheckMenuRadioItem(hMenuFont, IDM_TEXT_REGULAR, IDM_TEXT_BOLD_ITALIC,
			                   IDM_TEXT_BOLD, MF_BYCOMMAND);
			activeText = IDM_TEXT_BOLD;
			break;

		case IDM_TEXT_ITALIC:
			CheckMenuRadioItem(hMenuFont, IDM_TEXT_REGULAR, IDM_TEXT_BOLD_ITALIC,
			                   IDM_TEXT_ITALIC, MF_BYCOMMAND);
			activeText = IDM_TEXT_ITALIC;
			break;

		case IDM_TEXT_BOLD_ITALIC:
			CheckMenuRadioItem(hMenuFont, IDM_TEXT_REGULAR, IDM_TEXT_BOLD_ITALIC,
			                   IDM_TEXT_BOLD_ITALIC, MF_BYCOMMAND);
			activeText = IDM_TEXT_BOLD_ITALIC;
			break;
		case IDM_ALIGN_LEFT:
			CheckMenuRadioItem(hMenuAlign, IDM_ALIGN_LEFT, IDM_ALIGN_RIGHT,
			                   IDM_ALIGN_LEFT, MF_BYCOMMAND);
			activeAlign = IDM_ALIGN_LEFT;
			break;

		case IDM_ALIGN_CENTER:
			CheckMenuRadioItem(hMenuAlign, IDM_ALIGN_LEFT, IDM_ALIGN_RIGHT,
			                   IDM_ALIGN_CENTER, MF_BYCOMMAND);
			activeAlign = IDM_ALIGN_CENTER;
			break;
		case IDM_ALIGN_RIGHT:
			CheckMenuRadioItem(hMenuAlign, IDM_ALIGN_LEFT, IDM_ALIGN_RIGHT,
			                   IDM_ALIGN_RIGHT, MF_BYCOMMAND);
			activeAlign = IDM_ALIGN_RIGHT;
			break;

		case 1337:
			{
				bool bold = (activeText == IDM_TEXT_BOLD || activeText == IDM_TEXT_BOLD_ITALIC);
				bool italic = (activeText == IDM_TEXT_ITALIC || activeText == IDM_TEXT_BOLD_ITALIC);

				const auto font_weight = bold ? 750 : 400;
				const auto font_width = 36;
				const auto font_height = 15;

				// Customize
				HFONT hFont = CreateFontW(font_width, font_height, 0, 0, font_weight, italic, FALSE, FALSE,
				                          DEFAULT_CHARSET,
				                          OUT_OUTLINE_PRECIS,
				                          CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, VARIABLE_PITCH, TEXT("Arial"));

				LONG_PTR new_style = 0;

				if (activeAlign == IDM_ALIGN_LEFT)
					new_style = SS_LEFT;
				else if (activeAlign == IDM_ALIGN_CENTER)
					new_style = SS_CENTER;
				else if (activeAlign == IDM_ALIGN_RIGHT)
					new_style = SS_RIGHT;

				LONG_PTR s = GetWindowLongPtr(hwndText, GWL_STYLE);

				s = (s & ~(SS_LEFT | SS_CENTER | SS_RIGHT)) | new_style;

				SetWindowLongPtr(hwndText, GWL_STYLE, s);

				SendMessage(hwndText, WM_SETFONT, (WPARAM)hFont, TRUE);


				//InvalidateRect(hwndText, nullptr, TRUE);
				//UpdateWindow(hwndText);
			}
			break;
		}


		break;

	case WM_DESTROY:

		PostQuitMessage(0);
		break;
	}

	return DefWindowProcW(hwnd, msg, wParam, lParam);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
	                          CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	RECT rect;
	GetClientRect(hWnd, &rect);

	const auto button_width = 100;
	const auto button_height = 40;


	auto width = rect.right - rect.left;
	auto height = rect.bottom - rect.top;
	auto x_pos = (width - button_width) / 2;
	auto y_pos = (height - button_height) / 2;


	HWND hwndButton = CreateWindowW(
		L"BUTTON", // Predefined class; Unicode assumed 
		L"OK", // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, // Styles 
		x_pos, // x position 
		y_pos, // y position 
		button_width, // Button width
		button_height, // Button height
		hWnd, // Parent window
		reinterpret_cast<HMENU>(1337), // Control identifier.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL); // Pointer not needed.

	auto text_width = 400;
	auto text_height = 40;
	x_pos = (width - text_width) / 2;
	y_pos = height / 2 - 50 - text_height;

	hwndText = CreateWindowW(
		TEXT("STATIC"), TEXT("Trial output"),
		WS_VISIBLE | WS_CHILD,
		x_pos, y_pos, text_width, text_height,
		hWnd,
		nullptr,
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		nullptr);


	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}


void AddMenus(HWND hwnd)
{
	HMENU hMenubar = CreateMenu();
	hMenuFont = CreateMenu();
	hMenuAlign = CreateMenu();

	AppendMenuW(hMenuFont, MF_STRING, IDM_TEXT_REGULAR, L"&Regular");
	AppendMenuW(hMenuFont, MF_STRING, IDM_TEXT_BOLD, L"&Bold");
	AppendMenuW(hMenuFont, MF_STRING, IDM_TEXT_ITALIC, L"&Italic");
	AppendMenuW(hMenuFont, MF_STRING, IDM_TEXT_BOLD_ITALIC, L"Bold Italic");

	CheckMenuRadioItem(hMenuFont, IDM_TEXT_REGULAR, IDM_TEXT_BOLD_ITALIC,
	                   IDM_TEXT_REGULAR, MF_BYCOMMAND);

	AppendMenuW(hMenuAlign, MF_STRING, IDM_ALIGN_LEFT, L"&Left align");
	AppendMenuW(hMenuAlign, MF_STRING, IDM_ALIGN_CENTER, L"&Center align");
	AppendMenuW(hMenuAlign, MF_STRING, IDM_ALIGN_RIGHT, L"&Right align");

	CheckMenuRadioItem(hMenuAlign, IDM_ALIGN_LEFT, IDM_ALIGN_RIGHT,
	                   IDM_ALIGN_CENTER, MF_BYCOMMAND);

	AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR)hMenuFont, L"&Font");
	AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR)hMenuAlign, L"&Text Align");

	SetMenu(hwnd, hMenubar);
}
