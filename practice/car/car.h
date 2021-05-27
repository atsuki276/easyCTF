#include <cmath>
#include <string>
#include <iostream>

class Car {
	std::string name;
	int width, height, length;
	double xp, yp;
	double fuel_level;	//”R—¿

public:
	Car(std::string n, int w, int h, int l, double f) {
		name = n;
		width = w; height = h; length = l;
		fuel_level = f;
		xp = yp = 0.0;
	}

	double x() {
		return xp;
	}
	double y() {
		return yp;
	}
	double fuel() {
		return fuel_level;
	}

	void print_spec() {
		std::cout << "–¼‘O:" << name << "\n";
		std::cout << "ŽÔ•:" << width << "mm\n";
		std::cout << "ŽÔ‚:" << height << "mm\n";
		std::cout << "’·‚³:" << length << "mm\n";
	}

	void gas_in(double gas) {
		fuel_level += gas;
		std::cout << gas << "“ü‚ê‚Ü‚µ‚½B\n";
		fuel();
	}

	bool move(double dx, double dy) {
		double dist = sqrt(dx * dx + dy * dy);

		if (dist > fuel_level)
		{
			return false;
		} else
		{
			fuel_level -= dist;
			xp += dx;
			yp += dy;
			return true;
		}
	}
};