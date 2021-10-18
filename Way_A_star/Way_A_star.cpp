#include "main_header.h"

void map_loader(std::map<int, way_point>&, int*, int*);
void map_saver(std::map<int, way_point>&, int, int, int);
int set_way(std::map<int, way_point>&, std::vector<way_point>&, std::vector<way_point>&, std::vector<int>&, int, int);

int main()
{
	int N1 = 0;
	int N2 = 0;
	std::map<int, way_point> way_map;
	map_loader(way_map, &N1, &N2);
	
	

	std::vector<int> start_xy;
	start_xy.push_back(0);
	start_xy.push_back(0);
	std::vector<int> finish_xy;
	finish_xy.push_back(N2 - 1);
	finish_xy.push_back(N1 - 1);


	std::vector<way_point> opened_list;
	std::vector<way_point> closed_list;

	std::map <int, way_point>::iterator it = way_map.find(0);

	opened_list.push_back(it->second);

	it = way_map.begin();

	for (int i = 0; i < N1; i++)
	{
		for (int j = 0; j < N2; j++)
		{
			if (it->second.Get_status() == 0)
			{
				it->second.Set_hevristic(i, j, finish_xy[0], finish_xy[1]);
				it->second.Set_priority();
			}
			else
			{
				it->second.Set_hevristic(0, 0, 0, 0);
				it->second.Set_priority();
			}
			it++;
		}
	}

	map_saver(way_map, N1, N2, set_way(way_map, opened_list, closed_list, finish_xy, N1, N2));
	
	return 0;
}

