#include "Letter_3d.h"





Letter_3d::Letter_3d() : m_size(0), m_blocks(nullptr) {}

Letter_3d::Letter_3d(int size, const int* blocks) : m_size(size), m_blocks(new int[size])
{
	for (int i = 0; i < size; i++)
	{
		m_blocks[i] = blocks[i];
	}
}

Letter_3d::Letter_3d(const Letter_3d& other) : m_size(other.m_size), m_blocks(new int[other.m_size])
{
	for (int i = 0; i < m_size; i++)
	{
		m_blocks[i] = other.m_blocks[i];
	}
}

Letter_3d& Letter_3d::operator=(const Letter_3d& other)
{
	if(other.m_blocks == m_blocks)
	{
		return *this;
	}

	m_size = other.m_size;
	delete[] m_blocks;
	m_blocks = new int[m_size];
	for (int i = 0; i < m_size; i++)
	{
		m_blocks[i] = other.m_blocks[i];
	}

	return *this;

}



Letter_3d::~Letter_3d()
{
	delete[] m_blocks;
}



void Letter_3d::draw(sf::RenderTarget& target, sf::RenderStates states) const
{



	//sf::VertexArray points;

	/*sf::VertexArray points(sf::LinesStrip, m_size);

	for (int i = 0; i < m_size; i++)
	{
		points[i] = sf::Vertex(sf::Vector2f(m_blocks[i] % field_width * basic_scale, m_blocks[i] / field_height * basic_scale));
	}*/

}
