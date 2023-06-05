/*Program 1:  Test Scores

Write a program that includes an array to hold 16 test scores (either as integers or doubles).

Pass a pointer to the array to a function that will be used to get the test scores from the user.  

After all the scores are entered use another function to sort the array in ascending order (lowest to highest).

A third function should be used to calculate the average of the test scores.

Finally pass the array and average to a function that displays all the scores 
and the average with appropriate labels and spacing.  (That is a total of four (4) functions other than main!)

USE POINTER NOTATION RATHER THAN ARRAY NOTATION WHENEVER POSSIBLE!

INPUT VALIDATION: Do not accept negative numbers for the test scores.

Suggested testing set: six scores of 10 and ten scores of 12 for a total of 180 
should return an average of 11.25 (just 11 if you're using integers).*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath> 
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

void getTestScores(int*, int);
void displayScores(const int*, int);
bool inputverification(int& ptr);
void sortLowtoHigh(int*, int);
void showArray(const int*, int);
void calculateAverage(const int*, int);


int main()
{
    cout << "Hello World!\n";
   
    //test scores array
    const int SIZE = 16;
    int testscore[SIZE];

    //function to receive test scores
    getTestScores(testscore, SIZE);
   
    //sort scores low to high
    sortLowtoHigh(testscore, SIZE);
   
    // show scores both from low to high and the average
    showArray(testscore, SIZE);
    

}

//Pass a pointer to the array to a function that will be used to get the test scores from the user.
void getTestScores(int *testscore, int SIZE)
{
    int valid; 
    int* ptr = nullptr; //ptr

    cout << "Please enter test scores as a percentage: " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        do
        {
            cout << "Score " << (i + 1) << " out of 16: ";
            cin >> testscore[i];
            valid = testscore[i];
            ptr = &valid;

        } while (inputverification(*ptr) == false);
 

    }

}
//INPUT VALIDATION: Do not accept negative numbers for the test scores.
bool inputverification(int& ptr)
{
    if (ptr < 0 || ptr > 100)
    {
        cout << "invalid test score, please enter score between 0 and 100\n";
        return false;
    }
    else
        return true;
}

//for immediate testing
void displayScores(const int *testscore, int SIZE)
{
    cout << "Display scores as entered.\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Score " << (i + 1) << " out of 16: ";
        cout << *(testscore + i) << "%" << endl;

    }
    
}

//use another function to sort the array in ascending order(lowest to highest).
void sortLowtoHigh(int* testscore, int SIZE)
{
    int startScan, minIndex, minValue;

    for (startScan = 0; startScan < (SIZE - 1); startScan++)
    {
        minIndex = startScan;
        minValue = testscore[startScan];

        for (int index = startScan + 1; index < SIZE; index++)
        {
            if (testscore[index] < minValue)
            {
                minValue = testscore[index];
                minIndex = index;
            }
        } // end for

        testscore[minIndex] = testscore[startScan];
        testscore[startScan] = minValue;

    }
 
}

//pass the array and average to a function that displays all the scores
void showArray(const int* testscore, int SIZE)
{
    cout << "Display scores from lowest to highest.\n";
    for (int i = 0; i < SIZE; i++)
    {
        //cout << "Score " << (i + 1) << " out of 16: ";
        cout << *(testscore + i) << "%" << endl;

    }
    calculateAverage(testscore, SIZE);

}

//calculate the average of the test scores.
void calculateAverage(const int* testscore, int SIZE)
{
    cout << "Average score: ";
 
    double sum = 0;
    double average;

    for (int i = 0; i < SIZE; i++)
    {
        
        sum += testscore[i];
        

    }

    average = sum / SIZE;

    cout << average << "%\n";
}