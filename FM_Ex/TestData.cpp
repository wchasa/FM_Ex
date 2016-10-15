#include "stdafx.h"
#include "TestData.h"


testData::testData()
{
	//data = nullptr;
	length = 0;
}

void testData::GetFromFile(const char* path)
{
	FILE* fp;
//	unsigned char *_index = (TSA_Un *)malloc(sizeof(TSA_Un));
	if (fopen_s(&fp, path, "r"))
	{
		printf("The file %s is not exist.", path);
		return;
	}
	int err = fseek(fp, 0L, SEEK_END);
	long size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	size = size < SIZE ? size : SIZE;
	length = fread(data, sizeof(char), size, fp);
}

void testData::SetData(unsigned char* inarray,int leng)
{
	//data = *inarray;
	length = leng;
	memcpy(data, inarray, length);
	
}

unsigned char* testData::Getdata()
{
	return data;
}

unsigned testData::Getlength()
{
	return length;
}


