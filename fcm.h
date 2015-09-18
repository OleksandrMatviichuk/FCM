#ifndef FCM_H
#define FCM_H

class fcm
{
public:
	fcm();
	~fcm();
	void set_clasters_number(int claster);
	void set_data_matrix(double** dat, const int n, const int l);
	void set_iteration_number(int n); 
	void calculate(); 
	void show_data_matrix()const;
	void show_rand_matrix()const;
	void show_distance_matrix()const;
	void show_centr_matrix()const;
protected:
	double vec_distance(double *v1, double *v2, int len);
	void set_ones_matrix(double **matrix, int size_f, int size_s);
private:
	int num_clasters;// number clasters 
	double **data;//data matrix
	double **V;//matrix center point
	double **U;//random matrix
	double **D;//distance matrix	
	int num_vectors;
	int len_vectors; 
	int iteration_number; 
	//memory data
	int old_num_vect;
	int old_num_clas;
	int old_len_vect;
};


#endif
