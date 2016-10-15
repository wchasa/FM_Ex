#pragma once

#include "stdafx.h"

#include<stdio.h>
//#include<string.h>
#include <string>
#include <stdlib.h>
#pragma once

#define SIZE 100
class testData
{
	unsigned char data[SIZE];
	unsigned int length;
public:
	testData();
	void GetFromFile(const char* path);
	void SetData(unsigned char* inarray, int leng);
	unsigned char* Getdata();
	unsigned Getlength();

};
