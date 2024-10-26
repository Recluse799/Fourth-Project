// Fourth Project.cpp : This file contains the 'main' function. Program execution begins and ends there. two branches, one parallel
// one structs
//
// 
/*  Immanuel Braxton
//  5//7/24
// Arrays and Structs Project I.cpp : This file contains the 'main' function. Program execution begins and ends there. Parallel 
version.
// Function prototypes
////void calculateTotalsAndAverage(const string runners[], const double mil[][NUM_DAYS], int numRunners, int total[], double average[]);
//void outputResults(const string runners[], const int miles[][NUM_DAYS], int numRunners, const int total[], const double average[]);
//// Function prototypes
//Precondition - expects reference to names array and run time for each day, all are empty, has maxium capactiy of rows)
//Post conditon- return actual number of files, and store the data in the arrays in memory);;

*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_Runners = 45;  //rows of data
const int NUM_DAYS = 7;  // times columns for 7 days

const string filename = "marathon_data.txt";  //File containing the marathon data

struct MarRunner
{
    string name; //runner name
    int MilesRun[NUM_DAYS]; // Array for miles run each day
    int TotalMiles; // total miles ran calculated
    float AverageMiles; // average miles run calculated

};

//Precondition -  expects file to be available,  reads data input file 
//Postconditon- returing number of data on file and places it into memory
//only allows a specified amount of rows to be read from file
int getData(MarRunner runners[], int MAX_Runners);

//Precondition -  receives Miles two dimensiional array, and amout of runners/records,make const don't want to change
//Postconditon- cal total, returing and give location for avg miles for ea,actual number of records
void AvgMiles(MarRunner runners[], int numRecord);

//Precondition -  receives names of runners, two dimensiional array, output of total and avg miles, and amout of records
//Postconditon- output results displaying the runner, miles run, total and avg miles in proper format for each runner.
void outputResults(const MarRunner runners[], int numRec);


int main()
{

    MarRunner runners[MAX_Runners]; // Array of structs

    int numRecords;//keep track of the number of records read


    numRecords = getData(runners, MAX_Runners);

   // cout << " " << endl; 
    cout << "numRecords = " << numRecords << endl;

    for (int i = 0; i < numRecords; i++)
    {
        cout << runners[i].name << " ";
        for (int j = 0; j < NUM_DAYS; j++)
            cout << runners[i].MilesRun[j] << " ";

        cout << endl;
    }
    AvgMiles(runners, numRecords); 
    outputResults(runners, numRecords);


    return 0;
}



int getData(MarRunner runners[], int MAX_Runners)
{
    ifstream inFile;
    
    inFile.open(filename);
    if (!inFile.is_open())
    {
        cout << "Error opening file\n";
        return -1;
    }

    int row = 0;

    while (inFile >> runners[row].name && row < MAX_Runners)
    {
        cout << row << " " << runners[row].name << " " << endl;

        for (int i = 0; i < NUM_DAYS; i++)
        {
           if (!(inFile >> runners[row].MilesRun[i])) // Check for successful read
           {        
               cout << "\nError reading data for " << runners[row].name << endl;
               return row;                                     // Return number of successfully read rows
           }
            cout << runners[row].MilesRun[i] << " "; 
            
        }
        cout << endl;
        row++;

        cout << "row = " << row << " " << endl;

    }
    inFile.close();
    return row;
}

void AvgMiles(MarRunner runners[], int numRecord) // int total[], double avg[])
{


    for (int i = 0; i < numRecord; i++)
    {
        runners[i].TotalMiles = 0;

        for (int j = 0; j < NUM_DAYS; j++)
        {
            runners[i].TotalMiles += runners[i].MilesRun[j];
        }

        runners[i].AverageMiles = static_cast<float>(runners[i].TotalMiles) / NUM_DAYS; //( int total = sum; average = sum/7)


    }
}

void outputResults(const MarRunner runners[], int numRec) // const int total, const double average) 
{
    cout << endl;
    cout << endl;
    cout << setw(14) << "Name" << setw(6) << "Mon" << setw(6) << "Tue" << setw(6) << "Wed" << setw(6) << "Thu" << setw(6) << "Fri" << setw(6) << "Sat" << setw(6) << "Sun" << setw(8) << "Total" << setw(8) << "Avg" << endl;

    for (int i = 0; i < numRec; i++)
    {
        cout << setw(3) << i << " " << setw(10) << runners[i].name;
        
        for (int j = 0; j < NUM_DAYS; j++)
        {
            cout << setw(6) << runners[i].MilesRun[j];
        }

        cout << setw(8) << runners[i].TotalMiles;
        cout << setw(8) << fixed << setprecision(2) << runners[i].AverageMiles << endl;
    }
}
