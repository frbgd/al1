#include <windows.h> // �������� API

// �������� �������:
int WINAPI WinMain(HINSTANCE hInst, // ���������� ���������� ����������
	HINSTANCE hPreviousInst, // � Win32 �� ������������, �� ���������� �����
	LPSTR lpCommandLine, // ����� ��� ������� ������ � ������ ��������� ������
	int nCommandShow) // ����� ����������� ����
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