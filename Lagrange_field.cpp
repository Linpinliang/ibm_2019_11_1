#include "Lagrange_field.h"






Lagrange_field::Lagrange_field()
{
}

Lagrange_field::Lagrange_field(double center_x, double center_y, double r, int number_of_node)
{
	Set_center_x(center_x);
	Set_center_y(center_y);
	Set_r(r);
	Set_Number_of_lagrange_node(number_of_node);
	Set_lagrange_node();
	Set_delta_Sb();
}

void Lagrange_field::Set_center_x(double x)
{
	_center_x = x;
}

void Lagrange_field::Set_center_y(double y)
{
	_center_y = y;
}

void Lagrange_field::Set_Number_of_lagrange_node(int N)
{
	_Number_of_lagrange_node = N;
}

void Lagrange_field::Set_delta_Sb()
{
	double x1 = lagrange_node[0]->Get_Position_x();
	double y1 = lagrange_node[0]->Get_Position_y();

	double x2 = lagrange_node[1]->Get_Position_x();
	double y2 = lagrange_node[1]->Get_Position_y();


	//cout << "x1y1" <<"\t"<< x1   <<"\t"<<  y1 << endl;
	//cout << "x2y2" <<"\t"<< x2   <<"\t"<< y2 << endl;


	_delta_Sb = Distance(x1, y1, x2, y2);

	for (int i = 0; i < _Number_of_lagrange_node; i++)
	{
		lagrange_node[i]->Set_deleta_sb(_delta_Sb);
	}

}

void Lagrange_field::Set_r(double r)
{
	_r = r;

}

void Lagrange_field::Set_lagrange_node()
{
	lagrange_node = vector<Lagrange_Point*>(_Number_of_lagrange_node);

	for (int i = 0; i < _Number_of_lagrange_node; i++)
	{
		Lagrange_Point* p1 = new Lagrange_Point(_center_x + _r * cos(2 * pi * i / _Number_of_lagrange_node), _center_y + _r * sin(2 * pi * i / _Number_of_lagrange_node));
		lagrange_node[i] = p1;
		
	}
}

double Lagrange_field::Get_center_x()
{
	return _center_x;
}

double Lagrange_field::Get_center_y()
{
	return _center_y;
}

int Lagrange_field::Get_Number_of_lagrange_node(int N)
{
	return _Number_of_lagrange_node;
}

double Lagrange_field::Get_r(double r)
{
	return _r;
}

double Lagrange_field::Get_delta_Sb()
{
	return _delta_Sb;
}

void Lagrange_field::Output_Solid(double value, int step)
{
	ostringstream name;
	name << "Re = " << value << "_lagrange_node" << step << ".dat";
	ofstream out(name.str().c_str());

	out << "x" << "\t";
	out << "y" << "\t";

	out << "ub_nof" << "\t";
	out << "vb_nof" << "\t";

	out << "Fx" << "\t";
	out << "Fy" << "\t";
	out << endl;

	for (unsigned int i = 0; i < lagrange_node.size(); i++)
	{


		out << lagrange_node[i]->Get_Position_x() << "\t";
		out << lagrange_node[i]->Get_Position_y() << "\t";

		out << lagrange_node[i]->get_ub_nof() << "\t";
		out << lagrange_node[i]->get_vb_nof() << "\t";

		out << lagrange_node[i]->Get_Fx() << "\t";
		out << lagrange_node[i]->Get_Fy() << "\t";

		out << endl;

	}

}

void Lagrange_field::Set_center_velocity(double x, double y, double angle)
{
	_center_velocity_x = x;
	_center_velocity_y = y;
	_center_velocity_angle = angle;
}

void Lagrange_field::moving_update()
{
	_center_x = _center_x + _center_velocity_x;
	_center_y = _center_y + _center_velocity_y;
	_center_angle = _center_angle + _center_velocity_angle;

	//cout << "x=" << _center_x << endl;
	//cout << "y=" << _center_y << endl;
	//cout << "angle=" << _center_angle << endl;


	for (int i = 0; i < lagrange_node.size(); i++)
	{
		double x = lagrange_node[i]->Get_Position_x();
		double y = lagrange_node[i]->Get_Position_y();

		x = x + _center_velocity_x;
		y = y + _center_velocity_y;

		lagrange_node[i]->Set_Position(x,y);



		//double u = lagrange_node[i]->Get_Ub();
		//double v = lagrange_node[i]->Get_Vb();
		lagrange_node[i]->Set_Ub_Vb(_center_velocity_x, _center_velocity_y);


	}





}

void Lagrange_field::output_all(int step)
{
}

Lagrange_field::~Lagrange_field()
{
}
