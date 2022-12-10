#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <Windows.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	HKEY hKey = NULL;
	if (RegOpenKeyW(HKEY_CURRENT_USER, NULL, &hKey) != ERROR_SUCCESS)//Открываем раздел HKEY_CURRENT_USER
		return 1;

	HKEY tmp = NULL;
	if (RegCreateKeyW(hKey, L"MyKey", &tmp) == ERROR_SUCCESS) //Создаёт ключ
	{
		RegCloseKey(tmp);
		MessageBox(NULL, L"Ключ успешно создан", L"Информация", MB_OK);
	}
	//Создаёт подраздел + значение по умолчанию
	/*if (RegSetValue(hKey, L"MyKey", REG_SZ, L"Значение по умолчанию", 22 * sizeof(WCHAR)) == ERROR_SUCCESS)
	{
		MessageBox(NULL, L"Ключ успешно создан и ему присвоено значение по умолчанию", L"Информация", MB_OK);
	}*/
	LPWSTR StringParam = L"Строковое значение параметра";
	DWORD StringParamLen = wcslen(StringParam);
	//создаёт строковый параметр 
	if (RegSetValueExW(hKey, L"MyKey", NULL, REG_SZ, StringParam, StringParamLen * sizeof(WCHAR)) == ERROR_SUCCESS)
	{
		MessageBox(NULL, L"Параметр успешно создан и ему присвоено значение", L"Информация", MB_OK);
	}
	//получить значение ключа
	LPWSTR RegValue = malloc(512);
	DWORD DataType = 0;
	DWORD DataLen = 100500;
	if (RegGetValueW(HKEY_CURRENT_USER, NULL, L"MyKey", RRF_RT_ANY, &DataType, RegValue, &DataLen) == ERROR_SUCCESS)
	{
		MessageBox(NULL, RegValue, L"Значение параметра", MB_OK);
	}
	else 
	{
		MessageBox(NULL, L"Что-то пошло не так", L"Информация", MB_OK);
	}
	//Создание параметра типа DWORD
	DWORD d = 100500;
	if (RegSetValueExW(hKey, L"MyDWORDParam", NULL, REG_DWORD, &d, 4) == ERROR_SUCCESS)
	{

	}
	DWORD DWValue = 0;
	if (RegGetValueW(HKEY_CURRENT_USER, NULL, L"MyDWORDParam", RRF_RT_ANY, &DataType, &DWValue, &DataLen) == ERROR_SUCCESS)
	{

	}
}