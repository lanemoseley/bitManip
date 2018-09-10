/** ***************************************************************************
 * Author: Lane Moseley
 * Date:   09/09/2018
 *
 * Description: This program demonstrates the use of bitwise operators.
 *              With the use of a bit mask and bit shifting it prints a binary
 *              number entered by the user to the screen.
 *****************************************************************************/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Prototype
void printBinary ( int x );


int main()
{
    int userVal;
    
    cout << "Enter <ctrl>-z to terminate input." << endl;
    
    cout << "Enter an integer number: ";
    
    while ( cin >> userVal )
    {
        printBinary ( userVal );
        
        cout << "\nEnter an integer number: ";
    }
    
    return 0;
}

void printBinary ( int x )
{
    int i;
    int increment;
    int spaceCount = 0;
    int mask = 1;
    bool a = false;
    
    increment = int ( log2 ( x ) );
    
    if ( increment < 8 )
    {
        increment = 8;
    }
    
    while ( !a )
    {
        if ( increment % 4 == 0 )
        {
            increment -= 1;
            a = true;
        }
        
        else
        {
            ++increment;
        }
    }
    
    mask = mask << increment;
    
    for ( i = 0; i < increment + 1; ++i )
    {
        if ( x & mask )
        {
            cout << "1";
        }
        
        else
        {
            cout << "0";
        }
        
        ++spaceCount;
        
        if ( spaceCount == 4 )
        {
            cout << " ";
            spaceCount = 0;
        }
        
        mask = mask >> 1;
    }
    
    
    return;
}