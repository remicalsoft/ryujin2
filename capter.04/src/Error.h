#pragma once

#include <Windows.h>

class Error
{
public:
	static void finish(char* errorMessage, LPCTSTR lpszFuncName, int lineN);
};
