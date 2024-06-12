#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<string.h>
#include<limits>
#include <bits/stdc++.h>
#include <unordered_map>
#include<windows.h>
#include<ctime>
#include<conio.h>
#define restaurantcount 150

typedef std::pair<int,int> edge; //defining a a type 'edge' to denote an edge in graphs
using namespace std;
void clrscr()
{
	system("cls");
}
void capitalise(string& s)  //Utility Function to help validate user inputs of Yes/No or 1/0
{
	for(int i=0;i<s.length();i++)
	{
		s[i]= toupper(s[i]);
	}
}
class Account //UserAcoount clas
{
	public :
	private:
		
		vector<bool> options; //keep check of what preferences user has selected;
		bool ratings_select = false;
		bool distance_select= false;
		bool price_select=false;
		bool ambiance_select=false;
		bool vegan_select= false;
		bool drive_select = false;
		//Variables to hold user info / input;
		int age;
		int num_ops;
		string name;
		string cuisine;
		string address;
		int price;
		int ambiance;
		bool vegan;
		bool drivethru;
		
	public:
		int *distancefromrestaurants = new int[restaurantcount]; //Dynamic Array to hold the distance each restaurant has from user!
		Account()//Constructor To initialise
		{
			name="Sabih Uddin";
			age=20;
			cuisine="chinese";
			address="Street #1 Gulshan ,Karachi";
			price=0;
			ambiance=0;
			vegan=false;
			drivethru=false;
			num_ops=0;
			
			ratings_select = false;
			distance_select= false;
			price_select=false;;
			ambiance_select=false;
			vegan_select= false;
			drive_select = false;
			int *distancefromrestaurants = new int[restaurantcount];
			
		}
		Account(string n)
		{
			name=n;
			age=20;
			cuisine="chinese";
			address="Street #1 Gulshan ,Karachi";
			price=0;
			ambiance=0;
			vegan=false;
			drivethru=false;
			num_ops=0;
			
			ratings_select = false;
			distance_select= false;
			price_select=false;;
			ambiance_select=false;
			vegan_select= false;
			drive_select = false;
			int *distancefromrestaurants = new int[restaurantcount];
		}
//getters for user vars/flags
		void setname(string n)
		{
			name=n;
		}		
		void setaddress(string ad)
		{
			address=ad;
		}	
		void setcuisine(string c)
		{
			cuisine=c;
		}	
		void setage(int a)
		{
			age=a;
		}		
		int useroptions()
		{
			return num_ops;
		}
		bool chooseratings()
		{
			return ratings_select;
		}
		bool choosedistance()
		{
			return distance_select;
		}
		bool chooseprice()
		{
			return price_select;
		}
		bool chooseambiance()
		{
			return ambiance_select;
		}
		bool uservegan()
		{
			return vegan_select;
		}
		bool userdrivethru()
		{
			return drive_select;
		}
		int getprice()
		{
			return price;
		}
		string getaddress()
		{
			return address;
		}
		string getname()
		{
			return name;
		}
		int getage()
		{
			return age;
		}
		string getcuisins()
		{
			return cuisine;
		}
		int getambiance()
		{
			return ambiance;
		}
//--------------------------------------------------------------------------Setter Functions to SetUser Preferences		
		void setprice()
		{
			cout<<"Enter Price Range (Cheap : 1),(Moderate: 2),(Expensive: 3) : ";
			cin >> price;
			while(price<1||price>3)
			{
				cout<<"\nEnter Price Range between 1 and 3 ONLY : (1:Cheap, 2:Moderate, 3:Expensive)"; cin>>price;
			} 
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}
		void setambiance()
		{
			cout<<"Enter Ambiance Preferences: (1-3) (1:Least Formal, 3:Most Formal) : ";
			cin >> ambiance;
			while(ambiance<1||ambiance>3)
			{
				cout<<"\nEnter Ambiance Range between 1 and 3 ONLY : "; cin>>ambiance;
			} 
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}
		void setvegan()
		{
			string s;
			cout<<"\nAre You Vegan ? (YES/1 || NO/0 ) : ";
			cin>> s;
			capitalise(s);
			
			while(!(s=="YEAH" || s=="NO" || s=="YES" || s=="0" || s=="1" || s=="NAHH" || s=="Y" || s=="N")){
				cout<<"\nEnter Correct Options : ";
				cin>> s;
				capitalise(s);
			}
			if(s=="YES" || s=="Y" || s=="1" || s=="YEAH")
			{
				vegan=true;
				vegan_select=true;
			}
			else
			{
				vegan=false;
				options[4]=false;
			}
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}
		void setdrivethru()
		{
			string s;
			cout<<"\nAre You Looking For DriveThru ? (YES/1 || NO/0 ) :";
			cin>> s;
			capitalise(s);
			
			while(!(s=="YEAH" || s=="NO" || s=="YES" || s=="0" || s=="1" || s=="NAHH" || s=="Y" || s=="N"))
			{
				cout<<"\nEnter Correct Options : ";
				cin>> s;
				capitalise(s);
			}
			if(s=="YES" || s=="Y" || s=="1" || s=="YEAH")
			{
				drivethru=true;
				drive_select=true;
			}
			else
			{
				drivethru=false;
				options[5]=false;
			}
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}		
//--------------------------------------------------Function to Handle user Inputs for their preferences		
		void optionshandling(int num_ops)
		{	
			int op=0;
			while( num_ops<0 || num_ops>6)
			{
				cout<<"\nMin 0 and Max 6 Factors Only ! : ";
				cin>>num_ops;
			}
			if(num_ops==6)
			{
				options = vector<bool>(6,true);
			}
			else
			{
				for(int i=0;i<num_ops;i++)
				{
					cin>>op;
					while(op<1 || op>6)
					{
						cout<<"\nEnter Options betweeen 1-6 ONLY : ";
						
						cin>>op;
					}
					options[op-1]=true;
				}
			}
				if(options[0])
				{
					ratings_select =true;
				}
				if(options[1])
				{
					distance_select = true;
				}
				if(options[2])
				{	
					price_select = true;
					setprice();
				}
				if(options[3])
				{
					ambiance_select=true;
					setambiance();
				}
				if(options[4])
				{
					//vegan_select = true;
					setvegan();
				}
				if(options[5])
				{
					//drive_select = true;
					setdrivethru();
				}

		}
//Setter to Initialise User !		
		void setuser()
		{
			options = vector<bool>(6,false);
			string yesno;
			int num_ops2;
			cin.ignore();
			cout<<"\n(Kindly Input Your Details and Preferences to Search for Best Options \n";
			cout<<"\nEnter Name : ";  getline(cin,name);
			cout<<"Enter Age : "; cin>>age;
			while(age < 18)
			{
				cout<<"\nMinimum Age is 18 : " ; cin>>age;
			}
			cout<<"Enter Favourite Cuisine : "; cin>>cuisine;
		//	cout<<"\nEnter Address : ";cin>>address;
			
			cout<<"Select From The Following Factors Relevant For You :";
			cout<<"\n1) Ratings";
			cout<<"\n2) Distance";
			cout<<"\n3) Price";
			cout<<"\n4) Ambiance Preferences";
			cout<<"\n5) Vegan/NonVegan";
			cout<<"\n6) DriveThru Preferences";
			
			cout<<"\nHow Many Factors Do You Want to Select ? 0 if you dont want to select any preferenes: "; 
			cin>>num_ops;
			optionshandling(num_ops);
			
		}
//Display User Info and Their Preferences and Number of Preferences		
		void displayaccount()
		{
			cout<<"\nUSER DETAILS : ";
			cout<<"\n____________________";
			cout<<"\nName    : "<<name;
			cout<<"\nAge     : "<<age;
			cout<<"\nAddress : "<<address;
			cout<<"\nCuisine : "<<cuisine;
			cout<<"\nPreferences Selected : "<<num_ops;
			if(num_ops>=1)
			{	cout<<"\nVegan ? : ";
				if(vegan)
				{
					cout<<"Yes";
				}
				else
				{
					cout<<"No";
				}
				cout<<"\nDriveThru Option ? : ";
				if(drivethru)
				{
					cout<<"Yes";
				}
				else
				{
					cout<<"No";
				}
				cout<<"\nAmbiance Option? : ";
				if(ambiance_select)
				{
					cout<<"Yes";
					cout<<"||| Ambiance level : "<<ambiance;
				}
				else
				{
					cout<<"No";
				}
			}
			else
			{
				cout<<"\nNo Preferences Selected By User ";
			}
		}
		void save_usertodata(int& i)
		{
			ofstream outputfile("UserData.txt",ios::app);
			if(outputfile.is_open())
			{	
				outputfile<<"\nUSER INFO"<<" : ";
				outputfile<<"\n____________________";
				outputfile<<"\nName    : "<<name;
				outputfile<<"\nAge     : "<<age;
				outputfile<<"\nAddress : "<<address;
				outputfile<<"\nCuisine : "<<cuisine;
				outputfile<<"\nPreferences Selected : "<<num_ops;
				if(num_ops>=1)
				{	outputfile<<"\nVegan ? : ";
					if(vegan)
					{
						outputfile<<"Yes";
					}
					else
					
					{
						outputfile<<"No";
					}
				outputfile<<"\nDriveThru Option ? : ";
				if(drivethru)
				{
					outputfile<<"Yes";
				}
				else
				{
					outputfile<<"No";
				}
				outputfile<<"\nAmbiance Option? : ";
				if(ambiance_select)
				{
					outputfile<<"Yes";
					outputfile<<"||| Ambiance level : "<<ambiance;
				}
				else
				{
					outputfile<<"No";
				}
			}
			else
			{
				outputfile<<"\nNo Preferences Selected By User "<<endl;
			}
				outputfile<<"--------------------------------------"<<endl;
		}	
			else
			{
				cout<<"ERROR OPENING FILE \n";
			}
			outputfile.close();
		}
		void saving_usersadmin(int& i)
		{
			ofstream outputfile("AdminUserData.txt",ios::app);
			if(outputfile.is_open())
			{	
				outputfile<<name<<endl;
				outputfile<<age<<endl;
				outputfile<<address<<endl;
				outputfile<<cuisine<<endl;
			}
			else
			{
				cout<<"ERROR OPENING FILE \n";
			}
			outputfile.close();
		}		
		~Account()
		{
			delete[] distancefromrestaurants;  // free the DynamicArray of distances from restaurants
		}
}; //End oF UserClass

class Restaurant  // Restaurants, initialised via Filing to be used in the App Data Set
{
	public:
		string name;
		string address;
   	 	string cuisine;
		int price;
		float rating;
		int ambiance;
		bool drivethru;
		bool vegan;
		
		int numreviews;	
		int distancefromuser;
};//End oF RestaurantClass
class Node //NODE TO SAVE USERS AS A NODE IN A LINKLIST
{
	private:
		int age;
		int num_ops;
		string name;
		string cuisine;
		string address;
		int price;
		int ambiance;
		bool vegan;
		bool drivethru;

	public:		
		Node *nxt;
		Node *prv;
		Node()
		{
			nxt=NULL;
			prv=NULL;
			age=0;
			num_ops=0;
			name="";
			cuisine="";
			address="";
			price=0;
			ambiance=0;
			vegan=false;
			drivethru=false;
		}
		Node(Account &a)
		{
			nxt=NULL;
			prv=NULL;
			age=a.getage();
			num_ops=a.useroptions();
			name=a.getname();
			cuisine=a.getcuisins();
			address=a.getaddress();
			price=a.getprice();
			ambiance=a.getambiance();
			vegan=a.uservegan();
			drivethru=a.userdrivethru();
		}
		void diplay()
		{	cout<<"\nUSER DETAILS : ";
			cout<<"\n____________________";
			cout<<"\nName    : "<<name;
			cout<<"\nAge     : "<<age;
			cout<<"\nAddress : "<<address;
			cout<<"\nCuisine : "<<cuisine;
			
		}
};
class List //DOUBLY CIRCULAR LINK LIST FOR A SLIDER TO GO BACK AND FORTH BW ALL USERS
{
	private :
		Node *head;
	public :
		List()
		{
			head=NULL;
		}
		void insert(Account &a)
		{
			Node *ins = new Node(a);
			if(head==NULL)
			{ 
				head = ins;
				head->nxt=head;
				head->prv=head;
			}
			else
			{
				Node *itr=head;
				while(itr->nxt!=head)
				{
					itr =itr->nxt;
				}
				itr->nxt= ins;
				ins->prv= itr;
				ins->nxt= head;
				head->prv = ins;
			}
		}
		void display()
		{
			if(!head)
			{
				cout<<"\nUSER LIST IS EMPTY !";
				return;
			}
			else
			{
				Node* itr=head;
				do
				{
					itr->diplay();
					itr = itr->nxt;
				}while(itr!=head);
			}
		}
		bool displaycurr()
		{
			if(!head)
			{
				cout<<"\nUser List Is emptyy !";
				return false;
			}
			else
			{
				
				Node* itr =head;
				char key;
				while(true)
				{
					cout<<"\n Press LeftKey and RightKey To Move ahead (E to exit) \n";
					itr->diplay();
					
					key = _getch();
					if(key==75)
					{
						clrscr();
						moveprev(itr);
					}
					else if(key==77)
					{
						clrscr();
						movenxt(itr);
					}
					else if(key=='E')
					{
						clrscr();
						return true;
					}
				}
				
			}
		}
		void movenxt(Node* &itr)
		{
			if(itr&&itr->nxt)
			{
				itr = itr->nxt;
				return;
			}
		}	
		void moveprev(Node* &itr)
		{
			if(itr && itr->prv)
			{
				itr = itr->prv;
				return;
			}
		}
};
class Recommender  // The App has the user and the restaurants as part of its data set
{
	private:
		Account A1;
		vector <Restaurant> restaurants; 
		List ourusers;
		vector <Restaurant> results;
		map <string,int> addresses; // Graph of Restaurants and their distances from eachother
		vector <vector<int>> Map;
		int usercount=1;
		List users;
		
		int *distance;
		int INF = INT_MAX;
		clock_t start,end; //clock for computation time
//to view adjacency matrix; or socalled map		
	void displayMap()
	{
		cout<<"\nDISPLAYING ADJACENCY MATRIX : \n";
		for(int i=0;i<restaurantcount;i++)
		{
			cout<<"\nRestaurant #"<<i+1<<" : ";
			for(int j=0;j<restaurantcount;j++)
			{
				cout<<Map[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	void displayDistancesfromuseronly(){   //Program to check the distancefromrestaurant array of the user;
		for(int i=0;i<restaurantcount;i++)
		{
			cout<<i+1<<" )"<<A1.distancefromrestaurants[i]<<endl;
		}
	}			
//SORTING PER CRITERIA FUNCTIONS	 (nlogn)
	void sortbydistance()
	{
		std::sort(restaurants.begin(),restaurants.end(),[](const Restaurant& a,const Restaurant& b)
		{
			return a.distancefromuser > b.distancefromuser;
		});
	}
	void sortbyprice()
	{
		std::sort(restaurants.begin(),restaurants.end(),[](const Restaurant& a,const Restaurant& b)
		{
			return a.price > b.price;
		});
	}
	void sortbyrating()
	{
		std::sort(restaurants.begin(),restaurants.end(),[](const Restaurant& a,const Restaurant& b)
		{
			return a.rating > b.rating;
		});
	}
	void sortbyvegan()
	{
		vector<Restaurant> vegans;
		for(const auto& r: restaurants)
		{
			if(r.vegan)
			{
				vegans.push_back(r);
			}
		}
		std::sort(vegans.begin(),vegans.end(),[](const Restaurant& a,const Restaurant& b)
		{
			return a.vegan > b.vegan;
		});
		restaurants = std::move(vegans);	
	}
	void sortbydrivethru()
	{
		vector<Restaurant> sdrivethru;
		for(const auto& r: restaurants)
		{
			if(r.drivethru)
			{
				sdrivethru.push_back(r);
			}
		}
		std::sort(sdrivethru.begin(),sdrivethru.end(),[](const Restaurant& a,const Restaurant& b)
		{
			return a.drivethru > b.drivethru;
		});
		restaurants = std::move(sdrivethru);
	}
	//TO FILTER BY PREFERENCES EG WILL ONLY show ambiance level 1 restauratns if user selects it as 1;
	void filterbyambiance()
	{
		vector<Restaurant> filtered;
		for(const auto& r: restaurants)
		{
			if(r.ambiance== A1.getambiance())
			{
				filtered.push_back(r);
			}
		}
		restaurants = std::move(filtered);
	}
	void filterbyprice()
	{
		vector<Restaurant> filtered;
		for(const auto& r: restaurants)
		{
			Restaurant c;
			if(r.price== A1.getprice())
			{
				filtered.push_back(r);
			}
		}
		restaurants = std::move(filtered);
	}
	void sortbyambiancedefault()
	{
		std::sort(restaurants.begin(),restaurants.end(),[](const Restaurant& a,const Restaurant& b)
		{
			return a.ambiance > b.ambiance;
		});
	}

//SORTING PER CRITERIA FUNCTIONS			
	void sorter()  ///single sorter function to take care of all sortings
	{
		if(A1.uservegan())
		{
			sortbyvegan();
		}
		if(A1.userdrivethru())
		{
			sortbydrivethru();
		}
		if(A1.chooseambiance())
		{
			filterbyambiance();
		}
		else
		{
			sortbyambiancedefault();
		}
		sortbydistance();
		sortbyrating();
	}

//DJIKSTRA
	void djikstra()  //using Djikstra to find Most Closest Restaurants first !
	{
		int source = addresses[A1.getaddress()];
		initialisedistance();
		priority_queue< edge, vector<edge>, greater<edge>> pq;
		distance[source]=0;
		pq.push(make_pair(0,source));
		while(!pq.empty())
		{
			int u =pq.top().second;
			pq.pop();
			for(int v=0;v<restaurantcount;v++)
			{
				if(Map[u][v]!=0 && distance[u]!=INF && distance[u] +Map[u][v] < distance[v] )
				{
					distance[v] = distance[u] + Map[u][v];
					pq.push(make_pair(distance[v],v));
				}
			}
		}
	}
//FILE READING 	
	void read_data_fromfile(const string& filename )  //Read DataSet of Restaurants Fromt Txt to use in Program
	{
		ifstream inputfile(filename);
		if(!inputfile.is_open())
		{
			cout<<"\nError Opening The File :("<<filename<<") ";
			return;
		 
		} 
		
		
		int count=0;  //Keeep count of the line
		for(int j=0;j<restaurantcount;j++)
		{
				
			string line; //var to read line from file
			Restaurant r; //var to save restaurants read from file;
			count=0;
			for(int i=0;i<10;i++)
			{
				getline(inputfile,line);
				if(line.empty())
				break;
				
				if(count ==0)
				{
					r.name=line;
				}
				else if(count==1)
				{
					r.address=line;
				}
				else if(count==2)
				{
					r.cuisine=line;
				}
				else if(count==3)
				{
					r.rating= stof(line);
				}
				else if(count==4)
				{
					r.price=    stoi(line);
				}
				else if(count==5)
				{
					r.distancefromuser = stof(line);
					A1.distancefromrestaurants[j] = r.distancefromuser;  // distance of a restaurant from user is same as distance of user from restaurant;
				}
				else if(count==6)
				{
					r.ambiance= stoi(line);
				}
				else if(count==7)
				{
					r.vegan = (line=="Yes");
				}
				else if(count==8)
				{
					r.drivethru= (line=="Yes");
				}
				else if(count==9)
				{
					r.numreviews=stoi(line);
				}
				count++;
				
				
				if(count==10)
				{
					count=0;
				}
		}			
			
				getline(inputfile,line);
				restaurants.push_back(r);
			
			
		}
		
		inputfile.close();

	}	
	
	void readuserstodisplay(const string& filename)
	{
		ifstream inputfile(filename);
		if(!inputfile.is_open())
		{
			cout<<"\nError Opening The File :("<<filename<<") ";
			return;
		 
		}else
		{
			Account a;
			string line;
			int count=0;
			while(getline(inputfile,line))
			{
				if(line.empty())
				break;
				
				if(count==0)
				{
					a.setname(line);
				}
				else if(count==1)
				{
					a.setage(stoi(line));
				}
				else if(count==2)
				{
					a.setaddress(line);
				}
				else if(count==3)
				{
					a.setcuisine(line);
				}
				count++;
				if(count==4)
				{
					ourusers.insert(a);
					count=0;
				}
				
			}
		}
		inputfile.close(); 
	}
	void displayResults ()  //Display All Restaurants in the App Data set
	{
		cout<<"\n------------------------------\n";
		cout<<"\nRestaurants Near You : \n";
		djikstra();
		sorter();
		int i=0;
		for(const auto& r: restaurants)
		{
			cout<<"#"<<i+1<<")"<<endl;
			cout<<"Name : "<<r.name <<endl;
			cout<<"Address : "<<r.address <<endl;
			cout<<"Cuisine : "<<r.cuisine <<endl;
			cout<<"Rating : "<<r.rating <<endl;
			cout<<"Distance From You : "<<r.distancefromuser<<" km"<<endl;
			cout<<"Price : "<<r.price <<endl;
			cout<<"Ambiance : "<<r.ambiance <<endl;
			cout<<"Vegan : "<<(r.vegan ? "YES ": "NO")<<endl;
			cout<<"DriveThru : "<<(r.drivethru ? "YES ": "NO")<<endl;
			cout<<"Number OF Reviews : "<<r.numreviews <<endl;
			cout<<"-----------------------------"<<endl;
			i++;
		}
	}
	void displayAllRestaurants ()  //Display All Restaurants in the App Data set
	{
		cout<<"\n------------------------------\n";
		cout<<"\nRestaurants Near You : \n";
		djikstra();
		int i=0;
		for(const auto& r: restaurants)
		{
			cout<<"#"<<i+1<<")"<<endl;
			cout<<"Name : "<<r.name <<endl;
			cout<<"Address : "<<r.address <<endl;
			cout<<"Cuisine : "<<r.cuisine <<endl;
			cout<<"Rating : "<<r.rating <<endl;
			cout<<"Distance From You : "<<r.distancefromuser<<" km"<<endl;
			cout<<"Price : "<<r.price <<endl;
			cout<<"Ambiance : "<<r.ambiance <<endl;
			cout<<"Vegan : "<<(r.vegan ? "YES ": "NO")<<endl;
			cout<<"DriveThru : "<<(r.drivethru ? "YES ": "NO")<<endl;
			cout<<"Number OF Reviews : "<<r.numreviews <<endl;
			cout<<"-----------------------------"<<endl;
			i++;
		}
	}
	void userMenu() //User Menu and functionalities
	{
		start= clock();
		cout<<"\n----------------USER MENU----------------\n";
		djikstra();
		A1.setuser();
		A1.displayaccount();
		djikstra();
		if(A1.useroptions()==0)
		{
			displayAllRestaurants();
		}
		else
		{
			displayResults();
		}
		end = clock();
		displayclock();
	}
	
	void displayclock()
	{
		double total_time = double(end-start)/double(CLOCKS_PER_SEC);
		cout<<"\nTime Taken In Output : "<<fixed << total_time << setprecision(5) <<" secs.\n";
	}
	void adminMenu() //admin menu and functionalities
	{
		string inp;
		Account er;
		Account a1("SARA");
		Account a2("laib");
		Account a3("alis");
		Account a4("hony");
	//	users.insert(er);
	//	users.insert(a2);
	//	users.insert(a3);
	//	users.insert(a4);
		start= clock();
		cout<<"\n----------------ADMIN MENU----------------\n";
		cout<<"\nPRESS A to display all Users : ";
		cout<<"\nPRESS S to display User Slider: ";
		cout<<"\nPRESS ANYOTHER to EXIT : "; cin>>inp;
		capitalise(inp);
		if(inp == "A")
		{
			ourusers.display();
		}
		else if(inp== "S")
		{
			while(true)
			{
				if(ourusers.displaycurr())
				{
					break;
				}
			}
		}
		else if(inp!="A"  && inp!="S")
		{
			cout<<"\n THANKS BYEE !";
			end = clock();
			displayclock();
			return;
		}
		cout<<"\nTHANKS BYEE";
		end = clock();
		displayclock();
	}			
	public:	
	void initialisedistance()
	{
		for(int i=0;i<restaurantcount;i++)
		{
			distance[i] =INF;  // initialist distances as infinity as we dont know,
		}
	}
	Recommender()  // Constructor to initialise the Recommender Data set, from txt using readdata
	{
		Map = vector<vector<int>>(restaurantcount, vector<int>(restaurantcount,0));  //Initialise Map at 0,0 for all 
		A1.distancefromrestaurants = new int[restaurantcount];
		read_data_fromfile("RestaurantsList.txt");
		distance = new int[restaurantcount];
		
		for(int i=0;i<restaurantcount;i++)
		{
			int roads = rand()%4 +1;  //at max a restaurant is connected via 4 roads; 
			for(int j=0;j<roads;j++)
			{
				int connection = rand()%restaurantcount;
				if(Map[i][connection]!=0 || i==connection)
				{
					j--;
					continue;
				}
				Map[i][connection] = rand()%20 +1;
				Map[connection][i] = Map[i][connection];
			}
		}
		for(int i=0;i<restaurantcount;i++)
		{
			addresses[restaurants[i].address] = i; 
		}
	}
	
	void Apprun()  // SingleProgram to Run the App checks for User or Admin Menu
	{
		string ans;
		cout<<"\nHELLO Welcome to THE Restaurant Recommender Software (RRS)\n";
		cout<<"\nAdmin Page or User ? ";
		cin>> ans;
		capitalise(ans);
		while(ans!="USER" && ans!="ADMIN")
		{
			cout<<"\nONLY ADMIN OR USER OPTIONS CAN BE SELECTED ! : ";
			capitalise(ans);
			cin>>ans;
		}
		if(ans=="USER")
		{
			Account a;
			userMenu();
			A1.save_usertodata(usercount);
			A1.saving_usersadmin(usercount);
			usercount++;
		}
		if(ans=="ADMIN")
		{
			
			readuserstodisplay("AdminUserData.txt");
			Account b;
			adminMenu();
		}
	//	displayrrr();
	//	displayMap();
	}
	
};//End of RecommenderApp class;

int main()
{
	Recommender R;
	R.Apprun();  //Admin/User only runs the App();
	return 0;
}