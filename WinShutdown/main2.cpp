#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

volatile int Var=0;

DWORD WINAPI Calc_one(void *arg) 
{ 
	for(int i = 0 ; i <100000000; i++)
	Var++;
	return 0; 
} 

DWORD WINAPI Calc_two(void *arg) 
{ 
	for(int i = 0 ;i < 100000000; i++)
	Var--;
	return 0; 
} 


int main(int argc, char* argv[])
{	
	HANDLE *h; 
	h = new HANDLE[20]; 
	printf("\n Begin [ %i ]\n",Var);
	for(int i=0;i<10;i++)
	{
		h[i] = CreateThread(NULL, NULL, Calc_one, NULL, NULL, NULL);
	}
	for(int i=0;i<10;i++)
	{
		h[i] = CreateThread(NULL, NULL, Calc_two, NULL, NULL, NULL);
	}
	WaitForMultipleObjects(20, h, TRUE, INFINITE); 
	delete[] h; 
	printf("\n\n End [ %i ]\n",Var);
	system("pause");
	return 0;
}
