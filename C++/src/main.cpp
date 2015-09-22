#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
#include"fcm.h"
#include"file.h"

void menu();
int main()
{
	menu();
	return 0;
	
}
struct Setings
{
	int iteration_number;
	int number_claster;
	string filename;
	char point;
};
void menu()
{
//***********************Create work object block
	Setings setings;
	fcm *FCM=new fcm();
	file_class *file=new file_class();
//**********************End block create work object
	//start setings initialise
	setings.point=',';
	setings.number_claster=2;
	setings.iteration_number=50;
	char command[10];
	int i;
	system("clear");//clear console
	do
	{
	cout<<"----------------MENU----------------"<<endl;
	cout<<"1. load data with file"<<endl;
	cout<<"2. calculate "<<endl;
	cout<<"3. show result"<<endl;
	cout<<"4. change setings"<<endl;
	cout<<"5. exit"<<endl;
	cout<<"change number command: ";
	cin.clear();	// crear flags
	cin.sync();	//clear chars in stream 
	cin.getline(command,10);
	i=atoi(command);

	switch(i)
	{
		case 1:
			{
				cout<<"input name file: ";
				cin>>setings.filename;
				if(file->read_data(setings.filename),setings.point)
					cout<<"download complete"<<endl;
				else
					cout<<"download failed"<<endl;
				break;
			}
		case 2:
			{
				int tmp_n;
				int tmp_l;
// WARNING function return new double matrix, and depended memory not free in destructor
				double **tmp_data;
				tmp_data=file->get_data(tmp_n, tmp_l);
				FCM->set_data_matrix(tmp_data,tmp_n,tmp_l);
				FCM->set_iteration_number(setings.iteration_number);
				FCM->set_clasters_number(setings.number_claster);
				FCM->calculate();
				break;
			}
		case 3:
			{
				char tmp='n';
				cout<<"show distance matrix (y/n)?"<<endl;
				cin>>tmp;
				if(tmp=='y')
					FCM->show_distance_matrix();
				cout<<"show input data matrix (y/n)?"<<endl;
				cin>>tmp;
				if(tmp=='y')
					FCM->show_data_matrix();
				cout<<"show matrix with centr(y/n)?"<<endl;
				cin>>tmp;
				if(tmp=='y')
					FCM->show_centr_matrix();
				cout<<"show random ones matrix(y/n)?"<<endl;
				cin>>tmp;
				if(tmp=='y')
					FCM->show_rand_matrix();
				break;
			}
		case 4:
			{
				char tmp[10];
				cout<<"input number iteration ( now "<<setings.iteration_number<<"): ";
				cin.getline(tmp,10);
				if(atoi(tmp)!=0)
					setings.iteration_number=atoi(tmp);
				//cout<<setings.iteration_number;	
				cout<<"input number claster ( now "<<setings.number_claster<<"): ";
				cin.getline(tmp,10);
				if(atoi(tmp)!=0)
					setings.number_claster=atoi(tmp);
				//setings point between number
				/*cout<<"input point between number ( now ' "<<setings.point<<"'): ";
				cin.getline(tmp,10);
				if(tmp[0]!='\n')
					setings.point=tmp[0];*/
				break;
			}
		case 5:
				cout<<"Good luck"<<endl;
				break;
		default : 
				cout<<"incorect input, please input number in interval 1..5"<<endl;
				break;
	}
	}while(i!=5);
//*********************clear memory block
	delete FCM;
	delete file;
//*********************end clear memory block
}
