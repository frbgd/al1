#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR mainMessage[] = "Some text!"; // ������ � ����������

char WinName[] = "My window";

int WINAPI WinMain(HINSTANCE hInst,
	HINSTANCE hPreviousInst,
	LPSTR lpCommandLine,
	int nCommandShow
)
{
	HWND hMainWnd;// ������ ���������� ����
	MSG msg; //�������� ���. � ���������, ���������� Windows
	// ��������� ����� ����:
	WNDCLASSEX wc; // ������ ���������, ��� ��������� � ������ ������ WNDCLASSEX
	wc.hInstance = hInst; //���������� ���������� ����������
	wc.lpszClassName = WinName; //��������� �� const-������, ���������� ��� ������
	wc.lpfnWndProc = WndProc; // ��������� �� ���������������� �������
	wc.style = 0; //����� ������ ������ (�� ���������)
	wc.cbSize = sizeof(wc); // ������ ��������� (� ������)
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); //���������� ������
	wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO); //.... ���������� ������ (� ����)
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); // .... ������� ����
	wc.lpszMenuName = NULL; // ��������� �� const-������, ���������� ��� ����, ������������ ��� ������
						//�������������� ���������� �����������:
	wc.cbClsExtra = 0; // ����� ������������� ������ ��� �������� ���������� ����������
	wc.cbWndExtra = 0; // ����� ������������� ������ � ����� ���������
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //���������� ����� ���� ������ (�����)
		
	if (!RegisterClassEx(&wc)) {
		// � ������ ���������� ����������� ������:
		MessageBox(NULL,
			"Failed to register class!",
			"Error", MB_OK);
		return NULL; // ����������, �������������, ������� �� WinMain
	}
	// ������ ������, ���������� ��� �� ������
	hMainWnd = CreateWindow(WinName, // ��� ������
                 "Full window procedure", // ��� ���� (�� ��� ������)
                 WS_OVERLAPPEDWINDOW | WS_VSCROLL, // ������ ����������� ������
                 CW_USEDEFAULT, // ��������� ���� �� ��� � (�� ���������)
                 NULL, // ������� ���� �� ��� � (��� ������ � �, �� ������ �� �����)
                 CW_USEDEFAULT, // ������ ������ (�� ���������)
                 NULL, // ������ ���� (��� ������ � ������, �� ������ �� �����)
                 HWND(NULL), // ���������� ������������� ������ (� ��� ��� ���. ����)
                 NULL, // ���������� ���� (� ��� ��� ���)
                 HINSTANCE(hInst), // ���������� ���������� ����������
                 NULL); // ������ �� ������� �� WndProc
	if (!hMainWnd) {
		// � ������ ������������� �������� ���� (�������� ��������� � ��):
		MessageBox(NULL, "Could not create window!", "Error", MB_OK);
		return NULL; // ������� �� ����������
	}
	ShowWindow(hMainWnd, nCommandShow);
	UpdateWindow(hMainWnd);
	while (GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, // ���������� ������
						UINT uMsg, // ���������, ���������� ��
						WPARAM wParam, // ���������
						LPARAM lParam) // ���������, ��� ������������ ���������
{
	HDC hDC;
	PAINTSTRUCT ps;
	RECT rect;

	COLORREF colorText = RGB(255, 0, 0);

	switch (uMsg)
	{
	case WM_PAINT: // ���� ����� ����������, ��:
		hDC = BeginPaint(hWnd, &ps); // �������������� �������� ����������
		GetClientRect(hWnd, &rect); // �������� ������ � ������ ������� ��� ���������
		SetTextColor(hDC, colorText); // ������������� ���� ������������ ����������
		DrawText(hDC, mainMessage, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER); // ������ �����
		EndPaint(hWnd, &ps); // ����������� ��������
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}