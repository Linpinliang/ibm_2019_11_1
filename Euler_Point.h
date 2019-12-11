#ifndef EULER_POINT_H
#define EULER_POINT_H
#include "Parameter.h"
#include <iostream>
#include "Function.h"
/*


*/

using namespace std;

class Euler_Point
{
private:
	//����
	int grid_x;
	int grid_y;



	//�ٶ�
	double u;
	double v;

	double u0;
	double v0;

	//unfoced velocity 
	double u_noF;
	double v_noF;


	//��������
	char style;

	//�¶�
	double T;
	double T0;
	//�ܶ�
	double Rho;
	double Rho0;

	double P;

	//������
	double forcing_x;
	double forcing_y;

	//�ֲ�����
	double New_f[9];
	double f[9];

	//����
	double F[9];


public:

	Euler_Point();

	//��ʼ��
	Euler_Point(int x, int y);

	~Euler_Point();





	//LBM

	//����΢����
	void macroscopic();
	//��ײ
	void Collision();
	//����
	//void Scond_Forcing_Step();

	//void Collision_With_Body_Force();





	//Set����
	//�����ٶ�
	void Set_Velocity(double vx, double vy);

	void Set_Velocity0(double u ,double v);
	//�����������;
	void Set_Body_force(double fx, double fy);
	//���õ��λ��
	void Set_Position(int x, int y);
	//�����¶�
	void Set_Temperature(double t);
	//����ѹ��
	void Set_Pressure(double p);
	//�����ܶ�
	void Set_rho(double rho);
	void Set_u_v_noF(double u, double v);




	void Set_f(double value, int N);
	void Set_New_f(double value, int N);
	void Set_F(double value, int N);






	//Get����

	double Get_Body_force_fx();
	double Get_Body_force_fy();

	double Get_Velocity_x();
	double Get_Velocity_y();

	double Get_Velocity0_x();
	double Get_Velocity0_y(); 


	int Get_Position_x();
	int Get_Position_y();

	double Get_u_noF();
	double Get_v_noF();


	double Get_Pressure();
	double Get_Temperature();
	double Get_rho();

	double Get_f(int N);

	double  Get_New_f(int N);
	double Get_F(int N);



	//Print����
	//����ֲ�����
	void Print_f();




};


#endif // !EULER_POINT_H
