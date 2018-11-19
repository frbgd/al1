#include <windows.h> // содержит API

// Основная функция:
int WINAPI WinMain(HINSTANCE hInst, // дескриптор экземпляра приложения
	HINSTANCE hPreviousInst, // в Win32 не используется, но объявление нужно
	LPSTR lpCommandLine, // нужен для запуска окошка в режиме командной строки
	int nCommandShow) // режим отображения окна
{
	int result = MessageBox(NULL, "Do you like WINAPI?!", "Task",
		MB_ICONQUESTION | MB_YESNO);
	switch (result)
	{
	case IDYES: MessageBox(NULL, "Continue in the same spirit!!!",
		"Answer", MB_OK | MB_ICONASTERISK); break;
	case IDNO:  MessageBox(NULL, "Very sorry!!!", "Answer",
		MB_OK | MB_ICONSTOP); break;
	}
	return NULL;
}