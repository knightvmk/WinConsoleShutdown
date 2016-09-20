#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <clocale>
#define scanf scanf_s

void main()
{
	int q, x = 0;
	system("mode con cols=70 lines=20");

	setlocale(LC_ALL, "rus");
	system("color 0A");
	system("title WinShutdown");
	printf("**********************************************************************");
	Sleep(500);
	time_t tme = time(NULL);
	printf("\n\n                 Системное время: %s", ctime(&tme));
	Sleep(700);
	printf("\n\n                  Программа выключения ПК\n\n");
	Sleep(900);
	printf("\n Выберите настройку:\n 1: Выключение\n 2: Перезагрузка\n");
	do
	{
		scanf("%d", &x);
	} while (x < 1 || x>2);
	tme = time(NULL);
	system("cls");
	printf("**********************************************************************");
	printf("\n\n                 Системное время: %s", ctime(&tme));
	printf("\n\n                  Программа выключения ПК\n\n");
	printf("\n Введите время ожидания в минутах: ");
	do
	{
		scanf("%d", &q);
	} while (q <= 0);
	system("cls");
	tme = time(NULL);
	printf("**********************************************************************");
	printf("\n\n                 Системное время: %s", ctime(&tme));
	int restime = q * 60000;
	if (x == 1)
		 printf("\n\n                     ПК будет выключен через %d мин", q);
	else printf("\n\n                    ПК будет перезагружен через %d мин", q);
	Sleep(3000);
	system("cls");
	tme = time(NULL);
	printf("**********************************************************************\n\n");
	printf("\n Время запуска таймера: %s", ctime(&tme));
	Sleep(300);
	printf("\n\n Время ожидания: %d мин", q);
	printf("\n\n // Программу можно свернуть, но не закрывать");
	Sleep(restime);
	system("cls");
	printf("**********************************************************************");
	Sleep(500);
	printf("\n\nВыключение системы...");
	Sleep(4000);
	switch (x)
	{
	case 1:
	{
		WinExec("shutdown -s -t 0", SW_HIDE);
		break;
	}
	case 2:
	{
		WinExec("shutdown -r -t 0", SW_HIDE);
		break;
	}
	}
}