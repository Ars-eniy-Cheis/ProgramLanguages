#pragma once
class Figure
{
public:
	Figure()
	{

	};
	~Figure()
	{

	};
	virtual float Area() = 0;
	virtual Figure* Clone() = 0;
};