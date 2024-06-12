#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
# define restaurantcount 150
  
using namespace std;
class restaurant {
public:
    string name;
    string cuisine;
    string address;

    float rating;
    int price;


    int ambiance;
    bool vegan;
    bool drivethru;
    
    int numreviews;
	float distancefromuser;
};
vector<restaurant> restaurants;
void generate_restaurants()  //
{
	restaurant r;
	for(int i=0;i<restaurantcount; i++)
	{
		r.name = "Resaurant #" + to_string(i+1);
		r.cuisine = "Cuisine #" + to_string(i%5+1);
		r.address = "Karachi, Street #" + to_string(i%5+1); 
		r.rating = (rand()%50 +1) *0.1;
		r.ambiance = rand()%3+1;
		r.price = rand()%3+1;
		
		r.vegan =	rand()%2==0;
		r.drivethru= rand()%2==0;
		r.numreviews = rand()%100+1;
		float distance = (rand()%200 +1)*0.1f;
		r.distancefromuser = distance;
 		
		
		restaurants.push_back(r);
	}
}

void writetofile()
{
	ofstream outputfile("RestaurantsList.txt");
	if(outputfile.is_open())
	{
		for(const auto& r: restaurants)
		{
			outputfile << r.name <<endl;
			outputfile << r.address <<endl;
			outputfile << r.cuisine <<endl;
			outputfile << r.rating <<endl;
			outputfile << r.price <<endl;
			outputfile << r.distancefromuser <<endl;
			outputfile << r.ambiance <<endl;
			outputfile <<  (r.vegan ? "Yes":"No") <<endl;
			outputfile <<  (r.drivethru ? "Yes":"No") <<endl;
			outputfile << r.numreviews<<endl;
			outputfile << "---------------------------"<<endl;
		}
			
			outputfile.close();
	}
	else
	{
		cout<<"\nError Opening File ";
	}
}
int main()
{
	generate_restaurants();
	writetofile();
}