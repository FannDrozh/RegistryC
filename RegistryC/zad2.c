#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <Windows.h>
/*Задание 2 (напишите консольное приложение, которое позволяет настраивать свой интерфейс в процессе работы:
размер и цвет шрифта, цвет фона, тип шрифта. данные параметры должны храниться в реестре)*/
//CONSOLE_FONT_INFOEX cfi;
//HKEY hMyKey;
HANDLE hConsole;
void SetColor(int Text,int Fon)
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (Fon)+Text);
}
int main()
{
	system("chcp 1251");
	while (TRUE)
	{
		int size = 5;
		int colback = (int*)malloc(size * sizeof(int));
		int colfore = (int*)malloc(size * sizeof(int));
		scanf_s("%d%d\n", &colback, &colfore);
		if (colback != NULL && colfore != NULL)
		{
			SetColor(colfore, colback);
			system("pause");
		}
		else
		{
			break;
		}
		//HKEY hKey = NULL;
		//if (RegOpenKeyW(HKEY_CURRENT_USER, NULL, &hKey) != ERROR_SUCCESS)
		//		return 1;

		//HKEY tmp = NULL;
		//if (RegCreateKeyW(hKey, L"MyKey", &tmp) == ERROR_SUCCESS) //Создаёт ключ
		//{
		//	RegCloseKey(tmp);
		//	MessageBox(NULL, L"Ключ успешно создан", L"Информация", MB_OK);
		//}
	}
}


