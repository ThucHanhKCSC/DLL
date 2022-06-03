@echo off
g++ -c rundll.cpp 
rem g++ -c -DCREATE_DLL rundll.cpp
g++ -shared -o rundll.dll rundll.o 
rem g++ -shared -o rundll.dll rundll.o-Wl,--out-implib,libexample_dll.a

