// --- Обязательный включаемый файл
#include <windows.h>

#include "Resource.h"

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

// --- Описание функции главного окна
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// --- Глобальные переменные
HINSTANCE hInst; 		// Дескриптор экземпляра приложения
wchar_t ClassName[] = L"Window"; 		// Название класса окна
wchar_t AppTitle[] = L"Application Win32"; 	// Заголовок главного окна

// --- Функция WinMain
int APIENTRY WINAPI wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow
)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	
	WNDCLASS wc; 	// Структура для информации о классе окна
	HWND hWnd; 	// Дескриптор главного окна приложения
	MSG msg; 	// Структура для хранения сообщения
// Сохраняем дескриптор экземпляра приложения в глобальной
// переменной, чтобы при необходимости воспользоваться им в
// функции окна.
	hInst = hInstance;

	LoadStringW(hInstance, IDS_APP_TITLE, AppTitle, 100);
	LoadStringW(hInstance, IDC_WINAPI3, ClassName, 100);
	
	// --- Проверяем, было ли приложение запущено ранее.
	// Воспользуемся функцией FindWindow, которая позволяет
	// найти окно верхнего 
	// уровня по имени класса или по заголовку окна:
	// HWND FindWindow(LPCTSTR lpClassName,
	// LPCTSTRlpWindowName);
	// Через параметр lpClassName передается указатель на
	// текстовую строку, в которую необходимо записать имя
	// класса искомого окна. На базе одного и того же класса 
	// можно создать несколько окон. Если необходимо найти 
	// окно с заданным заголовком, то имя заголовка следует
	// передать через параметр lpWindowName. Если же подойдет 
	// любое окно, то параметр lpWindowName может иметь
	// значение NULL.
	if ((hWnd = FindWindow(ClassName, NULL)) != NULL)
	{
		// Пользователь может не помнить, какие приложения уже
		// запущены, а какие нет. Когда он запускает приложение, 
		// то ожидает, что на экране появится его главное окно.
		// Поэтому, если приложение было запущено ранее,
		// целесообразно активизировать и выдвинуть на передний
		// план его главное окно. Это именно то, к чему приготовился
		// пользователь.
		if (IsIconic(hWnd)) ShowWindow(hWnd, SW_RESTORE);
		SetForegroundWindow(hWnd);

		// Найдена работающая копия - работа новой копии
		// прекращается.
		return FALSE;
	}

	// --- Работающая копия не найдена - функция WinMain
	// приступает к инициализации. Заполнение структуры
	// WNDCLASS для регистрации класса окна.
	memset(&wc, 0, sizeof(wc));
	wc.lpszClassName = ClassName;		// Имя класса окон
	wc.lpfnWndProc = (WNDPROC)WndProc;
	// Адрес оконной функции
	wc.style = CS_HREDRAW | CS_VREDRAW;	// Стиль класса 
	wc.hInstance = hInstance;		// Экземпляр приложения
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	// Пиктограмма для окон
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	// Курсор мыши для окон
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	// Кисть для окон
	wc.lpszMenuName = MAKEINTRESOURCEW(IDC_WINAPI3);			// Ресурс меню окон
	wc.cbClsExtra = 0;			// Дополнительная память
	wc.cbWndExtra = 0;			// Дополнительная память
	// Pегистрация класса окна.
	RegisterClass(&wc);

	// Создаем главное окно приложения.
	hWnd = CreateWindow(
		ClassName, 			// Имя класса окон
		AppTitle,			// Заголовок окна 
		WS_OVERLAPPEDWINDOW, 		// Стиль окна
		CW_USEDEFAULT,			// X-координаты 
		CW_USEDEFAULT,			// Y-координаты 
		CW_USEDEFAULT,			// Ширина окна
		CW_USEDEFAULT,			// Высота окна
		NULL,			// Дескриптор окна-родителя
		NULL,			// Дескриптор меню окна
		hInst,		// Дескриптор экземпляра приложения
		NULL);		// Дополнительная информация
	if (!hWnd)
	{
		// Окно не создано, выдаем предупреждение.
		MessageBox(NULL,
			L"Create: error", AppTitle, MB_OK | MB_ICONSTOP);
		return FALSE;
	}

	// Отображаем окно.
	ShowWindow(hWnd, nCmdShow);

	// Обновляем содержимое клиентской области окна.
	UpdateWindow(hWnd);

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPI3));
	
	// Запускаем цикл обработки очереди сообщений.
	// Функция GetMessage получает сообщение из очереди, 
	// выдает false при выборке из очереди сообщения WM_QUIT
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

// --- Функция окна
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//wchar_t str[] = L"First Windows aplication";

	switch (msg)
	{
		// Необходимо обновить содержимое клиентской области окна.
	case WM_PAINT:
	{
		HDC hDC;
		PAINTSTRUCT ps;

		hDC = BeginPaint(hWnd, &ps);
		// Получить контекст окна
		//TextOut(hDC, 20, 20, str, wcslen(str));
		// Нарисовать текст
		EndPaint(hWnd, &ps);
		// Освободить контекст окна
	}; break;

	// Нажата левая клавиша мыши в клиентской области окна.
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
		// состояние кнопок мыши
		UINT fwKeys = wParam;
		// горизонтальная позиция курсора
		int xPos = LOWORD(lParam);
		// вертикальная позиция курсора
		int yPos = HIWORD(lParam);

		if (fwKeys & MK_LBUTTON || fwKeys & MK_SHIFT)
		{
			HDC hDC = GetDC(hWnd);
			SetPixel(hDC, xPos, yPos, RGB(0, 0, 0));
			ReleaseDC(hWnd, hDC);
		}
	}; break;
	// Нажата правая клавиша мыши в клиентской области окна.
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

	// Пользователь удалил окно.
	case WM_DESTROY:
	{
		// Если данная функция является оконной функцией
		// главного окна, то следует в очередь сообщений
		// приложения послать сообщение WM_QUIT 
		PostQuitMessage(0);
	}; break;

	// Необработанные сообщения передаем в стандартную
	// функцию обработки сообщений по умолчанию.
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