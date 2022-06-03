#include <math.h>
#include <iostream>
#include "rundll.h"
#include <windows.h>

void CALLBACK displayMSG(HWND hWnd, HINSTANCE hInst, LPSTR  lpszCmdLine, int nCmdShow){
	std::cout << "Hi! Im a DLL";
	MessageBoxA(0, lpszCmdLine, "func_1", 0);

}
