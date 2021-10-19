#include "main_header.h"

void point_check(way_point& checked_point, std::vector<way_point>& opened_list,
	std::vector<way_point>& closed_list, way_point& current_point)
{
	bool closed_check = false;
	if (checked_point.Get_status() != 1)
	{
		closed_check = false;
		for (int i = 0; i < closed_list.size(); i++)
		{
			if ((checked_point.Get_this_x() == closed_list[i].Get_this_x()) &&
				(checked_point.Get_this_y() == closed_list[i].Get_this_y()))
			{
				closed_check = true;
				break;
			}
		}
		if (!closed_check)
		{
			if (checked_point.Get_way_length() == 0)
			{
				checked_point.Set_way_length(current_point.Get_way_length() + 1);
				checked_point.Set_pre_xy(current_point.Get_this_x(), current_point.Get_this_y());
				checked_point.Set_priority();
				opened_list.push_back(checked_point);
			}
			else
			{
				if (current_point.Get_way_length() + 1 < checked_point.Get_way_length())
				{
					int num = 0;
					for (int i = 0; i < opened_list.size(); i++)
					{
						if ((checked_point.Get_this_x() == opened_list[i].Get_this_x()) &&
							(checked_point.Get_this_y() == opened_list[i].Get_this_y()))
						{
							num = i;
							break;
						}
					}
					checked_point.Set_way_length(current_point.Get_way_length() + 1);
					checked_point.Set_pre_xy(current_point.Get_this_x(), current_point.Get_this_y());
					checked_point.Set_priority();
					opened_list.push_back(checked_point);
					opened_list.erase(opened_list.begin() + num);
				}
			}
			
		}
	}
}