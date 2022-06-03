#include <iostream>
#include <windows.h>
#include <string.h>
#include <string>

int main(int argc, char *argv[]){

	if(argv[1] != NULL){
		//std::cout << argv[2] << std::endl;
		HINSTANCE hd;
		hd = LoadLibrary(argv[1]);

		if(hd == NULL){
			std::cout << "Library " << argv[1] << " is not available";
		}
		else{
			if(argv[2] == NULL){
				std::cout << "[+] Usage: <runDll.exe " << argv[1] << " [function name]>";				
			}
			else{
				
				typedef void(*DLLFunction)();
				DLLFunction functionDLL;

				functionDLL = (DLLFunction)GetProcAddress(hd, argv[2]);

				if(functionDLL){
					functionDLL();
				}
				else{
					std::cout << argv[1] << " doesn't have " << argv[2];
				}

			}
		}

	}
	else{
		std::cout << "[+] Usage: <runDll.exe [filedll]>";
	}
	return 0;
}