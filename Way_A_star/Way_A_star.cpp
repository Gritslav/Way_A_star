#include "main_header.h"

void map_loader(std::map<int, way_point>&, int*, int*);
void update_lists();
void update_ways();
void set_way();

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
			it->second.Set_hevristic(i, j, finish_xy[0], finish_xy[1]);
			it->second.Set_priority();
			std::cout << it->second.Get_priority() << ' ';
			it++;
		}
		std::cout << std::endl;
	}
	

	system("pause");
	return 0;
}

