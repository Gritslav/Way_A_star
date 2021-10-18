#include "main_header.h"
void map_saver(std::map<int, way_point>& way_map, int N1, int N2, int check)
{
	std::ofstream fout;
	fout.open("output.txt");
	if (!fout.is_open())
	{
		std::cout << "Input file did not opened!" << std::endl;
	}
	else
	{
		if (check == 1)
		{
			fout << "Way is not found!" << std::endl;
		}
		else
		{
			std::map <int, way_point>::iterator it;
			it = way_map.begin();
			for (int i = 0; i < N1; i++)
			{
				for (int j = 0; j < N2; j++)
				{
					fout << it->second.Get_status() << ' ';
					it++;
				}
				fout << std::endl;
			}
		}
		fout.close();

	}
}