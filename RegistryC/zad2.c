#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <Windows.h>
/*������� 2 (�������� ���������� ����������, ������� ��������� ����������� ���� ��������� � �������� ������:
������ � ���� ������, ���� ����, ��� ������. ������ ��������� ������ ��������� � �������)*/
//CONSOLE_FONT_INFOEX cfi;
//HKEY hMyKey;

main()
{
	system("chcp 1251");
	while (TRUE)
	{
		printf("0 � ������\n1 � �����\n2 � �������\n3 � �������\n4 � �������\n5 � �������\n6 � ������\n7 � �����\n8 � �����\n9 � ����� - �����\nA � ������ - �������\nB � ������ - �������\n� � ������ - �������\nE � ������ - ������\nF � ���� - �����\n");
		char colback = NULL;
		printf("������� ���� ����: ");
		scanf_s("%c", &colback);
		ColorBackground(colback);
		char colfore = NULL;
		printf("������� ���� ������: ");
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
		//if (RegCreateKeyW(hKey, L"MyKey", &tmp) == ERROR_SUCCESS) //������ ����
		//{
		//	RegCloseKey(tmp);
		//	MessageBox(NULL, L"���� ������� ������", L"����������", MB_OK);
		//}
	}
}

char ColorBackground(colback)
{

}
