#define _CRT_SECURE_NO_WARNINGS
#undef UNICODE
#include <windows.h>
#include <iostream>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

bool is_number(const char *s)
{
	char a[] = { '0','9','8','7','6','5','4','3','2','1'};
	if (strspn(s, a) == strlen(s))
		return true;
	else
		return false;
}

struct Bad_day
{};
struct Bad_month
{};
struct Bad_edit
{};
struct Wr_data
{};

struct
{
	long style;
	char str[];
}

button = { BS_HOLLOW,"Найти" };

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
char szAppName[] = "Задача Иосифа Флавия";
char kek[] = "Оставшийся человек под номером";
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	HWND        hwnd;
	MSG         msg;
	WNDCLASSEX  wndclass;

						  
	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(0);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass); 

	hwnd = CreateWindow(szAppName, "Задача Иосифа Флавия", WS_OVERLAPPEDWINDOW, 490, 350, 450, 300, NULL, NULL, hInstance, NULL);
																														 
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{

	static HWND  edit1,
		edit2,
		hbutton;
	RECT         rect;
	HDC          hdc, hCompatibleDC;
	HANDLE       hBitmap, hOldBitmap;
	int		  l1, l2, N, M, res;
	char         *s1, *s2;	
	BITMAP Bitmap;
	PAINTSTRUCT  ps;
	static int nHDif = 0, nVDif = 0, nHPos = 0, nVPos = 0;
	int  error = 0;

	switch (iMsg)
	{
	case WM_PAINT:
	{
		hdc = BeginPaint(hwnd, &ps);  
		hBitmap = LoadImage(NULL, "pic.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		if (!hBitmap)
		{
			MessageBox(NULL, "File not found!", "Error", MB_OK);
			return 0;
		}
		GetObject(hBitmap, sizeof(BITMAP), &Bitmap);            
		hCompatibleDC = CreateCompatibleDC(hdc);             
		hOldBitmap = SelectObject(hCompatibleDC, hBitmap);
		GetClientRect(hwnd, &rect);
		BitBlt(hdc, 0, 0, rect.right, rect.bottom, hCompatibleDC, nHPos, nVPos, SRCCOPY);  
																						    
		DeleteDC(hCompatibleDC);           
		HFONT newFont = CreateFont(0, 0, 0, 0, 700, 0, 0, 0, RUSSIAN_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_DECORATIVE, ("Arial"));
		SelectObject(hdc, newFont); 
									
		TextOut(hdc, 60, 110, "N человек",9); 
		TextOut(hdc, 200, 110, "число M",7 );
		EndPaint(hwnd, &ps); 

		return 0;
	}
	case WM_CREATE: 	
		hbutton = CreateWindow("button", button.str, WS_CHILD | WS_VISIBLE | button.style, 0, 0, 0, 0, hwnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		edit1 = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 0, 0, 0, 0, hwnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		edit2 = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 0, 0, 0, 0, hwnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		 
		return 0;

	case WM_SETFOCUS: 
		SetFocus(edit1);
		return 0;

	case WM_SIZE: 
		GetClientRect(hwnd, &rect); 
		MoveWindow(edit1, rect.right * 1 / 5 - 45, rect.bottom / 2, 90, 22, TRUE);
		MoveWindow(edit2, rect.right * 5 / 9 - 60, rect.bottom / 2, 90, 22, TRUE);
		MoveWindow(hbutton, rect.right * 5 / 9 - 67, rect.bottom * 4 / 5, 100, 22, TRUE);
		return 0;

	case WM_COMMAND:
		if (HIWORD(wParam) == BN_CLICKED)// если кнопка нажата
		{
			GetClientRect(hwnd, &rect);

			l1 = GetWindowTextLength(edit1);
			s1 = new char[l1 + 1];
			GetWindowText(edit1, s1, l1 + 1); // копирует символы из edit1 в s1  
			N = atoi(s1);


			l2 = GetWindowTextLength(edit2);
			s2 = new char[l2 + 1];
			GetWindowText(edit2, s2, l2 + 1);
			M = atoi(s2);

			char* str = new char[15];
			list <int> s1;
			for (int i = 1; i <= N; i++) {
				s1.push_back(i);
			}
			while (s1.size() != 1)
			{
				for (int i = 1; i < M; i++)
				{
					int temp = s1.front();
					s1.push_back(temp);
					s1.pop_front();
				}
				s1.pop_front();
			}
			
			res = s1.front();
			sprintf(str, "%d", res);
			
			MessageBox(hwnd, str, kek, MB_OK | MB_ICONASTERISK); //создает, показывает на экране и использует окно сообщения
		}

		return 0;
	case WM_DESTROY:// отправляется тогда, когда окно разрушается			 
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}