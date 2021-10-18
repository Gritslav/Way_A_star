#pragma once
#include "main_header.h"
#include <vector>
class way_point
{
private:
	std::vector<int> this_xy;
	std::vector<int> pre_xy;
	double priority;
	double hevristic;
	double way_length;
	int status;
public:
	void Set_status(int z);
	int Get_status();
	void Set_priority();
	double Get_priority();
	void Set_hevristic(int x1, int y1, int x2, int y2);
	double Get_hevristic();
	void Set_way_length(double z);
	double Get_way_length();
	void Set_this_xy(int x, int y);
	int Get_this_x();
	int Get_this_y();
	void Set_pre_xy(int x, int y);
	int Get_pre_x();
	int Get_pre_y();
};

