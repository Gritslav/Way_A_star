#include "main_header.h"

void map_loader(std::map<int, way_point> &way_map, int *N1, int *N2)
{
	std::ifstream fin;
	fin.open("input.txt");
	if (!fin.is_open())
	{
		std::cout << "Input file did not opened!" << std::endl;
	}
	else
	{
		way_point trash;
		int i = 0;
		std::string str_read = "";
		int j = 0;
		while (!fin.eof())
		{

			std::getline(fin, str_read);

			if (str_read[1] == ' ')
			{
				i = 0;
				trash.Set_pre_xy(-1, -1);
				trash.Set_this_xy(i, j);
				trash.Set_way_length(0);
				trash.Set_status(str_read[i * 2] - 48);
				way_map[j*(*N2) + i] = trash;
				i++;
				while (str_read[i * 2 - 1] != '\0')
				{
					trash.Set_pre_xy(-1, -1);
					trash.Set_this_xy(i, j);
					trash.Set_way_length(0);
					trash.Set_status(str_read[i * 2] - 48);
					way_map[j*(*N2) + i] = trash;
					i++;
				}
			}
			else
			{
				i = 0;
				while (str_read[i] != '\0')
				{
					trash.Set_pre_xy(-1, -1);
					trash.Set_this_xy(i, j);
					trash.Set_way_length(0);
					trash.Set_status(str_read[i] - 48);
					way_map[j*(*N2) + i] = trash;
					i++;
				}
			}
			if (j == 0)
			{
				*N2 = i;
			}
			j++;
		}
		*N1 = j;
		fin.close();

	}
}