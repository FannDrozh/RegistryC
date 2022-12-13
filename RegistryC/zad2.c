#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <Windows.h>
/*«адание 2 (напишите консольное приложение, которое позвол€ет настраивать свой интерфейс в процессе работы:
размер и цвет шрифта, цвет фона, тип шрифта. данные параметры должны хранитьс€ в реестре)*/
//CONSOLE_FONT_INFOEX cfi;
//HKEY hMyKey;

main()
{
	system("chcp 1251");
	while (TRUE)
	{
		printf("0 Ч черный\n1 Ч синий\n2 Ч зеленый\n3 Ч голубой\n4 Ч красный\n5 Ч лиловый\n6 Ч желтый\n7 Ч белый\n8 Ч серый\n9 Ч свело - синий\nA Ч светло - зеленый\nB Ч светло - голубой\n— Ч светло - красный\nE Ч светло - желтый\nF Ч €рко - белый\n");
		char colback = NULL;
		printf("¬ведите цвет фона: ");
		scanf_s("%c", &colback);
		ColorBackground(colback);
		char colfore = NULL;
		printf("¬ведите цвет шрифта: ");
		scanf_s("%c\n", &colfore);
		if (colback != NULL && colfore != NULL)
		{
			
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN);
			printf("Hello, World!\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
			system("pause");
		}
		//HKEY hKey = NULL;
		//if (RegOpenKeyW(HKEY_CURRENT_USER, NULL, &hKey) != ERROR_SUCCESS)
		//		return 1;

		//HKEY tmp = NULL;
		//if (RegCreateKeyW(hKey, L"MyKey", &tmp) == ERROR_SUCCESS) //—оздаЄт ключ
		//{
		//	RegCloseKey(tmp);
		//	MessageBox(NULL, L" люч успешно создан", L"»нформаци€", MB_OK);
		//}
	}
}

char ColorBackground(colback)
{

}
