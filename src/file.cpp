#include<fstream>
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
#include"file.h"

file_class::file_class():num(0),
			 len(0),
			 data_readed(0),
			data(NULL)
{
}

file_class::~file_class()
{
	if(num!=0)//if data matrix created, delete her
	{
		for(int i=0;i<num;i++)
			delete [] data[i];
		delete [] data;
	}
}
bool file_class::read_data(string& name,char point/* read flags*/)
{
	ifstream file(name.data());
	if(file.is_open())// file exist?
	{
		//***************READ DATA BLOCK
		vector<string> fdata;//vector for reading data with file
		string tmp;//temp variable for save current string
		
		cout<<"is_open complete"<<endl;
		while(getline(file,tmp))//read all string in file
		{
			fdata.push_back(tmp);
		}
		cout<<"data read complete"<<endl;
		//***************END READ DATA BLOCK
		file.close();//close file
		//***************DEPEND MEMORY BLOCK
		num=fdata.size();	//save number rows in matrix
		data=new double*[num];	//create depends in memory
		//find number numbers
		tmp=fdata.front();
		int count=1;// counter for calculate number in string
		for(string::iterator it=tmp.begin();it!=tmp.end();it++)
		{
			if(*it==point)
				count++;
		}
		for(int i=0;i<num;i++)
			data[i]=new double[count];
		len=count;
		//***************END DEPEND MEMORY BLOCK
		//******************PARSING DATA BLOCK
		int curr_str=0;
		for(vector<string>::iterator it=fdata.begin();it!= fdata.end(); ++it)
		{
			tmp=*it;//read current row for parsing
			int current_number=0;
			bool dot=false;
			int num_dot=0;
			double number=0.0f;
			for(string::iterator is=tmp.begin();is!=tmp.end();is++)
			{
				
				if(*is>='0' && *is<='9')
				{
					number=number*10+(*is-48);//48- index 0 in ASCII table
					if(dot)
						num_dot++;
				}
				else if(*is=='.')
					dot=true;
				if(*is==point)
				{
					data[curr_str][current_number]=number/pow(10.0,num_dot);
					number=0.0f;
					dot=false;
					num_dot=0;
					current_number++;
				}
				data[curr_str][current_number]=number/pow(10.0,num_dot);
				
			}		
			curr_str++;
		}

		//******************END PARSING DATA BLOCK


		return true;
	}	

	return false;

}

double** file_class::get_data(int &n, int&l)
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
