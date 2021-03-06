//This Runs the show 
//Written by Someone at PCC 
//Editid By Vinayaka Patrick Thompson;
//Sources Project1, Project2Description, Project2DriverCode
//https://github.com/caspen/CS260Projects.git

#include "Project2Main.h"


int main()

{

	char fileName[] = "data.dat";

	HouseQueue *housesOnList = new HouseQueue(fileName);

	House house;

	HouseStack *houseInterested = new HouseStack(); // i am probably overusing pointers

	char response;



	cout << "\nthe houses we will visit today:" << endl << endl;

	housesOnList->display();
	
	//start going through the house queue
	house = housesOnList->dequeue();
	while(housesOnList->queueNotEmpty())
	{
		cout << "\nnext house to be visited:" << house << endl;

		cout << "\nWould you like to revisit this house on our way back? (y, n): ";

		cin >> response;

		cin.ignore(100, '\n');
		

		if(response == 'y' || response == 'Y')
		{
			cout << "\nthe house is saved for revisiting" << endl;
			houseInterested->pushHouse (house);
		}
		
		house = housesOnList->dequeue();
	}

	
	delete housesOnList;
	//we are done using house queue

	cout << "\nWe have finished the first round of screening" << endl << endl;
	cout << "\nOn the way back to the office: " << endl << endl;

	//using house stack
	while(houseInterested->stackNotEmpty())

	{
		house = houseInterested->popHouse();

		cout << "\nnext house to be revisited: " << house << endl;
	}



	cout << "\nWe've finished the second round. ready to make an offer? (y, n):";

	cin >> response;
	cin.ignore (100, '\n');

	cout << "\nlet's talk about that in my office. " << endl << endl;



	delete houseInterested;

	return 0;

}
