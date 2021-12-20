#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<fstream>
#include<algorithm>
#include<map>
#include<iterator>
#include<vector>
#include<cstdio>
#include<stdlib.h>
#include<iomanip>
using namespace std;


long int empcnt=20000;
class registration
{
	public:
	string name;
	string email;
	string address;
	string status;
	int age;
	long int mobile;
		void getdetails()
		{
			string dum1,dum2;
			cout<<"\033[1;31mEnter your name : \033[0m"<<endl;
			/*getline(cin,name);
			getline(cin,dum1);*/
			cin>>name;
			cout<<"\033[1;31mEnter your age : \033[0m"<<endl;
			cin>>age;
			cout<<"\033[1;31mEnter the Mobile Number : \033[0m"<<endl;
			cin>>mobile;
			cout<<"\033[1;31mEnter the Email ID : \033[0m"<<endl;
			cin>>email;
			cout<<"\033[1;31mEnter your current address : \033[0m"<<endl;
			//getline(cin,address);
			//getline(cin,dum2);
			cin>>address;
			cout<<"\033[1;31mEnter your current status\033[0m"<<"\t"<<"\033[1;33mEMPLOYEE OR EMPLOYER\033[0m"<<endl;
			cin>>status;
		}
		int showdetails()
		{
			cout<<"\033[1;35m1.NAME :\033[0m"<<name<<endl;
			cout<<"\033[1;35m2.AGE :\033[0m"<<age<<endl;
			cout<<"\033[1;35m3.MOBILE_NO :\033[0m"<<mobile<<endl;
			cout<<"\033[1;35m4.EMAIL ID :\033[0m"<<email<<endl;
			cout<<"\033[1;35m5.ADDRESS :\033[0m"<<address<<endl;
			return 0;
		}

		void editdetails()
		{
			cout<<"Your Profile Details are : "<<endl;
			showdetails();
			int choice;
			int nage;
			string nname;
			double nmobile;
			string nemail;
			string naddress;
			cout<<"Enter the Detail No. to be changed : "<<endl;
			cin>>choice;
			switch(choice)
			{
				case 1: 
					cout<<"Enter your name correctly : "<<endl;
					cin>>nname;
					name=nname;
					cout<<"Your Profile Updated Successfully !"<<endl;
					break;

				case 2:
					cout<<"Enter the age : "<<endl;
					cin>>nage;
					age=nage;
					cout<<"Your Profile Updated Successfully !"<<endl;
					break;
				
				case 3: 
					cout<<"Enter the Mobile Number : "<<endl;
					cin>>nmobile;
					mobile=nmobile;
					cout<<"Your Profile Updated Successfully !"<<endl;
					break;
			
				case 4: 
					cout<<"Enter the Email_ID : "<<endl;
					cin>>nemail;
					email=nemail;
					cout<<"Your Profile Updated Successfully !"<<endl;
					break;

				case 5: 
					cout<<"Enter the Address : "<<endl;
					cin>>naddress;
					address=naddress;
					cout<<"Your Profile Updated Successfully !"<<endl;
					break;

				default:cout<<"You have choosen invalid option ! "<<endl;
					exit(1);
			}
		}

	
		

};



class employee:public registration
{
	string field;
	int exp,rate=2,qua;
	public:
	string status;
	int cur_stat;//Depends on the no. of employees required by the employer
	public:
	void set_emp()
	{
		cout<<"Enter the field in which you want to work\nagriculture\nconstruction\nindustry\n";
		cin>>field;
		if(field=="agriculture"||field=="construction"||field=="industry")
		{
		cout<<"Enter your years of experience\n";
		cin>>exp;
		cout<<"Enter your level of qualification: 1.Higher secondary or school 2.degree\n";
		cin>>qua;
		if(qua==2)
		{
			status="Supervisor";
		}
		else
			status="Employee";
		}
		else
		{
		cout<<"Sorry invalid option\n";
		exit(1);
		}
		
		
	}															
	bool emp_chk()
	{
		if(empcnt>0)
		{
			return true;
		}
		else 
		return false;
	}
	void emp_details()
	{
		ofstream myfile;
		myfile.open("employee.txt",ios::app);
			myfile<<"Name: "<<name<<endl;
			myfile<<"Age: "<<age<<endl;
			myfile<<"Mobile: "<<mobile<<endl;
			myfile<<"Email: "<<email<<endl;
			myfile<<"Address: "<<address<<endl;
		myfile<<"Field: "<<field<<"\n"<<"Experience: "<<exp<<"\n"<<"Rate: "<<rate<<"\n"<<"Status: "<<status<<endl;
		myfile.close();
	}
};
class payment
{
	long int acc_no,card_no;
	int cash,cvv,exp_dt,upi_pin;
	string upi_id,name1;
	public:
		void debit_card()
		{
			cout<<"Enter the name on your debit card : "<<endl;
			cin>>name1;
			cout<<"Enter 16-digit debit card number : "<<endl;
			cin>>card_no;
			cout<<"Enter the expiry date on your debit card : "<<endl;
			cin>>exp_dt;
			cout<<"Enter the cvv of your debit card : "<<endl;
			cin>>cvv;
			cout<<"Your payment has been successfull!!"<<endl;
			
		}
		void UPI()
		{
			cout<<"Enter your UPI id:\n";
			cin>>upi_id;
			cout<<"Enter UPI pin:\n";
			cin>>upi_pin;
			cout<<"Your payment has been successfull!!"<<endl;
		}
};
				
		
			
		


class agriculture
{
	int crop;
	int land;
	int duration;
	int soil_type;
	int cost_per_day[10];
	int larr[10];

	public:
		int agro()
		{
			cout<<"\033[1;32mEnter the crop type :\n1.cotton\n2.Rice \033[0m"<<endl;
			cin>>crop;
			cout<<"\033[1;32mEnter the duration time in days : \033[0m"<<endl;
			cin>>duration;
			map<string,int> agrimap;
			if(crop==1)
			{
				cout<<"\033[1;32mEnter the land in acres\033[0m"<<endl;
				cout<<"\033[1;32m1: for 5 to 10 acres\033[0m"<<endl;
				cout<<"\033[1;32m2: for 10 to 20 acres\033[0m"<<endl;
				cin>>land;
				
				
					switch(land)
					{
						case 1:
							agrimap["prep_field"]=20;
							cost_per_day[2]=200;
							agrimap["transplant"]=30;
							cost_per_day[4]=500;
							agrimap["field_main"]=10;
							cost_per_day[0]=300;
							agrimap["sowing"]=40;
							cost_per_day[3]=150;
							agrimap["harvest"]=50;
							cost_per_day[1]=400;
							break;

						case 2:
							agrimap["prep_field"]=30;
							cost_per_day[2]=400;
							agrimap["transplant"]=40;
							cost_per_day[4]=1000;
							agrimap["field_main"]=20;
							cost_per_day[0]=600;
							agrimap["sowing"]=50;
							cost_per_day[3]=300;
							agrimap["harvest"]=60;
							cost_per_day[1]=600;
							break;
					}
				
			}
			else
			{
				cout<<"\033[1;32mEnter the land in acres :\n1.5 to 10\n2.10 to 20\033[0m"<<endl;
				cin>>land;
				
					switch(land)
					{
						case 1:
							agrimap["prep_field"]=35;
							cost_per_day[2]=450;
							agrimap["transplant"]=45;
							cost_per_day[4]=520;
							agrimap["field_main"]=25;
							cost_per_day[0]=440;
							agrimap["sowing"]=45;
							cost_per_day[3]=520;
							agrimap["harvest"]=65;
							cost_per_day[1]=500;
							break;

						case 2:
							agrimap["prep_field"]=45;
							cost_per_day[2]=600;
							agrimap["transplant"]=55;
							cost_per_day[4]=450;
							agrimap["field_main"]=35;
							cost_per_day[0]=520;
							agrimap["sowing"]=80;
							cost_per_day[3]=450;
							agrimap["harvest"]=100;
							cost_per_day[1]=540;
							break;
					}
				
				
			}
			int i=0,total_cost=0,sum=0,sum1=0;
			string work;
			cout<<"\033[1;32mEnter the field for which you want labour:\nprep_field\ntransplant\nfield_main\nsowing\nharvest\nall\033[0m\n";
			cin>>work;
			for(auto it=agrimap.begin();it!=agrimap.end();it++)
			{
				if(it->first==work)
				{
					cout<<"\033[1;32mThe number of labours allocated for \033[0m"<<work<<":"<<it->second<<endl;
					total_cost=(it->second * cost_per_day[i++])*duration ;
					sum+=it->second;
					break;
				}
				 if(work=="all")
				{
					cout<<"\033[1;32mThe number of labours allocated for \033[0m"<<it->first<<":"<<it->second<<endl;
					total_cost=(it->second * cost_per_day[i++])*duration;
					sum=it->second;
				}
			}
			return total_cost;	
			
			
			
		}


};

class construction
{
	int input1,input2,input3,input4;
	int dur;
	int cpd[10];
	int nol;
	public:
	
	int buildings()
	{
		double t_cost=0;
		map<string,int>build;
		cout<<"\033[1;30mWhat kind of buildings do you want to construct:\n1.Educational institution\n2.Personal residence\033[0m\n";
		cin>>input1;
		cout<<"\033[1;30mEnter the duration for which you want labours in days\033[1;30m\n";
		cin>>dur;
		if(input1==1)
		{
			cout<<"\033[1;30mWhat are you going to construct:\n1.School\n2.College\033[0m\n";
			cin>>input2;
			if(input2==1)
			{
				build["poured_concrete"]=50;
				cpd[0]=200;
				build["super_structure"]=60;
				cpd[1]=200;
			}
			else if(input2==2)
			{
				build["poured_concrete"]=60;
				cpd[0]=300;
				build["super_structure"]=80;
				cpd[1]=300;
			}
		}
		else if(input1==2)
		{
			cout<<"\033[1;30mEnter the type of house you want to construct:\n1.Apartment\n2.Villa\033[0m\n";
			cin>>input2;
			if(input2==1)
			{
				build["precast_ponds"]=50;
				cpd[0]=200;
				build["super_structure"]=60;
				cpd[1]=300;
			}
			else if(input2==2)
			{
				build["precast_ponds"]=72;
				cpd[0]=300;
				build["super_structure"]=80;
				cpd[1]=300;
			}
		}
		else
			cout<<"\033[1;30mInvalid option\033[0m\n";
		int i=0,sum=0;
		auto it=build.begin();
		while(it!=build.end() && i<2)
		{
			cout<<"\033[1;30mThe number of labours allocated for \033[0m"<<it->first<<":"<<it->second<<endl;
			t_cost+=(it->second*cpd[i])*dur;
			sum+=it->second;
			it++;
			i++;
		}
		return t_cost;
			
	}

	int railways()
	{
		int sum=0;
		double t_cost=0;
		map<string,int>rail;
		cout<<"\033[1;36mEnter the option for railway:\n1.Construction\n2.Maintenance\033[0m\n";
		cin>>input3;
		cout<<"\033[1;36mEnter the duration for which you require labours in days\033[0m\n";
		cin>>dur;
		int i=0;
		if(input3==1)
		{
			rail["pre_activities"]=30;
			cpd[3]=200;
			rail["construction_materials"]=50;
			cpd[4]=300;
			rail["bottom_ballast"]=60;
			cpd[2]=320;
			rail["anchorage"]=70;
			cpd[0]=280;
			rail["rail_apology"]=75;
			cpd[1]=200;
			rail["top_ballast"]=65;
			cpd[6]=250;
			rail["rail_anchor"]=60;
			cpd[5]=270;
			auto it=rail.begin();
			while(it!=rail.end() && i<6)
			{
				cout<<"\033[1;36mThe number of labours allocated for \033[0m"<<it->first<<":"<<it->second<<endl;
				t_cost+=(it->second*cpd[i])*dur;
				sum+=it->second;
				it++;
				i++;
			}
			return t_cost;
		}
		else if(input3==2)
		{
			cout<<"\033[1;36mEnter the option for your maintenance:\n1.rail apology and track laying\n2.Anchorage problem\033[0m\n";
			cin>>input4;
			if(input4==1)
			{
				rail["rail_apology"]=75;
				cpd[0]=200;
			}
			else if(input4==2)
			{
				rail["anchorage"]=70;
				cpd[0]=240;
			}
			auto it=rail.begin();
			while(it!=rail.end() && i<1)
			{
				cout<<"\033[1;36mThe number of labours allocated for \033[0m"<<it->first<<":"<<it->second<<endl;
				t_cost+=(it->second*cpd[i])*dur;
				sum+=it->second;
				it++;
				i++;
			}
			return t_cost;
			
		}
		else
			cout<<"\033[1;36mSorry invalid statement:\033[0m\n";

			
	}
	
	int roads()
	{
		int sum=0;
		map<string,int>road;
		double t_cost=0;
		int i=0;
		cout<<"\033[1;34mEnter the option:\n1.Construction\n2.Widening\033[0m\n";
		cin>>input4;
		cout<<"\033[1;34mEnter the duration for which you require labours in days\033[0m\n";
		cin>>dur;
		if(input4==1)
		{
			road["embankmentlayer"]=50;
			cpd[2]=180;
			road["subgradeconstr"]=65;
			cpd[4]=200;
			road["subbase"]=60;
			cpd[3]=220;
			road["basecourse"]=55;
			cpd[0]=180;
			road["bituminouslayer"]=62;
			cpd[1]=240;
		}
		else if(input4==2)
		{
			road["earthwork"]=56;
			cpd[2]=200;
			road["subgradeconstr"]=60;
			cpd[4]=180;
			road["subbase"]=62;
			cpd[3]=220;
			road["basecourse"]=65;
			cpd[0]=210;
			road["bituminouslayer"]=58;
			cpd[1]=250;
		}
			
			
		else	
		{
			cout<<"\033[1;34Invalid statement\033[0m\n";
		}
		
			auto it=road.begin();
			while(it!=road.end() && i<5)
			{
				cout<<"The number of labours allocated for "<<it->first<<":"<<it->second<<endl;
				t_cost+=(it->second*cpd[i])*dur;
				sum+=it->second;
				it++;
				i++;
			}
			return t_cost;
	}
	
};
					
class industry
{
	int input,duration,no_of_lab,cpd[10],t_cost=0;

	public:
		int sum=0;
		map<string,int>indo;
		int garments()
		{
			indo["design"]=50;
			cpd[1]=180;
			indo["sample"]=45;
			cpd[4]=62;
			indo["stitch"]=65;
			cpd[5]=200;
			indo["button"]=62;
			cpd[0]=210;
			indo["threadtrim"]=55;
			cpd[6]=180;
			indo["dying"]=58;
			cpd[2]=180;
			indo["pack"]=65;
			cpd[3]=156;
			string work;
			cout<<"\033[1;31mEnter the field for which you want labour:\ndesign\nsample\nstitch\nbutton\nthreadtrim\ndying\npack\033[0m\n";
			cin>>work;
			cout<<"\033[1;31mEnter the number of days for which you require labours in days\033[0m\n";
			cin>>duration;
			int i=0;
			for(auto it=indo.begin();it!=indo.end();it++)
			{
				if(it->first==work)
				{
					cout<<"\033[1;31mThe number of labours allocated for \033[0m"<<it->first<<":"<<it->second<<endl;
					t_cost=it->second * cpd[i++] ;
					sum+=it->second;
					break;
				}
			}
			return t_cost;
		}
		int pharmaceutical()
		{
			map<string,int>pharma;
			pharma["milling"]=60;
			cpd[1]=182;
			pharma["granulation"]=65;
			cpd[0]=190;
			pharma["tabletpressing"]=56;
			cpd[3]=220;
			pharma["packing"]=54;
			cpd[2]=150;
			
			string work;
			cout<<"\033[1;31mEnter the field for which you want labour:\nmilling\ngranulation\ntabletpressing\npacking\033[0m\n";
			cin>>work;
			cout<<"\033[1;31mEnter the number of days for which you require labours\033[0m\n";
			cin>>duration;
			int i=0;
			for(auto it=pharma.begin();it!=pharma.end();it++)
			{
				if(it->first==work)
				{
					cout<<"\033[1;31mThe number of labours allocated for \033[0m"<<it->first<<":"<<it->second<<endl;
					t_cost=it->second * cpd[i++] ;
					sum+=it->second;
					break;
				}
				
			}
			return t_cost;
		}
};

class employer:public payment,public agriculture,public construction,public industry,public employee
{
	string job;
	int n_male;
	int n_female;
	int days;
	int exper;
	int l_plan;
	int l1_plan;
	string field;
	public:
	void exp_check()
	{
		cout<<"In which field do you require labourers\nagriculture\nconstruction\nindustry\nPlease enter the input as strings\n";
		cin>>field;
		if(field=="agriculture"||field=="construction"||field=="industry")
		{
		cout<<"Are you a well experienced employer:\n1.Yes 2.No\n";
		cin>>exper;
		if(exper==2)
		{
				cout<<"Don't worry we plan labourers for you in a cost efficient and standardised manner:\n";
				cout<<"Planning......\n";/*Inherit the respective class of job variety as necessary and assign labour jobs in 									a function of the respective derived class*/ 
				if (field=="agriculture")
				{
					int k=agro();
					cout<<"Total estimated cost is :"<<k<<endl;
					cout<<"Is our plan satisfiable for you:\n1.Yes 2.No";
					cin>>l1_plan;
					if(l1_plan==1 && emp_chk()==1)
					{
						empcnt-=sum;
					}

					else
					{
						cout<<"Insufficient labours:Try after a while"<<endl;
						exit(1);
					}
				

				}
				
				else if (field=="construction")
				{
					int ch,k;
					cout<<"1.Roads\n2.Buildings\n3.Railways\n"<<endl;
					cin>>ch;
					switch(ch)
					{
						case 1:
							k=roads();
							break;
						case 2:
							k=buildings();
							break;

						case 3:
							k=railways();
							break;
						default:
							cout<<"invalid option ";
							exit(1);
					}
					cout<<"Total estimated cost is :"<<k<<endl;
					cout<<"Is our plan satisfiable for you:\n1.Yes 2.No";
					cin>>l1_plan;
					if(l1_plan==1 && emp_chk()==1)
					{
						empcnt-=sum;
					}

					else
					{
						cout<<"Insufficient labours:Try after a while"<<endl;
						exit(1);
					}
				}

				else if(field=="industry")
				{
					
					int c,t;
					cout<<"1.Garments\n2.Pharmaceutical\n";
					cin>>c;
					switch(c)
					{
						case 1:
							t=garments();
							break;
						case 2:
							t=pharmaceutical();
							break;	
						default:
							cout<<"invalid option ";
							exit(1);
					}
					cout<<"Total estimated cost is :"<<t<<endl;
					cout<<"Is our plan satisfiable for you:\n1.Yes 2.No";
					cin>>l1_plan;	
					if(l1_plan==1 && emp_chk()==1)
					{
						empcnt-=sum;
					}

					else
					{
						cout<<"Insufficient labours:Try after a while"<<endl;
						exit(1);
					}
				
				}			
			
			if(l1_plan==1)
			{
				int c;
				cout<<"Taking you to payment portal:\n";
				cout<<"Please choose your payment option :"<<endl;
				cout<<"1.Debit_card\n2.UPI\n"<<endl;
				cin>>c;
				switch(c)
				{
					case 1:
						debit_card();
						break;
					case 2:
						UPI();
						break;

					default:
							cout<<"invalid option ";
							exit(1);
				}
			
					
				
							
				/*Now inherit the payment class and call the ffunction for payment. After payment show the employees details from the employee class print function to the employer only*/ 
				cout<<"Employee details have been loaded into your file:\n";
				ofstream myfile;
				myfile.open("employer.txt",ios::app);
				myfile<<"Field of requested labour: "<<field<<"\n"<<"Employee details:\n";
				
				myfile.close();
				cout<<"Thank you:\nDon't forget to share your ratings in our official twitter page after succesfull completion of our contract\n";
			}
			else
			cout<<"Sorry for the plan which did not satisfy you. Please give us feedback in our official twitter page on how can we improve our service to cater your expectations.Thank you:\n";
		}
		else
		{
			int c;
			cout<<"Enter the number of male labourers required for your job\n";
			cin>>n_male;
			cout<<"Enter the number of female labourers required for your job\n";	
			cin>>n_female;
			cout<<"Enter the total number of days for which you require labourers\n";
			cin>>days;
			int tcost=((n_male*200)+(n_female*150))*days;
			cout<<"Total cost estimated is : "<<tcost<<endl;
			cout<<"Taking you into the payment portal:\n";/*Now inherit the payment class and call the function for payment. After payment show the employees details from the employee    class print function to the employer only*/ 
			cout<<"Please choose your payment option :"<<endl;
				cout<<"1.Debit_card\n2.UPI\n"<<endl;
				cin>>c;
				switch(c)
				{
					case 1:
						debit_card();
						break;
					case 2:
						UPI();
						break;

					default:
							cout<<"invalid option ";
							exit(1);
				}
			cout<<"The employee details are loaded into your file:\n";
			cout<<"Thank you:\nDon't forget to share your ratings in our official twitter page\n";
				ofstream myfile;
				myfile.open("employer.txt",ios::app);
				myfile<<"Field of requested labour: "<<field<<"\n"<<"Number of male employees requested for: "<<n_male<<"\n"<<"Number of female employees requested for: "<<n_female<<"\n"<<"Number of days of contract: "<<days<<"\nTotal_cost:"<<tcost<<endl;
				myfile.close();
		}
	}
	else
	{
		cout<<"Invalid option try again:\n";
		exit(1);
	}
	}
   
		
};

int main()
{
	registration r;
	employer e1;
	employee e;
	int input;
	while(1)
	{
	cout<<"               ########  \033[1;31mWELCOME TO LABOUR HELP FOR AGRICULTURE,CONSTRUCTION AND INDUSTRY SECTORS\033[0m   #######"<<endl;       
	cout<<"\033[1;34mEnter the option : \n1.Enter your details\n2.show details\n3.Edit details\033[0m\n";
	cin>>input;
	switch(input)
	{

		case 1 :
				r.getdetails();

				if(r.status=="EMPLOYER")
				{
					
					r.showdetails();
					e1.exp_check();
				}
				else if(r.status=="EMPLOYEE")
				{
					r.showdetails();
					e.set_emp();
					e.emp_details();
				}
				break;
	
		case 2 :
				r.showdetails();
				break;

		case 3:
				r.editdetails();
				break;
	
		default:
				cout<<"Invalid option"<<endl;
				exit(1);
							
	}
	}
			
	return 0;
}
