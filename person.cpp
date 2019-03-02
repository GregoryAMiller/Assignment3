#include "person.h"

Person::Person() {
    firstName = "";
    lastName = "";
    employeeID = 0;
    companyName = "";
    payRate = 0;
    hoursWorked = 0;
}
string Person::getFirstName() {
    return firstName;
}
string Person::getLastName() {
    return lastName;
}
int Person::getEmployeeId() {
  return employeeID;
}
string Person::getCompanyName() {
  return companyName;
}
float Person::getPayRate() {
    return payRate;
}
float Person::getHoursWorked() {
    return hoursWorked;
}
void Person::setFirstName(string fname) {
    firstName = fname;
}
void Person::setLastName(string lname) {
    lastName = lname;
}
void Person::setEmployeeId(int id) {
    employeeID = id;
}
void Person::setCompanyName(string coName) {
    companyName = coName;
}
void Person::setPayRate(float rate) {
    payRate = rate;
}
void Person::setHoursWorked(float hours) {
    hoursWorked = hours;
}
string Person::fullName() {
    return firstName + " " + lastName;
}
float Person::totalPay() {
    return payRate * hoursWorked;
}
