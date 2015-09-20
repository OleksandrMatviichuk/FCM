#include<fstream>

#include"file.h"

file_class::file_class() : num(0),
                            len(0), 
                         data(nullptr) { }

file_class::~file_class()
{
	if(num!=0)//if data matrix created, delete her
	{
		for(int i=0;i<num;i++)
			delete [] data[i];
		delete [] data;
	}
}
bool file_class::read_data(string &name/* read flags*/)
{
	ifstream file(name.data());
	if(!file.is_open())// file exist
	{
		//read data block
		//end read date block
		file.close();
		return true;
	}	

	return false;
}

double** file_class::get_data(int &n, int &l)
{
//return sizes data
	n=num;
	l=len;
// if data not NULL copy data to array tmp and return tmp or return NULL
	if(num!=0)
	{
		double** tmp=new double*[num];
		for(int i=0;i<num;i++)
			tmp[i]=new double[len];
		for(int i=0;i<num;i++)
			for(int j=0;j<num;j++)
				tmp[i][j]=data[i][j];
		return tmp;
	}
	return NULL;
}
