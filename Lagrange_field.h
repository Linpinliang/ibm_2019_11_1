#ifndef LAGRANGE_FIELD_H
#define LAGRANGE_FIELD_H
#include <vector>
#include "Lagrange_Point.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Function.h"
#define pi  3.14159265358979323846



using namespace std;

class Lagrange_field
{
public:
	double _center_x;
	double _center_y;
	double _center_angle;

	double _center_velocity_x;
	double _center_velocity_y;
	double _center_velocity_angle;

	double _r;
	double mass;

	int _Number_of_lagrange_node;
	double _delta_Sb;
	vector<Lagrange_Point*> lagrange_node;

public:
	//
	Lagrange_field();
	
	//Բ��
	Lagrange_field(double center_x,double center_y, double r,int number_of_node);

	void Set_center_x(double x);
	void Set_center_y(double y);
	void Set_Number_of_lagrange_node(int N);
	void Set_delta_Sb();
	void Set_r(double r);
	void Set_lagrange_node();

	double Get_center_x();
	double Get_center_y();
	int Get_Number_of_lagrange_node(int N);
	double Get_r(double r);
	double Get_delta_Sb();

	//Output Data
	void Output_Solid(double value, int step);

	
	void Set_center_velocity(double x, double y, double angle);
	void moving_update();



	//output xyuvfxfy
	void output_all(int step);

	~Lagrange_field();



};

#endif 