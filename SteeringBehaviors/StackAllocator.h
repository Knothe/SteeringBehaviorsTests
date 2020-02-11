#pragma once
#include <cstdlib>
#include <iostream>

class StackAllocator
{
public:
	static StackAllocator* GetPtr();
	typedef size_t Marker;
	void* alloc(size_t size);
	Marker getMarker();
	void freeToMarker(Marker marker);
	void clear();

private:
	StackAllocator(size_t size);
	static StackAllocator* ptr;
	int maxSize;
	void * start;
	Marker marker;
	Marker prev;
};

