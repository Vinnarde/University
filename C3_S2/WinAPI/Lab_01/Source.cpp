// --- ������������ ���������� ����
#include <windows.h>

// --- �������� ������� �������� ����
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// --- ���������� ����������
HINSTANCE hInst; // ���������� ���������� ����������
char ClassName[] = "Window"; // �������� ������ ����
char AppTitle[] = "Application Win32"; // ��������� �������� ����

// --- ������� WinMain
int WINAPI WinMain(HINSTANCE hInstance,
                   // ���������� ���������� ����������
                   HINSTANCE hPrevInstance, // � Win32 ������ ����� NULL
                   LPSTR lpCmdLine,
                   // ��������� �� ��������� ������. �� // ���������
                   // ���������� �������� ������ �� ��������� ������.
                   int nCmdShow
                   // ����������, ��� ���������� ������������� 
                   // ������������ �� �������: ������������
                   // (nCmdShow = SW_SHOWMINNOACTIVE) 
                   // ��� � ���� ��������� ���� 					//(nCmdShow = SW_SHOWNORMAL).
)
{
	WNDCLASS wc; // ��������� ��� ���������� � ������ ����
	HWND hWnd; // ���������� �������� ���� ����������
	MSG msg; // ��������� ��� �������� ���������
	// ��������� ���������� ���������� ���������� � ����������
	// ����������, ����� ��� ������������� ��������������� �� �
	// ������� ����.
	hInst = hInstance;

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
	if ((hWnd = FindWindow(ClassName, nullptr)) != nullptr)
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
	wc.lpszClassName = ClassName; // ��� ������ ����
	wc.lpfnWndProc = static_cast<WNDPROC>(WndProc);
	// ����� ������� �������
	wc.style = CS_HREDRAW | CS_VREDRAW; // ����� ������ 
	wc.hInstance = hInstance; // ��������� ����������
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	// ����������� ��� ����
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	// ������ ���� ��� ����
	wc.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	// ����� ��� ����
	wc.lpszMenuName = nullptr; // ������ ���� ����
	wc.cbClsExtra = 0; // �������������� ������
	wc.cbWndExtra = 0; // �������������� ������
	// P���������� ������ ����.
	RegisterClass(&wc);

	// ������� ������� ���� ����������.
	hWnd = CreateWindow(
		ClassName, // ��� ������ ����
		AppTitle, // ��������� ���� 
		WS_OVERLAPPEDWINDOW, // ����� ����
		CW_USEDEFAULT, // X-���������� 
		CW_USEDEFAULT, // Y-���������� 
		CW_USEDEFAULT, // ������ ����
		CW_USEDEFAULT, // ������ ����
		NULL, // ���������� ����-��������
		NULL, // ���������� ���� ����
		hInst, // ���������� ���������� ����������
		NULL); // �������������� ����������
	if (!hWnd)
	{
		// ���� �� �������, ������ ��������������.
		MessageBox(nullptr,
		           "Create: error", AppTitle, MB_OK | MB_ICONSTOP);
		return FALSE;
	}

	// ���������� ����.
	ShowWindow(hWnd, nCmdShow);

	// ��������� ���������� ���������� ������� ����.
	UpdateWindow(hWnd);

	// ��������� ���� ��������� ������� ���������.
	// ������� GetMessage �������� ��������� �� �������, 
	// ������ false ��� ������� �� ������� ��������� WM_QUIT
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		// �������������� ��������� ���������, 
		// ���������� � ������� ����������
		TranslateMessage(&msg);
		// ���������� ��������� ������� ���������
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

// --- ������� ����
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	char str[] = "First Windows aplication";

	switch (msg)
	{
		// ���������� �������� ���������� ���������� ������� ����.
	case WM_PAINT:
		{
			PAINTSTRUCT ps;

			HDC hDC = BeginPaint(hWnd, &ps);
			// �������� �������� ����
			TextOut(hDC, 20, 20, str, strlen(str));
			// ���������� �����
			EndPaint(hWnd, &ps);
			// ���������� �������� ����
		}
		break;

		// ������ ����� ������� ���� � ���������� ������� ����.
	case WM_LBUTTONDOWN:
		{
			MessageBox(hWnd, "32-bit aplication", "Window",
			           MB_OK | MB_ICONINFORMATION);
		}
		break;

		// ������������ ������ ����.
	case WM_DESTROY:
		{
			// ���� ������ ������� �������� ������� ��������
			// �������� ����, �� ������� � ������� ���������
			// ���������� ������� ��������� WM_QUIT 
			PostQuitMessage(0);
		}
		break;

		// �������������� ��������� �������� � �����������
		// ������� ��������� ��������� �� ���������.
	default: return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0l;
}
