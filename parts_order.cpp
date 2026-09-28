/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Jazer E. Ramos Muniz]
 * Lab: 7 - Loops II
 * Description: [ordering parts for an inspection report]
 * Due Date: [Sep 30, 2026]
 */

 #include <iostream>                                      // Provides cin, cout, and endl
#include <iomanip>                                       // Provides fixed and setprecision
using namespace std;                                     // Allows standard-library names without the std:: prefix

int main() {                                             // Starts the program
    int requestCount;                                    // Stores the known number of part requests
    int partChoice;                                      // Stores one menu selection
    int quantity;                                        // Stores the requested quantity for one part
    int validLineCount = 0;                              // Counts requests that have a valid part and quantity
    double unitPrice;                                    // Stores the price selected by the switch
    double lineCost;                                     // Stores the cost of one valid request
    double orderTotal = 0.0;                             // Accumulates all valid line costs
    bool isValidPartChoice;                              // Tracks whether the switch selected a real part

    cout << "Enter number of part requests from 1 to 5: "; // Prompts for the iteration count
    cin >> requestCount;                                 // Reads the first request-count candidate

    // TODO: Validate requestCount with a while loop before processing requests.
    // Keep asking while the count is below 1 or above 5.
    while (requestCount < 1 || requestCount > 5) {
        cout << "Invalid request count. Try again: ";    // Explains why another count is required
        cin >> requestCount;                              // Reads a replacement count
    }                                                     // Ends after a valid count is entered

    // TODO: Write the for loop header that processes request 1 through requestCount.
    for (int request = 1; request <= requestCount; request++) {
        isValidPartChoice = false;                         // Reset the validity flag

        // TODO: Display the three menu options, prompt for partChoice, and read the selection.
        cout << "Menu Options:" << endl;
        cout << "1. Cable Set - $3.25" << endl;
        cout << "2. Fuse Pack - $4.50" << endl;
        cout << "3. Connector Kit - $1.75" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> partChoice;

        // TODO: Use a while loop to ask again while partChoice is below 1 or above 3.
        while (partChoice < 1 || partChoice > 3) {
            cout << "Invalid choice. Please enter a number between 1 and 3: ";
            cin >> partChoice;
        }

        // TODO: Use switch to assign unitPrice and display the selected part.
        // Include case 1, case 2, case 3, and a defensive default case.
        switch (partChoice) {
            case 1:
                unitPrice = 3.25;
                cout << "You selected Cable Set." << endl;
                isValidPartChoice = true;
                break;
            case 2:
                unitPrice = 4.50;
                cout << "You selected Fuse Pack." << endl;
                isValidPartChoice = true;
                break;
            case 3:
                unitPrice = 1.75;
                cout << "You selected Connector Kit." << endl;
                isValidPartChoice = true;
                break;
            default:
                cout << "Invalid part choice." << endl; // Defensive default case
                break;
        }

        // TODO: For a valid part choice, prompt for quantity and use if/else.
        // Accept quantities from 1 to 5 and update lineCost, orderTotal, and validLineCount.
        // Otherwise, report that the request was skipped.
        if (isValidPartChoice) {
            cout << "Enter quantity (1-5): ";
            cin >> quantity;

            if (quantity >= 1 && quantity <= 5) {
                lineCost = unitPrice * quantity;
                orderTotal += lineCost;
                validLineCount++;
                cout << "Line cost: $" << fixed << setprecision(2) << lineCost << endl;
            } else {
                cout << "Invalid quantity. Request skipped." << endl;
            }
        } else {
            cout << "Request skipped due to invalid part choice." << endl;
        }
    }

    cout << fixed << setprecision(2);
    cout << "Valid lines: " << validLineCount << endl;
    cout << "Order total: $" << orderTotal << endl;

    /*
 * Test analysis:
 * 1. [Explain why orderTotal starts at 0.0. : orderTotal starts at 0.0 because this is the initial value that we use as to not input an incorrect value for any part.]
 * 2. [Explain why an invalid part choice asks for another menu selection. : It asks for another part because it was invalid, hence it will ask you to do it again until it is correct.]
 * 3. [Explain why isValidPartChoice is reset during every for iteration. : It is reset to ensure that each iteration starts with a clean state for evaluating the part choice.]
 * 4. [Explain why an invalid quantity does not change validLineCount. : An invalid quantity means the line is not added to the order, so the count remains unchanged.]
 */

 /*
Case 1: requestCount = 2
Inputs: part 1 quantity 2; part 3 quantity 1

1. Initial accumulator: orderTotal = 0.00
2. After each iteration:
   Iteration 1: orderTotal = 6.50
   Iteration 2: orderTotal = 8.25
3. Counter: validLineCount goes from 0 to 1 and from 1 to 2 because
   the quantities are valid. It does not change if the quantity is invalid.
4. Expected final value: validLineCount = 2, orderTotal = 8.25
*/

    return 0;                        
                        // Ends the program successfully
}                                                         // Ends the main function