#pragma once
#include "SFML/Graphics.hpp"





class Letter_3d
{

private:

	static const int field_width = 9;	// size by x
	static const int field_height = 9;	// size by y
	static const int filed_count = 2;	// size by z, thickness of the letter

	int m_size;
	int* m_blocks;


public:

	Letter_3d();

	Letter_3d(int size, const int* blocks);

	Letter_3d(const Letter_3d& other);
	Letter_3d& operator=(const Letter_3d& other);

	~Letter_3d();

};

