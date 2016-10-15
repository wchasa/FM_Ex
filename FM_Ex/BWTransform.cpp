#include "stdafx.h"
#include "BWTransform.h"


BWTransform::BWTransform()
{
}


BWTransform::~BWTransform()
{
}

inline int BWTransform::rank1(unsigned char* L, int pos)
{
	int icount = 0;
	for (int i = 0; i < pos; i

		++)
	{
		if (L[i] == L[pos])
			icount++;
	}


	return icount;
}

void BWTransform::computerLF(int* C, unsigned char* L, int* LF, int length)
{
	int i;
	LF[0] = C

		[L[0]];
	for (i = 0; i < length; i++)
	{
		LF[i] = (C[L[i]] + rank1(L, i)) % length;
	}
}

void BWTransform::ReconstructT(unsigned char* L, int* LF, int I, unsigned char* T, int length)
{
	int i = I;


	for (int k = length - 1; k >= 0; k--)
	{
		T[k] = L[i];
		i = LF[i];
	}
}

int BWTransform::constructBWT(unsigned char* T, unsigned char* L, int length)
{
	//	int 

	int posofend = 0;
	int* sa = new int[length];
	SuffixArray	(T, sa, length, 256);
	for (int i = 0; i < length; i++)
	{
		//L[i] = T[(sa[i] - 1<0 ? sa[i] - 1 + length : sa[i] - 1) % length];
		if (sa[i] == 0)
		{
			posofend = i;
			L[i] = T[(sa[i] - 1 + length) % length];
		}
		else
			L[i] = T[(sa[i] - 1) % length];
	}
	return  posofend;
}

void BWTransform::constructC(unsigned char* T, int* CTable, int length)
{
	int i;
	memset

		(CTable, 0, CSize * sizeof(int));
	for (i = 0; i < length; i++)
	{
		CTable[T[i]

			+ 1]++;
	}
	for (i = 1; i < CSize; i++)
	{
		CTable[i] += CTable[i - 1];
	}
}

void SuffixArray(unsigned char  *r, int *sa, int n, int m)
{
	//n = n > m ? n : m;
	int* x = new int[n];
	int* y =

		new int[n];
	int* wv = new int[n > m ? n : m];
	int* ws = new int[n > m ? n : m];
	int i, j, p, *t;
	for

		(i = 0; i<m; i++) ws[i] = 0;
	for (i = 0; i<n; i++) ws[x[i] = r[i]]++;
	for (i = 1; i<m; i++) ws[i] += ws[i - 1];


	for (i = n - 1; i >= 0; i--)
		sa[--ws[x[i]]] = i;
	for (j = 1, p = 1; p<n; j *= 2, m = p)
	{
		for

			(p = 0, i = n - j; i<n; i++) y[p++] = i;
		for (i = 0; i<n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;


		for (i = 0; i<n; i++) wv[i] = x[y[i]];
		for (i = 0; i<m; i++) ws[i] = 0;
		for (i = 0; i<n; i++) ws

			[wv[i]]++;
		for (i = 1; i<m; i++) ws[i] += ws[i - 1];
		for (i = n - 1; i >= 0; i--) sa[--ws[wv

			[i]]] = y[i];
		for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
		{


			x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
		}
	}
	delete[] wv;
	delete[] ws;
	delete[] x;


	delete[] y;
	return;
}
int cmp(int *r, int a, int b, int l)
{
	return r[a] == r[b] && r[a + l] == r[b + l];
}
