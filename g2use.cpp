#include "g2use.h"

std::string getPath()
//Функція повертає шлях до файлу, введений користувачем
{
	std::string path;
	std::cout << "\nPlease, input file path: ";
	std::getline(std::cin, path);
	return path;
}

void processData(std::ifstream& fi, std::ofstream& fo)
{
	while (!fi.eof())
	{
		std::vector<Point> res = inData(fi);
		try {
			for (int i = 0; i < 4; ++i) {
				int count = 0;
				for (int j = 0; j < 4; ++j)
				{
					if (res[i] == res[j])
						++count;
					if (count > 1)
						throw res[i];
				}
			}
			bool result = isDeltoid(res);
			outData(res, result, fo);
		}
		catch(Point p) {
			outData(res, 0, fo);
			fo << " ERROR: a doubled point (" << p.getX() << ", " << p.getY() << ")";
		} 
	}
}

std::vector<Point> inData(std::ifstream& fi)
//Функція створює об'єкт - точку
{
	std::vector<Point> in_data(4);
	double x(0), y(0);
	for (int i = 0; i < 4; ++i)
	{
		x = getC(fi);
		y = getC(fi);
		in_data[i] = Point(x, y);
	}
	return in_data;
}

void outData(std::vector<Point>& data, bool result, std::ofstream& fo)
//Функція виводить результати роботи програми у файл
{
	fo << "\n";
	for (auto& p : data)
	{
		fo << '(' << p.getX() << ", " << p.getY() << ") ";
	}
	fo << ": ";
	if (result)
		fo << "True";
	else fo << "False";
}

double getC(std::ifstream& fi)
//Функція зчитує дані типу string з файлу і повертає double
{
	char a;
	std::string tempX_int, tempX;
	double res = 0;
	fi.get(a);
	while (a != ' ' && a != '.' && a != '\n' && !fi.eof())
	{
		tempX_int.push_back(a);
		fi.get(a);
	}
	if (a == '.')
	{
		fi.get(a);
		while (a != ' ' && a != '\n' && !fi.eof())
		{
			tempX.push_back(a);
			fi.get(a);
		}
	}
	int size = tempX_int.size();
	for (int i = size - 1; i >= 0; --i)
		res += (tempX_int[i] - '0') * pow(10, size - i - 1);
	size = tempX.size();
	for (int i = 0; i < size; ++i)
		res += (tempX[i] - '0') / pow(10, (i + 1));
	return res;
}

bool isDeltoid(std::vector<Point>& d)
//Функція перевіряє чи є заданий чотирикутник дельтоїдом
{
	std::vector<double> len;
	for (int i = 0; i < 3; ++i)
	{
		len.push_back(round(sqrt(pow((d[i].getX() - d[i + 1].getX()), 2) + 
			pow((d[i].getY() - d[i + 1].getY()), 2)) * 10000) / 10000);
	}
	len.push_back(round(sqrt(pow((d[3].getX() - d[0].getX()), 2) +
		pow((d[3].getY() - d[0].getY()), 2)) * 10000) / 10000);

	return ((len[0] == len[1] && len[2] == len[3]) || 
		(len[1] == len[2] && len[0] == len[3]));
}