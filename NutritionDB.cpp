#include <fstream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
header();
 
class nutplan
{
	char name[20], descrp[200],avoid[200],eat[200];
	float min_cal,max_cal;
 
	public:
	float get_min() {return min_cal;}
	float get_max() {return max_cal;}
	nutplan(char n[20], char des[], char av[], char et[], float min, float max)
		{strcpy(name,n);
		strcpy(descrp,des);
		strcpy(avoid,av);
		strcpy(eat,et);
		min_cal=min;
		max_cal=max;
		}
	void display();
};
 
//Function to write all the nutritional plans to a data file
void write_diet()
{
char n[20];
char des[200];
char av[200];
char et[200];
float min;
float max;
strcpy(n,"Keto Diet");
strcpy(des,"This diet is meant for weight loss.\nIt consists of low carbohydrates and high fat contents.\nIt helps you lose fat and lowers blood sugar and insulin levels.");
strcpy(av,"*Sugar*Starch*Legumes*Root Vegetables*Condiments and Sauces*Alcohol");
strcpy(et,"*MEat*Fish*Eggs*Butter*Cheese*Nuts*Healthy oils*Avocado*Water based vegetables");
min=1750;
max=8000;
nutplan a(n,des,av,et,min,max);
 
strcpy(n,"Paleo Diet");
strcpy(des,"This diet is meant for weight loss.\nIt consists of food similar to those eaten in the Paleolithic era.It gives a low chance of obesity, diabetes and heart diseases.");
strcpy(av,"*Sugar*Processed foods*Vegetable oils*Dairy products*Soft drinks*Trans fats");
strcpy(et,"*Meat*Seafood*Eggs*Nuts*Healthy fats*Vegetables*Salt and spices");
min=1600;
max=1749;
nutplan b(n,des,av,et,min,max);
 
strcpy(n,"Zone Diet");
strcpy(des,"This diet is meant for maintaining weight.\nIt consists of specified food items that reduce inflammation.\nThis diet reduces the risk of chronic diseases.");
strcpy(av,"*High Sugar fruits*Processed food*High sugar and starchy vegetables*Soft drinks");
strcpy(et,"*Lean beef*Fish*Soy*Egg Whites*Cheese*Fruits*Vegetables*Oats*Avocados*Nuts");
min=1400;
max=1599;
nutplan c(n,des,av,et,min,max);
 
 
strcpy(n,"Dash Diet");
strcpy(des,"This diet is meant for maintaining weight.\nIt reduces blood pressure and risk of cancer, diabetes, kidney and heart disease.");
strcpy(av,"*High Sugar*Processed foods");
strcpy(et,"*Nothing specific*Ensure a balanced diet");
min=1300;
max=1399;
nutplan d(n,des,av,et,min,max);
 
 
strcpy(n,"Weight Gain Diet");
strcpy(des,"This diet is meant for gaining weight.\nNon-cardio exercises are necessary to maintain weight.");
strcpy(av,"*High Sugar*Processed foods");
strcpy(et,"*Dairy*Rice*Nuts*Red meat*Potato and other starches*Protein supplements*Eggs*Full fat yoghurt");
min=0;
max=1299;
nutplan e(n,des,av,et,min,max);
 
fstream fw;
fw.open("NUTPLAN.dat",ios::app | ios::binary);
fw.write((char*)&a,sizeof(a));
fw.write((char*)&b,sizeof(b));
fw.write((char*)&c,sizeof(c));
fw.write((char*)&d,sizeof(d));
fw.write((char*)&e,sizeof(e));
 
fw.close();
}
 
void nutplan::display()
	{
		clrscr();
		gotoxy(30,3);
		textcolor(3);
		cprintf("Nutritional Plan");
		gotoxy(1,7);
		cout<<"\nMeal Plan : "<<name<<'\n'<<'\n'<<descrp;
		gotoxy(1,15);
		cout<<"Avoid : ";
		gotoxy(40,15);
		cout<<"Eat : ";
		for(int i=0; avoid[i]!='\0'; i++)
		{
			if(avoid[i]=='*')
				cout<<'\n';
			else
				cout<<avoid[i];
		}
		int n=0;
		for(int j=0; eat[j]!='\0'; j++)
		{
			if(eat[j]=='*')
			{
				n++;
				gotoxy(40,15+n);
			}
			else
				cout<<eat[j];
		}
	 }
 
