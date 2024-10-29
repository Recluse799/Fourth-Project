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
    double AverageMiles; // average miles run calculated

};

//Precondition -  expects file to be available,  reads data input file 
//Postconditon- returing number of data on file and places it into memory
//only allows a specified amount of rows to be read from file
int getData(MarRunner runners[], int MAX_Runners);

//Precondition -  receives Miles two dimensiional array, and amout of runners/records,make const don't want to change
//Postconditon- cal total, returing and give location for avg miles for ea,actual number of records
void AvgMiles(MarRunner runners[], int numRecord, double AvgMilesperday[]);

//Precondition -  receives names of runners, two dimensiional array, output of total and avg miles, and amout of records
//Postconditon- output results displaying the runner, miles run, total and avg miles in proper format for each runner.
void outputResults(const MarRunner runners[], int numRec, double AvgMiperday[]);


int main()
{

    MarRunner runners[MAX_Runners]; // Array of structs
    double AverageMilesperday[MAX_Runners];

    int numRecords;//keep track of the number of records read


    numRecords = getData(runners, MAX_Runners);

   // cout << " " << endl; 
   /* cout << "numRecords = " << numRecords << endl;

    for (int i = 0; i < numRecords; i++)
    {
        cout << runners[i].name << " ";
        for (int j = 0; j < NUM_DAYS; j++)
            cout << runners[i].MilesRun[j] << " ";

        cout << endl;
    }*/ 
   
    AvgMiles(runners, numRecords, AverageMilesperday);
    outputResults(runners, numRecords, AverageMilesperday);


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
       // cout << row << " " << runners[row].name << " " << endl;

        for (int i = 0; i < NUM_DAYS; i++)
        {
           if (!(inFile >> runners[row].MilesRun[i])) // Check for successful read
           {        
               //cout << "\nError reading data for " << runners[row].name << endl;
               return row;                                     // Return number of successfully read rows
           }
            //cout << runners[row].MilesRun[i] << " "; 
            
        }
        cout << endl;
        row++;

        //cout << "row = " << row << " " << endl;

    }
    inFile.close();
    return row;
}

void AvgMiles(MarRunner runners[], int numRecord, double AvgMilesperday[]) // int total[], double avg[])
{


    for (int i = 0; i < numRecord; i++)
    {
        runners[i].TotalMiles = 0;

        for (int j = 0; j < NUM_DAYS; j++)
        {
            runners[i].TotalMiles += runners[i].MilesRun[j];
        }

        runners[i].AverageMiles = static_cast<double>(runners[i].TotalMiles) / NUM_DAYS; //( int total = sum; average = sum/7)


    }

    for (int j = 0; j < NUM_DAYS; j++)
    {
        int TotMilesperday = 0;

        for (int i = 0; i < numRecord; i++)
        {
            TotMilesperday += runners[i].MilesRun[j];
        }
        AvgMilesperday[j] = static_cast<double> (TotMilesperday / numRecord); //( int total = sum; average = sum/7)
    }
}

void outputResults(const MarRunner runners[], int numRec , double AvgMiperday[]) // const int total, const double average) 
{
    cout << endl;
    cout << endl;
    cout << setw(14) << "Name" << setw(8) << "Mon" << setw(8) << "Tue" << setw(8) << "Wed" << setw(8) << "Thu" << setw(8) << "Fri" << setw(8) << "Sat" << setw(8) << "Sun" << setw(10) << "Total" << setw(10) << "Avg" << endl;

    for (int i = 0; i < numRec; i++)
    {
        cout << setw(3) << i << " " << setw(10) << runners[i].name;
        
        for (int j = 0; j < NUM_DAYS; j++)
        {
            cout << setw(8) << runners[i].MilesRun[j];
        }

        cout << setw(10) << runners[i].TotalMiles;
        cout << setw(10) << fixed << setprecision(2) << runners[i].AverageMiles << endl;
    }

    cout << setw(14) << "Avg Mi/day" << setw(14);


    /// cout << setw(8) << fixed << setprecision(2) << Amile[i] << endl;

    for (int j = 0; j < NUM_DAYS; j++)
    {
        cout << setw(8) << fixed << setprecision(2) << AvgMiperday[j];
    }
    cout << endl;
}
