#include "way_point.h"

void way_point::Set_status(int z)
{
	way_point::status = z;
}
int way_point::Get_status()
{
	return way_point::status;
}


void way_point::Set_priority()
{
	if (way_point::status == 0)
	{
		way_point::priority = way_point::hevristic + way_point::way_length;
	}
	else
	{
		way_point::priority = -1;
	}
	
}
double way_point::Get_priority()
{
	return way_point::priority;
}

void way_point::Set_hevristic(int x1, int y1, int x2, int y2)
{
	way_point::hevristic = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
double way_point::Get_hevristic()
{
	return way_point::hevristic;
}

void way_point::Set_way_length(double z)
{
	way_point::way_length = z;
}
double way_point::Get_way_length()
{
	return way_point::way_length;
}

void way_point::Set_this_xy(int x, int y)
{
	way_point::this_x=x;
	way_point::this_y=y;
}
int way_point::Get_this_x()
{
	return way_point::this_x;
}
int way_point::Get_this_y()
{
	return way_point::this_y;
}

void way_point::Set_pre_xy(int x, int y)
{
	way_point::pre_x=x;
	way_point::pre_y=y;
}
int way_point::Get_pre_x()
{
	return way_point::pre_x;
}
int way_point::Get_pre_y()
{
	return way_point::pre_y;
}