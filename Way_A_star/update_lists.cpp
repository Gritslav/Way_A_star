#include "main_header.h"

void point_check(way_point&, std::vector<way_point>&, std::vector<way_point>&, way_point&);

void update_lists(std::map<int, way_point>& way_map, std::vector<way_point>& opened_list, 
	std::vector<way_point>& closed_list, way_point& current_point, int N1, int N2, int current_num)
{
	std::map <int, way_point>::iterator it;
	it = way_map.find(current_point.Get_this_y() + N1*(current_point.Get_this_x()+1));
	
	if (it != way_map.end())
	{
		point_check(it->second, opened_list, closed_list, current_point);
	}
	it = way_map.find(current_point.Get_this_y() + N1 * (current_point.Get_this_x() - 1));
	if (it != way_map.end())
	{
		point_check(it->second, opened_list, closed_list, current_point);
	}
	it = way_map.find((current_point.Get_this_y() + 1) + N1 * current_point.Get_this_x());
	if (it != way_map.end())
	{
		point_check(it->second, opened_list, closed_list, current_point);
	}
	it = way_map.find((current_point.Get_this_y() - 1) + N1 * current_point.Get_this_x());
	if (it != way_map.end())
	{
		point_check(it->second, opened_list, closed_list, current_point);
	}
	opened_list.erase(opened_list.begin() + current_num);
	closed_list.push_back(current_point);
}