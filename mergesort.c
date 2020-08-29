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
#include <stdlib.h>
#include <string.h>

#include "mergesort.h"

#define copy(a, b, size)            \
do {                                \
	size_t __size = size;           \
	char *__a = a, *__b = b;        \
	do {                            \
		*__a++ = *__b++;            \
	} while(--__size > 0);          \
} while(0)
	
void
merge(char *left, char *right,
	size_t n, size_t m, size_t size,
	int (*comparator)(const void *, const void *))
{
	if(n > 1) mergesort(left, n, size, comparator);
	if(m > 1) mergesort(right, m, size, comparator);
	
	size_t
		tempsize = (n + m) * size,
		nsize = n * size,
		msize = m * size,
		i = 0, j = 0, k = 0;
	char *temp = (char *) malloc(tempsize);
	
	while(i < nsize && j < msize) {
		if(comparator(left + i, right + j) < 0) {
			copy(temp + k, left + i, size);
			i += size; k += size;
		} else {
			copy(temp + k, right + j, size);
			j += size; k += size;
		}
	}
	while(i < nsize) {
		copy(temp + k, left + i, size);
		i += size; k += size;
	}
	while(j < msize) {
		copy(temp + k, right + j, size);
		j += size; k += size;
	}
	
	memcpy(left, temp, tempsize);
	free(temp);
}

void 
mergesort(void *arr, 
	size_t n_elem, size_t size, 
	int (*comparator)(const void *, const void *))
{
	char *__arr = (char *) arr;
	size_t n = n_elem >> 1;
	size_t m = n_elem - n;
	merge(__arr, __arr + n * size, n, m, size, comparator);
}