//#include"pch.h"
#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<stdlib.h>
#include<iomanip.h>
#include<graphics.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
char pName[30];
int motionIntro=1;
void home();
void game2();
void loop(char l[],int d)
{	for(int i=0;l[i]!=0;i++)
	{
		cout<<l[i];delay(d);
	}
}
void loop1(char l[],int d,int x,int y)
{
	for(int i=0;l[i]!=0;i++)
	{
		++x;
		if(x==80)
		{
			cout<<"-";gotoxy(51,++y);
			cout<<l[i];delay(d);
		}
		else
		{
			cout<<l[i];delay(d);
		}
	}
}
void head()
{       gotoxy(36,2);
	cout<<" HANGMAN\n-----------------------------------";
	cout<<"---------------------------------------------";
	gotoxy(30,3);
	cout<<"A Brain Storming GAME\n";
}
void load()
{
	clrscr();head();
	for(int i=0;i<=100;i++)
	{
		clrscr();head();gotoxy(1,19);
		cout<<"--------------------------------------------------------------------------------";
		gotoxy(36,13);
		cout<<"Loading"<<i<<"%";
		delay(20);
	}
}
void instruction()
{
	textbackground(BLACK);textcolor(BROWN);clrscr();char a;
	gotoxy(1,19);
	cout<<"--------------------------------------------------------------------------------";
	head();
	char ins[]="\n1.Select a Category from which WORDS be Puzzled."
	"\n2.There are 10 ROUNDS and there is no Time Limit."
	"\n3.There are total 5 Helping Hints for 10 ROUNDS and 1 Free Hint for each\n  Round which will not decrease no. of hints remaining."
	"\n4.Enter an appropriate alphabet to fill the spaces to make a word as per the\n  Category."
	"\n5.Any Numeric or, Symbolic character are not present in the word."
	"\n6.Dash(-) present in the word represent spaces you have to FILL."
	"\n7.Blank spaces, if any, represent SPACE between the words.";
	loop(ins,10);
	gotoxy(1,17);cout<<"1.Home.\n2.EXIT.";
	gotoxy(1,20);cout<<"Your choice:";
	me:
	cin>>a;
	switch(a)
	{	case '1':home();break;
		case '2':cout<<"CLOSING THE GAME.\n";delay(1000);
			 cout<<"THANK YOU.";delay(1500);exit(0);
		default:cout<<"Can't get your choice.Enter Again:";
			goto me;
	}
}
void user(char a[])
{
	textbackground(WHITE);textcolor(BLACK);
	clrscr();head();gotoxy(1,19);
	cout<<"--------------------------------------------------------------------------------";
	gotoxy(1,18);cout<<"0. EXIT";
	gotoxy(1,5);cout<<"Enter your NAME:";
	me:
	gets(a);
	for(int i=0;a[i]!=0;i++)
	{	if(!((a[i]>='a'||a[i]>='A'||a[i]==' '||a[0]=='0')&&(a[i]<='z'||a[i]<='Z')))
		{
			cout<<"Numeric/Symbolic Character is not allowed.\nEnter Again:";
			goto me;
		}
	}
	switch(a[0])
	{
		case '0':gotoxy(1,20);cout<<"CLOSING THE GAME.\n";
			 delay(1000);cout<<"THANK YOU.";
			 delay(1500);exit(0);
	}
}
void home()
{
	textbackground(BLACK);textcolor(YELLOW);
	char z[]="A Brain Storming GAME",a;
	char b='H',c='A',d='N',e='G',f='M',g='A',h='N';
	if(motionIntro==1)
	{
		motionIntro=0;
		for(int i=1;i<=36;i++)
		{
			clrscr();
			gotoxy(i,5);
			cout<<b;
			delay(20);
		}
		for(i=1;i<=5;i++)
		{
			clrscr();
			gotoxy(36,5);cout<<b;
			gotoxy(37,i);cout<<c;
			delay(50);
		}
		for(i=24;i>=5;i--)
		{
			clrscr();
			gotoxy(36,5);cout<<b<<c;
			gotoxy(38,i);cout<<d;
			delay(50);
		}
		for(i=1;i<=5;i++)
		{
			clrscr();
			gotoxy(36,5);cout<<b<<c<<d;
			gotoxy(39,i);cout<<e;
			delay(50);
		}
		for(i=80;i>=40;i--)
		{
			clrscr();
			gotoxy(36,5);cout<<b<<c<<d<<e;
			gotoxy(i,5);cout<<f;
			delay(20);
		}
		for(i=24;i>=5;i--)
		{
			clrscr();
			gotoxy(36,5);cout<<b<<c<<d<<e<<f;
			gotoxy(41,i);cout<<g;
			delay(50);
		}
		for(i=80;i>=42;i--)
		{
			clrscr();
			gotoxy(36,5);cout<<b<<c<<d<<e<<f<<g;
			gotoxy(i,5);cout<<h;
			delay(20);
		}
		gotoxy(29,6);loop(z,70);
	}
	staticIntro:
	clrscr();
	textbackground(BLACK);textcolor(YELLOW);
	gotoxy(36,5);cout<<b<<c<<d<<e<<f<<g<<h;
	gotoxy(29,6);cout<<z;
	gotoxy(1,20);cout<<"--------------------------------------------------------------------------------";
	gotoxy(68,19);cout<<"by - GangaSon";delay(300);
	gotoxy(1,16);cout<<"\n1. Start Game\n2. Instructions\n3. EXIT";
	gotoxy(1,21);cout<<"Your choice:";
	me:
	cin>>a;
	switch(a)
	{       case '3':cout<<"CLOSING THE GAME.\n";delay(1000);
			 cout<<"THANK YOU.";delay(1500);exit(0);
		case '1':user(pName);game2();break;
		case '2':instruction();goto staticIntro;
		default:cout<<"Can't get your choice. Enter Again:";goto me;
	}
}
void hint(float t,char hin[50],char a,float &w,int &xz)
{
	char s[]="                             ";
	gotoxy(51,13);
	if(t==1)
	{
		cout<<"FREE HINT:-";gotoxy(51,14);
		loop1(hin,50,51,14);gotoxy(1,17);
		cout<<"              ";
		gotoxy(1,17);cout<<"1. HINTS";gotoxy(1,20);
		cout<<"            ";gotoxy(1,20);
		cout<<"Enter:";
	}
	else
	if(t==2)
	{
		if(w==0)
		{
			gotoxy(51,14);cout<<"You have zero Hint left.";
			gotoxy(1,20);cout<<"        ";
			gotoxy(1,20);cout<<"Enter:";
		}
		else
		{
			++xz;w--;
			gotoxy(51,13);cout<<"              ";
			gotoxy(51,13);cout<<"HINTS:-";
			gotoxy(51,14);cout<<s;
			gotoxy(51,15);cout<<s;
			gotoxy(51,16);cout<<s;
			gotoxy(51,14);cout<<"Next Alphabet is "<<a;
			gotoxy(34,17);cout<<w<<" Hints left.";
			gotoxy(1,20);cout<<"            ";
			gotoxy(1,20);cout<<"Enter:";
		}
	}
	else
	if(t==3)
	{
		if(w==0)
		{
			gotoxy(51,14);cout<<"You have zero Hint left.";
			gotoxy(1,20);cout<<"        ";
			gotoxy(1,20);cout<<"Enter:";
		}
		else
		{
			++xz;w--;
			gotoxy(51,13);cout<<"              ";
			gotoxy(51,13);cout<<"HINTS:-";
			gotoxy(51,14);cout<<s;
			gotoxy(51,15);cout<<s;
			gotoxy(51,16);cout<<s;
			gotoxy(51,14);cout<<"Next Alphabet is "<<a;
			gotoxy(34,17);cout<<w<<" Hints left.";
			gotoxy(1,20);cout<<"            ";
			gotoxy(1,20);cout<<"Enter:";
		}
	}
	else
	if(t==4)
	{
		if(w==0)
		{
			gotoxy(51,14);cout<<"You have zero Hint left.";
			gotoxy(1,20);cout<<"        ";
			gotoxy(1,20);cout<<"Enter:";
		}
		else
		{
			++xz;w--;
			gotoxy(51,13);cout<<"              ";
			gotoxy(51,13);cout<<"HINTS:-";
			gotoxy(51,14);cout<<s;
			gotoxy(51,15);cout<<s;
			gotoxy(51,16);cout<<s;
			gotoxy(51,14);cout<<"Next Alphabet is "<<a;
			gotoxy(34,17);cout<<w<<" Hints left.";
			gotoxy(1,20);cout<<"            ";
			gotoxy(1,20);cout<<"Enter:";
		}
	}
	else
	if(t==5)
	{
		if(w==0)
		{
			gotoxy(51,14);cout<<"You have zero Hint left.";
			gotoxy(1,20);cout<<"        ";
			gotoxy(1,20);cout<<"Enter:";
		}
		else
		{
			++xz;w--;
			gotoxy(51,13);cout<<"              ";
			gotoxy(51,13);cout<<"HINTS:-";
			gotoxy(51,14);cout<<s;
			gotoxy(51,15);cout<<s;
			gotoxy(51,16);cout<<s;
			gotoxy(51,14);cout<<"Next Alphabet is "<<a;
			gotoxy(34,17);cout<<w<<" Hints left.";
			gotoxy(1,20);cout<<"            ";
			gotoxy(1,20);cout<<"Enter:";
		}
	}
	else
	if(t==6)
	{
		if(w==0)
		{
			gotoxy(51,14);cout<<"You have zero Hint left.";
			gotoxy(1,20);cout<<"        ";
			gotoxy(1,20);cout<<"Enter:";
		}
		else
		{
			++xz;w--;
			gotoxy(51,13);cout<<"              ";
			gotoxy(51,13);cout<<"HINTS:-";
			gotoxy(51,14);cout<<s;
			gotoxy(51,15);cout<<s;
			gotoxy(51,16);cout<<s;
			gotoxy(51,14);cout<<"Next Alphabet is "<<a;
			gotoxy(34,17);cout<<w<<" Hints left.";
			gotoxy(1,20);cout<<"            ";
			gotoxy(1,20);cout<<"Enter:";
		}
	}
}
void score(float &co,float &in,char ca[20],char a[30])
{
	for(int i=4;i<=18;i++)
	{
		gotoxy(50,i);cout<<"|";
	}
	gotoxy(51,5);cout<<"NAME: "<<strupr(a);
	gotoxy(51,7);cout<<"CORRECT: "<<co;
	gotoxy(51,9);cout<<"INCORRECT: "<<in;
	gotoxy(51,11);cout<<"CATEGORY: "<<ca;
}
void game1(char a[20],int r,float &co,float &in,char ca[20],char x[30],char hin[50],int &t,float &w)
{
	textbackground(BLACK);textcolor(YELLOW);
	z:
	char ch[20]=";;;;;;;;;;;;;;;;;;;;",b[20];
	strcpy(b,a);
	int l;
	char t1[]="ROUND ";
	clrscr();head();
	if((strlen(a)%2)==0)
	l=(strlen(a)/2);
	else
	l=((strlen(a)/2)+1);
	gotoxy(1,19);
	cout<<"--------------------------------------------------------------------------------";
	score(co,in,ca,x);
	gotoxy(22,6);
	loop(t1,100);cout<<r<<endl;
	for(int i=1;i<=l;i++)
	{	me:
		time_t t;
		unsigned int sp;
		sp=(unsigned)time(&t);
		srand(sp);
		int space=(rand()%(strlen(a)-1))+0;
		if(a[space]==' ')
		goto me;
		else
		if(a[space]!='-')
		{
			a[space]='-';ch[space]='.';
		}
		else
		goto me;
	}
	clrscr();head();
	score(co,in,ca,x);
	gotoxy(34,17);
	gotoxy(1,19);
	cout<<"--------------------------------------------------------------------------------";
	gotoxy(22,6);cout<<"ROUND "<<r<<endl<<endl;
	loop(a,100);gotoxy(1,17);
	cout<<"1. FREE HINT\n0. EXIT";
	char m;
	int xz;
	for(i=0;i<=(strlen(a)-1);i++)
	{
		gotoxy(22,6);cout<<"ROUND "<<r<<endl<<endl;
		cout<<a;
		gotoxy(34,17);cout<<w<<" Hints left.";
		gotoxy(1,20);cout<<"Enter:";
		{
		xz=0;
		p:
		if(ch[i]=='.')
		{
			m=b[i];
			cin>>a[i];
		}
		{
		if(a[i]=='0')
		{
			cout<<"CLOSING THE GAME.\n";delay(1000);
			cout<<"THANK YOU.";delay(1500);exit(0);
		}
		else
		if(a[i]=='1')
		{
			a[i]='-';
			++t;
			if(w==0)
			{
				hint(t,hin,m,w,xz);
				{
				if(xz>=2)
				{
					++w;gotoxy(34,17);
					cout<<w<<" Hints left.";
					gotoxy(51,15);
					cout<<"Already Given.";
					gotoxy(1,20);
					cout<<"            ";
					gotoxy(1,20);
					cout<<"Enter:";
				}
				}
			goto p;
			}
			else
			hint(t,hin,m,w,xz);
			{
			if(xz>=2)
			{
				++w;gotoxy(34,17);
				cout<<w<<" Hints left.";
				gotoxy(51,15);
				cout<<"Already Given.";
				gotoxy(1,20);
				cout<<"            ";
				gotoxy(1,20);cout<<"Enter:";
			}
			}
			goto p;
		}
		}
		}
	cout<<strupr(a);
	clrscr();score(co,in,ca,x);head();
	if(t>=1)
	{
		gotoxy(1,17);cout<<"1. HINTS\n0. EXIT";
	}
	else
	{
		gotoxy(1,17);cout<<"1. FREE HINT\n0. EXIT";
	}
	gotoxy(1,19);cout<<"--------------------------------------------------------------------------------";
	}
	gotoxy(22,6);cout<<"ROUND "<<r<<endl<<endl<<a<<endl<<endl;
	cout<<"You have made:"<<strupr(a);
	char incorr[]="Oops!!!\nYou have WRONGLY fill the word.\nCorrect Word is ";
	char corr[]="FANTASTIC!!!\nCORRECT.",pro[]="loading",dot[]=".....";
	if(!(strcmp(a,b)==0))
	{
		gotoxy(1,11);loop(incorr,50);loop(b,50);in++;
		score(co,in,ca,x);
	}
	else
	{
		co++;gotoxy(1,11);loop(corr,100);
		score(co,in,ca,x);
	}
	gotoxy(1,17);cout<<"             ";gotoxy(1,18);cout<<pro;loop(dot,750);
}
void game(char ca[20],char a[20],char b[20],char c[20],char l[20],char e[20],char f[20],char g[20],char h[20],char k[20],char j[20],char x[30],char h1[50],char h2[50],char h3[50],char h4[50],char h5[50],char h6[50],char h7[50],char h8[50],char h9[50],char h10[50])
{
	clrscr();
	textbackground(BLACK);textcolor(YELLOW);
	head();
	float w=5,co=0,in=0;
	for(int i=1;i<=10;i++)
	{
		if(i==1)
		{
			load();gotoxy(1,19);
			cout<<"--------------------------------------------------------------------------------";
			game1(a,i,co,in,ca,x,h1,0,w);
		}
		else
		if(i==2)
		game1(b,i,co,in,ca,x,h2,0,w);
		else
		if(i==3)
		game1(c,i,co,in,ca,x,h3,0,w);
		else
		if(i==4)
		game1(l,i,co,in,ca,x,h4,0,w);
		else
		if(i==5)
		game1(e,i,co,in,ca,x,h5,0,w);
		else
		if(i==6)
		game1(f,i,co,in,ca,x,h6,0,w);
		else
		if(i==7)
		game1(g,i,co,in,ca,x,h7,0,w);
		else
		if(i==8)
		game1(h,i,co,in,ca,x,h8,0,w);
		else
		if(i==9)
		game1(k,i,co,in,ca,x,h9,0,w);
		else
		if(i==10)
		game1(j,i,co,in,ca,x,h10,0,w);
	}
	char q;
	clrscr();
	head();
	gotoxy(1,19);cout<<"--------------------------------------------------------------------------------";
	char bn[]="You have made ",bm[]=" Correct word and ";
	char bb[]=" Incorrect word and used ",bv[]=" Hint.";
	char bh[]="Your Accuracy is ";
	gotoxy(1,7);loop(bn,50);cout<<co;loop(bm,50);cout<<in;loop(bb,50);
	cout<<(5-w);loop(bv,50);gotoxy(1,10);loop(bh,50);
	cout<<(co*10)<<" %";delay(1000);
	gotoxy(1,17);cout<<"1. Restart.\n2. EXIT.";
	qw:
	gotoxy(1,20);cout<<"Your Choice:";
	cin>>q;
	switch(q)
	{
		case '1':break;
		case '2':cout<<"CLOSING THE GAME.\n";delay(1000);
			 cout<<"THANK YOU.";delay(1500);exit(0);
		default:cout<<"Can't get your choice.";
			goto qw;
	}
}
void game2()
{
	char z,ca[20];
	textbackground(WHITE);textcolor(RED);
	char x7[]="9. Home\n0. EXIT.";//x6[]="5. Name of the CONTINENTS.";
	char x5[]="4. Name of the CAPITAL of States of INDIA.";
	char x4[]="3. Name of the CITY.",x3[]="2. Name of the STATE.";
	char x2[]="1. Name of the COUNTRY.",x1[]="Select a Category:-";
	char s1[]="CHHATTISGARH",s2[]="TELANGANA",s3[]="MIZORAM";
	char s4[]="WEST BENGAL",s5[]="SIKKIM",s6[]="UTTARAKHAND";
	char s7[]="MAHARASHTRA",s8[]="ARUNACHAL PRADESH",s9[]="KARNATAKA";
	char s10[]="NAGALAND";
	char c1[]="PONDICHERRY",c2[]="LUDHIANA",c3[]="AHEMDABAD";
	char c4[]="JAIPUR",c5[]="BENGALURU",c6[]="MUMBAI";
	char c7[]="HYDERABAD",c8[]="VISHAKAPATNAM",c9[]="MATHURA";
	char c10[]="GUWAHATI";
	char co1[]="MADAGASCAR",co2[]="AFGHANISTAN",co3[]="PHILIPPINES";
	char co4[]="GERMANY",co5[]="FRANCE",co6[]="ARGENTINA";
	char co7[]="PORTUGAL",co8[]="TAJIKISTAN";
	char co9[]="INDONESIA",co10[]="VATICAN CITY";
	char cap1[]="THIRUVANANTHAPURAM",cap2[]="PANAJI",cap3[]="BENGALURU";
	char cap4[]="LUCKNOW",cap5[]="ITANAGAR",cap6[]="AIZAWI";
	char cap7[]="SHILLONG",cap8[]="GANDHINAGAR";
	char cap9[]="GANGTOK",cap10[]="PATNA";
	//char con1[]="ANDAMAN AND NICOBAR",con2[]="CHANDIGARH";
	//char con3[]="DADRA AND NAGARHAVELI",con4[]="DAMAN AND DIU";
	//char con5[]="LAKSHADWEEP",con6[]="PUDUCHERRY",con7[]="NEW DELHI";
	//char con8[10],con9[10],con10[10];
	char hs1[]="Its Capital is Raipur & located near Odisha.";
	char hs2[]="Divided from Andhra Pradesh.",hs3[]="Down the Manipur.";
	char hs4[]="Its Capital is Kolkata.";
	char hs5[]="It forms thumb like shape in map of India.";
	char hs6[]="Bounded by Uttar Pradesh, Himachal Pradesh & Nepal.";
	char hs7[]="Its Capital is Mumbai.",hs8[]="Rightmost State of India.";
	char hs9[]="State of Silicon Valley.",hs10[]="Its Capital is Kohima.";
	char hc1[]="Capital of Puducherry.",hc2[]="City located in Punjab.";
	char hc3[]="Largest City of Gujarat.",hc4[]="Pink city of India.";
	char hc5[]="Silicon Valley of India.",hc6[]="Capital of Maharashtra.";
	char hc7[]="Capital of Andhra Pradesh.";
	char hc8[]="Largest city of Andhra Pradesh.";
	char hc9[]="Birth place of Lord Krishna & famous city of India.";
	char hc10[]="Famous city of Assam";
	char hco1[]="Country in Africa & a popular Hollywood movie named after it.";
	char hco2[]="Neighbor of Pakistan.";
	char hco3[]="Small Island near Indonesia & Malaysia.";
	char hco4[]="Winner of FIFA World Cup 2015.";
	char hco5[]="Its Capital is Paris.";
	char hco6[]="Football star Lionel Messi belong to this country.";
	char hco7[]="Football star Cristiano Ronaldo belong to this country.";
	char hco8[]="Neighbor of Afghanistan.",hco9[]="Neighbor of Malaysia.";
	char hco10[]="Smallest country in the World.";
	char hcap1[]="Capital of Kerela.",hcap2[]="Capital of Goa.";
	char hcap3[]="Capital of Karnataka.",hcap4[]="Capital of Uttar Pradesh.";
	char hcap5[]="Capital of Arunachal Pradesh.";
	char hcap6[]="Capital of Mizoram.",hcap7[]="Capital of Meghalaya.";
	char hcap8[]="Capital of Gujarat.",hcap9[]="Capital of Sikkim.";
	char hcap10[]="Famous for Gandhi Maidan.";
	ne:
	clrscr();head();
	gotoxy(1,19);cout<<"--------------------------------------------------------------------------------";
	gotoxy(1,5);
	cout<<endl;loop(x1,50);//delay(1000);
	cout<<endl;loop(x2,50);//delay(1000);
	cout<<endl;loop(x3,50);//delay(1000);
	cout<<endl;loop(x4,50);//delay(1000);
	cout<<endl;loop(x5,50);//delay(500);
	//delay(1000);cout<<endl;loop(x6,50);
	gotoxy(1,17);delay(500);
	loop(x7,50);
	gotoxy(1,20);cout<<"\nYour choice:";
	me:
	cin>>z;
	switch(z)
	{
		case '1':strcpy(ca,"COUNTRY");
			 game(ca,co1,co2,co3,co4,co5,co6,co7,co8,co9,co10,pName,hco1,hco2,hco3,hco4,hco5,hco6,hco7,hco8,hco9,hco10);
			 goto ne;
		case '2':strcpy(ca,"STATE");
			 game(ca,s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,pName,hs1,hs2,hs3,hs4,hs5,hs6,hs7,hs8,hs9,hs10);
			 goto ne;
		case '3':strcpy(ca,"CITY");
			 game(ca,c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,pName,hc1,hc2,hc3,hc4,hc5,hc6,hc7,hc8,hc9,hc10);
			 goto ne;
		case '4':strcpy(ca,"CAPITAL of STATES");
			 game(ca,cap1,cap2,cap3,cap4,cap5,cap6,cap7,cap8,cap9,cap10,pName,hcap1,hcap2,hcap3,hcap4,hcap5,hcap6,hcap7,hcap8,hcap9,hcap10);
			 goto ne;
		//case '5':strcpy(ca,"CONTINENT");game(ca,con1,con2,con3,con4,con5,con6,con7,con8,con9,con10,x);break;
		case '0':cout<<"CLOSING THE GAME.\n";delay(1000);
			 cout<<"THANK YOU.";delay(1500);exit(0);
		case '9':home();
			 goto ne;
		default:cout<<"Wrong Input\nPress Again:";goto me;
	}
}
void main()
{
	clrscr();
	head();
	home();
	game2();
	getch();
}