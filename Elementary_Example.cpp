

double round_up(double value, int decimal_places)
{
	const double multiplier = std::pow(10.0, decimal_places);
	return std::ceil(value * multiplier) / multiplier;
}


	int i = 0;
	float x, y, z;
	float _x, _y, _z;
	float __x, __y, __z;
	float dx, dy, dz;
	
	dx = 1; dy = 1; dz = 1;
	x = 0;
	y = 0;
	z = 0;



	do
	{

		_x = x;
		_y = y;
		_z = z;
		x = 0.5 * (7 + y);
		y = 0.5 * (1 + x + z);
		z = 0.5 * (1 + y);
		std::cout << i << " " << x << " " << y << " " << z << "\n";
		dx = x - _x;
		dy = y - _y;
		dz = z - _z;
		i++;
	} while ((dx >= 0.0001 && dy >= 0.0001 && dz >= 0.0001));


	for (int c = 0; c <= 30; c++) std::cout << (char)220;
	std::cout << "\n";
	std::cout << "EQUATIONS: \n 2x - y = 7\n -x +2y -z = 1\n -y +2z = 1\n SOLVED USING GUASS SIDEL ITERATIVE METHOD in "<<i<<" ITERATIONS\n";
	std::cout << "\nSOLUTION: " << "\nx = " << round_up(x, 3) << "\ny = " << round_up(y, 3) << "\nz = " << round_up(z, 3) << "\n";


