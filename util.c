#include <windows.h>
#include <stdio.h>
#include "util.h"

int utf16_to_utf8(const wchar_t* utf16, size_t is, char* utfc, size_t os)
{
	(void)is;
	return WideCharToMultiByte(CP_UTF8, 0, utf16, -1, utfc, os, NULL, NULL);
}

int utf8_to_utf16(const char* utfc, size_t is, wchar_t* utf16, size_t os)
{
	(void)is;
	return MultiByteToWideChar(CP_UTF8, 0, utfc, -1, utf16, os);
}