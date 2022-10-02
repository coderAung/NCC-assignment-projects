//Gambling Program
//yewontaung798@gmail.com

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class UserData
{
public:
	int currentID = 0;
	string userName[100];
	string userPw[100];
	int point[100];
	int index = 0;
	
	int main_pg();
	int crt_acc();
	int log_in();
	int buy_point();
	int game_board(int curID);
	void game_play(int userCurrentId);
	int point_amount(int OP, int GamePoint);
	int playing();
	void withdraw(int curr_id);	
};

int UserData::main_pg()//main page
{
	string option;
	int mainReturn = 0;
	
	cout<<"Press 1 to create account"<<endl;
	cout<<"Press 2 to log in"<<endl;
	cout<<"Press 3 to exit"<<endl;
	cout<<" >>> ";
	cin>>option;
	
	if(option == "1")
	{
		crt_acc();
		mainReturn = 0;
	}
	else if(option == "2")
	{
		log_in();
		mainReturn = 0;
	}
	else if(option == "3")
	{
		cout<<"Bye Bye"<<endl;
		mainReturn = 1;
	}
	else
	{
		cout<<"Invalid option."<<endl;
	}
	return mainReturn;
}

int UserData::crt_acc()//create account
{
	int loop = 1;
	string name;
	string temp_pw;
	string password;
	
	cout<<"Enter your data"<<endl;
	
	cout<<"Name >> ";
	getline(cin>>ws,name);	
	
	cout<<"Create Password >> ";
	cin>>temp_pw;
	
	cout<<"Confirm password >> ";
	cin>>password;
	
	if(temp_pw == password)
	{
		userName[index] = name;
		userPw[index] = password;
		currentID = index;
		cout<<"Account created successfully"<<endl;
		cout<<"You need MINIMUM 10 points to create an account."<<endl;
		
		while (loop == 1)
		{
			int pointReturn = buy_point();
			if (pointReturn >= 10)
			{
				point[index] = pointReturn;
				cout<<"Top up success!"<<endl;
				loop = 0;
			}
			else if(pointReturn < 10)
			{
				cout<<"Invalid amount."<<endl;
				cout<<"Try again!"<<endl;
			}
		}
	}
	else
	{
		cout<<"Password is not indentical."<<endl;
		cout<<"Try again!"<<endl;
		return -1;
	}
	cout<<endl;
	game_board(currentID);
	index++;
	return 0;
}

int UserData::log_in()//logging in
{
	string logName;
	string logPw;
	
	cout<<"Name = ";
	getline(cin>>ws,logName);
	
	cout<<"Password = ";
	cin>>logPw;
	
	for(int i = 0; i<= index; i++)
	{
		if(userName[i] == logName && userPw[i] == logPw)
		{
			currentID = i;
			cout<<"Log in success."<<endl;
			cout<<endl;
			game_board(currentID);
		}
	}
	cout<<endl;
	return 0;
}

int UserData::buy_point()
{
	int p = 0;
	
	cout<<"<1point = 1$>"<<endl;
	cout<<"Enter Amount of Points = ";
	cin>>p;
	return p;
}

int UserData::game_board(int curID)
{
	int id = curID;
	int press = 0;
	cout<<"This is from game"<<endl;
	
	cout<<" - Press 1 to play game"<<endl;
	cout<<" - Press 2 to top up"<<endl;
	cout<<" - Press 3 to withdraw"<<endl;
	cout<<" - Press 4 to check balance"<<endl;
	cout<<" - Press 5 to exit"<<endl;
	cout<<" >>> ";
	cin>>press;
	
	if(press == 1)
	{
		game_play(id);
	}
	else if(press == 2)
	{
		int pointReturn = buy_point();
		if(pointReturn > 0)
		{
			point[id] = point[id] + pointReturn;
		}
		cout<<"Top up success!"<<endl;
		cout<<"Balance = "<<point[id];
		cout<<endl;
		game_board(id);
	}
	else if(press == 3)
	{
		withdraw(id);
		cout<<endl;
		game_board(id);
	}
	else if(press == 4)
	{
		cout<<endl;
		cout<<"Name = "<<userName[id]<<endl;
		cout<<"Points = "<<point[id]<<endl;
		cout<<endl;
		game_board(id);
	}
	return 0;
}

void UserData::game_play(int userCurrentId)
{
	int Id = userCurrentId;
	int op;
	int gamePoint;
	int PlayPoint = 0;
	int userMark = 0;
	int cMark = 0;
	
	if(point[Id] <= 10)
	{
		cout<<"Insufficient balance."<<endl;
		cout<<"Need MINIMUM 11 points to play game."<<endl;
		cout<<"Please Top up with option 2"<<endl;
		cout<<endl;
		game_board(Id);
	}
	else
	{
		cout<<"Amount of points to play = ";
		cin>>gamePoint;
		if(gamePoint > point[Id] - 10)
		{
			cout<<"Points not enough to play"<<endl;
			cout<<"Your points = "<<point[Id]<<endl;
			cout<<"MAXIMUM amount to play = "<<point[Id]-10<<endl;
			cout<<endl;
			game_play(Id);
		}
		else
		{
			cout<<"Choose an option."<<endl;
			cout<<" 1 (2x)\n"<<" 2 (3x)\n"<<" 3 (4x)"<<endl;
			cin>>op;//op = game option
			if(op > 0 && op < 4)
			{
			
			PlayPoint = point_amount(op, gamePoint);
			
			int loop = 0;
			while(loop < 3)
			{
				if(loop == 2 && userMark == 2) break;
				else if(loop == 2 && cMark == -2) break;
				
				cout<<"Round "<<loop+1<<endl;
				int playingReturn = playing();
				
				if(playingReturn == 1) userMark = userMark + 1;
				
				else if(playingReturn == -1) cMark = cMark + 1;
				
				else if(playingReturn == 0) loop = loop - 1;
				
				loop++;
			}
			}
		else
		{
			cout<<"Invalid option."<<endl;
		}
			
			if(userMark > cMark)
			{
				point[Id] = point[Id] + PlayPoint;
				cout<<"You won\n"<<"Points are added"<<endl;
				cout<<"Your points = "<<point[Id]<<endl;
			}
			else if(userMark < cMark)
			{
				point[Id] = point[Id] - gamePoint;
			}
			cout<<endl;
			game_board(Id);
		}
	}
}

int UserData::point_amount(int OP, int GamePoint)
{
	int playPoint = 0;
	switch(OP)
	{
		case 1:
			playPoint = GamePoint*2;
		break;
		case 2:
			playPoint = GamePoint*3;
		break;
		case 3:
			playPoint = GamePoint*4;
		break;
		default:
			cout<<"Invalid option."<<endl;
			cout<<"Try again."<<endl;
		break;
	}
	return playPoint;
}

int UserData::playing()
{
	srand(time(NULL));
	
	string rps[3] = {"r", "p", "s"};
	string RPS[3] = {"R", "P", "S"};
	string gin;
	string ai;
	int winORlose;
	
	int ran = rand() % 3;
	string c = rps[ran];
	
	if(ran == 0) ai = "ROCK";
	else if(ran == 1) ai = "PAPER";
	else if(ran == 2) ai = "SCISSOR";
	
	cout<<"Entet ROCK(r) or PAPER(p) or SCISSOR(s)"<<endl;
	cout<<" >>> ";
	cin>>gin;//gin = game input
	
	cout<<"Computer Chose "<<ai<<endl;
	
	if(((gin=="R"||gin=="r")&&c=="s")||((gin=="P"||gin=="p")&&c=="r")||((gin=="S"||gin=="s")&&c=="p"))
	{
		cout<<"You Win"<<endl;
		winORlose = 1;
	}
	else if(gin == rps[ran] || gin == RPS[ran])
	{
		cout<<"Draw"<<endl;
		winORlose = 0;
	}
	else
	{
		cout<<"You Lose."<<endl;
		winORlose = -1;
	}
	return winORlose;
}

void UserData::withdraw(int curr_id)
{
	int ID = curr_id;
	int withdrawPoint = 0;
	
	cout<<"Enter amount of points to withdraw"<<endl;
	cout<<" >>> ";
	cin>>withdrawPoint;
	
	if(point[ID] - 10 < withdrawPoint)
	{
		cout<<"Insufficient amount to withdraw."<<endl;
		cout<<"You have "<<point[ID]<<" points"<<endl;
		cout<<"MAXIMUM amount to withdraw = "<<point[ID]-10<<endl;
	}
	else
	{
		point[ID] = point[ID] - withdrawPoint;
		cout<<"Withdraw success."<<endl;
	}
}

int main()
{
	UserData game;
	int mainloop = 0;
	
	while(mainloop != 1)
	{
		mainloop = game.main_pg();
	}
	
	return 0;
}
