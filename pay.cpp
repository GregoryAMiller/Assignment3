#include "person.cpp"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>  // sort(), unique()
#include <iterator> // distance()

using namespace std;

void readData(vector<Person> &employees);
void getcompanies(vector<Person> &employees, vector<string> &companyNames);
void printHighestPaid(vector<Person> &employees);
void separateAndSave(vector<Person> &employees, vector<string> &companyNames);

int main() {

  vector<Person> employees;
  vector<string> companyNames;
  readData(employees);
  getcompanies(employees, companyNames);
  printHighestPaid(employees);
  separateAndSave(employees, companyNames);

  return 0;
}

void readData(vector<Person> &employees) {
  string fname;
  string lname;
  int id;
  string coName;
  float rate;
  float hours;
  ifstream data;
  data.open("input.txt");
  if(!data) {
    cout << "File could not be opened" << endl;
    exit(0);
  }
  else {
    while(!data.eof()){
      Person temp;  // temp Person(object)
      data >> fname >> lname >> id >> coName >> rate >> hours;  // take in a line and seperate the data into variables
      // set our temp obj with all of the variables we need for Person
      temp.setFirstName(fname);
      temp.setLastName(lname);
      temp.setEmployeeId(id);
      temp.setCompanyName(coName);
      temp.setPayRate(rate);
      temp.setHoursWorked(hours);
      // push our temp obj into our employees vector
      employees.push_back(temp);
    }
  }
}
void getcompanies(vector<Person> &employees, vector<string> &companyNames) {
  // loop through our employees vecotr
  for(int i = 0; i < employees.size(); i++) {
    // set our temp to the employees company name
    string temp = employees[i].getCompanyName();
    // push all the employees company names to the vector
    companyNames.push_back(temp);
  }
  vector<string>::iterator it;  // vector iterator
  sort(companyNames.begin(), companyNames.end()); // sort vector so we can unique and remove all duplicates
  it = std::unique(companyNames.begin(), companyNames.end()); // unique returns an iterator to the element that follows the last element not removed.
  companyNames.resize(std::distance(companyNames.begin(), it)); // resize our vector using distance(which we need to pass it the beggining
    // position and the end(iterator position) and it returns the number of elements from start to finish)
}
void printHighestPaid(vector<Person> &employees) {
  int counter = 0;  // variable to hold the index of most paid person
  float paycomp = 0;
  for(int i = 0; i < employees.size(); i++) {
    // if paycompare is less then employees[i].totalPay then set counter to the index of the higher valued totalpay
    if(paycomp < employees[i].totalPay()) { counter = i; paycomp = employees[i].totalPay(); }
  }
  cout << "Highest paid: " << employees[counter].fullName() << "\n" << "Employee ID: " << employees[counter].getEmployeeId() << "\n"
   << "Employer: " << employees[counter].getCompanyName() << "\n" << fixed << setprecision(2) << "Total Pay: $" << employees[counter].totalPay() << endl;
}
void separateAndSave(vector<Person> &employees, vector<string> &companyNames) {
  // loop through our company vector
  for(int n = 0; n < companyNames.size(); n++) {
    float companyPay = 0; // temp variable to hold each companies total pay of employees
    string fileName = companyNames[n].data(); // set a variable to the name of the company to set files
    ofstream data;
    data.open(fileName + ".txt"); // open a file given the company name
    // loop through our employees
    for(int i = 0; i < employees.size(); i++) {
      // if the employees company == the company from company vector
      if(employees[i].getCompanyName() == companyNames[n].data()) {
        // add their total pay to comapnyPay
          companyPay += employees[i].totalPay();
          // write to the company file with employees info
          data << setw(19) << left << employees[i].fullName() << " " << setw(4) << employees[i].getEmployeeId() << " "
           << setw(8) << left << employees[i].getCompanyName() << " " << fixed << setprecision(2) << left << employees[i].totalPay() << endl;
      }
    }
    // before we leave outer for loop we write the companies total pay
    data << "Total: " << " $" << fixed << setprecision(2) << companyPay << endl;
  }
}
