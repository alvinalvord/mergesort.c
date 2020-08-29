/*
MIT License

Copyright (c) 2020 alvinalvord

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <stdio.h>

#include "mergesort.h"

int
cmp(const void *a, const void *b)
{
	return (int)(*((int *) a) - *((int *) b));
}

int
main(int argc, char *argv[])
{
	int nelem = 10;
	int test[nelem];
	int i;
	
	for(i = 0; i < nelem; i++)
		test[i] = nelem - i;
	
	mergesort(test, nelem, sizeof(int), cmp);
	
	for(i = 0; i < nelem; i++) 
		printf("[%2d] %2d\n", i, test[i]);
	
	return 0;
}
