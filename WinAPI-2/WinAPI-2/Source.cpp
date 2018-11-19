#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR mainMessage[] = "Some text!"; // строка с сообщением

char WinName[] = "My window";

int WINAPI WinMain(HINSTANCE hInst,
	HINSTANCE hPreviousInst,
	LPSTR lpCommandLine,
	int nCommandShow
)
{
	HWND hMainWnd;// создаём дескриптор окна
	MSG msg; //содержит инф. о сообщении, посылаемом Windows
	// описываем класс окна:
	WNDCLASSEX wc; // создаём экземпляр, для обращения к членам класса WNDCLASSEX
	wc.hInstance = hInst; //дескриптор экземпляра приложения
	wc.lpszClassName = WinName; //указатель на const-строку, содержащюю имя класса
	wc.lpfnWndProc = WndProc; // указатель на пользовательскую функцию
	wc.style = 0; //стиль класса окошка (по умолчанию)
	wc.cbSize = sizeof(wc); // размер структуры (в байтах)
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); //дескриптор значка
	wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO); //.... маленького значка (в трэе)
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); // .... курсора мыши
	wc.lpszMenuName = NULL; // указатель на const-строку, содержащюю имя меню, применяемого для класса
						//дополнительная информация отсутствует:
	wc.cbClsExtra = 0; // число освобождаемых байтов при создании экземпляра приложения
	wc.cbWndExtra = 0; // число освобождаемых байтов в конце структуры
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //дескриптор цвета фона окошка (белый)
		
	if (!RegisterClassEx(&wc)) {
		// в случае отсутствия регистрации класса:
		MessageBox(NULL,
			"Failed to register class!",
			"Error", MB_OK);
		return NULL; // возвращаем, следовательно, выходим из WinMain
	}
	// создаём окошко, показываем его на экране
	hMainWnd = CreateWindow(WinName, // имя класса
                 "Full window procedure", // имя окна (то что сверху)
                 WS_OVERLAPPEDWINDOW | WS_VSCROLL, // режимы отображения окошка
                 CW_USEDEFAULT, // положение окна по оси х (по умолчанию)
                 NULL, // позиция окна по оси у (раз дефолт в х, то писать не нужно)
                 CW_USEDEFAULT, // ширина окошка (по умолчанию)
                 NULL, // высота окна (раз дефолт в ширине, то писать не нужно)
                 HWND(NULL), // дескриптор родительского окошка (у нас нет род. окон)
                 NULL, // дескриптор меню (у нас его нет)
                 HINSTANCE(hInst), // дескриптор экземпляра приложения
                 NULL); // ничего не передаём из WndProc
	if (!hMainWnd) {
		// в случае некорректного создания окна (неверные параметры и тп):
		MessageBox(NULL, "Could not create window!", "Error", MB_OK);
		return NULL; // выходим из приложения
	}
	ShowWindow(hMainWnd, nCommandShow);
	UpdateWindow(hMainWnd);
	while (GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, // дескриптор окошка
						UINT uMsg, // сообщение, посылаемое ОС
						WPARAM wParam, // параметры
						LPARAM lParam) // сообщений, для последующего обращения
{
	HDC hDC;
	PAINTSTRUCT ps;
	RECT rect;

	COLORREF colorText = RGB(255, 0, 0);

	switch (uMsg)
	{
	case WM_PAINT: // если нужно нарисовать, то:
		hDC = BeginPaint(hWnd, &ps); // инициализируем контекст устройства
		GetClientRect(hWnd, &rect); // получаем ширину и высоту области для рисования
		SetTextColor(hDC, colorText); // устанавливаем цвет контекстного устройства
		DrawText(hDC, mainMessage, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER); // рисуем текст
		EndPaint(hWnd, &ps); // заканчиваем рисовать
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}