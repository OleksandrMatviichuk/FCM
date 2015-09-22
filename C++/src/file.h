#ifndef FILE_CLASS
#define FILE_CLASS

#include<fstream>
#include<string>
using namespace std;
class file_class
{
public:
	file_class();
	~file_class();
	bool read_data(string & name,char point= ',');	//inpun name file with data and read they
	double** get_data(int&n, int&l);//return data matrix
	
private:
	double** data;		// matrix width data in file
	int num;		//number vectors
	int len;		//lenght vectors
	bool data_readed;	//matrix=NULL?

};

#endif
