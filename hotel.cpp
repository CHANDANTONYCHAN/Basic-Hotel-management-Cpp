
#include<iostream.h>
#include<string.h>
#include<iomanip.h>
#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<math.h>
#include<time.h>

class customer
{
 public:
	int custm_id;
	int custm_age;
	int check_inyear;
	int check_inmonth;
	int check_indate;
	char roomtype[20];
	char custm_name[30];
	int room_charge;
	int compare(char[]);
	char custm_occupation[20];
	void getdata();
	void putdata();
	long total;
	int food;
	long room;
	float ser;
	int t;
	int oc;
	int r_day;
   public:
	  void welcomescreen();
	  void login_screen();
	  void add_customer();
	  void delete_customer();
	  void update_customer();
	  void search_customer();
	  void main_screen();
	  void display_customer();
	  void checkout_customer();
	  void room_detail();
	  void generate_bill();
	  void room_bill();
    };

void main(){

	char push[10];
	char string[20];
	char pass[20];
	char username[20];
	int custm_id;
	int custm_age;
	int check_inyear;
	int check_inmonth;
	int check_indate;
	char roomtype[20];
	char custm_name[30];
	int room_charge;
	int compare(char[]);
	char custm_occupation[20];
	void getdata();
	void putdata();
	long total;
	int food;
	long room;
	float ser;
	int t;
	int oc;
	int r_day;

	       START:
		     cout<<"\n Enter customer CheckIn Date:";
		     cout<<"\n--------------------";
		     cout<<"\n Year:";
		     cin>>check_inyear;
		     cout<<"\n Month:";
		     cin>>check_inmonth;
		     cout<<"\nDate:";
		     cin>>check_indate;
		     cout<<"\n Enter Room Type:";
		     cin>>roomtype;
		     cout<<"\nEnter Room Charge:";
		     cin>>room_charge;
		if((check_inmonth==2)&&(check_indate>29))
		  {
		    cout<<"wrong input\n";
		    cout<<"\nenter the date again\n";
		    goto START;
		  }
		   if((check_inmonth>12)||(check_indate>31))
		     {
		      cout<<"wrong input\n";
		      cout<<"\n enter the date again\n";
		      goto START;
		      }
		    if((check_inmonth==4||check_inmonth==6||check_inmonth==9||check_inmonth==11)&&(check_indate>30))
		      {
		       cout<<"wrong input\n";
		       cout<<"\n enter the date again\n";
		       goto START;
		     }

	cout<<"\t\t\t\t User Name=";
	   cin>>username;
	   if(strcmp(username,"admin")==0)
	    {
	      string pass="";
	      char ch;
	      cout<<"\n\t\tPassword=";
	      ch=getch();
	      while(ch!=13)
	      {
	      push.push_back(ch);
	       cout<<"*";
	       ch=getch();
	    }
	    if(pass=="admin")
	    {
	       cout<<"\n\t\t"<<"Access granted";
	       do
	       {
	 }
      }

    }
	   void customer::welcomescreen()
	   {
	      system("cls");
	      cout<<endl<<endl<<endl<<endl;
	      cout"welcome";
	      cout"press enter to continue"<<endl<<endl<<endl;
	      getch();
	    }
	    void customer::login_screen()
	    {
	       time_t t;
	       system("cls");
	       t=time(NULL);
	       cout<<"\n                  " <<ctime(&t);
	       customer c:
	       t-=24L*60L*60L;
	       char choice;
	       cout<<endl<<endl<<endl<<endl ;
	       cout<<"\t\t LOGIN SCREEN\n";
	       cout<<"--------------------"<<endl;
	       cout<<"\t\t 1.Administrator Login\n";
	       cout<<"\t\t 2.Customer Login\n";
	       cout<<"\t\t 3.Exit\n";
	       cout<<"\n\n\n";
	       cout<<"Enter Choice::";
	       cin>>choice;
	       switch(choice)
	       {
	       case'1':
		       system("cls");
		       c.main_screen();
		       break;
	       case'2':
		       search_customer();
		       break;
	       case'3':
		       exit(0);
		       break;
	       default:
		       cout<<"wrong choice entered";
		}
	   }

	       void customer::add_customer()
	       {
		  customer c:
		  ofstream outf;
		  outf.open("customer.txt",ios::out|ios::app|ios::binary);
		  c.getdata();
		  outf.write((char*)&c,sizeof(c));
		  outf.close();
		  _getch();
	       }


       void customer::search_customer()
       {
	  fstream file;
	  customer c;
	  int i=1;
	  char nam[25];
	  file.open("customer.txt",ios::in);
	  cout<<"\t\t\t customer Detail\n";
	  cout<<"\t\t\t---------------------\n\n";
	  cout<<"\t\t\t\nEnter name to search:";
	  cin>>nam;
	  file.seekg(0,ios::beg);
	  while(file.read((char*)&c,sizeof(customer)))
	    {
	      if(c.compare(nam))
	    {
	      cout<<"\t\t\t custm_id"<<"     "<<"custm_name\n"<<endl;
	      cout<<"          "<<c.custm_id<<"        "<<c.custm_name;
	      cout<<"\n\t\t\t      Thank You";
	    i=0;
	    break;
	    }
	   }
	   file.close();
	   if(i)
	   {
	    cout<<"Sorry Record not found";
	    }
	   getch();
	  }

	  void customer::delete_customer()
	  { fstream file;
	    fstream temp;
	    temp.open("tempdata.txt",ios::out);
	    customer c;
	    int i=1;
	    char nam[25];
	    file.open("customer.txt",ios::in);
	    cout<<"\t\t\t All customer Detail\n";
	    cout<<"\t\t\t-----------------------\n\n";
	    cout<<"\t\t\t\\nEnter name to search:";
	    cin>>nam;
	    file.seekg(0,ios::beg);
	    while(file.read((char*)&c,sizeof(customer)))
	    {
	      if(!c.compare(nam))
	      {
		  cout<<"\t\t\t custm_id"<<"          "<<"custm_name\n"<<endl;
		  cout<<"              "<<c.custm_id<<"       "<<c.custm_name;
		  i=0;
		  temp.write((char*)&c,sizeof(customer));
	       }
	     }
	       file.close();
	       temp.close();
	       remove("customer.txt");
	       rename("tempfile.txt","customer.txt");
	       getch();
	      }


       void customer::checkout_customer()
       {
	  system("cls");
	  cout<<"Hotel Management "<<endl;
	  cout<<"all customer detail\n";
	}

	{
	   system("cls");
	   cout<<"\n\t\t\t Hotel management";
	   cout<<"details\n";
	   cout<<left<<setw(10)<<"roomtype"<<left<<setw(15)<<"room_charge"<<endl;
	   }



	 class Generatebill:public customer
	 {
	  public:
		 int r_charge;
		 char custm_name[25];
		 char b;
	  public:
		 void calculate()
		 {   system("cls");
		     cout<<"\n enter room type:";
		     cout<<"\n select 1 for super luxary\n select 2 for Luxary\n select 3 for Delux\n";
		     cin>>b;
		     if(b=1)
		     {
			   r_charge=4000;
		      }
		       else
		       if(b=2)
		       {
			  r_charge=3000;
		       }
		       else
			    if(b=3)
			    {
			       r_charge=2000;
			    }
			    else{
				  cout<<"\n wrong choice";
				  cout<<"np room";

	     cout<<"\n enter the bill amount of restaurant";
	     cin>>food;
	     cout>>"\n enter other charges";
	     cin>>oc;
	     cout<<"\n enter customer name";
	     cin>>custm_name;
	     cout<<"\n enter no of days";
	     cin>>r_day;
	     room=r_charge*r_day;
	     t=(int)room+food+oc;
	     ser=(int)(0.05*t);
	     total=t+ser;
	     }

	     void display_bill()
	     {
	      system("CLS");
	      cout<<"customer name"<<custm_name;
	      cout<<"\n stayes for"<<r_day<<"days";
	      cout<<"\n room charges"<<room<<"(total)";
	      cout<<"\n restaurant bill"<<food;
	      cout<<"\n oter charges"<<oc;
	      cout<<"    ser.tax% = 5%";
	      cout<<"    ser.tax ="<<ser;
	      cout<<"\n bill amount"<<total;
	      cout<<"thank you";
	     }
	   };


	   void customer::generate_bill()
	   {
	     Generatebill b;
	     b.calculate();
	     b.display_bill();
	   }



      }
 };




























































