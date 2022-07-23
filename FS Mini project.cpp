#include<iostream>
#include<string.h>
#include<math.h>
#include<fstream>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip>

using namespace std;

fstream data;
char Baf[80],Buffer[80];
unsigned long int total = 0;
char charr[50];
class member
{
   public: int flag;
    char name[20],num[20];
unsigned long int duration;

};
class items
{
public:
char num[20],name[20];
unsigned long int dur;
}acc;
member rec[10];
int no,k;


int Hash(int m)
{  
int r,q;
r=m%10;
q=rand()/10;
q=m/10;
k=(q+r+7)%10;
return k;
}


void unpack()
{   int i=0;
    fstream in;
    in.open("ca.txt",ios::in);
    char buf[80];
    while(!in.eof())
    {
      in.getline(rec[i].name,50,'|');
      in.getline(rec[i].num,50,'|');
      in.getline(charr,50,'\n');
      rec[i].duration=atoi(charr);
      i++;
    }
    in.close();
}
void search()
{
 int m,i,f=0,ff=0;
 char num[15];
    cout<<endl;
    cout<<"Enter Workout Plan: ";
    cin>>num;
    m =atoi(num);
    k = Hash(m);
    unpack();
    for(i=0;i<10;i++)
    {
      if((strcmp(rec[k%10].num,num))==0 && ff==0)
      {
      ff=1;
      cout<<"\n Available workouts for today are: "<<k<<": "<<endl;
      cout<<"\n\n\tPLAN NUMBER : "<<rec[k%10].num<<"\t"<<"\n\n\tWORKOUT PLAN : "<<rec[k%10].name<<"\t"<<"\n\n\tDURATION(in mins) : "<<rec[k%10].duration<<"\n";
      f=1;
      }
      k=k+1;
    }
    if(f!=1)
    cout<<"\n Unfortunately, the workout isn't available for today.' :( \n";    getch();
    return;
 }
 void deletee()
 {
     int ch;
     system("cls");
cout<<"\n\n\t\t REMOVING TODAY'S SCHEDULE'............\n\n";
     cout<<" \n\n\n 1. Specific Workout Plans ";
     cout<<" \n\n\n 2. All Workout Plans ";
     cout<<" \n\n\n 3. Exit ";
     cout<<" \n\n\n\t ENTER YOUR CHOICE    : ";
     cin>>ch;
     switch(ch)
      {
       case 1:
        {
 
int m,i,f=0,cc;
char vv[20];
   char tt[20],num[20];
   unsigned long dur;
    cout<<endl;
    cout<<"Enter Plan Number : ";
    cin>>num;
    m=atoi(num);
    k=Hash(m);
    unpack();
    for(i=0;i<10;i++)
    {
      if((strcmp(rec[k%10].num,num))==0)
      {
      f=1;
      cout<<" \n\n\t\t WORKOUT REMOVED :) "    ;
      rec[k%10].flag=0;
      strcpy(rec[k%10].num,"zzzzzzzzzzzzzzzzzzz");
      total = total - rec[k%10].duration;
      break;
      }
     k=k+1;
    }
    fstream f1;
    f1.open("ca.txt",ios::out);
    for(i=0;i<10;i++)
    {
      if(rec[i].flag==0)
{
 f1<<"#|#"<<"\n";}
     
      else
{
 f1<<rec[i].num<<"|"<<rec[i].name<<"|"<<rec[i].duration<<"\n";}
    }
   f1.close();
    if(f!=1)
    cout<<"\n not found \n";   getch();
    return;

}
  case 2:
{

fstream f12;
f12.open("nidhi.txt",ios::out);
for(int i=0;i<10;i++)
{
if(rec[i].flag==0)
f12<<"#|#"<<"\n";
else
 {
 rec[i].flag=0;
 strcpy(rec[i].num,"zzzzzzzzzzzzzzzzzzz");
 f12<<"#|#"<<"\n";
 }
}
f12.close();
     total = 0;

     cout<<" \n\n\t\tREMOVED THE ENTIRE WORKOUT PLAN FOR TODAY.     :) "  ;
     getch();

   break;
}


 }
}
 void disp()
{
system("cls");
cout<<"\n\n\t\tDISPLAYING TODAY'S SCHEDULE'...............\n";
cout<<"\n\n\nWORKOUT PLAN \t PLAN NUMBER \t duration OF TIME\n";
cout<<"###########################################################\n";
 for(int i=0;i<10;i++)
    {
    if(rec[i].flag==1)
    cout<<endl<<rec[i].name<<"\t\t"<<rec[i].num<<"\t\t"<<rec[i].duration<<"\n";
}
getch();
}
void additems()
{
       system("cls");
       cout<<"\n\n\t\tINSERTION OF WORKOUT PLANS....................\n\n";
char Buffer[51],offset[10];
char itno[20],baa[50],num[20],name[20],charr[20];
unsigned long int a;
int flaggg=0;

char ch='y';
while(ch=='y')
{

data.open("kshitij.txt",ios::in);
cout<<"\n Enter Plan Number: ";
    cin>>acc.num;
    if(!data)
   

    flaggg=2;
    while(!data.eof() && flaggg==0)
{
 data.getline(num,50,'|');
 data.getline(name,50,'|');
      data.getline(charr,50,'\n');
      a=atoi(charr);
      if((strcmp(acc.num,num))==0)
      {
flaggg=1;
cout<<"\n\n\t\t Choose a differnt plan number";
getch();
 }
 if(data.eof())
break;
}
data.close();
if(flaggg==1)
break;


if(flaggg != 1)
{

cout<<"\n Enter  Workout: ";
cin>>acc.name;
cout<<"\n Enter Duration of the workout(in mins): ";
cin>>acc.dur;

data.open("kshitij.txt",ios::app);
data<<acc.num<<'|'<<acc.name<<'|'<<acc.dur<<'\n';

data.close();

 cout<<" \n\n\n\n\n NEW WORKOUT ADDED TO THE SCHEDULE......!! ";
cout<<"\n\n\n\t\t\tClick y to Add one more  :  "    ;
cin>>ch;
}
  }




}

 void viewitems()
 {
system("cls");
cout<<"\n\n\t\tDISPLAYING TODAY'S WORKOUT PLAN SCHEDULE'......................\n\n";
data.open("kshitij.txt",ios::in);
cout<<"\n PLAN NUMBER \t WORKOUT PLAN \t DURATION(in mins)\n";
cout<<"\n***********************************************************\n";


while(!data.eof())
{

data.getline(acc.num,50,'|');
data.getline(acc.name,50,'|');
data.getline(charr,50,'\n');
acc.dur=atoi(charr);


if(data.eof())
break;


for(int i=0;i<strlen(Baf);i++)
{
cout<<endl<<Baf[i]<<" ";
}
cout<<"\n "<<acc.num<<"   \t     "<<acc.name<<"     \t\t"<<acc.dur;
}
data.close();
getch();


 }
void searchitem()
{
char itno[20],baa[50],num[20],name[20],charr[20];
unsigned long int a;
int flaggg=0;
fstream ff;
ff.open("kshitij.txt",ios::in);
cout<<"\n\n\t Enter Plan Number : ";
cin>>itno;
while(!ff.eof())
{
 ff.getline(num,50,'|');
 ff.getline(name,50,'|');
      ff.getline(charr,50,'\n');
      a=atoi(charr);
      if((strcmp(itno,num))==0)
      {
flaggg=1;
cout<<"\n\n\tWorkout Plan : "<<name<<"\n\n\tDuration of Workout(in mins) : "<<a;
 }
 if(ff.eof())
break;
}
if(flaggg == 0)
cout<<"\n\n\t\tWORKOUT NOT FOUND :( ";
getch();
ff.close();

}




int main()
{
    int m,ch,chh;
    char num[20],name[20];

    unsigned int duration;
    while(1)
    {
    system("cls");
    cout<<"\n\n\t\t-----------NK GYM-----------------\n\n\n";
    cout<<"\n\n Press 1 for MEMBER - Choose your Workout routine for today";
    cout<<"\n\n Press 2 for TRAINER - Add all the workout which will be available today!";
    cout<<"\n\n Press 3 for Viewing lis of workout plans available at NK Gym";
    cout<<"\n\n Press 4 for EXIT";
    cout<<"\n\n\t Enter your Choice : ";
    cin>>ch;
    switch(ch)
    {
case 1:
cout<<"Enter your name\n";
cin>>name;
do{
system("cls");
cout<<"\n\n\t\tHello " <<name<< "\n\n\n";
cout<<"\n\n Press 1 for Adding new workout to your workout schedule";
cout<<"\n\n Press 2 for Viewing your current workout schedule";
cout<<"\n\n Press 3 for Removing workout from your workout schedule";
cout<<"\n\n Press 4 for Searching for a specific workout in your workout schedule";
cout<<"\n\n Press 5 to GO BACK";
cout<<"\n\n PRESS 6 TO SEE YOUR POSSIBLE RESULT "    ;
cout<<"\n\n\n\n\t Enter your Choice : ";
cin>>chh;
switch(chh)
{
case 1:
system("cls");
cout<<"\n\t\tADDING WORKOUT...........\n\n";
cout<<"\nEnter how many workout session you want to do today\n : ";
cin>>no;
   if(no<=10)
   {
 for(int l=0;l<no;l++)
 rec[l].flag=0;
for(int i=0;i<no;i++)
{
int ff=0;
cout<<"\n  Enter Plan No : ";
cin>>num;
char Baf[80];
data.open("kshitij.txt",ios::in);

while(!data.eof())
{
if(data.eof())
break;

data.getline(acc.num,50,'|');
data.getline(acc.name,50,'|');
data.getline(charr,50,'\n');
acc.dur=atoi(charr);

for(int i=0;i<strlen(Baf);i++)
{
cout<<Baf[i]<<" ";
}

if(strcmp(acc.num,num)==0)
{
ff=1;
strcpy(name,acc.name);
duration = acc.dur;
cout<<"\n\t WORKOUT NAME :"<<name<<"\n\t DURATION OF THE WORKOUT(in mins) :"<<duration<<"\n\n";
total = total + duration;

}
}
data.close();


if(ff==1)
{

m=atoi(num);
k=Hash(m);
cout<<"address: "<<k<<"\n";
if(rec[k].flag==0)
{
   strcpy(rec[k].name,name);
   strcpy(rec[k].num,num);
   rec[k].duration=duration;
rec[k].flag=1;
}
else
{
   for(int j=k+1;j%10<10;j++)
   {
if(rec[j%10].flag==0)
{
strcpy(rec[j%10].name,name);
strcpy(rec[j%10].num,num);
rec[j%10].duration=duration;
rec[j%10].flag=1;
break;
}
   }
}
 }
 else
  cout<<"\n\n\t\t\ WORKOUT ISNT AVAILABLE TODAY.!!!!!!";
}
   cout<<"\n\n\tTOTAL DURATION OF TODAY'S WORKOUT (in mins) : "<<total;
   fstream f1;
   f1.open("nidhi.txt",ios::out);
   for(int i=0;i<10;i++)
{
   if(rec[i].flag==0)
   f1<<"#|#"<<"\n";
   else
   f1<<rec[i].name<<"|"<<rec[i].num<<"|"<<rec[i].duration<<"\n";
}
f1.close();
}getch();
  break;
case 2:

disp();
break;
case 3:
deletee();
break;
case 4:
search();
break;

case 6:
int cal;
cal=500*(total/60);
system("cls");
cout<< "Your body can stand almost anything, its your mind that you have to continue. Remember pain is temporary, result is permanent.\n";
cout<< "-------------------------------DID YOU KNOW!----------------------------------\n";
cout<<"Each of our workout plans are curated in such way you loose approx *400-500* calories in one hour\n";
cout<<"\n\n\n\n*******************************************************\n\n\n\n";
cout<<"\nYOUR TOTAL HOURS IN GYM TODAY : "<<total;
cout<<" which means you will lose approx   " <<cal<< "   calories today.\n";
cout<<"Dont lose hope! Lose calories! See you there today.\n";

fstream f12;
f12.open("ca.txt",ios::out);
for(int i=0;i<10;i++)
{
if(rec[i].flag==0)
f12<<"#|#"<<"\n";
else
{
rec[i].flag=0;
 strcpy(rec[i].num,"zzzzzzzzzzzzzzzzzzz");
 f12<<"#|#"<<"\n";
  }
}
f12.close();
     total = 0;
cout<<"\n\n\n\n\t\t REMEMBER IT BEGINS WITH I :)";
     getch();

    break;




}
}while(chh!=5);
  break;

case 2:
	{
	
int flag=1;
   system("cls");
   cout<<"\nPlease enter your name:\n ";
char name[20];
cin>>name;
cout<<"\nEnter your password: \n";
char pass[10];
cin>>pass;
if(strcmp(pass,"momos")==0)
{
system("cls");
cout<<"\n\tWelcome "<<name<<endl;
getch();

}
else
{
cout<<"INVALID PASSWORD!!!! \n";
cout<<"enter 1 to exit, any other to continue";
flag=0;
}

if(flag==1)
{


do
{
cout<<"\n\n Press 1 for ADDING NEW WORKOUT PLANS";
cout<<"\n\n Press 2 to SEARCH FOR AN EXISTING WORKOUT";
cout<<"\n\n Press 3 to GO BACK";
cout<<"\n\n\t Enter your Choice : ";
cin>>chh;
 switch(chh)
{
case 1:
additems();
break;
case 2:
searchitem();
break;
case 3:
	break;
}


 }while(chh!=3);
}
}
 case 3:
 	{
	 
viewitems();
break;

}
case 4:
exit(0);
}
   }

}


