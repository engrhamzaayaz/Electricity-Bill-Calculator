#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
// Global Constants
const int maxBills = 3;
const int meterRent = 50;
const int serviceRent = 20;
const int tvFee = 35;
int meterNo = 1680120;
float fuelPriceAdjustment = 0;
float fcSurcharge = 0;
// Function Declarations
float calculateCharge(int units);
void line(char ch, int length);
void showHistory(string months[], int unitsArr[], float bills[], float payments[], int billCounter);
void displayBill(string consumerID, string refrenceNo, string name, string address, string month, int meterNo, int pReading,
int cReading, int units, float electricityCharge, float totalHC, float gst, float totalGC, float arrears, float currentBill, float
payableDue, float payableAfter);
int main()
{
 char choice;
 float arrears = 0;
 int billCounter = 0;
// Arrays to store last 3 bills history
 string months[maxBills];
 int unitsArr[maxBills];
 float bills[maxBills];
 float payments[maxBills];
 do
 {
 // Variables Declerations
 string consumerID;
 string refrenceNo;
 int pReading;
 int cReading;
 string name;
 string address;
 string month;
 float units;
 float electricityCharge;
 float totalHC;
 float totalGC;
 float currentBill;
 float payableDue;
 float payableAfter;
 float LPS;
 float gst;
 float electricityDutyLocal;
 // Inputs By User
 cout << "Enter Bill Month (e.g. NOV25): ";
 cin >> month;
 cout << "Enter Consumer ID: ";
 cin >> consumerID;
 cout << "Enter Refrence Number: ";
 cin >> refrenceNo;
 cout << "Enter Name: ";
 cin.ignore();
 getline(cin, name);
 cout << "Enter Address: ";
 getline(cin, address);
 cout << "Enter Meter No: ";
 cout << meterNo;
 cout << "Enter Previous Reading: ";
 cin >> pReading;
 cout << "Enter Current Reading: ";
 cin >> cReading;
// Charges
 // HAZECO Company Charges
 electricityCharge = calculateCharge(units);
 fcSurcharge = units * 0.43;
 totalHC = electricityCharge + meterRent + serviceRent + fuelPriceAdjustment + fcSurcharge;
 // Government Charges
 electricityDutyLocal = electricityCharge * 0.015;
 gst = electricityCharge * 0.15;
 totalGC = electricityDutyLocal + tvFee + gst;
 // Final Bill Calculations
 currentBill = totalHC + totalGC + arrears;
 payableDue = currentBill;
 LPS = currentBill * 0.10;
payableAfter = currentBill + LPS;
 // Displays bill
 displayBill(consumerID, refrenceNo, name, address, month, meterNo, pReading, cReading, units,
 electricityCharge, totalHC, gst, totalGC, arrears,
 currentBill, payableDue, payableAfter);
 // Payment status
 char paidChoice;
 cout << endl;
 cout << "Is this bill PAID? (y/n): ";
 cin >> paidChoice;
 if (paidChoice == 'y' || paidChoice == 'Y')
 {
 arrears = 0;
 cout << "Bill is Paid...!!!" << endl;
 payments[billCounter] = currentBill; // store bill amount
 }
 else
 {
 arrears = payableAfter;
 cout << "Bill unpaid. Rs " << arrears << " will be added to next bill." << endl;
 payments[billCounter] = 0; // store 0 if unpaid
 }
 // Save history
 int index = billCounter % maxBills;
 months[index] = month;
 unitsArr[index] = units;
 bills[index] = currentBill;
 payments[index] = (paidChoice == 'y' || paidChoice == 'Y') ? currentBill : 0;
 billCounter++;
 // Show last bills summary
 showHistory(months, unitsArr, bills, payments, billCounter);
 cout << endl;
 cout << "Bill is Generated Successfully...!!!";
 cout << endl;
 cout << endl;
 cout << "Do you want to enter another bill? (y/n): ";
 cin >> choice;
 cout << endl << endl;
 }
 while ((choice == 'y' || choice == 'Y'));
 return 0;
}
// Calculates electricity charges based on slab rates
float calculateCharge(int units)
{
 float charge = 0;
 if (units <= 100)
 {
 charge = units * 10;
 }
 else if (units <= 300) 
{
 charge = (100 * 10) + (units - 100) * 15;
 }
 else
{
 charge = (100 * 10) + (200 * 15) + (units - 300) * 20;
 }
 return charge;
}
// Prints a line of characters for formatting
void line(char ch, int length)
{
 for (int i = 1; i <= length; i++)
 {
 cout << ch;
 }
}
// Displays Last three Months bill Summary
void showHistory(string months[], int unitsArr[], float bills[], float payments[], int billCounter)
{
 int count = (billCounter < maxBills) ? billCounter : maxBills; // how many bills to show
 int start = (billCounter - count) % maxBills; // oldest bill index
 line('-', 18);
 cout << " LAST 3 MONTHS HISTORY ";
 line('-', 18);
 cout << endl << endl;
 cout << left << setw(10) << "Month"
 << setw(10) << "Units"
 << setw(15) << "Bill"
 << setw(15) << "Payment" << endl;
 line('-', 60);
 cout << endl;
for (int i = 0; i < count; i++)
 {
 int index = (start + i) % maxBills;
 cout << left << setw(10) << months[index]
 << setw(10) << unitsArr[index]
 << setw(15) << bills[index]
 << setw(15) << payments[index] << endl;
 }
}
// Displays Detailed Bill
void displayBill(string consumerID, string refrenceNo, string name, string address, string month, int meterNo, int pReading,
int cReading, int units, float electricityCharge, float totalHC, float gst, float totalGC, float arrears, float currentBill, float
payableDue, float payableAfter)
{
 line('-', 60);
 cout << endl;
 cout << " \t\t HAZARA ELECTRIC SUPPLY COMPANY " << endl;
 cout << " \t YOUR BETTER SERVICE - OUR PRIDE " << endl;
 line('-', 60);
 cout << endl;
 cout << setw(40) << "ELECTRICITY CONSUMER BILL " << endl;
 cout << "Consumer ID : " << consumerID << endl;
 cout << "Refrence Number : " << refrenceNo << endl;
 cout << "Name : " << name << endl;
 cout << "Address : " << address << endl;
 cout << "Bill Month : " << month << endl;
 cout << "Meter No: S-P " << meterNo << endl;
 cout << "Previous Reading : " << pReading << endl;
 cout << "Current Reading : " << cReading << endl;
 cout << "Units : " << units << endl;
 line('-', 22);
cout << " HAZECO CHARGES ";
 line('-', 22);
 cout << endl;
 cout << "Units Consumed: " << units << endl;
 cout << "Cost of Electricity: " << electricityCharge << endl;
 cout << "Meter Rent (fix charges): " << meterRent << endl;
 cout << "Service Rent: " << serviceRent << endl;
 cout << "Fuel Price Adjustment: " << fuelPriceAdjustment << endl;
 cout << "F.C Surcharge: " << fcSurcharge << endl;
 cout << "Total: " << totalHC << endl;
 line('-', 23);
 cout << " GOVT CHARGES ";
 line('-', 23);
 cout << endl;
 cout << "Electricity Duty: " << electricityCharge * 0.015 << endl;
 cout << "TV Fee: " << tvFee << endl;
 cout << "General Sales Tax (GST): " << gst << endl;
 cout << "Total: " << totalGC << endl;
 line('-', 22);
 cout << " TOTAL CHARGES ";
 line('-', 22);
 cout << endl;
 cout << "Arrears/AGE: " << arrears << endl;
 cout << "Current Bill: " << currentBill << endl;
 cout << "Payable Within Due Date: " << payableDue << endl;
 cout << "Payable After Due Date: " << payableAfter << endl;
}
