//yewontaung798@gmail.com

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>

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
	int pass_w;
	
	void addData()
	{
		ofstream af; //adding data to file
		af.open("udata.txt", ofstream::app);
		
		if(af.fail())
		{
			cout << "Error opening file" << endl;
			exit(1);
		}
		
		af << name << " : " << id << " : " << amount << " : " << age << " : " << location << endl;
		
		af.close();
		
		ofstream ap; // add password
			
		ap.open("pw.txt", ofstream::app);
			
		if(ap.fail())
		{
			cout << "Error occurs!" << endl;
			exit(1);
		}
			
		ap << "\n" << pass_w;
		
		ap.close();
			
		cout << "Data added successfully." << endl;
	}
	
	int findData(int read_line)
	{
		ifstream rf; //reading data from file
			
		rf.open("udata.txt");
			
		if(rf.fail())
		{
			cout << "Error occurs!" << endl;
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
					cout << "Name  " << " || ";
					cout << " ID " << " || ";
					cout << " Amount " << " || ";
					cout << " Age " << " || ";
					cout << " Location " << endl;
					cout << user_data << endl;
					break;
				}
			}
			current_line++;
		}
		
		rf.close();
		
		return 0;
	}
	
	void updateData(int readLine)
	{
		ifstream readfile;
		
		readfile.open("udata.txt");
		
		vector<string> temp_lines;
		string temp_line;
		
		if(readfile.fail())
		{
			cout << "Error opening file!" << endl;
			exit(1);
		}
		
		while(getline(readfile, temp_line))
		{
			temp_lines.push_back(temp_line);
		}
		
		readfile.close();
		
		ofstream writefile;
		
		writefile.open("udata.txt");
		
		if(writefile.fail())
		{
			cout << "Error opening file!" << endl;
			exit(1);
		}
		
		readLine--;
		
		for(int index = 0; index < temp_lines.size(); index++)
		{
			if(index != readLine)
				writefile << temp_lines[index] << endl;
			else
				writefile << name << " : " << id << " : " << amount << " : " << age << " : " << location << endl;
		}
		
		
		writefile.close();
		cout << "Data updated successfully" << endl;
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
	cout << " >>> ";
	
	cin >> choice;
	
	while(choice != 4)
	{
		if(choice == 1)
		{
			cout << "************" << endl;
			cout << "Enter your data" << endl;
			
			cout << "Name :: ";
			getline(cin >> ws, user.name);
			
			cout << "ID :: ";
			cin >> user.id;
			
			cout << "Amount :: ";
			cin >> user.amount;
			
			cout << "Age :: ";
			cin >> user.age;
			
			cout << "Location(town) :: ";
			getline(cin >> ws, user.location);
			
			cout << "Password (4 digits) :: ";
			cin >> user.pass_w;
			
			user.addData();
			
			cout << "____________________" << endl;
		}
			
		else if(choice == 2)
		{
			cout << "************" << endl;
			
			int readline = password();
			
			user.findData(readline);
			
			cout << "____________________" << endl;
		}

		
		if(choice == 3)
		{
			cout << "************" << endl;
			
			int read_line = password();
			cout << "This is your old data" << endl;
			user.findData(read_line);
			cout << "<<<<<<>>>>>>" << endl;
			
			cout << "Enter new data" << endl;
			
			cout << "Name :: ";
			getline(cin >> ws, user.name);
			
			cout << "ID :: ";
			cin >> user.id;
			
			cout << "Amount :: ";
			cin >> user.amount;
			
			cout << "Age :: ";
			cin >> user.age;
			
			cout << "Location(town) :: ";
			getline(cin >> ws, user.location);
			
			user.updateData(read_line);
			
			cout << "____________________" << endl;
		}
		
		cout << "Press 1 to insert data" << endl;
		cout << "Press 2 to find data" << endl;
		cout << "Press 3 to update data" << endl;
		cout << "Press 4 to exit" << endl;
		cout << " >>> ";
		
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
	
	cout << "Enter your password :: ";
	cin >> temp_pw;
	
	while(getline(file, counter_pw))
	{	
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
	
	file.close();
	
	return 0;
}
