#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <Windows.h>
/*������� 2 (�������� ���������� ����������, ������� ��������� ����������� ���� ��������� � �������� ������:
������ � ���� ������, ���� ����, ��� ������. ������ ��������� ������ ��������� � �������)*/
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
		//if (RegCreateKeyW(hKey, L"MyKey", &tmp) == ERROR_SUCCESS) //������ ����
		//{
		//	RegCloseKey(tmp);
		//	MessageBox(NULL, L"���� ������� ������", L"����������", MB_OK);
		//}
	}
}


