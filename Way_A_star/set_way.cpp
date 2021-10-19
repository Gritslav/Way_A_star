#include "main_header.h"

void update_lists(std::map<int, way_point>&, std::vector<way_point>&, std::vector<way_point>&, way_point&, int, int, int);



int set_way(std::map<int, way_point>& way_map, std::vector<way_point>& opened_list, std::vector<way_point>& closed_list, 
	std::vector<int>& finish_xy, int N1, int N2)
{
	way_point current_point = opened_list[0];
	int current_num = 0;
	while ((current_point.Get_this_x() != finish_xy[0]) ||
		(current_point.Get_this_y() != finish_xy[1]))
	{
		update_lists(way_map, opened_list, closed_list, current_point, N1, N2, current_num);
		if (opened_list.empty())
		{
			break;
		}
		int min_priority = 0;
		for (int i = 1; i < opened_list.size(); i++)
		{
			if (opened_list[i].Get_priority() < opened_list[min_priority].Get_priority())
			{
				min_priority = i;
			}
		}
		current_num = min_priority;
		current_point = opened_list[min_priority];
	}
	if ((current_point.Get_this_x() == finish_xy[0]) &&
		(current_point.Get_this_y() == finish_xy[1]))
	{
		std::map <int, way_point>::iterator it = way_map.find(current_point.Get_this_y() * N1 + current_point.Get_this_x());
		for (int i = 0; i <= current_point.Get_way_length(); i++)
		{
			it->second.Set_status(3);
			it = way_map.find(it->second.Get_pre_y() * N1 + it->second.Get_pre_x());
		}
	}
	else
	{
		return 1;
	}
	return 0;

}

