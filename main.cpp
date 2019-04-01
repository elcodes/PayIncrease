#include <iostream>
#include <string>

using namespace std;

int main() {
// if (hrs <= 40) && (dependents >= 3) { gross pay - all those taxes like dependentFees}
    //declare
        const double dependentFees = 35.0;       // extra cost on dependent fees for health insurance when # of dependents it 3 or more.
        double dependentFeesAmount;              // total amount of dependent fees * number of dependents when it's 3 or more.
        const double payRaisePercentage = 0.076; // pay raise rate
        double previousSalary;                  `// salary before pay raise
        double newSalary;                        // new annual salary after adding a pay raise
        const double socialSecurityTax = 0.006;  // SS rate withheld by employer from employee's paycheck
        double socialSecurityTaxAmount;          // totaly amount of SS withheld from employee's paycheck by the employer
        const double federalIncomeTax = 0.14;    // federal tax on income rate
        double federalIncomeTaxAmount;           // total amount of federal tax amount taken from paycheck
        const double stateIncomeTax = 0.05;      // rate for state income tax
        double stateIncomeTaxAmount;             // total amount of state income tax taken from paycheck
        const double UNION_DUES = 10.00;                // fixed amount of union dues taken out of paycheck every week
        double totalUnionDues;                   // total amount of union dues taken every week throughout the year
        int numberOfDependents;       // amount of people who are dependents of employee
        double hourlyRate = 16.75;    // hourly wage
        double totalHourlyRateAmount; // total amount for hourly wage * hours worked
        double overTimeRate;          // hourly rate after 40 hours
        double totalOvertimeAmount;   // total from overtime hourly rate after 40 hours * hours worked
        double hoursWorked = 0;
        double workerGrossPay;        // Gross pay is the employee's wage times the number of hours worked
        double workerNetPay;          // Gross pay minus all the taxes
        double totalWithholding;      // the amount employer withheld from an employee's wages to pay to the government and all taxes.
        int noDependentFees = 0;      // 0 dependent fees when # of denpendents are less than 3 people.
        double netSalaryWithDependentFees = 0;
        double netSalaryWithoutDependentFees = 0;
        double netWeeklySalaryWithDependentFees;
        double netWeekSalaryWithoutDependentFees;
        int numberOfWorkDays;
    //input..
        cout<<"What is your previous annual salary?"<<endl;
        cin>>previousSalary;

        cout<<"Enter number of dependents: "<<endl;
        cin>>numberOfDependents;

        cout<<"Enter numbers of hours worked: "<<endl;
        cin>>hoursWorked;

        cout<<"Ender numbers of days worked: "<< endl;
        cin>>numberOfWorkDays;
    //process..
        newSalary = previousSalary + ( previousSalary * payRaisePercentage);
        socialSecurityTaxAmount = previousSalary * socialSecurityTax;
        stateIncomeTaxAmount = previousSalary * stateIncomeTax;
        federalIncomeTaxAmount = previousSalary * federalIncomeTax;
        totalUnionDues = 52 * UNION_DUES;
        totalWithholding = federalIncomeTaxAmount + stateIncomeTaxAmount + socialSecurityTaxAmount + totalUnionDues;
        workerNetPay = previousSalary - totalWithholding;
        totalHourlyRateAmount = hoursWorked * hourlyRate;
        overTimeRate = (1.50 * hourlyRate) + hourlyRate;
        totalOvertimeAmount = hoursWorked * overTimeRate;
        dependentFeesAmount = (dependentFees * numberOfDependents);
        netSalaryWithDependentFees = workerGrossPay - (dependentFeesAmount + totalWithholding);
        netSalaryWithoutDependentFees = (workerGrossPay - totalWithholding);
        netWeeklySalaryWithDependentFees = netSalaryWithDependentFees * numberOfWorkDays;

    if ((hoursWorked <= 40) && (numberOfDependents >= 3)) { // if hours worked is less than or equal to 40 hours and if
                                                            // # of dependents is equal to or less than 3 than dependent fees is 0 and hourly wage is regular
        cout << totalHourlyRateAmount << endl;
        cout <<"You pay $ "<< dependentFees << " for dependent fees"<<endl;
        cout <<"Your total dependent fees amount is: "<< dependentFeesAmount << endl;
        cout <<"Your net salary is $ " << netSalaryWithDependentFees << endl;
    else {
        cout << totalOvertimeAmount << endl;
        cout << noDependentFees << endl;         // health insurance is 0 if it's less than 3
        cout <<"Your net salary is $ "<< netSalaryWithoutDependentFees << endl;
    }

    }
    //output
        // This is the magic formula
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);

        cout<< "Your new salary is " << newSalary<< endl;
        cout<< "your weekly net pay is "<< netSalaryWithDependentFees << endl;
        return 0;


}
