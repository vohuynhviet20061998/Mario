#pragma once

#include <Windows.h>

#include <signal.h>
#include <string>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <D3DX10.h>


using namespace std;


namespace GlobalUtil {


	const unsigned int SCREEN_WIDTH = 256;
	const unsigned int SCREEN_HEIGHT = 224;
	
	const unsigned int MAX_FILE_LINE = 5000;

	extern 	LPD3DX10SPRITE spriteObject;
}



vector<string> split(string line, string delimeter = "\t");
wstring ToWSTR(string st);

LPCWSTR ToLPCWSTR(string st);


typedef struct RectFloat {
	float left, top, right, bottom;

	RectFloat() : left(0), top(0), right(0), bottom(0) {}
	RectFloat(float l, float t, float r, float b) : left(l), top(t), right(r), bottom(b) {}
} RECTF;