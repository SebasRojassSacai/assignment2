//Sebastian Rojas
//Assignment 2
//9/21/2023
//Purpose of this assignment is to create my very own and fully accurate loan calculator.
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double CMP(double P, double r, int n)
{
    return P * (r * pow(1 + r, n)) / (pow(1 + r, n) - 1);
}
double CMIR(double apr)
{
    return (apr / 100) / 12;
}
void DT(int month, double MP, double principal, double interest, double balance)
{
    cout << setw(5) << month << setw(15) << fixed << setprecision(2) << MP
        << setw(15) << principal << setw(15) << interest << setw(15) << balance << endl;
}
void ILD(double& LA, double& AIR, int& LT)
{
    cout << "Please enter the loan amount here (in dollars and cents): ";
    cin >> LA;
    cout << "Please enter the annual percentage rate here (APR): ";
    cin >> AIR;
    cout << "Please enter the loan term here (in years): ";
    cin >> LT;
}
void DS(double TP, double TI)
{
    cout << " *******************************************************" << endl;
    cout << "************************ Summary ************************" << endl;
    cout << " *******************************************************" << endl;
    cout << "The complete amount of payments made are: $" << TP << endl;
    cout << "The total Interest being Paid is: $" << TI << endl;
}
int main()
{
    double LA, AIR;
    int LT;
    ILD(LA, AIR, LT);
    double MIR = CMIR(AIR);
    int NOP = LT * 12;
    double MP = CMP(LA, MIR, NOP);
    cout << "The Monthly Payments are: $" << MP << endl;
    double TP = 0.0;
    double TI = 0.0;
    cout << setw(5) << "Month" << setw(15) << "Payment" << setw(15) << "Principal"
        << setw(15) << "Interest" << setw(15) << "Ending Balance" << endl;
    // This calculates and displays the balance for each month
    double balance = LA;
    for (int month = 1; month <= NOP; ++month)
    {
        double IP, principalP;
        IP = balance * MIR;
        principalP = MP - IP;
        balance -= principalP;
        TP += MP;
        TI += IP;
        DT(month, MP, principalP, IP, balance);
        // This is to check if the load is fully paid off
        if (balance <= 0) {
            cout << "Loan is paid off in " << month << " months." << endl;
            break;
        }
    }
    // Display the summary of payments at the end
    DS(TP, TI);
    return 0;
}
