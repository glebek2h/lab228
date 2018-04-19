#include <windows.h>

int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow)
{
	MessageBox(NULL, "Простейшая программа!", "WinAPI App", 0); //сообщение
	return 0;
}