#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int Menu();
void AddStudent(string FN);
void DisplayStudentData(string FN);
void DisplayAverageScore(string FN);
void DisplayStudentGrade(string FN);

int main()
{
	const string Filename = "student.dat";
	ifstream InFile;
	ofstream OutFile;
	int c;
	do{
		system("cls");
		c= Menu();
		switch(c)
		{
		case 1 : AddStudent(Filename); break;
		case 2 : DisplayStudentData(Filename); break;
		case 3 : DisplayAverageScore(Filename); break;
		case 4 : DisplayStudentGrade(Filename); break;
		}
	}while(c != 0);
	cout << "Exit program...." << endl;
	return(0);
}

int Menu()
{
	string line(30,'=');
	int Choose;
	cout << "Program Add-Display Student Data\n";
	cout << line << endl;
	cout << ": Main Menu                  :\n";
	cout << line << endl;
	cout << ": 0 - Exit                   :\n";
	cout << ": 1 - Add Student            :\n";
	cout << ": 2 - Display Student Data   :\n";
	cout << ": 3 - Display Average Score  :\n";
	cout << ": 4 - Display Student Grade  :\n";
	cout << line << endl;
	cout << " Enter choose : ";
	cin >> Choose;
	return(Choose);
}

void AddStudent(string FN)
{
	string Id[5], Name[20];
	float score1,score2,score3;
	int n = 0;

	ofstream OutFile(FN.c_str(), ios_base::out | ios_base::app);
	if (OutFile.is_open())
	{
		cout << "\n Add Student \n";
		cout << "Enter ID : ";
		cin >> Id[n] ;
		cout << "Enter Name : ";
		cin >> Name[n] ;
		cout << "Enter Test1 (0-100) : ";
		cin >> score1;
		cout << "Enter Test2 (0-100) : ";
		cin >> score2;
		cout << "Enter Test3 (0-100) : ";
		cin >> score3;
		OutFile << Id[n] << " " << Name[n] << " " << score1 << " " << score2 << " " << score3 << " " << endl;
		cout << endl;
		cout << "Data Student:\n";
		cout << Id[n] << " " << Name[n] << " " << score1 << " " << score2 << " " << score3 << " " << endl;
		OutFile.close();
		cout << "\nSaved already.\n";
		system("pause");
	}
	else
		cout << "File could not opened." << endl;
}

void DisplayStudentData(string FN)
{
	string Id[5], Name[20];
	float score1,score2,score3;
	int n = 0;

	ifstream InFile(FN.c_str(), ios_base::in);
	if (InFile.is_open())
	{
		string line(58,'=');
		int i = 0;
		cout << "\nList Student\n";
		cout << line << endl;
		cout << " No.  Id     Name                  Test1    Test2    Test3\n";
		cout << line << endl;
		InFile >> Id[n] >> Name[n] >> score1 >> score2 >> score3;
		while (!InFile.eof()) {
			i = i + 1;
			cout << right << setw(3) << i << " : ";
			cout << left << setw(6) << Id[n];
			cout << " " << left << setw(21)<< Name[n] ;
			cout << " " << setw(8) << fixed << setprecision(2) << score1;
			cout << " " << setw(8) << setprecision(2) << score2 << " " << setprecision(2) << score3 << endl;
			InFile >> Id[n] >> Name[n] >> score1 >> score2 >> score3;
		}
		cout << line << endl;
		InFile.close();
		system("pause");
	}
	else
		cout << "File could not opened." << endl;
}

void DisplayAverageScore(string FN)
{
	float average = 0.0;
	string Id[5], Name[20];
	float score1,score2,score3;
	int n = 0;
	

	ifstream InFile(FN.c_str(), ios_base::in);
	if (InFile.is_open())
	{
		string line(82,'=');
		int i = 0;
		float avt1 = 0, avt2 = 0,avt3 = 0,avtt = 0;
		cout << "\nDisplay Average Score\n";
		cout << line << endl;
		cout << " No.   Id    Name               Test1(25%)    Test2(25%)   Test3(50%)   Total(100%)\n";
		cout << line << endl;
		InFile >> Id[n] >> Name[n] >> score1 >> score2 >> score3;
		while (!InFile.eof()) {
			i = i + 1;
			cout << right << fixed << setw(3) << i << " : ";
			cout << left << setw(6) << Id[n];
			cout << " " << left << setw(20)<< Name[n] ;
			float sc1 = score1 / 4;
			float sc2 = score2 / 4;
			float sc3 = score3 / 2;
			float avgsc = sc1 + sc2 + sc3;
			cout << " " << setw(13) << fixed << setprecision(2) << sc1;
			cout << " " << setw(12) << setprecision(2) << sc2;
			cout << " " << setw(13) << setprecision(2) << sc3;
			cout << " " << setw(12) << setprecision(2) << avgsc << endl;
			avt1 = avt1 + sc1;
			avt2 = avt2 + sc2;
			avt3 = avt3 + sc3;
			avtt = avtt + avgsc; 


			InFile >> Id[n] >> Name[n] >> score1 >> score2 >> score3;
		}
		cout << line << endl;
		cout << setw(24) << "Average : " << setw(10) << " "  << avt1 / i ;
		cout << setw(9) << " " << avt2 / i << setw(8) << " " << avt3 / i;
		cout << setw(9) << " " << avtt/i << endl;
		cout << line << endl;

		InFile.close();
		system("pause");
	}
	else
		cout << "File could not opened." << endl;
}

void DisplayStudentGrade(string FN)
{
	string Id[5], Name[20];
	float score1,score2,score3;
	int n = 0;

	ifstream InFile(FN.c_str(), ios_base::in);
	if (InFile.is_open())
	{
		string line(46,'=');
		int i = 0;
		cout << "\nReport Student Grade\n";
		cout << line << endl;
		cout << " No.  Id     Name              Total     Grade\n";
		cout << line << endl;
		InFile >> Id[n] >> Name[n] >> score1 >> score2 >> score3;
		while (!InFile.eof()) 
		{
			float sc1 = score1 / 4;
			float sc2 = score2 / 4;
			float sc3 = score3 / 2;
			float avgsc = sc1 + sc2 + sc3;

			i = i + 1;
			cout << right << setw(2) << i << " : ";
			cout << left << setw(2) << Id[n];
			cout << " " << setw(19) << Name[n];
			cout << " " << setw(2) << fixed << setprecision(2) << avgsc << " " ;

			string grade;

			if (avgsc >= 80)
            {
                grade = "A";
            }
			else if (avgsc >= 75)
            {
                grade = "B+";
            }
            else if (avgsc >= 70)
            {
                grade = "B";
            }
			else if (avgsc >= 65)
            {
                grade = "C+";
            }
            else if (avgsc >= 60)
            {
                grade = "C";
            }
			else if (avgsc >= 55)
            {
                grade = "D+";
            }
            else if (avgsc >= 50)
            {
                grade = "D";
            }
            else
            {
                grade = "F";
            }
            cout << right << setw(6) << " " << grade << endl;
			InFile >> Id[n] >> Name[n] >> score1 >> score2 >> score3 ;
		}
		cout << line << endl;
		InFile.close();
		system("pause");
	}
	else
		cout << "File could not opened." << endl;
}