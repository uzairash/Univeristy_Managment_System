#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string>
#include <time.h>
#include <fstream>
#include <cstring>
#undef max;
using namespace std;



enum  Campuses
{
	LAHORE = 0,
	ISLAMABAD,
	KARACHI
};

enum Department_Names
{
	CS = 0,
	EE,
	BBA,
	MBA,
	MSc,
	MA,
	Accounts
};


//-------------DATE CLASS-------------------
class Date
{
private:
	int Day;
	int Month;
	int Year;
public:
	Date(int, int, int);
	void setDate(int, int, int);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDay();
	int getMonth();
	int getYear();
	void printDate();
};
Date::Date(int Day = 1, int Month = 1, int Year = 1999)
{
	if (Day < 32 && Month < 13 && Year < 2021)
	{
		this->Day = Day;
		this->Month = Month;
		this->Year = Year;
	}
	else
	{
		//If user gives Invalid Values at Initialization
		this->Day = 1;
		this->Month = 1;
		this->Year = 1999;
		cout << "Invalid Date Format. Default Date Set!" << endl;
	}
}
void Date::setDate(int Day = 1, int Month = 1, int Year = 1999)
{
	if (Day < 32 && Month < 13)
	{
		this->Day = Day;
		this->Month = Month;
		this->Year = Year;
	}
	else
	{
		cout << "Invalid Date Format. Date Not Changed!" << endl;
	}
}
void Date::setDay(int Day)
{
	if (Day < 32)
	{
		this->Day = Day;
	}
}
void Date::setMonth(int Month)
{
	if (Month < 13)
	{
		this->Month = Month;
	}
}
void Date::setYear(int Year)
{
	this->Year = Year;
}
int Date::getDay()
{
	return this->Day;
}
int Date::getMonth()
{
	return this->Month;
}
int Date::getYear()
{
	return this->Year;
}
void Date::printDate()
{
	cout << setw(2) << setfill('0') << this->Day << "/" << setw(2) << setfill('0') << this->Month << "/" << this->Year << endl;
}
//:::::::::::::::::::::::::::::::::::::::

//-----------Person Class--------------
class Person
{
protected:
	string Name;
	string Gender;
	string CNIC;
	Date DOB;
public:
	Person();
	Person(string, string, string, Date);

	void Set_Values(string, string, string, Date);
	void Set_Name(string);
	void Set_Gender(string);
	void Set_CNIC(string);
	void Set_DOB_Day(int);
	void Set_DOB_Month(int);
	void Set_DOB_Year(int);
	void Set_DOB(int, int, int);

	string Get_Name();
	string Get_Gender();
	string Get_CNIC();
	int Get_DOB_Day();
	int Get_DOB_Month();
	int Get_DOB_Year();
	Date Get_DOB();

	void Print_DOB();

	void Display_Person();
};

Person::Person()
{
	this->Name = "";
	this->Gender = ' ';
	this->CNIC = "1234-567890-1";
	this->DOB.setDate(1, 1, 1999);
}
Person::Person(string Name, string Gender, string CNIC, Date DOB)
{
	this->Name = Name;
	this->Gender = Gender;
	this->CNIC = CNIC;
	this->DOB = DOB;
}

void Person::Set_Values(string Name, string Gender, string CNIC, Date DOB)
{
	this->Name = Name;
	this->Gender = Gender;
	this->CNIC = CNIC;
	this->DOB = DOB;
}

void Person::Set_Name(string Name)
{
	this->Name = Name;
}
void Person::Set_Gender(string Gender)
{
	this->Gender = Gender;
}
void Person::Set_CNIC(string CNIC)
{
	this->CNIC = CNIC;
}
void Person::Set_DOB_Day(int Day)
{
	this->DOB.setDay(Day);
}
void Person::Set_DOB_Month(int Month)
{
	this->DOB.setMonth(Month);
}
void Person::Set_DOB_Year(int Year)
{
	this->DOB.setYear(Year);
}
void Person::Set_DOB(int Day, int Month, int Year)
{
	if (Day < 32 && Month < 13)
	{
		this->DOB.setDay(Day);
		this->DOB.setMonth(Month);
		this->DOB.setYear(Year);
	}
	else
	{
		cout << "Invalid DOB Format. Date Not Changed!" << endl;
	}
}


string Person::Get_Name()
{
	return this->Name;
}
string Person::Get_Gender()
{
	return this->Gender;
}
string Person::Get_CNIC()
{
	return this->CNIC;
}
int Person::Get_DOB_Day()
{
	return this->DOB.getDay();
}
int Person::Get_DOB_Month()
{
	return this->DOB.getMonth();
}
int Person::Get_DOB_Year()
{
	return this->DOB.getYear();
}
Date Person::Get_DOB()
{
	return DOB;
}

void Person::Print_DOB()
{
	cout << setw(2) << setfill('0') << DOB.getDay() << "/" << setw(2) << setfill('0') << DOB.getMonth() << "/" << DOB.getYear();
}

void Person::Display_Person()
{
	cout << "Name: " << this->Name << endl;
	cout << "Gender: " << this->Gender << endl;
	cout << "CNIC Number: " << this->CNIC << endl;
	cout << "Date of Birth: "; this->DOB.printDate();
}
//:::::::::::::::::::::::::::::::::::::::


//-----------Student Class---------------
class Student :public Person
{
private:
	string Enrollemnt_Number;
	float GPA;
	int Extra_Subjects_Taken;
	bool Fee_paid_status;

	static int Enroll_count;
public:

	Student(float, bool, int, string, string, string, Date);

	void Set_values_To_NULL();
	void Set_GPA(float);
	void Set_Fee_paid_status(bool);
	void Set_Extra_Subjects_Taken(int);
	void Reset_Enroll_count();

	string Get_Enrollemnt_Number();
	float Get_GPA();
	bool Get_Fee_paid_status();
	int Get_Extra_Subjects_Taken();


	bool Is_eligible_for_Scholarship();

	void Display_Student();
};

int Student::Enroll_count = 1;

Student::Student(float GPA = 0.0, bool Fee_paid_status = true, int Extra_Subjects_Taken = 0,
	string Name = "", string Gender = "", string CNIC = "", Date DOB = NULL) :Person(Name, Gender, CNIC, DOB)
{
	this->Enrollemnt_Number = to_string(Enroll_count);
	this->GPA = GPA;
	this->Fee_paid_status = Fee_paid_status;
	this->Extra_Subjects_Taken = Extra_Subjects_Taken;

	this->Enroll_count++;
}

void Student::Set_values_To_NULL()
{
	this->GPA = NULL;
	this->Fee_paid_status = NULL;
	this->Extra_Subjects_Taken = NULL;
	this->Enrollemnt_Number = "";
	this->Name = "";
	this->Gender = "";
	this->CNIC = "";
	this->DOB.setDate(1, 1, 1999);

}

void Student::Set_Extra_Subjects_Taken(int Extra_Subjects_Taken)
{
	this->Extra_Subjects_Taken = Extra_Subjects_Taken;
}
void Student::Set_GPA(float GPA)
{
	if (GPA >= 0 || GPA <= 4)
	{
		this->GPA = GPA;
	}

}
void Student::Set_Fee_paid_status(bool Fee_paid_status)
{
	this->Fee_paid_status = Fee_paid_status;
}
void Student::Reset_Enroll_count()
{
	this->Enroll_count = 1;
}


int Student::Get_Extra_Subjects_Taken()
{
	return this->Extra_Subjects_Taken;
}
string Student::Get_Enrollemnt_Number()
{
	return Enrollemnt_Number;
}

float Student::Get_GPA()
{
	return GPA;
}
bool Student::Get_Fee_paid_status()
{
	return this->Fee_paid_status;
}

bool Student::Is_eligible_for_Scholarship()
{
	return (this->GPA >= 3.5) ? true : false;
}

void Student::Display_Student()
{
	this->Display_Person();
	cout << "Enrollment Number: " << this->Enrollemnt_Number << endl;
	cout << "GPA: " << this->GPA << endl;
	cout << "Extra Classes Taken: " << this->Extra_Subjects_Taken << endl;
	cout << "Fee Status: ";
	if (this->Fee_paid_status)
	{
		cout << "PAID!" << endl;
	}
	else
	{
		cout << "UN-PAID!" << endl;
	}
}
//:::::::::::::::::::::::::::::::::::::::



//----------Employee Class------------
class Employee : public Person
{
protected:
	Department_Names Dpt_Name;
	int Uni_ID;
	int Employee_Grade;
	Date Date_Of_joining;
	float Salary;

	//Static number for keeping track of Employee's ID serial number!
	static int ID_Counter;
public:
	Employee();
	Employee(Department_Names, int, float, Date);
	Employee(string, string, string, Department_Names, int, float, Date, Date);

	void Set_Emp_Values(Department_Names, int, float, Date);
	void Set_Dpt_Name(Department_Names);
	void Set_Employee_Grade(int);
	void Set_Date_Of_joining(Date);
	void Set_Salary(float);

	string Get_Dpt_Name();
	int Get_Uni_ID();
	int Get_Employee_Grade();
	Date Get_Date_Of_joining();
	float Get_Salary();

	int Years_Worked();

	void Display_Emp();
};

int Employee::ID_Counter = 1000;

Employee::Employee()
{
	this->Dpt_Name = CS;
	this->Employee_Grade = 16;
	this->Date_Of_joining.setDate(1, 1, 2010);
	this->Salary = 15000;

	//University Employee ID gets incremented whenever a new Employee is Declared!
	this->Uni_ID = ID_Counter++;
}

Employee::Employee(Department_Names Dpt_Name, int Employee_Grade, float Salary, Date Date_Of_joining) : Person()
{
	this->Dpt_Name = Dpt_Name;
	this->Employee_Grade = Employee_Grade;
	this->Date_Of_joining = Date_Of_joining;
	this->Salary = Salary;

	Uni_ID = ID_Counter++;
}

Employee::Employee(string Name, string Gender, string CNIC, Department_Names Dpt_Name, int Employee_Grade, float Salary, Date DOB, Date Date_Of_joining) : Person(Name, Gender, CNIC, DOB)
{
	this->Dpt_Name = Dpt_Name;
	this->Employee_Grade = Employee_Grade;
	this->Date_Of_joining = Date_Of_joining;
	this->Salary = Salary;

	Uni_ID = ID_Counter++;
}


void Employee::Set_Emp_Values(Department_Names Dpt_Name, int Employee_Grade, float Salary, Date Date_Of_joining)
{
	this->Dpt_Name = Dpt_Name;
	this->Employee_Grade = Employee_Grade;
	this->Date_Of_joining = Date_Of_joining;
	this->Salary = Salary;
}

void Employee::Set_Dpt_Name(Department_Names Dpt_Name)
{
	this->Dpt_Name = Dpt_Name;
}
void Employee::Set_Employee_Grade(int Employee_Grade)
{
	this->Employee_Grade = Employee_Grade;
}
void Employee::Set_Date_Of_joining(Date Date_Of_joining)
{
	this->Date_Of_joining = Date_Of_joining;
}
void Employee::Set_Salary(float Salary)
{
	this->Salary = Salary;
}



string Employee::Get_Dpt_Name()
{
	switch (this->Dpt_Name)
	{
	case 0:
	{
		return "Computer Science.";
	}
	case 1:
	{
		return "Electrical Engineering.";
	}
	case 2:
	{
		return "BBA.";
	}
	case 3:
	{
		return "Accounts.";
	}
	default:
	{
		return "Invalid CASE DEPARTMENT CAMPUS DISPLAY!";
	}
	}

}
int Employee::Get_Uni_ID()
{
	return this->Uni_ID;
}
int Employee::Get_Employee_Grade()
{
	return this->Employee_Grade;
}
Date Employee::Get_Date_Of_joining()
{
	return this->Date_Of_joining;
}
float Employee::Get_Salary()
{
	return this->Salary;
}



int Employee::Years_Worked()
{
	return 2021 - this->Date_Of_joining.getYear();
}

void Employee::Display_Emp()
{
	this->Display_Person();
	cout << "Department Name: " << this->Get_Dpt_Name() << endl;
	cout << "University EMP ID: " << this->Uni_ID << endl;
	cout << "Grade/Rank: " << this->Employee_Grade << endl;
	cout << "Date of Joining: "; this->Date_Of_joining.printDate();
	cout << "Salary: " << this->Salary << endl;
}
//:::::::::::::::::::::::::::::::::::::::


//------------Teacher Class---------------
class Teacher :public Employee
{
private:
	string Qualification;
	int Num_Assigned_section;
public:

	Teacher();
	Teacher(Date, Date, string, string, string, Department_Names, int, string, float, int);

	void Set_Qualification(string);
	void Set_Num_Assigned_section(int);

	string Get_Qualification();
	int Get_Num_Assigned_section();

	void Display_Teacher();
};

Teacher::Teacher()
{
	this->Qualification = "Bachealors";
	this->Num_Assigned_section = 1;
}

Teacher::Teacher(Date DOB, Date Date_Of_joining, string Name = "", string Gender = "", string CNIC = "", Department_Names Dpt_Name = CS,
	int Employee_Grade = 16, string Qualification = "Intermediate", float Salary = 15000, int Num_Assigned_Section = 1) : Employee(Name, Gender, CNIC, Dpt_Name, Employee_Grade, Salary, DOB, Date_Of_joining)
{
	this->Qualification = Qualification;
	this->Num_Assigned_section = Num_Assigned_Section;
}

void Teacher::Set_Qualification(string Qualification)
{
	this->Qualification = Qualification;
}
void Teacher::Set_Num_Assigned_section(int Num_Assigned_Section)
{
	this->Num_Assigned_section = Num_Assigned_Section;
}

string Teacher::Get_Qualification()
{
	return this->Qualification;
}

int Teacher::Get_Num_Assigned_section()
{
	return this->Num_Assigned_section;
}


void Teacher::Display_Teacher()
{
	this->Display_Emp();
	cout << "Qualification: " << this->Qualification << endl;
	cout << "Number of Assigned Sections: " << this->Num_Assigned_section << endl;
}
//:::::::::::::::::::::::::::::::::::::::






//----------Head_Of_Dept Class------------
class Head_Of_Dept :public Employee
{
protected:
	float Bonus_Salary;
public:
	Head_Of_Dept(float);

	void Set_Bonus_Salary(float);

	float Get_Bonus_Salary();

	void Change_Teachers_Salary(Teacher, float);
	void Change_Num_Assigned_section(Teacher, int);
	void Promote_Teacher(Teacher);

};

Head_Of_Dept::Head_Of_Dept(float Bonus_Salary = 10000)
{
	this->Bonus_Salary = Bonus_Salary;
}


void Head_Of_Dept::Set_Bonus_Salary(float Bonus_Salary)
{
	this->Bonus_Salary = Bonus_Salary;
}

float Head_Of_Dept::Get_Bonus_Salary()
{
	return this->Bonus_Salary;
}



void Head_Of_Dept::Change_Teachers_Salary(Teacher Temp_Teacher, float Salary)
{
	Temp_Teacher.Set_Salary(Salary);
}

void Head_Of_Dept::Change_Num_Assigned_section(Teacher Temp_Teacher, int Assign_Sections)
{
	Temp_Teacher.Set_Num_Assigned_section(Assign_Sections);
}

void Head_Of_Dept::Promote_Teacher(Teacher Promoted_Teacher)
{
	Promoted_Teacher.Set_Employee_Grade(Promoted_Teacher.Get_Employee_Grade() + 1); //Taking previous Rank/Grade and Incrementing it by 1
}


//:::::::::::::::::::::::::::::::::::::::

//----------University Class------------
class University
{
private:
	string UniversityName;
	Campuses Uni_Campus; //ENUMERATION OF CAMPUSES CONTAINING ONLY 3 CAMPUS
	string Location;
	string Website;

public:

	University(string, Campuses, string);

	void Set_Values(string, Campuses, string);

	void Set_UniversityName(string);
	void Set_Campus(Campuses);
	void Set_Website(string);



	string Get_UniversityName();
	string Get_Campus();
	string Get_Location();
	string Get_Website();

	void display_Uni();
};

University::University(string UniversityName = "", Campuses Uni_Campus = LAHORE, string Website = "")
{
	this->UniversityName = UniversityName;
	this->Uni_Campus = Uni_Campus;
	this->Website = Website;
	switch (this->Uni_Campus)
	{
	case 0:
	{
		this->Location = "47-C Chaudhry Rehmat Ali Underpass, Civic Centre Block D 2 Phase 1 Johar Town, Lahore.";
		break;
	}
	case 1:
	{
		this->Location = "Shangrilla Rd, E-8/1 ,Islamabad Capital Territory.";
		break;
	}
	case 2:
	{
		this->Location = "13 National Stadium Rd, Karachi.";
		break;
	}
	default:
	{
		cout << "Invalid UNI CAMPUS ADRESS." << endl;
	}
	}
}

void University::Set_Values(string UniversityName, Campuses Uni_Campus, string Website)
{
	this->UniversityName = UniversityName;
	this->Uni_Campus = Uni_Campus;
	this->Website = Website;
}

void University::Set_UniversityName(string UniversityName)
{
	this->UniversityName = UniversityName;
}
void University::Set_Campus(Campuses Uni_Campus)
{
	this->Uni_Campus = Uni_Campus;
}
void University::Set_Website(string Website)
{
	this->Website = Website;
}

string University::Get_UniversityName()
{
	return UniversityName;
}
string University::Get_Campus()
{
	switch (this->Uni_Campus)
	{
	case 0:
	{
		return "Lahore.";
	}
	case 1:
	{
		return "Islamabad.";
	}
	case 2:
	{
		return "Karachi.";
	}
	default:
	{
		return "Invalid CASE UNI CAMPUS DISPLAY!";
	}
	}
}
string University::Get_Location()
{
	return Location;
}
string University::Get_Website()
{
	return Website;
}

void University::display_Uni()
{
	cout << "University Name: " << this->UniversityName << endl;
	cout << "Campus Name : "; this->Get_Campus();
	cout << "University Location: " << this->Location << endl;
	cout << "University Website: " << this->Website << endl;

}
//:::::::::::::::::::::::::::::::::::::::



//-----------Academics_Department Class------------
class Degree_Programs : public University
{
protected:
	Department_Names Department_Name;
	int Semester;
	int Degree_Duraion;
	int Credit_Hours;
	string Enroll_Signature;


public:

	Degree_Programs(Department_Names, int, int, int);

	void Set_Department_Name(Department_Names);
	void Set_Degree_Duration(int);
	void Set_Credit_Hours(int);
	void Set_Semester(int);

	string Get_Department_Name();
	int Get_Degree_Duration();
	int Get_Credit_Hours();
	int Get_Semester();

	void Display_Dep_Data();


	void change_Enroll_Signature();


};


Degree_Programs::Degree_Programs(Department_Names Department_Name = CS, int Degree_Duraion = 0, int Credit_Hours = 0, int Semester = 1)
{
	this->Department_Name = Department_Name;
	this->Degree_Duraion = Degree_Duraion;
	this->Credit_Hours = Credit_Hours;
	this->Semester = Semester;

	this->change_Enroll_Signature();
}

void Degree_Programs::Set_Department_Name(Department_Names Department_Name)
{
	this->Department_Name = Department_Name;
	this->change_Enroll_Signature();
}
void Degree_Programs::Set_Degree_Duration(int Degree_Duration)
{
	this->Degree_Duraion = Degree_Duraion;
}
void Degree_Programs::Set_Credit_Hours(int Credit_Hours)
{
	this->Credit_Hours = Credit_Hours;
}
void Degree_Programs::Set_Semester(int Semester)
{
	this->Semester = Semester;
	this->change_Enroll_Signature();
}


string Degree_Programs::Get_Department_Name()
{
	switch (this->Department_Name)
	{
	case 0:
	{
		return "CS";
	}
	case 1:
	{
		return "EE";
	}
	case 2:
	{
		return "BBA";
	}
	case 3:
	{
		return "MBA";
	}
	case 4:
	{
		return "MSc";
	}
	case 5:
	{
		return "MA";
	}
	default:
	{
		return "Invalid CASE DEPARTMENT CAMPUS DISPLAY!";
	}
	}
}
int Degree_Programs::Get_Degree_Duration()
{
	return this->Degree_Duraion;
}
int Degree_Programs::Get_Credit_Hours()
{
	return this->Credit_Hours;
}
int Degree_Programs::Get_Semester()
{
	return this->Semester;
}


void Degree_Programs::Display_Dep_Data()
{
	cout << "Department Name: " << this->Get_Department_Name() << endl;
	cout << "Semester: " << this->Semester << endl;
	cout << "Degree Duration: " << this->Degree_Duraion << endl;
	cout << "Total Credit Hours: " << this - Credit_Hours << endl;
}


void Degree_Programs::change_Enroll_Signature()
{
	this->Enroll_Signature = to_string(this->Semester) + "-" + this->Get_Department_Name() + "-"; //1-BBA-

}



//*****UNDER GRAD CLASS*****

class Under_Graduate : public Degree_Programs
{
protected:
	string Major;
	string UG_Subjects[6];
	int No_of_Students = 50;
	Student* Student_Batch = new Student[No_of_Students];
	Teacher UG_Teachers[6];
	Head_Of_Dept UG_HOD;


public:
	Under_Graduate(Department_Names, int, int, int);

	void Set_Semester(int);
	void Set_N0_Of_Students(int);
	void set_GPA(int, float);

	int Get_No_Of_Students();

	void Get_File_Data();
	void Set_File_Data();
	void delete_Student_data(int);
	void Admit_New_Student(string, string, Date, float, int, bool);


	int search_Student_by_Enroll(int);
	void Print_By_FeeStatus();
	int Get_no_of_unpaid();
	int search_Student_by_Unpaid();
	void Disp_Single_Student(int);

	void Disp_UG_Top();
	void Display_UG();
};


Under_Graduate::Under_Graduate(Department_Names Department_Name = CS, int Degree_Duraion = 4, int Credit_Hours = 18, int Semester = 1) : Degree_Programs(Department_Name, Degree_Duraion, Credit_Hours, Semester)
{
	if (this->Department_Name == CS)
	{
		this->Major = "Computer Programming";
	}
	else if (this->Department_Name == EE)
	{
		this->Major = "Digital Locic Design";
	}
	else if (this->Department_Name == BBA)
	{
		this->Major = "Accounting and Finance";
	}
	else
	{
		cout << "OUT OF SCOPE UG DPT!" << endl;
	}

	this->UG_Subjects[0] = "Fundamentals of English";
	this->UG_Subjects[1] = "Analytical Geometry";
	this->UG_Subjects[2] = "Applied Physics";
	this->UG_Subjects[3] = "Communication Skills";
	this->UG_Subjects[4] = "Critical Thinking";
	this->UG_Subjects[5] = this->Major;
	if (Semester < 9)
	{
		this->Semester = Semester;
	}
	else
	{
		this->Semester = 1;
	}
	Student_Batch->Reset_Enroll_count();
}


void Under_Graduate::Set_Semester(int Semester)
{
	if (Semester < 9)
	{
		this->Semester = Semester;
		this->change_Enroll_Signature();
	}
}
void Under_Graduate::Set_N0_Of_Students(int No_Of_Students)
{
	this->No_of_Students = No_Of_Students;
}
void Under_Graduate::set_GPA(int enroll, float GPA)
{
	int index = this->search_Student_by_Enroll(enroll);
	this->Student_Batch[index].Set_GPA(GPA);
}

int Under_Graduate::Get_No_Of_Students()
{
	return this->No_of_Students;
}


void Under_Graduate::Disp_UG_Top()
{
	int toper_index = 0;
	int Toppers[3];
	int size = this->No_of_Students;

	for (int loop = 0; loop < 3; loop++)
	{

		for (int index = 0; index < size; index++)
		{
			if (loop != 0 && index == Toppers[loop - 1])
			{
				continue;
			}
			else if (this->Student_Batch[index].Get_GPA() > this->Student_Batch[index + 1].Get_GPA())
			{
				toper_index = index;
			}
		}
		Toppers[loop] = toper_index;
		if (loop == 0)
		{
			cout << "1st Position: ";
		}
		else if (loop == 1)
		{
			cout << "2nd Position: ";
		}
		else
		{
			cout << "3rd Position: ";
		}
		cout << this->Student_Batch[toper_index].Get_Name() << ", GPA: " << this->Student_Batch[toper_index].Get_GPA() << endl;
		size--;
	}
}

void Under_Graduate::Disp_Single_Student(int enroll)
{
	int index = this->search_Student_by_Enroll(enroll);
	if (index != -1)
	{
		cout << "Enroll.\t";
		if (Department_Name == BBA)
		{
			//Just for styling purpose as BBA is 3 lettered so we need an extra tab!
			cout << "\t";
		}
		cout << "Name\t\tDOB\t\tGender\tCNIC Number\tFee\tGPA\tExtra Subjects" << endl;
		int TOintEnroll;
		TOintEnroll = stoi(this->Student_Batch[index].Get_Enrollemnt_Number());
		cout << this->Enroll_Signature << setw(2) << setfill('0') << TOintEnroll << "\t" << this->Student_Batch[index].Get_Name() << "\t";
		this->Student_Batch[index].Print_DOB();

		cout << "\t" << this->Student_Batch[index].Get_Gender() << "\t" << this->Student_Batch[index].Get_CNIC() << "\t";

		if (this->Student_Batch[index].Get_Fee_paid_status())
		{
			cout << "PAID" << "\t";
		}
		else
		{
			cout << "UN-PAID" << "\t";
		}

		cout << this->Student_Batch[index].Get_GPA() << "\t" << this->Student_Batch[index].Get_Extra_Subjects_Taken() << "\t";


		cout << "\n";
	}

}
void Under_Graduate::Display_UG()
{
	cout << "Enroll.\t";
	if (Department_Name == BBA)
	{
		//Just for styling purpose as BBA is 3 lettered so we need an extra tab!
		cout << "\t";
	}
	cout << "Name\t\tDOB\t\tGender\tCNIC Number\tFee\tGPA\tExtra Subjects" << endl;
	int TOintEnroll;
	for (int index = 0; index < No_of_Students; index++)
	{
		TOintEnroll = stoi(this->Student_Batch[index].Get_Enrollemnt_Number());
		cout << this->Enroll_Signature << setw(2) << setfill('0') << TOintEnroll << "\t" << this->Student_Batch[index].Get_Name() << "\t";
		this->Student_Batch[index].Print_DOB();

		cout << "\t" << this->Student_Batch[index].Get_Gender() << "\t" << this->Student_Batch[index].Get_CNIC() << "\t";

		if (this->Student_Batch[index].Get_Fee_paid_status())
		{
			cout << "PAID" << "\t";
		}
		else
		{
			cout << "UN-PAID" << "\t";
		}

		cout << this->Student_Batch[index].Get_GPA() << "\t" << this->Student_Batch[index].Get_Extra_Subjects_Taken() << "\t";


		cout << "\n";
	}
}

void Under_Graduate::Set_File_Data()
{

	srand(time(0));

	string name;

	//Random functions to initialize Data into different files At first Launch! 
	/*if (Department_Name == EE)
	{
		ifstream inFile("Names.txt", ios::in);
		for (int index = 0; index < this->No_of_Students; index++)
		{
			getline(inFile, name, '\n');
			this->Student_Batch[index].Set_Name(name);

		}
		inFile.close();

	}*/
	////for Gender
	//int gen;
	//for (int index = 0; index < this->No_of_Students; index++)
	//{
	//	gen = 0 + rand() % 2;
	//	if (gen == 0)
	//	{
	//		this->Student_Batch[index].Set_Gender("Male");
	//	}
	//	else if (gen == 1)
	//	{
	//		this->Student_Batch[index].Set_Gender("Female");
	//	}
	//}
	////for CNIC
	//gen = 0;
	//
	//for (int index = 0; index < this->No_of_Students; index++)
	//{
	//	name = "";
	//	for (int loop = 0; loop < 15; loop++)
	//	{
	//		gen = 0 + rand() % 10;

	//		if (loop == 5 || loop == 13)
	//		{
	//			name += '-';
	//		}
	//		else
	//		{
	//			name += to_string(gen);
	//		}
	//	}

	//	this->Student_Batch[index].Set_CNIC(name);
	//	
	//}

	////for DOB
	//int day, month, year;

	//for (int index = 0; index < this->No_of_Students; index++)
	//{
	//	day = 1 + rand() % 30;
	//	month = 1 + rand() % 12;

	//	year = 1996 + rand() % 10;
	//	this->Student_Batch[index].Set_DOB(day, month, year);
	//}

	////for GPA
	//float gpa;
	//int first;
	//float last;

	//for (int index = 0; index < this->No_of_Students; index++)
	//{
	//	first = 0 + rand() % 5;
	//	last = (0 + rand() % 10);
	//	last /= 10;
	//	if (first == 4)
	//	{
	//		last = 0;
	//	}
	//	gpa = first + last;
	//	this->Student_Batch[index].Set_GPA(gpa);
	//	
	//}

	//int rand_index;
	//
	//
	////UNPAID
	//for (int i = 0; i < No_of_Students; i++)
	//{
	//	this->Student_Batch[i].Set_Fee_paid_status(true);
	//}
	//for (int i = 0; i < 9; i++)
	//{
	//	rand_index = 0 + rand() % 50;
	//	this->Student_Batch[rand_index].Set_Fee_paid_status(false);
	//}
	//
	//for (int i = 0; i < No_of_Students; i++)
	//{
	//	this->Student_Batch[i].Set_Extra_Subjects_Taken(0);
	//}
	////ADDITIONAL SUBJECTS
	//for (int i = 0; i < 9; i++)
	//{
	//	rand_index = 0 + rand() % 50;
	//	this->Student_Batch[rand_index].Set_Extra_Subjects_Taken(1);
	//}
	//for (int i = 0; i < 9; i++)
	//{
	//	rand_index = 0 + rand() % 50;
	//	this->Student_Batch[rand_index].Set_Extra_Subjects_Taken(2);
	//}

	string fileName;
	if (this->Department_Name == CS)
	{
		fileName = "UG_CS.txt";
	}
	else if (this->Department_Name == EE)
	{
		fileName = "UG_EE.txt";
	}
	else if (this->Department_Name == BBA)
	{
		fileName = "UG_BBA.txt";
	}
	else
	{
		cout << "Invalid Department in UG Set_File!" << endl;
	}
	ofstream OutFile(fileName, ios::out);
	int TOintEnroll;
	for (int index = 0; index < this->No_of_Students; index++)
	{
		TOintEnroll = stoi(this->Student_Batch[index].Get_Enrollemnt_Number());
		OutFile << this->Enroll_Signature << setw(2) << setfill('0') << TOintEnroll << "\t" << this->Student_Batch[index].Get_Name() << "\t";
		OutFile << setw(2) << setfill('0') << this->Student_Batch[index].Get_DOB_Day() << '/' << setw(2) << setfill('0') << this->Student_Batch[index].Get_DOB_Month() << '/' << this->Student_Batch[index].Get_DOB_Year() << "\t";

		OutFile << this->Student_Batch[index].Get_Gender() << "\t" << this->Student_Batch[index].Get_CNIC() << "\t";

		if (this->Student_Batch[index].Get_Fee_paid_status())
		{
			OutFile << "PAID" << "\t";
		}
		else
		{
			OutFile << "UN-PAID" << "\t";
		}

		OutFile << this->Student_Batch[index].Get_GPA() << "\t" << this->Student_Batch[index].Get_Extra_Subjects_Taken() << "\t";


		OutFile << "\n";
	}
	OutFile.close();

}

void Under_Graduate::Get_File_Data()
{
	string fileName;
	if (this->Department_Name == CS)
	{
		fileName = "UG_CS.txt";
	}
	else if (this->Department_Name == EE)
	{
		fileName = "UG_EE.txt";
	}
	else if (this->Department_Name == BBA)
	{
		fileName = "UG_BBA.txt";
	}
	else
	{
		cout << "Invalid Department in UG Set_File!" << endl;
	}
	ifstream My_File(fileName);
	if (!My_File.is_open())
	{
		cout << " Input File not Open!" << endl;
		exit(0);
	}
	else
	{
		string temp;
		int row = 0, col = 0;

		for (int row = 0; row < this->No_of_Students; row++)
		{
			for (int col = 0; col <= 7; col++)
			{
				getline(My_File, temp, '\t');

				if (col == 0)
				{
					if (row != 0)
					{
						temp.erase(0, 1);
					}
				}
				else if (col == 1)
				{
					this->Student_Batch[row].Set_Name(temp);
				}
				else if (col == 2)
				{
					int Start_Index = 0;
					int count = 0;
					string D_M_Y;
					int day = 1, month = 1, year = 1233;
					for (int index = 0; index <= temp.length(); index++)
					{
						if (temp[index] == '/' || index == temp.length())
						{
							count++;
							D_M_Y = temp.substr(Start_Index, (index - Start_Index));
							Start_Index = index + 1;
							if (count == 1)
							{
								day = stoi(D_M_Y);
							}
							else if (count == 2)
							{
								month = stoi(D_M_Y);
							}
							else if (count == 3)
							{
								year = stoi(D_M_Y);
							}
						}
					}

					this->Student_Batch[row].Set_DOB(day, month, year);
				}
				else if (col == 3)
				{
					this->Student_Batch[row].Set_Gender(temp);
				}
				else if (col == 4)
				{
					this->Student_Batch[row].Set_CNIC(temp);
				}
				else if (col == 5)
				{
					if (temp == "PAID")
					{
						this->Student_Batch[row].Set_Fee_paid_status(true);
					}
					else
					{
						this->Student_Batch[row].Set_Fee_paid_status(false);
					}
				}
				else if (col == 6)
				{
					this->Student_Batch[row].Set_GPA(stof(temp));
				}
				else if (col == 7)
				{
					this->Student_Batch[row].Set_Extra_Subjects_Taken(stoi(temp));
				}
			}
			if (My_File.eof())
			{
				break;
			}
		}
	}
}



void Under_Graduate::Print_By_FeeStatus()
{

	for (int index = 0; index < this->No_of_Students; index++)
	{
		if (this->Student_Batch[index].Get_Fee_paid_status() == false)
		{
			cout << "STUDENT " << index + 1 << " : " << endl;
			this->Student_Batch[index].Display_Student();
			cout << "\n" << endl;
		}
	}

}

void Under_Graduate::delete_Student_data(int enroll)
{
	int index = search_Student_by_Enroll(enroll);

	if (index != -1)
	{
		//Student_Batch[index].Set_values_To_NULL();
		for (int loop = index; loop < No_of_Students; loop++)
		{
			if (loop < No_of_Students - 1)
			{
				Student_Batch[loop] = Student_Batch[loop + 1];
			}
			else
			{
				Student_Batch[loop].Set_values_To_NULL();
			}
		}
		No_of_Students--;
	}
	else
	{
		cout << "STUDENT With Enrollment Number " << enroll << " DOESN'T Exist!" << endl;
	}
}

void Under_Graduate::Admit_New_Student(string Name, string Gender, Date DOB, float GPA, int Extra_Subjects_Taken, bool Fee_paid_status = true)
{
	if (this->No_of_Students >= 50)
	{
		cout << "Sorry! All 50 Under Grad Seats Are Taken. Can't Admit another Student!" << endl;
	}
	else
	{
		this->Student_Batch[this->No_of_Students].Set_Name(Name);
		this->Student_Batch[this->No_of_Students].Set_Gender(Gender);
		this->Student_Batch[this->No_of_Students].Set_DOB(DOB.getDay(), DOB.getMonth(), DOB.getYear());


		srand(time(0));
		//Randomly getting CNIC to avoid Complications
		string ID = "";
		int gen = 0;
		for (int loop = 0; loop < 15; loop++)
		{
			gen = 0 + rand() % 10;
			if (loop == 5 || loop == 13)
			{
				ID += '-';
			}
			else
			{
				ID += to_string(gen);
			}
		}

		this->Student_Batch[this->No_of_Students].Set_CNIC(ID);
		this->Student_Batch[this->No_of_Students].Set_GPA(GPA);
		this->Student_Batch[this->No_of_Students].Set_Extra_Subjects_Taken(Extra_Subjects_Taken);
		this->Student_Batch[this->No_of_Students].Set_Fee_paid_status(Fee_paid_status);
		this->No_of_Students++;

	}
}

int Under_Graduate::search_Student_by_Enroll(int Enroll)
{
	for (int loop = 0; loop < No_of_Students; loop++)
	{
		if (this->Student_Batch[loop].Get_Enrollemnt_Number() == to_string(Enroll))
		{
			return loop;
		}
	}
	return -1;
}

int Under_Graduate::Get_no_of_unpaid()
{
	int count = 0;
	for (int loop = 0; loop < No_of_Students; loop++)
	{
		if (this->Student_Batch[loop].Get_Fee_paid_status() == false)
		{
			count++;
		}
	}
	return count;
}

int Under_Graduate::search_Student_by_Unpaid()
{
	for (int loop = 0; loop < No_of_Students; loop++)
	{
		if (this->Student_Batch[loop].Get_Fee_paid_status() == false)
		{
			int res = stoi(this->Student_Batch[loop].Get_Enrollemnt_Number());
			return res;
		}
	}
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::





//**************************************  POST GRAD CLASS  *******************************************************
class Post_Graduate : public Degree_Programs
{
private:
	string PG_Subjects[2];
	string Electives[2];

	int Num_of_Students = 30;
	Student* PG_Student_Batch = new Student[Num_of_Students];
	Teacher PG_Teachers[2];
	Teacher Electives_Teachers[2];
	Head_Of_Dept PG_HOD;


public:

	Post_Graduate(Department_Names, int, int, int);

	void Set_Semester(int);
	void set_GPA(int, float);

	int Get_no_of_PG_Students();

	void Set_PG_File_Data();
	void Get_PG_File_Data();

	void delete_PG_Student_data(int);
	void Admit_New_PG_Student(string, string, Date, float, int, bool);

	int search_PG_Student_by_Enroll(int);
	void Print_PG_By_FeeStatus();
	int search_PG_Student_by_Unpaid();

	int Get_no_of_unpaid_PG();

	void Disp_PG_Top();
	void Disp_Single_PG_Student(int);
	void Display_PG();

};


Post_Graduate::Post_Graduate(Department_Names Department_Name = MBA, int Degree_Duraion = 2, int Credit_Hours = 8, int Semester = 1) : Degree_Programs(Department_Name, Degree_Duraion, Credit_Hours, Semester)
{
	this->PG_Subjects[0] = "Human Resource Management";
	this->PG_Subjects[1] = "Philosophy";
	if (this->Department_Name == MBA)
	{
		this->Electives[0] = "Customer Relationship";
		this->Electives[1] = "Financial Management";
	}
	else if (this->Department_Name == MA)
	{
		this->Electives[0] = "General English";
		this->Electives[1] = "Political Science";
	}
	else if (this->Department_Name == MSc)
	{
		this->Electives[0] = "Applied Psychology";
		this->Electives[1] = "Archaeology";
	}
	else
	{
		cout << "Invalid PG Dept Name." << endl;
		this->Electives[0] = "Customer Relationship";
		this->Electives[1] = "Financial Management";
	}

	this->PG_Student_Batch->Reset_Enroll_count();
}

void Post_Graduate::Set_Semester(int Semester)
{
	if (Semester < 5)
	{
		this->Semester = Semester;
	}
}

int Post_Graduate::Get_no_of_PG_Students()
{
	return this->Num_of_Students;
}

void Post_Graduate::set_GPA(int enroll, float GPA)
{
	int index = this->search_PG_Student_by_Enroll(enroll);
	this->PG_Student_Batch[index].Set_GPA(GPA);
}

void Post_Graduate::Set_PG_File_Data()
{
	srand(time(0));

	//Random functions to initialize Data into different files At first Launch!
	string name;
	if (Department_Name == MSc)
	{
		ifstream inFile("Names.txt", ios::in);
		for (int index = 0; index < this->Num_of_Students; index++)
		{
			getline(inFile, name, '\n');
			this->PG_Student_Batch[index].Set_Name(name);

		}
		inFile.close();

	}
	//for Gender
	int gen;
	for (int index = 0; index < this->Num_of_Students; index++)
	{
		gen = 0 + rand() % 2;
		if (gen == 0)
		{
			this->PG_Student_Batch[index].Set_Gender("Male");
		}
		else if (gen == 1)
		{
			this->PG_Student_Batch[index].Set_Gender("Female");
		}
	}
	//for CNIC
	gen = 0;

	for (int index = 0; index < this->Num_of_Students; index++)
	{
		name = "";
		for (int loop = 0; loop < 15; loop++)
		{
			gen = 0 + rand() % 10;

			if (loop == 5 || loop == 13)
			{
				name += '-';
			}
			else
			{
				name += to_string(gen);
			}
		}

		this->PG_Student_Batch[index].Set_CNIC(name);

	}

	//for DOB
	int day, month, year;

	for (int index = 0; index < this->Num_of_Students; index++)
	{
		day = 1 + rand() % 30;
		month = 1 + rand() % 12;

		year = 1996 + rand() % 10;
		this->PG_Student_Batch[index].Set_DOB(day, month, year);
	}

	//for GPA
	float gpa;
	int first;
	float last;

	for (int index = 0; index < this->Num_of_Students; index++)
	{
		first = 0 + rand() % 5;
		last = (0 + rand() % 10);
		last /= 10;
		if (first == 4)
		{
			last = 0;
		}
		gpa = first + last;
		this->PG_Student_Batch[index].Set_GPA(gpa);

	}

	int rand_index;


	//UNPAID
	for (int i = 0; i < Num_of_Students; i++)
	{
		this->PG_Student_Batch[i].Set_Fee_paid_status(true);
	}
	for (int i = 0; i < 9; i++)
	{
		rand_index = 0 + rand() % 50;
		this->PG_Student_Batch[rand_index].Set_Fee_paid_status(false);
	}

	for (int i = 0; i < Num_of_Students; i++)
	{
		this->PG_Student_Batch[i].Set_Extra_Subjects_Taken(0);
	}

	//ADDITIONAL SUBJECTS
	for (int i = 0; i < 9; i++)
	{
		rand_index = 0 + rand() % 50;
		this->PG_Student_Batch[rand_index].Set_Extra_Subjects_Taken(1);
	}
	for (int i = 0; i < 9; i++)
	{
		rand_index = 0 + rand() % 50;
		this->PG_Student_Batch[rand_index].Set_Extra_Subjects_Taken(2);
	}

	string fileName;
	if (this->Department_Name == MBA)
	{
		fileName = "PG_MBA.txt";
	}
	else if (this->Department_Name == MA)
	{
		fileName = "PG_MA.txt";
	}
	else if (this->Department_Name == MSc)
	{
		fileName = "PG_MSC.txt";
	}
	else
	{
		cout << "Invalid Department in PG Set_File!" << endl;
	}
	ofstream OutFile(fileName, ios::out);
	int TOintEnroll;
	for (int index = 0; index < this->Num_of_Students; index++)
	{
		TOintEnroll = stoi(this->PG_Student_Batch[index].Get_Enrollemnt_Number());
		OutFile << this->Enroll_Signature << setw(2) << setfill('0') << TOintEnroll << "\t" << this->PG_Student_Batch[index].Get_Name() << "\t";
		OutFile << setw(2) << setfill('0') << this->PG_Student_Batch[index].Get_DOB_Day() << '/' << setw(2) << setfill('0') << this->PG_Student_Batch[index].Get_DOB_Month() << '/' << this->PG_Student_Batch[index].Get_DOB_Year() << "\t";

		OutFile << this->PG_Student_Batch[index].Get_Gender() << "\t" << this->PG_Student_Batch[index].Get_CNIC() << "\t";

		if (this->PG_Student_Batch[index].Get_Fee_paid_status())
		{
			OutFile << "PAID" << "\t";
		}
		else
		{
			OutFile << "UN-PAID" << "\t";
		}

		OutFile << this->PG_Student_Batch[index].Get_GPA() << "\t" << this->PG_Student_Batch[index].Get_Extra_Subjects_Taken() << "\t";


		OutFile << "\n";
	}
	OutFile.close();
}

void Post_Graduate::Get_PG_File_Data()
{
	ifstream My_File("PG_MBA.txt");
	if (!My_File.is_open())
	{
		cout << " Input File not Open!" << endl;
		exit(0);
	}
	else
	{
		string temp;
		int row = 0, col = 0;

		for (int row = 0; row < this->Num_of_Students; row++)
		{
			for (int col = 0; col <= 7; col++)
			{
				getline(My_File, temp, '\t');

				if (col == 0)
				{
					if (row != 0)
					{
						temp.erase(0, 1);
					}
				}
				else if (col == 1)
				{
					this->PG_Student_Batch[row].Set_Name(temp);
				}
				else if (col == 2)
				{
					int Start_Index = 0;
					int count = 0;
					string D_M_Y;
					int day = 1, month = 1, year = 1233;
					for (int index = 0; index <= temp.length(); index++)
					{
						if (temp[index] == '/' || index == temp.length())
						{
							count++;
							D_M_Y = temp.substr(Start_Index, (index - Start_Index));
							Start_Index = index + 1;
							if (count == 1)
							{
								day = stoi(D_M_Y);
							}
							else if (count == 2)
							{
								month = stoi(D_M_Y);
							}
							else if (count == 3)
							{
								year = stoi(D_M_Y);
							}
						}
					}

					this->PG_Student_Batch[row].Set_DOB(day, month, year);
				}
				else if (col == 3)
				{
					this->PG_Student_Batch[row].Set_Gender(temp);
				}
				else if (col == 4)
				{
					this->PG_Student_Batch[row].Set_CNIC(temp);
				}
				else if (col == 5)
				{
					if (temp == "PAID")
					{
						this->PG_Student_Batch[row].Set_Fee_paid_status(true);
					}
					else
					{
						this->PG_Student_Batch[row].Set_Fee_paid_status(false);
					}
				}
				else if (col == 6)
				{
					this->PG_Student_Batch[row].Set_GPA(stof(temp));
				}
				else if (col == 7)
				{
					this->PG_Student_Batch[row].Set_Extra_Subjects_Taken(stoi(temp));
				}
			}
			if (My_File.eof())
			{
				break;
			}
		}
	}
}



void Post_Graduate::delete_PG_Student_data(int enroll)
{
	int index = search_PG_Student_by_Enroll(enroll);

	if (index != -1)
	{
		//PG_Student_Batch[index].Set_values_To_NULL();
		for (int loop = index; loop < Num_of_Students; loop++)
		{
			if (loop < Num_of_Students - 1)
			{
				PG_Student_Batch[loop] = PG_Student_Batch[loop + 1];
			}
			else
			{
				PG_Student_Batch[loop].Set_values_To_NULL();
			}
		}
		Num_of_Students--;
	}
	else
	{
		cout << "STUDENT With Enrollment Number " << enroll << " DOESN'T Exist!" << endl;
	}
}

void Post_Graduate::Admit_New_PG_Student(string Name, string Gender, Date DOB, float GPA, int Extra_Subjects_Taken, bool Fee_paid_status = true)
{
	if (this->Num_of_Students >= 50)
	{
		cout << "Sorry! All 50 Under Grad Seats Are Taken. Can't Admit another Student!" << endl;
	}
	else
	{
		this->PG_Student_Batch[this->Num_of_Students].Set_Name(Name);
		this->PG_Student_Batch[this->Num_of_Students].Set_Gender(Gender);
		this->PG_Student_Batch[this->Num_of_Students].Set_DOB(DOB.getDay(), DOB.getMonth(), DOB.getYear());


		srand(time(0));
		//Randomly getting CNIC to avoid Complications
		string ID = "";
		int gen = 0;
		for (int loop = 0; loop < 15; loop++)
		{
			gen = 0 + rand() % 10;
			if (loop == 5 || loop == 13)
			{
				ID += '-';
			}
			else
			{
				ID += to_string(gen);
			}
		}

		this->PG_Student_Batch[this->Num_of_Students].Set_CNIC(ID);
		this->PG_Student_Batch[this->Num_of_Students].Set_GPA(GPA);
		this->PG_Student_Batch[this->Num_of_Students].Set_Extra_Subjects_Taken(Extra_Subjects_Taken);
		this->PG_Student_Batch[this->Num_of_Students].Set_Fee_paid_status(Fee_paid_status);
		this->Num_of_Students++;

	}
}

void Post_Graduate::Print_PG_By_FeeStatus()
{

	for (int index = 0; index < this->Num_of_Students; index++)
	{
		if (this->PG_Student_Batch[index].Get_Fee_paid_status() == false)
		{
			cout << "STUDENT " << index + 1 << " : " << endl;
			this->PG_Student_Batch[index].Display_Student();
			cout << "\n" << endl;
		}
	}

}

int Post_Graduate::search_PG_Student_by_Enroll(int Enroll)
{
	for (int loop = 0; loop < this->Num_of_Students; loop++)
	{
		if (this->PG_Student_Batch[loop].Get_Enrollemnt_Number() == to_string(Enroll))
		{
			return loop;
		}
	}
	return -1;
}

int Post_Graduate::search_PG_Student_by_Unpaid()
{
	for (int loop = 0; loop < Num_of_Students; loop++)
	{
		if (this->PG_Student_Batch[loop].Get_Fee_paid_status() == false)
		{

			return stoi(this->PG_Student_Batch[loop].Get_Enrollemnt_Number());
		}
	}
}

int Post_Graduate::Get_no_of_unpaid_PG()
{
	int count = 0;
	for (int loop = 0; loop < Num_of_Students; loop++)
	{
		if (this->PG_Student_Batch[loop].Get_Fee_paid_status() == false)
		{
			count++;
		}
	}
	return count;
}


void Post_Graduate::Disp_PG_Top()
{
	int toper_index = 0;
	int Toppers[3];
	int size = this->Num_of_Students;

	for (int loop = 0; loop < 3; loop++)
	{

		for (int index = 0; index < size; index++)
		{
			if (loop != 0 && index == Toppers[loop])
			{
				continue;
			}
			else if (this->PG_Student_Batch[index].Get_GPA() > this->PG_Student_Batch[index + 1].Get_GPA())
			{
				toper_index = index;
			}
		}
		Toppers[loop] = toper_index;
		if (loop == 0)
		{
			cout << "1st Position: ";
		}
		else if (loop == 1)
		{
			cout << "2nd Position: ";
		}
		else
		{
			cout << "3rd Position: ";
		}
		cout << this->PG_Student_Batch[toper_index].Get_Name() << ", GPA: " << this->PG_Student_Batch[toper_index].Get_GPA() << endl;
		size--;
	}
}

void Post_Graduate::Disp_Single_PG_Student(int enroll)
{
	int index = this->search_PG_Student_by_Enroll(enroll);
	if (index != -1)
	{
		cout << "Enroll.\t\tName\t\tDOB\t\tGender\tCNIC Number\tFee\tGPA\tExtra Subjects" << endl;
		int TOintEnroll;
		TOintEnroll = stoi(this->PG_Student_Batch[index].Get_Enrollemnt_Number());
		cout << this->Enroll_Signature << setw(2) << setfill('0') << TOintEnroll << "\t" << this->PG_Student_Batch[index].Get_Name() << "\t";
		this->PG_Student_Batch[index].Print_DOB();

		cout << "\t" << this->PG_Student_Batch[index].Get_Gender() << "\t" << this->PG_Student_Batch[index].Get_CNIC() << "\t";

		if (this->PG_Student_Batch[index].Get_Fee_paid_status())
		{
			cout << "PAID" << "\t";
		}
		else
		{
			cout << "UN-PAID" << "\t";
		}

		cout << this->PG_Student_Batch[index].Get_GPA() << "\t" << this->PG_Student_Batch[index].Get_Extra_Subjects_Taken() << "\t";


		cout << "\n";
	}

}
void Post_Graduate::Display_PG()
{
	cout << "Enroll.\t\tName\t\tDOB\t\tGender\tCNIC Number\tFee\tGPA\tExtra Subjects" << endl;
	int TOintEnroll;
	for (int index = 0; index < Num_of_Students; index++)
	{
		TOintEnroll = stoi(this->PG_Student_Batch[index].Get_Enrollemnt_Number());
		cout << this->Enroll_Signature << setw(2) << setfill('0') << TOintEnroll << "\t" << this->PG_Student_Batch[index].Get_Name() << "\t";
		this->PG_Student_Batch[index].Print_DOB();

		cout << "\t" << this->PG_Student_Batch[index].Get_Gender() << "\t" << this->PG_Student_Batch[index].Get_CNIC() << "\t";

		if (this->PG_Student_Batch[index].Get_Fee_paid_status())
		{
			cout << "PAID" << "\t";
		}
		else
		{
			cout << "UN-PAID" << "\t";
		}

		cout << this->PG_Student_Batch[index].Get_GPA() << "\t" << this->PG_Student_Batch[index].Get_Extra_Subjects_Taken() << "\t";


		cout << "\n";
	}
}






//""""""""""""""""ACCOUNTS CLASS""""""""""""""""
class Accounts_Office :public University
{
private:
	float Salary_Increase;
	Under_Graduate* U;
	Post_Graduate* P;

	//int Search_By_enroll(string);

public:
	Accounts_Office(Under_Graduate&, Post_Graduate&, float);

	void Set_Under_Graduate(Under_Graduate&);
	void Set_Post_Graduate(Post_Graduate&);

	void Increase_HOD_salary(Head_Of_Dept, float);
	void Increase_Teacher_Salary(Head_Of_Dept, Teacher, float);

	void Del_UG_Students(int);
	void Del_PG_Students(int);

	void Delete_all_Unpaid_UG();
	void Delete_all_Unpaid_PG();

	void Display_UG_Toppers();
	void Display_PG_Toppers();


	void Display_all_unpaid_UG();
	void Display_all_unpaid_PG();
};
Accounts_Office::Accounts_Office(Under_Graduate& U, Post_Graduate& P, float Salary_Increase = 0)
{
	this->U = &U;
	this->P = &P;
	this->Salary_Increase = Salary_Increase;
}

void Accounts_Office::Set_Under_Graduate(Under_Graduate& U)
{
	this->U = &U;
}

void Accounts_Office::Set_Post_Graduate(Post_Graduate& P)
{
	this->P = &P;
}

void Accounts_Office::Increase_HOD_salary(Head_Of_Dept HOD, float Salary_Increase)
{
	HOD.Set_Bonus_Salary(Salary_Increase);
}
void Accounts_Office::Increase_Teacher_Salary(Head_Of_Dept HOD, Teacher Temp_Teacaher, float Salary_Increase)
{
	HOD.Change_Teachers_Salary(Temp_Teacaher, Salary_Increase);
}



void Accounts_Office::Del_UG_Students(int Enrollment_Number)
{
	this->U->delete_Student_data(Enrollment_Number);
}
void Accounts_Office::Del_PG_Students(int Enrollment_Number)
{
	this->P->delete_PG_Student_data(Enrollment_Number);
}

void Accounts_Office::Delete_all_Unpaid_UG()
{
	int No_of_Unpaid = this->U->Get_no_of_unpaid();
	int Unpaid_index = 0;
	for (int index = 0; index < No_of_Unpaid; index++)
	{
		Unpaid_index = this->U->search_Student_by_Unpaid();

		this->U->delete_Student_data(Unpaid_index);
	}
}

void Accounts_Office::Delete_all_Unpaid_PG()
{
	int No_of_Unpaid = this->P->Get_no_of_unpaid_PG();
	int Unpaid_index = 0;
	for (int index = 0; index < No_of_Unpaid; index++)
	{
		Unpaid_index = this->P->search_PG_Student_by_Unpaid();
		this->P->delete_PG_Student_data(Unpaid_index);
	}
}

void Accounts_Office::Display_UG_Toppers()
{
	this->U->Disp_UG_Top();
}
void Accounts_Office::Display_PG_Toppers()
{
	this->P->Disp_PG_Top();
}

void Accounts_Office::Display_all_unpaid_UG()
{
	U->Print_By_FeeStatus();
}
void Accounts_Office::Display_all_unpaid_PG()
{
	P->Print_PG_By_FeeStatus();
}
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;






int main()
{
	Under_Graduate UG_Section_1;
	UG_Section_1.Get_File_Data();
	Post_Graduate PG_section_1;
	PG_section_1.Get_PG_File_Data();
	Date DOB(12, 4, 1978);
	Date DoJ(3, 11, 2005);

	Teacher t1(DOB, DoJ, "Dr. Abrar Ahmed", "Male", "53246-1251245-32", CS, 17, "Bachelors", 25000, 2);
	Head_Of_Dept HOD1(11000);

	Accounts_Office Acc1(UG_Section_1, PG_section_1);

START:
	system("CLS");
	int Login_Choice = 0;
	int Enrollment_Number = 0;
	float GPA;
	//string Pass_Input;
	string Password_Input = "";
	int MAX_Row = 7, Max_Col = 20, Row, Col;

	for (Row = 1; Row <= MAX_Row; Row++) {
		for (Col = 1; Col <= Max_Col; Col++) {
			if (Row == 1 || Row == MAX_Row || Col == 1 || Col == Max_Col)
				cout << "* ";
			else
				cout << "  ";
			if (Row == 4 && Col == 3)
			{
				cout << setw(5) << "Welcome To Bahria Univerity";

				cout << setw(6) << "*";

			}
		}

		cout << "\n";
	}

	cout << "\n\n\nDo you want to Login as:\n~~>.:: 1. Student\n~~>.:: 2. Teacher\n~~>.:: 3. HOD\n~~>.:: 4. Accounts Manager" << endl;
	while (Login_Choice != 1 && Login_Choice != 2 && Login_Choice != 3 && Login_Choice != 4)
	{
		cout << "Choice: ";
		cin >> Login_Choice;
		if (!cin)
		{
			cout << "Wrong Choice! Please Enter Again:  " << endl;
			cin.clear();

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		if (Login_Choice == 1)
		{


			int User_Input = 1;
			cout << "\n~~> .::Press 1 to login as Under-Graduate Student!\n~~> .::Press 2 to Login as Post-graduate Student!" << endl;

			string Password = "1234";
			cout << "Choice: ";
			do
			{
				if (User_Input != 1 && User_Input != 2)
				{
					cout << "Wrong Choice! Please Enter a valid Value: ";
				}
				cin >> User_Input;

			} while (User_Input != 1 && User_Input != 2);

			cout << "Enter 4 Digit Password: " << endl;
			do
			{
				char s;
				for (int index = 0; index < 4; index++)
				{
					s = _getch();
					Password_Input += s;
					cout << "*";
				}


				if (Password_Input == Password)
				{

					if (User_Input == 1)
					{

						cout << "\nChose your Department: \nPress 0 for CS\nPress 1 for EE\nPress 2 for BBA" << endl;
						int Choice_Input = 0;
						cout << "Choice: ";
						do
						{
							if (Choice_Input != 0 && Choice_Input != 1 && Choice_Input != 2)
							{
								cout << "Wrong Choice! Kindly Enter Again: ";
							}
							cin >> Choice_Input;
						} while (Choice_Input != 0 && Choice_Input != 1 && Choice_Input != 2);
						if (Choice_Input == 0)
						{
							UG_Section_1.Set_Department_Name(CS);
						}
						else if (Choice_Input == 1)
						{
							UG_Section_1.Set_Department_Name(EE);
						}
						else if (Choice_Input == 2)
						{
							UG_Section_1.Set_Department_Name(BBA);
						}

						Enrollment_Number = 0;
						cout << "\nEnter your Enrollemnt Number: ";
						do
						{
							if (Enrollment_Number > 50 || Enrollment_Number < 0)
							{
								cout << "Enrollment Must be between 0-50: ";
							}
							cin >> Enrollment_Number;
						} while (Enrollment_Number > 50 || Enrollment_Number < 0);


						cout << "\n\n~~> .::Press 1 to view your Data! \n~~> .::Press 2 to View your Batch Data!" << endl;
						int data_Input = 1;
						do
						{
							if (data_Input != 1 && data_Input != 2)
							{
								cout << "Please Enter a valid Value (1/2): " << endl;
							}
							else
							{
								cin >> data_Input;
							}
						} while (data_Input != 1 && data_Input != 2);
						if (data_Input == 1)
						{
							UG_Section_1.Disp_Single_Student(Enrollment_Number);
						}
						else
						{
							UG_Section_1.Display_UG();
						}

					}

					if (User_Input == 2)
					{
						cout << "\nChose your Department: \n~~> .::Press 0 for MBA\n~~> .::Press 1 for MA\n~~> .::Press 2 for MSc" << endl;


						int Choice_Input = 0;
						cout << "Choice: ";
						do
						{
							if (Choice_Input != 0 && Choice_Input != 1 && Choice_Input != 2)
							{
								cout << "Invalid Choice! Please select 1/2/3: ";
							}
							cin >> Choice_Input;
						} while (Choice_Input != 0 && Choice_Input != 1 && Choice_Input != 2);


						if (Choice_Input == 0)
						{
							PG_section_1.Set_Department_Name(MBA);
						}
						if (Choice_Input == 1)
						{
							PG_section_1.Set_Department_Name(MA);
						}
						if (Choice_Input == 2)
						{
							PG_section_1.Set_Department_Name(MSc);
						}

						Enrollment_Number = 0;
						cout << "Enter your Enrollemnt Number: ";
						do
						{
							if (Enrollment_Number > 30 || Enrollment_Number < 0)
							{
								cout << "Enrollment Must be between 0-30: ";
							}
							cin >> Enrollment_Number;
						} while (Enrollment_Number > 30 || Enrollment_Number < 0);


						cout << "\n\nPress 1 to view your Data! \nPress 2 view your Batch's Data! " << endl;
						int data_Input = 1;
						do
						{
							if (data_Input != 1 && data_Input != 2)
							{
								cout << "Please Enter a valid Value: " << endl;
							}
							cin >> data_Input;
						} while (data_Input != 1 && data_Input != 2);
						if (data_Input == 1)
						{
							PG_section_1.Disp_Single_PG_Student(Enrollment_Number);
						}
						else
						{
							PG_section_1.Display_PG();
						}

					}
				}
				else
				{
					cout << "\nWrong Password, Enter Again: ";
					Password_Input = "";
				}
			} while (Password_Input != Password);


		}
		else if (Login_Choice == 2)
		{
			string Password = "1234";
			cout << "Enter 4 Digit Password: " << endl;
			do
			{
				char s;
				for (int index = 0; index < 4; index++)
				{
					s = _getch();
					Password_Input += s;
					cout << "*";
				}


				if (Password_Input == Password)
				{
					cout << "\n\nChose your Department: \n~~> .::Press 0 for CS\n~~> .::Press 1 for EE\n~~> .::Press 2 for BBA\n~~> .::Press 3 for MBA\n~~> .::Press 4 for MA\n~~> .::Press 5 for MSc" << endl;
					int Choice_Input = 0;
					do
					{
						if (Choice_Input != 0 && Choice_Input != 1 && Choice_Input != 2 && Choice_Input != 3 && Choice_Input != 4 && Choice_Input != 5)
						{
							cout << "Invalid Input! Try Again: ";
						}
						cin >> Choice_Input;
					} while (Choice_Input != 0 && Choice_Input != 1 && Choice_Input != 2 && Choice_Input != 3 && Choice_Input != 4 && Choice_Input != 5);
					if (Choice_Input == 0)
					{
						UG_Section_1.Set_Department_Name(CS);
					}
					else if (Choice_Input == 1)
					{
						UG_Section_1.Set_Department_Name(EE);
					}
					else if (Choice_Input == 2)
					{
						UG_Section_1.Set_Department_Name(BBA);
					}
					else if (Choice_Input == 3)
					{
						PG_section_1.Set_Department_Name(MBA);
					}
					else if (Choice_Input == 4)
					{
						PG_section_1.Set_Department_Name(MA);
					}
					else if (Choice_Input == 5)
					{
						PG_section_1.Set_Department_Name(MSc);
					}


					cout << "\n\nPress 1 to see Your Department's Data! \nPress 2 to see a student's data: ";
					int choice = 1;
					do
					{
						if (choice != 1 && choice != 2)
						{
							cout << "Please Enter a valid Value: " << endl;
						}
						cin >> choice;
					} while (choice != 1 && choice != 2);
					if (choice == 1)
					{
						if (Choice_Input < 3)
						{
							UG_Section_1.Display_UG();
						}
						else
						{
							PG_section_1.Display_PG();
						}
					}
					else
					{
						Enrollment_Number = 0;
						cout << "\nEnter your Enrollemnt Number: ";
						if (Choice_Input < 3)
						{
							do
							{
								if (Enrollment_Number > 50 || Enrollment_Number < 0)
								{
									cout << "Enrollment Must be between 0-50: ";
								}
								cin >> Enrollment_Number;
							} while (Enrollment_Number > 50 || Enrollment_Number < 0);
						}
						else
						{
							do
							{
								if (Enrollment_Number > 30 || Enrollment_Number < 0)
								{
									cout << "Enrollment Must be between 0-30: ";
								}
								cin >> Enrollment_Number;
							} while (Enrollment_Number > 30 || Enrollment_Number < 0);
						}
						cout << "\n\n~~> .::Press 1 to change this student's GPA!\n~~> .::Press 2 to Skip!" << endl;
						do
						{
							if (choice != 1 && choice != 2)
							{
								cout << "Please Enter a valid Value: " << endl;
							}
							cin >> choice;
						} while (choice != 1 && choice != 2);


						if (choice == 1)
						{
							cout << "Enter Updated GPA: ";
							cin >> GPA;
							//show students updated data
							cout << "\n\nUPDATED Student Data: " << endl;
							if (Choice_Input < 3)
							{
								UG_Section_1.set_GPA(Enrollment_Number, GPA);
								UG_Section_1.Disp_Single_Student(Enrollment_Number);
							}
							else
							{
								PG_section_1.set_GPA(Enrollment_Number, GPA);
								PG_section_1.Disp_Single_PG_Student(Enrollment_Number);
							}


						}

					}
					cout << "\n\n\n~~>Press 1 to go back to Main menu!\n~~>Press 2 to Exit!" << endl;
					choice = 1;
					do
					{
						if (choice != 1 && choice != 2)
						{
							cout << "Please Enter a valid Value: " << endl;
						}
						cin >> choice;
					} while (choice != 1 && choice != 2);
					if (choice == 1)
					{
						goto START;
					}
					else
					{
						cout << "Management system Exited Successfully! " << endl;
						exit(0);
					}
				}
				else
				{
					cout << "\nWrong Password, Enter Again: ";
					Password_Input = "";
				}
			} while (Password_Input != Password);
		}

		else if (Login_Choice == 3)
		{
			string Password = "1234";
			cout << "Enter 4 Digit Password: " << endl;
			do
			{
				char s;
				for (int index = 0; index < 4; index++)
				{
					s = _getch();
					Password_Input += s;
					cout << "*";
				}


				if (Password_Input == Password)
				{

					cout << "\n\nChose HOD's Department: \n~~> .::Press 0 for CS\n~~> .::Press 1 for EE\n~~> .::Press 2 for BBA\n~~> .::Press 3 for MBA\n~~> .::Press 4 for MA\n~~> .::Press 5 for MSc" << endl;
					int Choice_Input = 0;
					do
					{
						if (Choice_Input != 0 && Choice_Input != 1 && Choice_Input != 2 && Choice_Input != 3 && Choice_Input != 4 && Choice_Input != 5)
						{
							cout << "Invalid Input! Try Again: ";
						}
						cin >> Choice_Input;

					} while (Choice_Input != 0 && Choice_Input != 1 && Choice_Input != 2 && Choice_Input != 3 && Choice_Input != 4 && Choice_Input != 5);
					if (Choice_Input == 0)
					{
						UG_Section_1.Set_Department_Name(CS);
					}
					else if (Choice_Input == 1)
					{
						UG_Section_1.Set_Department_Name(EE);
					}
					else if (Choice_Input == 2)
					{
						UG_Section_1.Set_Department_Name(BBA);
					}
					else if (Choice_Input == 3)
					{
						PG_section_1.Set_Department_Name(MBA);
					}
					else if (Choice_Input == 4)
					{
						PG_section_1.Set_Department_Name(MA);
					}
					else if (Choice_Input == 5)
					{
						PG_section_1.Set_Department_Name(MSc);
					}

					int choice = 1;
					cout << "Press 1 to see student's Data\nPress 2 to see Teacher's Data\nPress 3 to change Teacher's salary\nPress 4 to changed Number of Assigned Sections for Teacher" << endl;
					do
					{
						if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
						{
							cout << "Please Enter a valid Value: " << endl;
						}
						cin >> choice;
					} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
					if (choice == 1)
					{
						if (Choice_Input < 3)
						{
							UG_Section_1.Display_UG();
						}
						else
						{
							PG_section_1.Display_PG();
						}
					}
					else if (choice == 2)
					{
						t1.Display_Teacher();
					}
					else if (choice == 3)
					{

						float salary;
						cout << "Enter updated Teacher's salary: "; cin >> salary;
						HOD1.Change_Teachers_Salary(t1, salary);
						cout << "\n\nUpdated Teacher DATA: " << endl;
						t1.Display_Teacher();
					}
					else
					{
						int sec;
						cout << "Enter updated Teacher's Sections: "; cin >> sec;
						HOD1.Change_Num_Assigned_section(t1, sec);
						cout << "\n\nUpdated Teacher DATA: " << endl;
						t1.Display_Teacher();
					}
					cout << "\n\n\nPress 1 to go back to Main menu!\n Press 2 to Exit! " << endl;
					choice = 1;
					do
					{
						if (choice != 1 && choice != 2)
						{
							cout << "Please Enter a valid Value: " << endl;
						}
						cin >> choice;
					} while (choice != 1 && choice != 2);
					if (choice == 1)
					{
						goto START;
					}
					else
					{
						cout << "Management system Exited Successfully! " << endl;
						exit(0);
					}

				}
				else
				{
					cout << "\nWrong Password, Enter Again: ";
					Password_Input = "";
				}
			} while (Password_Input != Password);
		}

		else if (Login_Choice == 4) //accounts
		{
			string Password = "1234";
			cout << "Enter 4 Digit Password: " << endl;
			do
			{
				char s;
				for (int index = 0; index < 4; index++)
				{
					s = _getch();
					Password_Input += s;
					cout << "*";
				}


				if (Password_Input == Password)
				{
					int choice = 1;
					cout << "~~> .::Press 1 to increase HOD's Salary!\n~~> .::Press 2 to increase Teacher's Salary\n~~> .::Press 3 to delete ALL UNPAID under-graduate students!\n~~> .::Press 4 to delete ALL UNPAID post-graduate students!\n~~> .::Press 5 to Display all Under Graduate toppers Data!\n~~> .::Press 6 to Display all Post Graduate toppers Data!" << endl;
					do
					{
						if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7)
						{
							cout << "Please Enter a valid Value: " << endl;
						}
						cin >> choice;
					} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7);
					float Updated_salary;

					if (choice == 1)
					{
						cout << "Enter HOD's Updated Salary: "; cin >> Updated_salary;
						Acc1.Increase_HOD_salary(HOD1, Updated_salary);

					}


					else if (choice == 2)
					{
						cout << "\n\nTeacher Data: " << endl;
						t1.Display_Teacher();
						cout << "Enter Teacher's Updated Salary: "; cin >> Updated_salary;
						Acc1.Increase_Teacher_Salary(HOD1, t1, Updated_salary);
						cout << "\n\nTeacher's Updated Data: " << endl;
						t1.Display_Teacher();
					}



					else if (choice == 3)
					{
						cout << "Following is the list of Under-Graduate Students who have not paid there fee!: " << endl;
						Acc1.Display_all_unpaid_UG();

						cout << "\n\nPress 1 to Delete all Unpaid Under-Graduate student's Data!\nPress 2 to delete Specific students Data!\nPress 3 to Skip!" << endl;
						do
						{
							if (choice != 1 && choice != 2 && choice != 3)
							{
								cout << "Please Enter a valid Value: " << endl;
							}

							cin >> choice;
						} while (choice != 1 && choice != 2 && choice != 3);
						if (choice == 1)
						{
							cout << "LIST OF UG STUDENTS: " << endl;
							UG_Section_1.Display_UG();
							Acc1.Delete_all_Unpaid_UG();
							cout << "\n\nUPDATED LIST OF UG STUDENTS After Removing All Unpaid Students: " << endl;
							UG_Section_1.Display_UG();

						}
						else if (choice == 2)
						{
							cout << "LIST OF UG STUDENTS: " << endl;
							UG_Section_1.Display_UG();
							Enrollment_Number = 0;
							cout << "\nEnter your Enrollemnt Number: ";
							do
							{
								if (Enrollment_Number > 50 || Enrollment_Number < 0)
								{
									cout << "Enrollment Must be between 0-50: ";
								}
								cin >> Enrollment_Number;
							} while (Enrollment_Number > 50 || Enrollment_Number < 0);

							Acc1.Del_UG_Students(Enrollment_Number);

							cout << "\n\nUPDATED LIST OF UG STUDENTS After Removing Student: " << endl;
							UG_Section_1.Display_UG();

						}
						else
						{
							goto START;
						}
					}


					else if (choice == 4)
					{
						cout << "Following is the list of POST-Graduate Students who have not paid there fee!:" << endl;
						Acc1.Display_all_unpaid_PG();

						cout << "~~> .::Press 1 to Delete all Unpaid Post-Graduate student's Data\n~~> .::Press 2 to delete Specific students Data\n\n~~> .::Press 3 to Skip" << endl;
						do
						{
							if (choice != 1 && choice != 2 && choice != 3)
							{
								cout << "Please Enter a valid Value: " << endl;
							}
							cin >> choice;
						} while (choice != 1 && choice != 2 && choice != 3);

						if (choice == 1)
						{
							cout << "LIST OF ALL PG STUDENTS: " << endl;
							PG_section_1.Display_PG();
							Acc1.Delete_all_Unpaid_PG();
							cout << "\n\nUPDATED LIST OF UG STUDENTS After Removing All Unpaid Students: " << endl;
							PG_section_1.Display_PG();
						}
						else if (choice == 2)
						{
							cout << "LIST OF ALL PG STUDENTS: " << endl;
							PG_section_1.Display_PG();
							Enrollment_Number = 0;
							cout << "\nEnter your Enrollemnt Number: ";
							do
							{
								if (Enrollment_Number > 30 || Enrollment_Number < 0)
								{
									cout << "Enrollment Must be between 0-30: ";
								}
								cin >> Enrollment_Number;
							} while (Enrollment_Number > 30 || Enrollment_Number < 0);

							Acc1.Del_PG_Students(Enrollment_Number);

							cout << "\n\nUPDATED LIST OF PG STUDENTS After Removing Student: " << endl;
							PG_section_1.Display_PG();
						}
						else
						{
							goto START;
						}

					}
					else if (choice == 5)
					{
						cout << "The List of all Under Graduate students who have topped in their Department: " << endl;
						Acc1.Display_UG_Toppers();
					}
					else if (choice == 6)
					{
						cout << "The List of all Post Graduate students who have topped in their Department: " << endl;
						Acc1.Display_PG_Toppers();
					}
					else
					{
						cout << "\n\n\n\nPress 1 to go back to Main menu\n press 2 to Exit " << endl;
						choice = 1;
						do
						{
							if (choice != 1 && choice != 2)
							{
								cout << "Please Enter a valid Value: " << endl;
							}
							cin >> choice;
						} while (choice != 1 && choice != 2);
						if (choice == 1)
						{
							goto START;
						}
						else
						{
							cout << "Management system Exited Successfully! " << endl;
							exit(0);
						}

					}

				}
				else
				{
					cout << "\nWrong Password, Enter Again: ";
					Password_Input = "";
				}
			} while (Password_Input != Password);
		}
		else
		{
			cout << "Invalid Choice!" << endl;
		}

	}

	return 0;
}