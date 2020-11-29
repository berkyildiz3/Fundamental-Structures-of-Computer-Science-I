#include <iostream>
#include <string>

using namespace std;

class BoxOffice {
public:
    BoxOffice();
    ~BoxOffice();
    void addTheater(int theaterId, string movieName, int numRows, int numSeatsPerRow);
    void removeTheater (int theaterId);
    void showAllTheaters();
    void showTheater(int theaterId);
    int makeReservation (int theaterId, int numAudiences, char *seatRow, int *seatCol);
    void cancelReservation(int resCode);
    void showReservation(int resCode);
    void stringDeneme(string abc);

private:
    int size1 = 0;
     int *tID = new int[size1];
     string *name = new string[size1+1]{};
     int *rows = new int[size1];
     int *seatsPerRow = new int[size1];
};
