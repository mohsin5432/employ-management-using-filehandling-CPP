#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <windows.h>
using namespace std;
int login();
void displaymenu();
void chosemenu();
void enterrecord();
void searchbyid();
void searchbyname();
void aboveage();
void displayAll();
void samedep();
void totale();
void maxsal();
void younge();
void palin();
void armst();
void updaterec();
void delrec();

struct employ
{
	char name[20];
	char gender[10];
	char desig[20];
	char dep[20];
	char join[20];
	int age,id,salary;
	
};
employ e;

int main()
{	


	int l=0;
	cout<<"\t\t\t\tADMIN ID : 12abc\t:\tADMIN PASSWORD : 12ab34cd"<<endl;
	x:
	int v,choise;
	if(l==0)
	{
		v=3;
	}
	else
	{
		v=1;
	}
	while(v!=1)
	{
	cout<<"Enter choise\n1->Login\n2->quit\n=";
	cin>>choise;
	switch(choise)
		{
		
		case 1:
			{
			v=login();
			if(v==1)
			{
			cout<<"\t\t\t * * * * * * * * *LOGIN SUCCESFULL * * * * * * * * *"<<endl;
			Beep (1500,200);
			}
			else if(v==0)
			{
			cout<<"\n\n\t\t\t * * * * * * * * *LOGIN FAILED * * * * * * * * *"<<endl;
			Beep (1200,1000);
			}
			break;
			}
		case 2:
			{
			cout<<"\n\n\t\t\t\t* * * * * *THANKS FOR USING OUR SERVICES* * * * * *\n\n";	
			exit(0);
			}
		default:
			{	
			cout<<"\n\t\t\t* * * YOU HAVE ENTERED A WRONG CHOISE * * *"<<endl;
			break;
			}
		}
	}
	if(l==0)
	{
		displaymenu();
		chosemenu();
	}
	else if(l>0)
	{
		int k;
		cout<<"ENTER 1 TO AGAIN ENTER IN MAIN MENU : ";
		cin>>k;
		if(k==1)
		{
			displaymenu();
			chosemenu();
		}
	}
	
	l++;
	
	goto x;

}




	
int login()
{
	string user,pass,u,p;
	cout<<"ENTER Admin ID : ";
	cin>>user;
	cout<<"ENTER Admin Password : ";
	cin>>pass;
	
	ifstream read("admin.txt");
	getline(read,u);
	getline(read,p);
	
	if(u == user && p == pass)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


	
	
void displaymenu()
{ 
	cout<<"\n\n\n\n\t\t\t\t* * * * * * * * *MENU* * * * * * * * *\n"<<endl;
	cout<<"1-> Enter New Record\n2-> Search a Record by Employ id\n3-> Search a record by Employ name\n4-> List Employ of a perticular department\n";
	cout<<"5-> List Employ Above Age 50\n6-> Display All Employs\n7-> Find Total No of Employs\n8-> Find the Employ With Highest Salery\n9-> Find youngest Male And Female Employ\n";
	cout<<"10-> Find the Emploly having palindrome Employ Id\n11-> Find The Employ having Armstrong Salarry\n12-> Update a record of a Particular Employ\n";
	cout<<"13-> Delete the Employs Record\n14-> Quit the Program"<<endl;
}


void chosemenu()
{
	int c;
	cout<<"\n\n\t\t\t\tEnter Choise : ";
	cin>>c;
	switch(c)
	{
	case 1:
		{
		enterrecord();
		break;
		}
	case 2:
		{	
	    searchbyid();
	    break;
		}
	case 3:
		{  
	    searchbyname();
	    break;
		}
	case 4:
		{   
	    samedep();
	    break;
		}	
	case 5:
		{
		aboveage();
		break;
		}
	case 6:
		{	
		displayAll();
		break;
		}
	case 7:
		{
		totale();
		break;
		}
	case 8:
		{
		maxsal();
		break;
		}
	case 9:
		{
		younge();
		break;	
		}
	case 10:
		{
		palin();
		break;	
		}
	case 11:
		{
		armst();
		break;	
		}
	case 12:
		{
		updaterec();
		break;	
		}
	case 13:
		{
		delrec();
		break;	
		}	
	case 14:
		{
		cout<<"\n\n\t\t\t********THANKS FOR USING OUR SERVICES********";	
		exit(0);
		}		
		
				
	default:
	cout<<"\t\t\tYOU ENTERED A WRONG CHOISE";
	}
}




void enterrecord()
{

  	cout << "Enter name : ";cin.ignore(); cin.getline(e.name, 20);
  	cout << "Enter Age : "; 	cin >> e.age;
  	cin.ignore();
  	cout << "Enter Gender : "; cin.getline(e.gender, 10);
  	cout << "Enter Designation : "; cin.getline(e.desig, 20);
  	cout << "Enter Department : "; cin.getline(e.dep, 20);
	cout << "Enter salary : "; 	cin>> e.salary;
	cin.ignore();
	cout << "Enter Date of joining (dd-mm-yyyy) : "; cin.getline(e.join, 20);
	srand(time(0));
	e.id = rand()%1000;
	cout << "ID is : " << e.id<<endl;
	ofstream output("data.bat", ios :: binary | ios :: app);
	output.write((char*)&e, sizeof(e));
	output.close();
}




void searchbyid()
{
	int id;
	cout << "Enter ID :";	cin >> id;
	ifstream input("data.bat", ios :: binary);
	while(input){
		input.read((char*)&e, sizeof(e));
		if(input.eof())	break;
		if(e.id == id){
			cout << "\n\nName : " << e.name << endl
			<< "Age : " << e.age << endl
			<< "Gender : " << e.gender << endl
			<< "Designation : " << e.desig << endl
			<< "Department : " << e.dep << endl
			<< "Salary : " << e.salary << endl
			<< "Date of join : " << e.join << endl;
		}
	}
	input.close();
}




void searchbyname()
{
	char name[20];
	cout << "Enter Name :";	cin.ignore();cin.getline(name, 20);
	ifstream input("data.bat", ios :: binary);
	while(input){
		input.read((char*)&e, sizeof(e));	
		if(input.eof())	break;
		if(strcmp(e.name,name)==0){
			cout << "\n\nName : " << e.name << endl
			<< "Age : " << e.age << endl
			<< "Gender : " << e.gender << endl
			<< "Designation : " << e.desig << endl
			<< "Department : " << e.dep << endl
			<< "Salary : " << e.salary << endl
			<< "Date of join : " << e.join <<endl
			<< "Employ ID : "<<e.id<< endl;
		}
	}
	
	input.close();	
}




void samedep()
{
	char dep[20];
	cout << "Enter Department :";	cin.ignore();cin.getline(dep, 20);
	ifstream input("data.bat", ios :: binary);
	while(input){
		input.read((char*)&e, sizeof(e));
		if(input.eof())	break;
		if(strcmp(e.dep,dep)==0){
			cout << "\n\n\nName : " << e.name << endl
			<< "Age : " << e.age << endl
			<< "Gender : " << e.gender << endl
			<< "Designation : " << e.desig << endl
			<< "Department : " << e.dep << endl
			<< "Salary : " << e.salary << endl
			<< "Date of join : " << e.join << endl;
		}	
		
	}
	input.close();
}





void aboveage()
{

	ifstream input("data.bat", ios :: binary);
	while(input)
	{
		if(input.read((char*)&e, sizeof(e)));
		if(input.eof())	break;
		if(e.age > 50){
			cout << "\n\nName : " << e.name << endl
			<< "Age : " << e.age << endl
			<< "Gender : " << e.gender << endl
			<< "Designation : " << e.desig << endl
			<< "Department : " << e.dep << endl
			<< "Salary : " << e.salary << endl
			<< "Date of join : " << e.join << endl;
		}}
		input.close();
	
}




void displayAll()
{
    ifstream file("data.bat",ios::binary|ios::in);
    while(file){
    if(file.read((char*)&e,sizeof(e))){
    	if(file.eof())	break;
    	cout <<"\nID : " << e.id << endl
			<< "Name : " << e.name << endl
			<< "Age : " << e.age << endl
			<< "Gender : " << e.gender << endl
			<< "Designation : " << e.desig << endl
			<< "Department : " << e.dep << endl
			<< "Salary : " << e.salary << endl
			<< "Date of join : " << e.join << endl
			<< "\n\n"<<endl;
	}
        
    }
  file.close();
}





void totale()
{
    ifstream file("data.bat",ios::binary);
    int total=0;
    while(file)
	{
    if(file.read((char*)&e,sizeof(e)))
    {
    	if(file.eof())	break;
    	total++;
        
    }
	}
	cout<<"TOTAL EMPLOY REGISTERED :"<<total<<endl;
	file.close();

}
void maxsal()
{
    ifstream file("data.bat",ios::binary);
    int max=0;
    while(file)
	{
    if(file.read((char*)&e,sizeof(e)))
	{
    	if(max<e.salary)
    	{
    		max=e.salary;
		}
        
    }
	}
	
	file.close();
	ifstream maxxx("data.bat",ios::binary);
    while(maxxx)
	{
    if(maxxx.read((char*)&e,sizeof(e)))
	{
		if(maxxx.eof())	break;
    	if(max==e.salary)
    	{
    		cout<<"\n\n\n";
    		cout<<"\t\t\t"<<e.name<<" ID NO "<<e.id<<" got maximum salary : "<<max<<endl;
		}
        
    }
	}
	
	file.close();
}
void younge()
{
    ifstream file("data.bat",ios::binary);
    int ym=9999,yf=9999;
    char m[20]="male";
    char f[20]="female";
    while(file)
	{
    if(file.read((char*)&e,sizeof(e)))
	{
    	if(strcmp(e.gender,m)==0)
    	{
    		if(ym>e.age)
    		ym=e.age;
		}
		else if(strcmp(e.gender,f)==0)
		{
			if(yf>e.age)
    		yf=e.age;
		}
        
    }
	}
	
	file.close();
	ifstream young("data.bat",ios::binary);
    while(young)
	{
    if(young.read((char*)&e,sizeof(e)))
	{
		if(young.eof())	break;
    	if(ym==e.age && strcmp(e.gender,m)==0)
    	{
    		cout<<"\n\n\n";
    		cout<<"\t\t\t"<<e.name<<" is the youngest male employ of age : "<<e.age<<endl;
		}
		else if (yf==e.age && strcmp(e.gender,f)==0)
		{
    		cout<<"\n\t\t\t"<<e.name<<" is the youngest Female employ of age : "<<e.age<<endl;
		}
        
    }
	}
	
	file.close();

}
void palin()
{
	//palindromic number is a number that is the same when written forwards or backwards
	ifstream file("data.bat",ios::binary);
    while(file)
	{
    if(file.read((char*)&e,sizeof(e)))
	{
		if(file.eof())	break;
    	int id=0,r=0,rem;

    	id=e.id;

    	while(id != 0)
    	{
        rem= id%10;
        r = r*10 + rem;
        id /= 10;
    	}
    	if(r==e.id)
    	{
    		cout<<"\n\n\t\t\t"<<e.name<<" has palindrome ID : "<<e.id<<endl;
		}

        
    }
	}
	
	file.close();
}
void armst()
{
	//Armstrong number if the sum of cubes of individual digit is equal to that number itself
	ifstream file("data.bat",ios::binary);
    while(file)
	{
    if(file.read((char*)&e,sizeof(e)))
	{
    int orig=0, num=0, rem=0, sum = 0;
  	orig=e.salary;

  	num = orig;

  	while(num != 0)
  	{
    rem = num % 10;
    sum += rem * rem * rem;
    num /= 10;
  	}

  	if(sum == e.salary)
    cout<<"\n\n\t\t"<<e.name<<" got Armstrong salary : "<<e.salary<<endl;
    
    }
	}
	
	file.close();
	
}
void updaterec()
{
	int id;
	cout << "Enter ID :";	cin >> id;
	ifstream input("data.bat", ios :: binary);
	ofstream output("temp.bat", ios :: binary | ios :: app);
	while(input)
	{
		if(input.read((char*)&e, sizeof(e)));
		{if(input.eof())	break;
		if(e.id == id){
			cout << "Name : " << e.name << endl
			<< "Age : " << e.age << endl
			<< "Gender : " << e.gender << endl
			<< "Designation : " << e.desig << endl
			<< "Department : " << e.dep << endl
			<< "Salary : " << e.salary << endl
			<< "Date of join : " << e.join << endl
			<< "update record now\n"<<endl;
		cout << "Enter name : ";cin.ignore(); cin.getline(e.name, 20);
  		cout << "Enter Age : "; 	cin >> e.age;
  		cin.ignore();
  		cout << "Enter Gender : "; cin.getline(e.gender, 10);
  		cout << "Enter Designation : "; cin.getline(e.desig, 20);
  		cout << "Enter Department : "; cin.getline(e.dep, 20);
		cout << "Enter salary : "; 	cin>> e.salary;
		cin.ignore();
		cout << "Enter Date of joining (dd-mm-yyyy) : "; cin.getline(e.join, 20);
		output.write((char*)&e, sizeof(e));
		}
		else
		{
			if(input.eof())	break;
			output.write((char*)&e, sizeof(e));	
		}
	}}
		output.close();
		input.close();
		remove("data.bat");
		rename ("temp.bat","data.bat");
}
void delrec()
{
	int id;
	cout << "Enter ID :";	cin >> id;
	ifstream input("data.bat", ios :: binary);
	ofstream output("temp.bat", ios :: binary | ios :: app);
	while(input)
	{
		if(input.read((char*)&e, sizeof(e)));
		{
		if(input.eof())	break;	
		if(e.id == id){
			cout <<"\n\t\tTHIS RECORD HAS BEEN DELETED"<<endl
			<< "Name : " << e.name << endl
			<< "Age : " << e.age << endl
			<< "Gender : " << e.gender << endl
			<< "Designation : " << e.desig << endl
			<< "Department : " << e.dep << endl
			<< "Salary : " << e.salary << endl
			<< "Date of join : " << e.join << endl;
		}
		else
		{
			if(input.eof())	break;
			output.write((char*)&e, sizeof(e));	
		}
	}}
		output.close();
		input.close();
		remove("data.bat");
		rename ("temp.bat","data.bat");
}











	
	
	
