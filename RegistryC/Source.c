#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <Windows.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	HKEY hKey = NULL;
	if (RegOpenKeyW(HKEY_CURRENT_USER, NULL, &hKey) != ERROR_SUCCESS)//��������� ������ HKEY_CURRENT_USER
		return 1;

	HKEY tmp = NULL;
	if (RegCreateKeyW(hKey, L"MyKey", &tmp) == ERROR_SUCCESS) //������ ����
	{
		RegCloseKey(tmp);
		MessageBox(NULL, L"���� ������� ������", L"����������", MB_OK);
	}
	//������ ��������� + �������� �� ���������
	/*if (RegSetValue(hKey, L"MyKey", REG_SZ, L"�������� �� ���������", 22 * sizeof(WCHAR)) == ERROR_SUCCESS)
	{
		MessageBox(NULL, L"���� ������� ������ � ��� ��������� �������� �� ���������", L"����������", MB_OK);
	}*/
	LPWSTR StringParam = L"��������� �������� ���������";
	DWORD StringParamLen = wcslen(StringParam);
	//������ ��������� �������� 
	if (RegSetValueExW(hKey, L"MyKey", NULL, REG_SZ, StringParam, StringParamLen * sizeof(WCHAR)) == ERROR_SUCCESS)
	{
		MessageBox(NULL, L"�������� ������� ������ � ��� ��������� ��������", L"����������", MB_OK);
	}
	//�������� �������� �����
	LPWSTR RegValue = malloc(512);
	DWORD DataType = 0;
	DWORD DataLen = 100500;
	if (RegGetValueW(HKEY_CURRENT_USER, NULL, L"MyKey", RRF_RT_ANY, &DataType, RegValue, &DataLen) == ERROR_SUCCESS)
	{
		MessageBox(NULL, RegValue, L"�������� ���������", MB_OK);
	}
	else 
	{
		MessageBox(NULL, L"���-�� ����� �� ���", L"����������", MB_OK);
	}
	//�������� ��������� ���� DWORD
	DWORD d = 100500;
	if (RegSetValueExW(hKey, L"MyDWORDParam", NULL, REG_DWORD, &d, 4) == ERROR_SUCCESS)
	{

	}
	DWORD DWValue = 0;
	if (RegGetValueW(HKEY_CURRENT_USER, NULL, L"MyDWORDParam", RRF_RT_ANY, &DataType, &DWValue, &DataLen) == ERROR_SUCCESS)
	{

	}
}