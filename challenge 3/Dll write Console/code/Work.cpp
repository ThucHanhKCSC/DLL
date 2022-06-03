#include <iostream>
#include <windows.h>

#include <exception>
using namespace std;

int main(){

	HINSTANCE hdll = LoadLibrary("rundll.dll");

	typedef void(*DLLFunc)();
	DLLFunc displayMSG_call;

	displayMSG_call = (DLLFunc)GetProcAddress(hdll, "displayMSG");

	if(hdll){
		//cout << "successfull\n";
	}
	else{
		std::cout << "Error: " <<GetLastError();
	}


	if(displayMSG_call){
		//HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
		try{
			displayMSG_call();
		}
		catch(exception& e){
			cout << e.what();
		}
	}
	else{
		std::cout << "Error: " <<GetLastError();
	}

	FreeLibrary(hdll);


	return 0;
}