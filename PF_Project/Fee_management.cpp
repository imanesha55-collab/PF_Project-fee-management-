#include<iostream>
#include<fstream>
using namespace std;

void menu();
void addStudent();
void payFee();
void show();
int main()
{
int c;
do
{
menu();
cin>>c;
if(c==1)
addStudent();
else if(c==2)
payFee();
else if(c==3)
show();
else if(c==4)
cout<<"Exiting program...\n";
else
cout<<"Invalid choice!\n";

}while(c!=4);

return 0;
}

void menu()
{
cout<<"\n===== Fee Management System =====\n";
cout<<"1. Add Student\n";
cout<<"2. Pay Fee\n";
cout<<"3. View Records\n";
cout<<"4. Exit\n";
cout<<"Enter your choice: ";
}

void addStudent()
{
int roll;
int total;
int paid=0;
char name[30];

ofstream file("fees.txt",ios::app);

cout<<"Enter Roll No: ";
cin>>roll;
cout<<"Enter Name: ";
cin>>name;
cout<<"Enter Total Fee: ";
cin>>total;

file<<roll<<" "<<name<<" "<<total<<" "<<paid<<endl;
file.close();

cout<<"Student added successfully!\n";
}

void payFee()
{
int roll;
int pay;
int r;
int total;
int paid;
char name[30];
int found=0;

ifstream file("fees.txt");
ofstream temp("temp.txt");

cout<<"Enter Roll No: ";
cin>>roll;
cout<<"Enter Amount to Pay: ";
cin>>pay;

while(file>>r>>name>>total>>paid)
{
if(r==roll)
{
paid=paid+pay;
found=1;
}
temp<<r<<" "<<name<<" "<<total<<" "<<paid<<endl;
}

file.close();
temp.close();

remove("fees.txt");
rename("temp.txt","fees.txt");

if(found==1)
cout<<"Fee paid successfully!\n";
else
cout<<"Student not found!\n";
}

void show()
{
int roll;
int total;
int paid;
char name[30];

ifstream file("fees.txt");

cout<<"\nRoll  Name  TotalFee  PaidFee  Remaining\n";
cout<<"----------------------------------------\n";

while(file>>roll>>name>>total>>paid)
{
cout<<roll<<"    "<<name <<"    "<<total<<"        "<<paid<<"        "<<(total-paid)<<endl;
}

file.close();
}
