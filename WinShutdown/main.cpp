#include <stdio.h>
#include <stdlib.h>
#include "Windows.h"

int main(int argc, char* argv[])
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	ZeroMemory( &pi, sizeof(pi) );
	printf(" Begin\n");
	if(!CreateProcess(NULL,"notepad", NULL, NULL, FALSE, 0,NULL,NULL,&si,&pi))
	ExitProcess((UINT)3);
	printf("\n End\n");
	WaitForSingleObject( pi.hProcess, INFINITE );
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	return 0;
}