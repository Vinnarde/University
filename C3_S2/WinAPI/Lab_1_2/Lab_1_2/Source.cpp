#include <windows.h>

// --- Описание функции главного окна
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// --- Глобальные переменные
HINSTANCE hInst; 		// Дескриптор экземпляра приложения
char ClassName[] = "Window"; 		// Название класса окна
char AppTitle[] = "Application Win32"; 	// Заголовок главного окна

// --- Функция WinMain
int WINAPI WinMain(HINSTANCE hInstance,
	// Дескриптор экземпляра приложения
	HINSTANCE hPrevInstance, // В Win32 всегда равен NULL
	LPSTR lpCmdLine,
	// Указатель на командную строку. Он // позволяет
	// приложению получать данные из командной строки.
	int nCmdShow
	// Определяет, как приложение первоначально 
	// отображается на дисплее: пиктограммой
	// (nCmdShow = SW_SHOWMINNOACTIVE) 
	// или в виде открытого окна 					//(nCmdShow = SW_SHOWNORMAL).
)
{
	WNDCLASS wc; 	// Структура для информации о классе окна
	HWND hWnd; 	// Дескриптор главного окна приложения
	MSG msg; 	// Структура для хранения сообщения
// Сохраняем дескриптор экземпляра приложения в глобальной
// переменной, чтобы при необходимости воспользоваться им в
// функции окна.
	hInst = hInstance;

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
	wc.lpszMenuName = NULL;			// Ресурс меню окон
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
			"Create: error", AppTitle, MB_OK | MB_ICONSTOP);
		return FALSE;
	}

	// Отображаем окно.
	ShowWindow(hWnd, nCmdShow);

	// Обновляем содержимое клиентской области окна.
	UpdateWindow(hWnd);

	// Запускаем цикл обработки очереди сообщений.
	// Функция GetMessage получает сообщение из очереди, 
	// выдает false при выборке из очереди сообщения WM_QUIT
	while (GetMessage(&msg, NULL, 0, 0))
	{
		// Преобразование некоторых сообщений, 
		// полученных с помощью клавиатуры
		TranslateMessage(&msg);
		// Отправляем сообщение оконной процедуре
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

// --- Функция окна
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	char str[] = "First Windows aplication";

	switch (msg)
	{
		// Необходимо обновить содержимое клиентской области окна.
	case WM_PAINT:
	{
		HDC hDC;
		PAINTSTRUCT ps;

		hDC = BeginPaint(hWnd, &ps);
		// Получить контекст окна
		TextOut(hDC, 20, 20, str, strlen(str));
		// Нарисовать текст
		EndPaint(hWnd, &ps);
		// Освободить контекст окна
	}; break;

	// Нажата левая клавиша мыши в клиентской области окна.
	case WM_LBUTTONDOWN:
	{
		MessageBox(hWnd, "32-bit aplication", "Window",
			MB_OK | MB_ICONINFORMATION);

	}; break;

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
