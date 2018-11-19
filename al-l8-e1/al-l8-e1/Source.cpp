#include <Windows.h>

LRESULT CALLBACK WinFun(HWND, UINT, WPARAM, LPARAM);

char WinName[] = "My_window";

int WINAPI WinMain(HINSTANCE hIns, HINSTANCE hPrevIns, LPSTR arg, int WinMode)
{
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wcl;

	wcl.hInstance = hIns;
	wcl.lpszClassName = WinName;
	wcl.lpfnWndProc = WinFun;
	wcl.style = 0;
	wcl.cbSize = sizeof(WNDCLASSEX);
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcl.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcl.lpszMenuName = NULL;
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;

	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

	if (!RegisterClassEx(&wcl)) return 0;

	hwnd = CreateWindow(
		WinName,
		"My_simple_window",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		HWND_DESKTOP,
		NULL,
		hIns,
		NULL);

	ShowWindow(hwnd, WinMode);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

struct Line
{
	int x1, x2, y1, y2;
};

struct LineList
{
	Line L;
	LineList *pNext;
};

LineList *pFirst = 0, *p;

void add(LineList *&pF, LineList *p)
{
	p->pNext = pF;
	pF = p;
}

int x1, x2, y1, y2;
HPEN pB, pW;

LRESULT CALLBACK WinFun(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (message)
	{
	case WM_CREATE:
		pB = (HPEN)GetStockObject(BLACK_PEN);
		pW = (HPEN)GetStockObject(WHITE_PEN);
		break;
	case WM_LBUTTONDOWN:
		x2 = x1 = LOWORD(lParam);
		y2 = y1 = HIWORD(lParam);
		break;
	case WM_MOUSEMOVE:
		if (wParam & MK_LBUTTON)
		{
			hdc = GetDC(hwnd);
			SelectObject(hdc, pW);
			MoveToEx(hdc, x1, y1, (LPPOINT)NULL);
			LineTo(hdc, x2, y2);
			x2 = LOWORD(lParam);
			y2 = HIWORD(lParam);
			SelectObject(hdc, pB);
			MoveToEx(hdc, x1, y1, (LPPOINT)NULL);
			LineTo(hdc, x2, y2);
			ReleaseDC(hwnd, hdc);
		}
		break;
	case WM_LBUTTONUP:
		p = new LineList;
		p->L.x1 = x1; p->L.x2 = x2;
		p->L.y1 = y1; p->L.y2 = y2;
		add(pFirst, p);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		p = pFirst;
		while (p)
		{
			MoveToEx(hdc, p->L.x1, p->L.y1, (LPPOINT)NULL);
			LineTo(hdc, p->L.x2, p->L.y2);
			p = p->pNext;
		}
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}