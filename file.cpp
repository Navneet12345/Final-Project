#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

class student
{
private:
	string name;
	int roll_no;
	char gender;

public:
	void student_Details();
	void display_Student_Details();
};

void student::student_Details()
{
	cout << "Enter student details!!" << endl;
	cout << "NAME: ";
	getline(cin,name);
	cout << endl;
	cout << "ROLL NO: ";
	cin >> roll_no;
	cout << endl;
	cout << "GENDER(M/F): ";
	cin >> gender;
	cout << endl;
}

void student::display_Student_Details()
{
	cout << "*******************************************" << endl;
	cout << "*******************************************" << endl;
	cout << "STUDENT DETAILS:" << endl;
	cout << "NAME: "<< name << endl;
	cout << "ROLL NO: "<< roll_no << endl;
	cout << "GENDER: "<< gender << endl;
}

class Internal_Exam :public student
{
protected:
	int eng, maths, phys, chem, ADS, EVS;

public:
	void getImarks();
	float calcImarks();
	void displayImarksr();
};

void Internal_Exam::displayImarksr()
{
	cout << "*******************************************" << endl;
	cout << "Your external exam marks are: " << endl << endl;
	cout << " ENGLISH: " << eng << " ";
	cout << "  MATHS    : " << maths << endl;
	cout << " PHYSICS: " << phys << " ";
	cout << "  CHEMISTRY: " << chem << endl;
	cout << " ADS    : " << ADS << " ";
	cout << "  EVS      : " << EVS << endl << endl;
	cout << "Total marks in internals: " << calcImarks() << "%" << endl;
}

void Internal_Exam::getImarks()
{
	cout << "Enter the marks of English in internals: ";
	cin >> eng;
	cout << endl;
	cout << "Enter the marks of maths in internals: ";
	cin >> maths;
	cout << endl;
	cout << "Enter the marks of physics in internals: ";
	cin >> phys;
	cout << endl;
	cout << "Enter the marks of Chemistry in internals: ";
	cin >> chem;
	cout << endl;
	cout << "Enter the marks of ADS in internals: ";
	cin >> ADS;
	cout << endl;
	cout << "Enter the marks of EVS in internals: ";
	cin >> EVS;
	cout << endl;
}

float Internal_Exam::calcImarks()
{
	float res;
	res = eng + maths + phys + chem + ADS + EVS;
	res = res / 6;
	return res;
}

class External_Exam :public student
{
protected:
	int eng, maths, phys, chem, ADS, EVS;

public:
	void getEmarks();
	float calcEmarks();
	void displayEmarkse();
};

void External_Exam::displayEmarkse()
{
	cout << "*******************************************" << endl;
	cout << "Your external exam marks are: " << endl << endl;
	cout << " ENGLISH: " << eng << " ";
	cout << "  MATHS    : " << maths << endl;
	cout << " PHYSICS: " << phys << " ";
	cout << "  CHEMISTRY: " << chem << endl;
	cout << " ADS    : " << ADS << " ";
	cout << "  EVS      : " << EVS << endl << endl;
	cout << "Total marks in externals: " << calcEmarks() << "%" << endl;
	cout << "*******************************************" << endl;
}

void External_Exam::getEmarks()
{
	cout << "Enter the marks of English in externals: ";
	cin >> eng;
	cout << endl;
	cout << "Enter the marks of maths in externals: ";
	cin >> maths;
	cout << endl;
	cout << "Enter the marks of physics in externals: ";
	cin >> phys;
	cout << endl;
	cout << "Enter the marks of Chemistry in externals: ";
	cin >> chem;
	cout << endl;
	cout << "Enter the marks of ADS in externals: ";
	cin >> ADS;
	cout << endl;
	cout << "Enter the marks of EVS in externals: ";
	cin >> EVS;
	cout << endl;
}

float External_Exam::calcEmarks()
{
	float res2;
	res2 = eng + maths + phys + chem + ADS + EVS;
	res2 = res2 / 6;
	return res2;
}

class result :public Internal_Exam, public External_Exam
{
private:
	float f_result;

public:
	float calc_fresult(float, float);
	void dis_fresult(float,float);
};

float result::calc_fresult(float internal, float external)
{
	f_result = (internal * 0.4 ) + (external * 0.6);
	return f_result;
}

 void result::dis_fresult(float internal, float external)
{
	cout << "Your internal total result: ";
	cout << internal << "%" << endl;
	cout << "Your external total result: ";
	cout << external << "%" << endl;
	cout << "Your total result: ";
	cout << f_result << "%" << endl;
	cout << "*******************************************" << endl;
	cout << "*******************************************" << endl;
}


int main()
{
	float internal, external;
	student main_object;
	Internal_Exam int_object;
	External_Exam ext_object;
	result final_object;

	main_object.student_Details();
	int_object.getImarks();

	internal = int_object.calcImarks();

	ext_object.getEmarks();

	external = ext_object.calcEmarks();
	
	main_object.display_Student_Details();
	
	int_object.displayImarksr();
	ext_object.displayEmarkse();
	
	final_object.calc_fresult(internal,external);
	final_object.dis_fresult(internal,external);

	getch();
	return 0;
}

