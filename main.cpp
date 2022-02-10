/*Program to record fitness data of individuals for a week and calculate calories burned per day and suggest a diet based on data
Done By: Archita Hothur and Gauri Pradeep
*/
 
#include <stdio.h>
#include <ctype.h>
#include <fstream.h>
#include <conio.h>
#include <process.h>
#include <string.h>
#include <graphics.h>
#include <dos.h>
#include "user.cpp";
#include "nutplan.cpp";
 
user X; //Global user that stores current user
 
//Changing colour of heading
void head(char *str)
	{gotoxy(37,2);
	 textcolor(3);
	 cprintf(str);
	}
 
//Function to display sub-menu after user logs in
void sub_menu()
	{clrscr();
	 gotoxy(1,20);
	 char ch;
	 while(1)
		{clrscr();
		 head("SPARTA");
		 gotoxy(30,8);
		 cout<<"1. Enter fitness details";
		 gotoxy(30,10);
		 cout<<"2. View nutritional plan";
		 gotoxy(35,12);
		 cout<<"3. Log out\n\n\n\n\t\t\t\tEnter a choice: ";
		 cin>>ch;
		 if(ch=='1')
			{//Enter fitness for given day
			 X.get_fit();
			 changeday(&X);
			}
		 else if(ch=='2')
			{//View nutritional plan if day<6
			 if(X.getd()<=6)
				{cout<<"Nutritional Plan can be viewed only
   after data for 1 week is entered";
				cout<<"\nEnter data for "<<7-X.getd()<<" 
   more days to view diet plan\n";
				getch();
				}
			 //ELSE display diet plan as per cal & active min
			 else
				{long tot=X.add_cal();
				nutplan plan(" "," "," "," ",0,0);
				tot/=7;
				cout<<tot;
				getch();
				ifstream fnut("NUTPLAN.dat", ios::in| 
  ios::binary);
				while(fnut.read((char*)&plan,sizeof(plan)))
			//To compare with nutrition plan calorie ranges
					{if(tot>=plan.get_min()&& 
  tot<=plan.get_max())
						{clrscr();
						 plan.display();
						 break;
						}
					}
				fnut.close();
				getch();
				}
			}
 
		 else if(ch=='3')
			{//Writing current day's data to text file
			 changeday(&X);
			 break;
			}
		 else
			{cout<<"Invalid Option";
			 getch();
			}
		}
	}
 
 
void main()
{fstream f;
write_food();
write_diet();
 
clrscr();
char ch;
 
 while(1)
	{clrscr();
	 ch=home_menu();
	 if(ch=='1')
		{//LOG IN
		int fl=1;
		char n[30], p[20];
		clrscr();
		gotoxy(37,3);
		head("SPARTA");
		gotoxy(22,5);
		cout<<"Enter username/email: ";
		cin>>n;
		gotoxy(30,7);
		cout<<"Enter password: ";
		cin>>p;
		f.open("USER_DATA.dat",ios::in|ios::binary);
		//Comparing input data to users in database
		while(!f.eof())
			{f.read((char*)&X,sizeof(X));
			 if((strcmp(X.getn(),n)==0) && (strcmp(X.getp(),p)==0) )
				{fl=0;
				break;}
			}
		f.close();
		if(fl)
			{cout<<"Invalid username or password!";
			 getch();
			}
		else
			sub_menu();
 
 
		}
	 else if(ch=='2')
		{//SIGN UP
		 //Create new user and write to file
		 X.get_data();
		 f.open("USER_DATA.dat",ios::app|ios::binary);
		 f.write((char*)&X,sizeof(X));
		 f.close();
		}
	 else  if(ch=='3')
		break;
 
	 else
		{gotoxy(14,18);
		 cout<<"Invalid Option entered. Please press enter to
  continue...";
		}
	 getch();
	}
}
 
 
