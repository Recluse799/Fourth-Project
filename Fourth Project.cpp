/* Fourth Project.cpp : This file contains the 'main' function.Program execution begins and ends there.two branches, one parallel
   one structs
  
   
   Immanuel Braxton
   5//7/24
   Desription: This program uses arrays to store and calculate runners distence ran in miles for each day and week,
   then average them for the day and week. Then It will show the miles and average miles ran in the corresponding day or week, to the user.

   Arrays and Structs Project I.cpp : This file contains the 'main' function. Program execution begins and ends there. Parallel 
   version.
   Function prototypes
   void calculateTotalsAndAverage(const string runners[], const double mil[][NUM_DAYS], int numRunners, int total[], double average[]);
   void outputResults(const string runners[], const int miles[][NUM_DAYS], int numRunners, const int total[], const double average[]);
   Function prototypes
   Precondition - expects reference to names array and run time for each day, all are empty, has maxium capactiy of rows)
   Post conditon- return actual number of files, and store the data in the arrays in memory);;

*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_Runners = 45;  //rows of data
const int NUM_DAYS = 7;  // times columns for 7 days

const string filename = "marathon_data.txt";  //File containing the marathon data

//Precondition -  expects file to be available,  reads data input file 
//Postconditon- returing number of data on file and places it into memory
//only allows a specified amount of rows to be read from file
int getData(string Runers[], int MileRun[][NUM_DAYS], int MAX_Runners);

//Precondition -  receives Miles two dimensiional array, and amout of runners/records,make const don't want to change
//Postconditon- cal total, returing and give location for avg miles for ea,actual number of records
void AvgMiles(const int MiRun[][NUM_DAYS], int TotMile[], double AvgMileD [], double AvgMileR[], int numRecord);

//Precondition -  receives names of runners, two dimensiional array, output of total and avg miles, and amout of records
//Postconditon- output results displaying the runner, miles run, total and avg miles in proper format for each runner.
void outputResults(string Runer[], const int MiRn[][NUM_DAYS], int TMile[], double AmileD[], double AmileR[], int numRec);


int main()
{

    string Runners[MAX_Runners];
    int MilesRun[MAX_Runners][NUM_DAYS];
    int Totalmiles[MAX_Runners];
    double AveragemilesD[MAX_Runners];
    double AveragemilesR[NUM_DAYS];

    int numRecords;//keep track of the number of records read


    numRecords = getData(Runners,MilesRun, MAX_Runners);

    /*cout << " " << endl;  // used as a checkpoint
    cout << "numRecords = " << numRecords << endl;

    for (int i = 0; i < numRecords; i++)
    {
        cout << Runners[i] << " ";
        for (int j = 0; j < NUM_DAYS; j++)
            cout << MilesRun[i][j] << " ";

        cout << endl;
    }*/
    AvgMiles(MilesRun,Totalmiles, AveragemilesD, AveragemilesR, numRecords);
    outputResults(Runners, MilesRun, Totalmiles, AveragemilesD, AveragemilesR, numRecords);


    return 0;
}



int getData(string Runers[], int MileRun[][NUM_DAYS], int MAX_Runners)
{
    ifstream inFile;
    int row = 0;
    inFile.open(filename);
    if (!inFile.is_open())
    {
        cout << "Error opening file\n";
        return -1;
    }

    inFile >> Runers[row];

    while (!inFile.eof() && !(row >= MAX_Runners))
    {
        //cout << row << " " << Runers[row] << " " << endl; check point

        for (int i = 0; i < NUM_DAYS; i++)
        {
            inFile >> MileRun[row][i];
            //cout << MileRun[row][i] << " ";
        }
        //cout << endl;
        row++;
       // cout << "row = " << row << " " << endl;
        inFile >> Runers[row];//which means row +1 because starts at 0

    }
    inFile.close();
    return row;
}

void AvgMiles(const int MiRun[][NUM_DAYS], int TotMile[], double AvgMileD[], double AvgMileR[], int numRecord) // int total[], double avg[])
{

    double sum;


    for (int i = 0; i < numRecord; i++)
    {
        sum = 0;
        for (int j = 0; j < NUM_DAYS; j++)
        {
            sum += MiRun[i][j];
        }
        TotMile[i] = sum; //( int total = sum)

        AvgMileR[i] = sum / (NUM_DAYS); //per runner
    }

    for (int j = 0; j < NUM_DAYS; j++)
    {
        sum = 0;
        for (int i = 0; i < numRecord; i++)
        {
            sum += MiRun[i][j];
        }
        AvgMileD[j] = sum / (numRecord); //(  average = per day



    }
}

void outputResults(string Runer[], const int MiRn[][NUM_DAYS], int TMile[], double AmileD[], double AmileR[], int numRec) // const int total[], const double average[]) 
{
    cout << endl;
    cout << endl;
    cout << setw(14) << "Name" << setw(8) << "Mon" << setw(8) << "Tue" << setw(8) << "Wed" << setw(8) << "Thu" << setw(8) << "Fri" << setw(8) << "Sat" << setw(8) << "Sun" << setw(10) << "Total" << setw(10) << "Avg/Run" << endl;

    for (int i = 0; i < numRec; i++)
    {
        cout << setw(3) << i << " " << setw(10) << Runer[i];
        
        for (int j = 0; j < NUM_DAYS; j++)
        {
            cout << setw(8) << MiRn[i][j];
        }

        cout << setw(10) << TMile[i];
        cout << setw(10) << fixed << setprecision(2) << AmileR[i] << endl;
    }
    cout << setw(14) << "Avg Mi/day" << setw(6);

   
   /// cout << setw(8) << fixed << setprecision(2) << Amile[i] << endl;
   
   for (int i = 0; i < NUM_DAYS; i++)
    {
        cout << setw(8) << fixed << setprecision(2) << AmileD[i];   
    }
   cout << endl;
}
