/** ***************************************************************************
 * Author: Lane Moseley
 * Date:   09/09/2018
 *
 * Description: This program demonstrates the use of bitwise operators.
 *              Using bitwise operators it will compress and extract a date
 *              entered by the user.
 *****************************************************************************/
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

// Prototypes
int compressDate ( int m, int d, int y );
void extractDate ( int date, int &m, int &d, int &y );


int main()
{
    bool cont = false;
    char choice = 'z';
    
    int day, month, year, date;
    int extD, extM, extY;
    
    // Getting user input
    cout << "Bitwise Date Compressor and Extractor" << endl << endl;
    
    do
    {
        cout << "Enter the month (mm, 1-12): ";
        cin >> month;
        cout << "Enter the day (dd, 1-31): ";
        cin >> day;
        cout << "Enter the year (yyyy, 0-3000): ";
        cin >> year;
        
        cout << "\nDate entered (mm/dd/yyyy): " << month << "-" << day << "-"
             << year << endl << endl;
             
        // Compressing date and display
        date = compressDate ( month, day, year );
        cout << "Date compressed as an integer: " << date << endl << endl;
        
        // Extract date and display
        extractDate ( date, extM, extD, extY );
        cout << "Extracted Month: " << extM << endl;
        cout << setw ( 17 ) << "Day: " << extD << endl;
        cout << setw ( 17 ) << "Year: " << extY << endl << endl;
        
        // Prompt user to continue or end
        cont = false;
        cout << "Would you like to enter another date (y/n)?";
        cin >> choice;
        cout << endl;
        
        if ( toupper ( choice ) == 'Y' )
        {
            cont = true;
        }
        
    }
    while ( cont );
    
    
    return 0;
}

int compressDate ( int m, int d, int y )
{
    // Variables
    int date;
    
    // Compressing date
    date = y;
    date = date << 4;
    date = date | m;
    date = date << 6;
    date = date | d;
    
    return date;
}

void extractDate ( int date, int &m, int &d, int &y )
{
    // Variables
    int dayMask = 63;
    int monthMask = 15;
    int yearMask = 4095;
    
    
    // Shifting masks
    monthMask = monthMask << 6;
    yearMask = yearMask << 10;
    
    // Retrieving date
    d = date & dayMask;
    m = date & monthMask;
    m = m >> 6;
    y = date & yearMask;
    y = y >> 10;
    
    return;
}