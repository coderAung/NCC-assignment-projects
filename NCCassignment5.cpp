//yewontaung798@gmail.com

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

int password();

class Data
{
public:
	string name;
	int id;
	int amount;
	int age;
	string location;
	
	void addData()
	{
		ofstream af; //adding adata to file
		af.open("udata.txt", ofstream::app);
		
		if(af.fail())
		{
			cout << "Error opening file" << endl;
			exit(1);
		}
		
		af << name << " : " << id << " : " << amount << " : " << age << " : " << location << endl;
		
		af.close();
	}
	
};

int main()
{
	Data user;
	
	int choice;
	int pass_w;
	
	cout << "Press 1 to insert data" << endl;
	cout << "Press 2 to find data" << endl;
	cout << "Press 3 to update data" << endl;
	cout << "Press 4 to exit" << endl;
	
	cin >> choice;
	
	//cout << "choice = " << choice << endl;
	
	while(choice != 4)
	{
		if(choice == 1)
		{
			cout << "Enter your data" << endl;
			
			cout << "Name :: ";
			//cin >> user.name;
			getline(cin >> ws, user.name);
			
			cout << "ID :: ";
			cin >> user.id;
			
			cout << "Amount :: ";
			cin >> user.amount;
			
			cout << "Age :: ";
			cin >> user.age;
			
			cout << "Location(town) :: ";
			getline(cin >> ws, user.location);
			
			user.addData();
			
			cout << "Password (4 digits) :: ";
			cin >> pass_w;
			
			ofstream ap; // add password
			
			ap.open("pw.txt", ofstream::app);
			
			if(ap.fail())
			{
				cout << "Error occurs!" << endl;
				return 1;
			}
			
			ap << "\n" << pass_w;
			
			cout << "Data added successfully." << endl;
			
			ap.close();
		}
			
		else if(choice == 2)
		{
			int read_line = password();
			
			//cout << "Read line = " << read_line << endl;
			
			ifstream rf; //reading file
			
			rf.open("udata.txt");
			
			if(rf.fail())
			{
				cout << "Error occura!" << endl;
				return 1;
			}
			
			string user_data;
			int current_line = 1;
			
			while(getline(rf, user_data))
			{
				if(!rf.eof())
				{
					if(current_line == read_line)
					{
						cout << user_data << endl;
						break;
					}
				}
				current_line++;
			}
			rf.close();
			
		}
			
			/*case 3:
			break;
			
			case 4:
			break;*/
			
			//default:
			//break;
		
		cout << "Press 1 to insert data" << endl;
		cout << "Press 2 to find data" << endl;
		cout << "Press 3 to update data" << endl;
		cout << "Press 4 to exit" << endl;
		
		cin >> choice;
	}
	
	
	return 0;	
}


int password()
{
	string temp_pw;
	string counter_pw;
	
	int line = 1;
	
	ifstream file;
	
	file.open("pw.txt");
	
	if(file.fail())
	{
		cout << "Error occur!" << endl;
		return 1;
	}
	
	cout << "Enter password to find :: ";
	cin >> temp_pw;
	
	while(getline(file, counter_pw))
	{
		
		/*if(temp_pw == counter_pw)
		{
			cout << "Temp = " << temp_pw << endl;
			cout << "Counter = " << counter_pw << endl;
			cout << "Line :: " << line - 1 << endl;
			break;
		}
		
		line++;*/
		
		//cout << "Counter = " << counter_pw << endl;
		
		if(counter_pw == temp_pw)
		{
			/*cout << "Right pw = " << counter_pw << endl;
			cout << "Temp pw = " << temp_pw << endl;
			cout << "Line = " << line - 1<< endl;*/
			
			int new_line = line -1;
			return new_line;
			break;
		}
		
		
		line++;
	}
	
	
	/*cout << "Wrong password" << endl;
	cout << "There are only " << line - 1 << " lines" << endl;*/
	
	file.close();
	
	
	return 0;
}
