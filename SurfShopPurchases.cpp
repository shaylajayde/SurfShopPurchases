// SurfShopPurchases.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


// Johnny Utah owns a surf shop on the beach called “Point Break Surf Shop”. Johnny sells surfboards in 4 \ 
// sizes: XXXS (6 inches), small (2 meters), medium (3 meters), and large (4 meters). The cost of one XXXS surfboard is $10.00, small surfboard is $175.00, 
// one medium is $190.00, and one large is $200.00.  Write a program that will make the surf shop operational.  
// Your program should allow the user to do the following:

// Buy any surfboard in any size and in any quanity.
// At any time show the total number of surfboards of each size sold.
// At any time show the total money made.

#include <iostream>
// needed to use decimals for total
#include <iomanip>
#include <string>

using namespace std;
// declaring const variables - prices of each surfboard options
const float xsmallPrice = 10.00;
const float smallPrice = 175.00;
const float mediumPrice = 190.00;
const float largePrice = 200.00;
// const ints to get rid of magic numbers for setw()
int introSet = 58;
int introHalf = 5;

// function prototypes to call main function first
void ShowUsage();
void MakePurchase(int&iTotalXsmall, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge);
void DisplayPurchase(const int iTotalXsmall, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge);
void DisplayTotal(const int iTotalXsmall, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge);


// main function
int main()
{

    // introduction print statement
    cout << setw(introSet) << setfill('*') << "" << endl;
    cout << setw(introHalf) << "";
    cout << "Welcome to my Johnny Utah's PointBreak Surf Shop" << setw(5) << "" << endl;
    cout << setw(introSet) << setfill('*') << "" << endl;

    // calling ShowUsage function to print the menu options
    ShowUsage();
    // initializing variables to pass as reference
    int iTotalXsmall = 0;
    int iTotalSmall = 0;
    int iTotalMedium = 0;
    int iTotalLarge = 0;
    // initializing the choice for the menu option
    char choice = '0';
    // allows user to choice the menu option
    while (choice != 'Q')
    {
        // allows user to choice the menu option
        cout << "Please enter selection: ";
        // I tried to use toupper and it wouldn't work for the while statement, only the switch statement. I decided against using
        // a switch statement so ended up just incorporating both upper and lowercase.
        cin >> choice;
        if (choice == 'S' || choice == 's')
            ShowUsage();
        else if (choice == 'P' || choice == 'p')
            MakePurchase(iTotalXsmall, iTotalSmall, iTotalMedium, iTotalLarge);
        else if (choice == 'C' || choice == 'c')
            DisplayPurchase(iTotalXsmall, iTotalSmall, iTotalMedium, iTotalLarge);
        else if (choice == 'T' || choice == 't')
            DisplayTotal(iTotalXsmall, iTotalSmall, iTotalMedium, iTotalLarge);
        else if (choice == 'Q' || choice == 'q')
        {
            cout << "Thank you";
            return 0;
        }
    }
}

// function to show the user how to use the program - base menu of the program
void ShowUsage()
{
    // prints program menu options
    cout << "To show program usage 'S'" << endl;
    cout << "To purchase a surfboard press 'P'" << endl;
    cout << "To display current purchases press 'C'" << endl;
    cout << "To display total amount due press 'T'" << endl;
    cout << "To quit the program press 'Q'" << endl;
    cout << "" << endl;
}


// function to sell surfboards.
void MakePurchase(int& iTotalXsmall, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge)
{
    // declaring variables for quantity and type
    int quantity = 0;
    char type = '0';
    // print statement for user selection
    cout << "Please enter the quantity and type (X=XXXSmall, S=small, M=medium, L=large) of surfboard you would like to purchase: ";
    cin >> quantity >> type;
    cout << "" << endl;
    // switch statement that calculates the total amount of which size purchased
    switch (toupper(type))
    {
    case 'X':
        iTotalXsmall = iTotalXsmall + quantity;
        break;
    case 'S':
        iTotalSmall = iTotalSmall + quantity;
        break;
    case 'M':
        iTotalMedium = iTotalMedium + quantity;
        break;
    case 'L':
        iTotalLarge = iTotalLarge + quantity;
        break;
    }
}

// function to show the number of surfboards of each size sold in the order.
void DisplayPurchase(const int iTotalXsmall, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{

    // displays the number of smalls purchased (if none - doesn't display)
    if (iTotalXsmall != 0)
    {
        cout << "The total number of XXXSmall surfboards is " << iTotalXsmall << endl;
    }
    if (iTotalSmall != 0)
    {
        cout << "The total number of small surfboards is " << iTotalSmall << endl;
    }

    // displays the number of medium purchased (if none - doesn't display)
    if (iTotalMedium != 0) {
        cout << "The total number of medium surfboards is " << iTotalMedium << endl;
    }

    // displays the number of large purchased (if none - doesn't display)
    if (iTotalLarge != 0) {
        cout << "The total number of large surfboards is " << iTotalLarge << endl;
    }

    // this if statement used to print out when there has been no purchases made if all totals are 0
    else if (iTotalXsmall == 0 && iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0)
        cout << "No purchases made yet." << endl;

    cout << "" << endl;
}

// function to display the total amount of money for the order.
void DisplayTotal(const int iTotalXsmall, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{
    //calculates the total amount of the purchases based on consts declared at top of program and the quantity sold
    float xsmallSold = xsmallPrice * iTotalXsmall;
    float smallSold = smallPrice * iTotalSmall;
    float mediumSold = mediumPrice * iTotalMedium;
    float largeSold = largePrice * iTotalLarge;
    float totalSold = xsmallSold + smallSold + mediumSold + largeSold;

    // displays the number of smalls purchased (if none - doesn't display)
    if (iTotalXsmall != 0)
    {
        cout << "The total number of XXXSmall surfboards is " << iTotalXsmall << " at a total of $" << xsmallSold << ".00" << endl;
    }
    if (iTotalSmall != 0)
    {
        cout << "The total number of small surfboards is " << iTotalSmall << " at a total of $" << smallSold << ".00" << endl;
    }

    // displays the number of medium purchased (if none - doesn't display)
    if (iTotalMedium != 0) {
        cout << "The total number of medium surfboards is " << iTotalMedium << " at a total of $" << mediumSold << ".00" << endl;
    }

    // displays the number of large purchased (if none - doesn't display)
    if (iTotalLarge != 0) {
        cout << "The total number of large surfboards is " << iTotalLarge << " at a total of $" << largeSold << ".00" << endl;
    }
    if (iTotalXsmall > 0 || iTotalSmall > 0 || iTotalMedium > 0 || iTotalLarge > 0) {
        cout << "Amount due: $" << totalSold << ".00" << endl;
    }

    // this if statement used to print out when there has been no purchases made if all totals are 0
    else if (iTotalXsmall == 0 && iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0)
    {
        cout << "No purchases made yet." << endl;
    }

    //prints out total number sold and total price of those sold
    // I attempted to use setprecision(2) here, but it was printing out weird values. IE. using test values shown in homework screenshot,
    // the total of medium showed as $5.7e+02 and the total of large showed as $4e+02
    /*else
    {
        cout << "The total number of small surfboards is " << iTotalSmall << " at a total of $" << smallSold << ".00" << endl;
        cout << "The total number of medium surfboards is " << iTotalMedium << " at a total of $" << mediumSold << ".00" << endl;
        cout << "The total number of large surfboards is " << iTotalLarge << " at a total of $"  << largeSold << ".00" << endl;
        cout << "Amount due: $" << totalSold << ".00" << endl;
    }*/
    cout << "" << endl;
}



// CODE THAT DIDN'T WORK
// 
// 
// 
// 
// 
// 
// 
// 
// tried to use this method from page 408 in textbook - kept giving syntax error so I switched to a while loop for main
//do {
//ShowUsage();
//cout << "Enter--" << endl;
//cin >> choice;
//cout << endl;
//switch (toupper(choice))
//{
//case 'S':
//    break;
//case 'P':
//    break;
//case 'C':
//    break;
//case 'T':
//    break;
//case 'Q':
//    break;
//}
//    }

//while (toupper(choice) != 'Q')
// {
// allows user to choice the menu option
//   cout << "Please enter selection: " << endl;
//   cin >> choice;
//   if (choice == 'S')
//      ShowUsage();
//   else if (choice == 'P')
//       MakePurchase(smallQty, medQty, largeQty);
//   else if (choice == 'C')
//      DisplayPurchase(smallQty, medQty, largeQty);
//   else if (choice == 'T')
//       DisplayTotal(smallQty, medQty, largeQty);
// }
//  cout << "Thank you";
//   return 0;

//    cout << "Please enter selection: " << endl;
//    cin >> choice;
//    switch (toupper(choice))
//    {
//    case 'S':
//        ShowUsage();
//        break;
//    case 'P':
//        MakePurchase(smallQty, medQty, largeQty);
//        break;
//    case 'C':
//        DisplayPurchase(smallQty, medQty, largeQty);
//        break;
//    case 'T':
//        DisplayTotal(smallQty, medQty, largeQty);
//        break;
//    case 'Q':
//        cout << "Thank you";
//        return 0;
//        break;
//    }
//}


