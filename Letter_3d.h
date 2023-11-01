#pragma once
#include "SFML/Graphics.hpp"





class Letter_3d : public sf::Drawable
{

private:

	static const int field_width = 9;	// size by x
	static const int field_height = 9;	// size by y
	static const int field_count = 3;	// size by z, thickness of the letter
	static const int basic_scale = 10;	//



	int m_size;
	int* m_blocks;



	sf::Transformable tr_XY;
	sf::Transformable tr_XZ;
	sf::Transformable tr_YZ;

	int render_distance = 100;


public:

	Letter_3d();

	Letter_3d(int size, const int* blocks);

	Letter_3d(const Letter_3d& other);
	Letter_3d& operator=(const Letter_3d& other);

	~Letter_3d();



	void move_xy(float offsetX, float offsetY)
	{
		tr_XY.move(offsetX, offsetY);
	}
	void move_xz(float offsetX, float offsetZ)
	{
		tr_XZ.move(offsetX, offsetZ);
	}
	void move_yz(float offsetY, float offsetZ)
	{
		tr_YZ.move(offsetY, offsetZ);
	}

	void move_xy(const sf::Vector2f& offset)
	{
		tr_XY.move(offset);
	}
	void move_xz(const sf::Vector2f& offset)
	{
		tr_XZ.move(offset);
	}
	void move_yz(const sf::Vector2f& offset)
	{
		tr_YZ.move(offset);
	}


	void rotate_xy(float angle)
	{
		tr_XY.rotate(angle);
	}
	void rotate_xz(float angle)
	{
		tr_XZ.rotate(angle);
	}
	void rotate_yz(float angle)
	{
		tr_YZ.rotate(angle);
	}


	void scale_xy(float factorX, float factorY)
	{
		tr_XY.scale(factorX, factorY);
	}
	void scale_xz(float factorX, float factorZ)
	{
		tr_XZ.scale(factorX, factorZ);
	}
	void scale_yz(float factorY, float factorZ)
	{
		tr_YZ.scale(factorY, factorZ);
	}

	void scale_xy(const sf::Vector2f& factor)
	{
		tr_XY.scale(factor);
	}
	void scale_xz(const sf::Vector2f& factor)
	{
		tr_XZ.scale(factor);
	}
	void scale_yz(const sf::Vector2f& factor)
	{
		tr_YZ.scale(factor);
	}



	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

