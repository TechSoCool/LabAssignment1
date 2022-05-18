// Sterling Gerard
// 2/25/22
//Objective: This program is going to use three arrays to store students' names, test scores and average
// for each student. The program will read and store students' grade in two arrays, calculate average
// and output the results. I will also output the average.

#include <iostream> // preprocessor directive for cout object 
#include <string>   // preprocessor directive for reading string of characters 
#include <fstream>  // Preprocessor directive for file
#include <iomanip>  // Preprocessor directive to manage format of output

using namespace std;
#define MAX_SIZE 5
// Global variables
ifstream inname, ingrade;
ofstream output;

int const row = 5;  // num of rows
int const col = 6;  // num of columns


//+++++++++++Definition of Read Function++++++++++++++
void read_data(string studentsName[row], double studentsGrades[row][col])
{
	inname.open("Names.txt");
	ingrade.open("Grades.txt");

	int r; // loop control variable for rows
	int c; // loop control variable for col
		   // loop to read all 5 or as many names and grades in the array in your files

	for (r = 0; r < row; r++) {
		getline(inname, studentsName[r]); // Read name and stores them in array of studentsName array
		for (c = 0; c < col; c++)
			ingrade >> studentsGrades[r][c]; // Read grades and stores them in array of your flies
	}

}

//================================Definition of Display function =========== 
void display_data(string studentsName[row], double studentsGrade[row][col], double sumGrades[row], double averageGrades[row], char createletter[row])
{
	int r;  // Loop control variable
	int c;  // Loop control variable
			// loop to read all 5 or as many names and grades in the array of your files

	output << "   Name						Total	Average	    Grades	" << endl;
	output << " +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	for (r = 0; r < row; r++)
	{

		output << fixed << showpoint << setprecision(2);
		output << left << setw(20) << studentsName[r];

		for (c = 0; c < col; c++)
		{
			output << right << setw(7) << studentsGrade[r][c] << setw(8) << sumGrades[r] << setw(8) << averageGrades[r] << setw(8) << createletter[r] << endl;
		}


		// cout << right << setw(8) << " The sum is: " << sumGrades[r] << right << setw(8) << " The average is: " << averageGrades[r] << setw(20) << createletter[r] << endl;
			 // Read grades and stores them in array of studentsGrade array
	}

}

void sum(double studentGrades[row][col], double sumGrades[row])//calculate sum of students' grades
{
	int r;
	int c;

	for (r = 0; r < row; r++)
		for (c = 0; c < col; c++)
			sumGrades[r] = studentGrades[r][c] + sumGrades[r];

}

void average(double sumGrades[row], double averageGrades[row]) // calculate average of students' grades
{
	int r;


	for (r = 0; r < row; r++)
		averageGrades[r] = (sumGrades[r]) / static_cast <double> (col);

}

void createletter(double averageGrades[row], char letter[row]) // calculate lettter grade for students' grade
{
	int r;

	for (r = 0; r < row; r++)
	{
		if (averageGrades[r] >= 90)
			letter[r] = 'A';
		else if (averageGrades[r] >= 80)
			letter[r] = 'B';
		else if (averageGrades[r] >= 70)
			letter[r] = 'C';
		else if (averageGrades[r] >= 60)
			letter[r] = 'D';
		else
			letter[r] = 'F';
	}
}

void swapname(string& xp, string& yp) // function to swap name
{
	string temp = xp;
	xp = yp;
	yp = temp;

}
void swapsum(double& xp, double& yp) // function to swap sum
{
	double temp = xp;
	xp = yp;
	yp = temp;


}
void swapaverage(double& xp, double& yp) // function to swap average
{
	double temp = xp;
	xp = yp;
	yp = temp;

}
void swapletter(char& xp, char& yp) // function to swap letter 
{
	char temp = xp;
	xp = yp;
	yp = temp;


}
void swapgrade(double& xp, double& yp) // function to swapp grade
{
	double temp = xp;
	xp = yp;
	yp = temp;


}

void bubblesort(string studentsName[row], double studentGrades[row][col], double sumGrades[row], double averageGrades[row], char letter[row]) // bubble sort algorithm
{

	int c;			//loop control variable to control 
	int fp, np;


	for (fp = 0; fp < row; fp++)
	{
		for (np = 0; np < (row - 1); np++)
		{
			if (letter[np] >= letter[np + 1])
			{
				swapname(studentsName[np], studentsName[np + 1]);
				swapsum(sumGrades[np], sumGrades[np + 1]);
				swapaverage(averageGrades[np], averageGrades[np + 1]);
				swapletter(letter[np], letter[np + 1]);

				for (c = 0; c < col; c++) {
					swapgrade(studentGrades[np][c], studentGrades[np + 1][c]);

				}

			}
		}

	}
}

// Binary Search 
void binary_search(int fn_arr[], int element)
{
	int f = 0, l = MAX_SIZE, mid;

	while (f <= l)
	{
		mid = (f + l) / 2;

		if (fn_arr[mid] == element)
		{
			cout << "\nSearch Element  : " << element << " : Found :  Position : " << mid + 1 << ".\n";
			break;
		}
		else if (fn_arr[mid] < element)
			f = mid + 1;
		else
			l = mid - 1;
	}

	if (f > l)
		cout << "\nSearch Element : " << element << "  : Not Found \n";
}

//+++++++++++++++++++++++++++++++++++++++++++Main Program+++++++++++++++++++++++++++++++++++++++
int main()
{

	// open output file
	output.open("Result.txt", ios::app);

	double grade[row][col] = { {0.0}, {0.0} }; // Declaration of arguments
	string name[row] = {};
	double sumGrades[row] = { 0.0 };
	double averageGrades[row] = { 0.0 };
	char letter[row] = {};


	read_data(name, grade); // calling read function, passing proper arguments
	sum(grade, sumGrades);	// calling function sum
	average(sumGrades, averageGrades);	// calling function average
	createletter(averageGrades, letter);

	output << " This data is before the bubblesort " << endl;
	display_data(name, grade, sumGrades, averageGrades, letter); // calling display data function

	bubblesort(name, grade, sumGrades, averageGrades, letter);
	output << " This data is after the bubble sort " << endl; // calling bubble sort function 

	int arr_search[MAX_SIZE], i, targetname;

	cout << "Simple C++ Binary Search Example - Array and Functions\n";
	cout << "\nEnter " << MAX_SIZE << " Name for Searching : " << endl;
	for (i = 0; i < MAX_SIZE; i++)
		cin >> arr_search[i];

	cout << "\nYour Data   :";
	for (i = 0; i < MAX_SIZE; i++)
	{
		cout << "\t" << arr_search[i];
	}

	cout << "\nEnter Name to Search : ";
	cin >> targetname;

	display_data(name, grade, sumGrades, averageGrades, letter);



	inname.close(); // close name file
	ingrade.close(); // close grade file
	output.close(); // close output file

	system("pause");
	return 0;
}