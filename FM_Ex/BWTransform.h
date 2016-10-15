#pragma once
#include "stdafx.h"
#include <cstring>
#define CSize 257
void SuffixArray(unsigned char  *r, int *sa, int n, int m);
int cmp(int *r, int a, int b, int l);

class BWTransform
{
public:
	BWTransform();
	~BWTransform();
	static int rank1(unsigned char* L, int pos);
	//construct LF map 
	static void computerLF(int* C, unsigned char* L, int* LF, int length);
	static void ReconstructT(unsigned char* L, int* LF, int I, unsigned char* T, int length);
	static int constructBWT(unsigned char* T, unsigned char* L, int length);
	static void constructC(unsigned char* T, int* CTable, int length);
};

