#include <iostream>
#include <string>
#include "BoxOffice.h"
using namespace std;



BoxOffice::BoxOffice() {};
BoxOffice::~BoxOffice() {};

//add theaters to the system by their unique id number.
void BoxOffice::addTheater(int theaterId, string movieName, int numRows, int numSeatsPerRow)
{
    bool check = true;

    //check for the existence of specified id
    for(int i = 0; i < size1; i++)
    {
        if (tID[i] == theaterId)
        {
            cout << "Theater " << theaterId << " already exists." << endl;
            check = false;
        }
    }

    if(check)
    {
        //arrays for storing the information about theaters

        //tID hold theater ID's
        tID[size1] = theaterId;
        //name hold movie names
        name[size1] = movieName;
        //rows hold number of rows of the theater
        rows[size1] = numRows;
        //seatsPerRow hold number of seats per row
        seatsPerRow[size1] = numSeatsPerRow;
        size1++;

        cout << "Theater " << theaterId << " (" << movieName << ")" << " has been added." << endl;

        //temp arrays for protecting the data and deallocating the memory
        string *temp = new string[size1+1];
        for(int i=0; i < size1; i++)
            temp[i]=name[i];
        delete [] name;
        name = temp;

        int *temp2 = new int[size1+1];
        for(int i=0; i < size1; i++)
            temp2[i]=tID[i];
        delete [] tID;
        tID = temp2;

        temp2 = new int[size1+1];
        for(int i=0; i < size1; i++)
            temp2[i]=rows[i];
        delete [] rows;
        rows = temp2;

        temp2 = new int[size1+1];
        for(int i=0; i < size1; i++)
            temp2[i]=seatsPerRow[i];
        delete [] seatsPerRow;
        seatsPerRow = temp2;
    }
}

//removes specified theaters from the system
void BoxOffice::removeTheater (int theaterId)
{
    bool check = false;
    for(int i = 0; i < size1; i++)
    {
        //check for the existence of specified theater
        if (tID[i] == theaterId)
        {
            check = true;
            //is specified theater exists, than removes that theaters from the arrays
            for(int k=i; k < size1-1; k++ )
            {
                tID[k] = tID[k+1];
                name[k] = name[k+1];
                rows[k] = rows[k+1];
                seatsPerRow[k] = seatsPerRow[k+1];
            }

            //temp arrays for deallocating the memory
            int *temp = new int[size1-1];
            for(int i=0; i < size1-1; i++)
                temp[i]=tID[i];

            delete [] tID;
            tID = temp;

            string *temp1 = new string[size1];
            for(int i=0; i < size1-1; i++)
                temp1[i]=name[i];

            delete [] name;
            name = temp1;

            temp = new int[size1-1];
            for(int i=0; i < size1-1; i++)
                temp[i]=rows[i];

            delete [] rows;
            rows = temp;

            temp = new int[size1-1];
            for(int i=0; i < size1-1; i++)
                temp[i]=seatsPerRow[i];

            delete [] seatsPerRow;
            seatsPerRow = temp;
            size1--;
        }
    }

    if(!check)
    {
        cout << "There is no theater with the specified id!" << endl;
    }
}

// show the theaters in the system as a list
void BoxOffice::showAllTheaters()
{
    if (size1 == 0)
    {
        cout << "No movie theaters in the system!" << endl;
    }
    else
    {
        cout << "Theaters currently in the system: " << endl;
        for(int i = 0; i < size1; i++)
        {
            cout << "Theater " << tID[i] << "(" << name[i] << "): " << rows[i]*seatsPerRow[i] << " available seats." << endl ;
        }
    }
}

//show info about the specified theater
void BoxOffice::showTheater(int theaterId)
{
    int j;
    bool check = false;
    int *columnNumbers = new int[20];
    char *rowLetters = new char[20] {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U'};

    for(int i = 0; i < 20; i++)
        columnNumbers[i] = i+1;

    //check for the existence of specified theater
    for(int i = 0; i < size1; i++)
        if(tID[i] == theaterId)
        {
            check = true;
            j = i;
        }

    if(!check)
        cout << "There is no theater with the specified id!" << endl;
    else
    {
        //print the view of the theater
        cout << " ";
        for(int i = 0; i < j-1; i++)
            cout<<" " << columnNumbers[i] << " ";
        cout << endl;
        for(int i = 0; i < rows[j]; i++)
        {
            cout << rowLetters[i];
            for(int k = 0; k < seatsPerRow[j]; k++)
            {

                cout << " o ";

            }

            cout << endl;
        }
    }
    delete [] columnNumbers;
    delete [] rowLetters;
}

int main(){

BoxOffice a;
a.addTheater(32, "fr", 54, 54);
a.addTheater(342, "fra", 454, 154);
a.addTheater(325, "far", 574, 514);

return 0;



}


