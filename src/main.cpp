#include<iostream>

#include"fcm.h"
int main()
{
	//test data;
	const int n=4, k=3;
	double **X=new double*[n];
	for(int i=0;i<n;i++)
	X[i]=new double[k];
	X[0][0]=1.0; X[0][1]=1.0; X[0][2]=0.0;
	X[1][0]=0.0; X[1][1]=1.0; X[1][2]=1.0;
	X[2][0]=1.2; X[2][1]=0.9; X[2][2]=0.1;
	X[3][0]=0.1; X[3][1]=1.1; X[3][2]=0.95;

	fcm *obj=new fcm();
	
	obj->set_iteration_number(50);
	obj->set_clasters_number(2);
	obj->set_data_matrix(X,n,k);

	obj->calculate();

	obj->show_data_matrix();
	obj->show_rand_matrix();
	obj->show_distance_matrix();
	obj->show_centr_matrix();

	delete obj;
	for(int i=0;i<n;i++)
		delete [] X[i];
	delete [] X;

	return 0;
}
