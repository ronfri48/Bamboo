#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;


void main()
{
	const wstring filePath = L"C:\\Windows\\Temp\\Ron\\Wow.txt";
	const wstring fileContent = L"Ron Friedman Ron Friedman Ron Friedman";
	HANDLE handle = CreateFileW(
		filePath.data(),
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_DELETE | FILE_SHARE_WRITE | FILE_SHARE_READ,
		nullptr,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		nullptr);

	if (nullptr == handle) {
		return;
	}

	DWORD len = 0;
	WriteFile(handle, fileContent.data(), fileContent.size(), &len, nullptr);

	CloseHandle(handle);
}