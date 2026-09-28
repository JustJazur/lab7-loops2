/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Jazer E. Ramos Muniz]
 * Lab: 7 - Loops II
 * Description: [generating an inspection report]
 * Due Date: [Sep 30, 2026]
 */

 #include <iostream>                                      // Provides cin, cout, and endl
#include <iomanip>                                       // Provides fixed and setprecision
using namespace std;                                     // Allows standard-library names without the std:: prefix

int main() {                                             // Starts the program
    int deviceCount;                                     // Stores the known number of devices in the batch
    int passingDeviceCount = 0;                          // Counts devices with a passing quality score
    double qualityScore;                                 // Stores one device score per iteration
    double totalScore = 0.0;                             // Accumulates all quality scores

    cout << "Enter number of devices from 1 to 10: ";  // Prompts for the batch size
    cin >> deviceCount;                                  // Reads the first batch-size candidate

    while (deviceCount < 1 || deviceCount > 10) {        // Repeats while the batch size is outside the allowed range
        cout << "Invalid device count. Try again: ";    // Explains why another batch size is required
        cin >> deviceCount;                              // Reads a replacement batch size
    }                                                     // Ends after a valid batch size is entered

    // TODO: Process each device with a for loop and update the total and counter.
    for (int device = 1; device <= deviceCount; device++) { // Repeats once for each requested device
        cout << "Enter quality score for device " << device << ": "; // Identifies the current device in the prompt
        cin >> qualityScore;                              // Reads one quality score for this iteration
        totalScore += qualityScore;                       // Adds this score to the running total

        if (qualityScore >= 70.0) {                       // Checks whether the score is passing
            passingDeviceCount++;                         // Counts one passing device
            cout << "Device passes inspection." << endl;  // Reports the passing result
        } else {                                          // Handles a failing score
            cout << "Device fails inspection." << endl;   // Reports the failing result
        }                                                 // Ends the selection structure
    }
   
    double averageScore = totalScore / deviceCount;     // Calculates the average score
    cout << fixed << setprecision(2);                    // Formats displayed decimal values with two places
    cout << "Total score: " << totalScore << endl;     // Displays the accumulated score total
    cout << "Average score: " << averageScore << endl; // Displays the calculated average
    cout << "Passing devices: " << passingDeviceCount << endl; // Displays the passing device count


/*
 * Analysis:
 * 1. [Explain why totalScore starts at 0.0.: totalScore starts at 0 because this is the initial value that we use as to not input an incorrect value for any device.]
 * 2. [Explain why passingDeviceCount changes for 70 but not for 69.: in the loop we made it so that anything below 70 is not a passing score.]
 * 3. [Explain why averageScore is calculated after the for loop. : that is because we need all the variables to even get the average score, it is calculated after the loop is done.]
 */

 /*
Case 1: deviceCount = 3
Inputs: scores 80.0, 65.0, 70.0

1. Initial accumulator: totalScore = 0.00
2. After each iteration:
   Iteration 1: totalScore = 80.00
   Iteration 2: totalScore = 145.00
   Iteration 3: totalScore = 215.00
3. Counter: passingDeviceCount goes from 0 to 1 on iteration 1 (80 >= 70).
   It does not change on iteration 2 (65 < 70).
   It goes from 1 to 2 on iteration 3 (70 >= 70).
4. Expected final values: passingDeviceCount = 2, totalScore = 215.00,
   average = 215.00 / 3 = 71.67
   Expected output:
     Total devices inspected: 3
     Devices passing inspection: 2
     Average quality score: 71.67
*/

    return 0;                                            // Ends the program successfully
}                                                         // Ends the main function