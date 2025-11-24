/*
Corporate Sales Program
Description: Calculates total and average sales for multiple divisions in a company
Author: Kate Lueders
Date: 11/20/2025
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// TODO: Create a struct for division's sales data.
struct Division {
    string name;
    double quarter_sales[4];
    double total_annual_sales;
    double average_quarterly_sales;
};

Division inputSales(Division div) {

    cout << "1st Quarter Sales: $";
    cin >> div.quarter_sales[0];
    cout << "2nd Quarter Sales: $";
    cin >> div.quarter_sales[1];
    cout << "3rd Quarter Sales: $";
    cin >> div.quarter_sales[2];
    cout << "4th Quarter Sales: $";
    cin >> div.quarter_sales[3];

    return div;
}

double calcTotal(double quarter_sales[]) {
    double total = 0;
    for (int i = 0; i < 4; i++) {
        total += quarter_sales[i];
    }
    return total;
}

double calcAverage(double total_annual_sales) {
    return total_annual_sales / 4;
}

void displaySalesReport(Division divList[], int num_divisions) {
    cout << endl;
    cout << "***SALES REPORT***" << endl;

    for (int i = 0; i < num_divisions; i++) {
        cout << "Divison: " << divList[i].name << endl;
        for (int y = 0; y < 4; y++) {
            cout << "Quarter " << y + 1 << " Sales: $" << divList[i].quarter_sales[y] << endl;
        }
        cout << fixed << setprecision(2);
        cout << "Total Annual Sales: $" << divList[i].total_annual_sales << endl;
        cout << "Average Quarterly Sales: $" << divList[i].average_quarterly_sales << endl << endl;
    }
}

int main()
{
    const int NUM_DIVISIONS = 4;
    Division divList[NUM_DIVISIONS];
    string divStrings[NUM_DIVISIONS] = {"East", "West", "North", "South"};

    // Fill each struct with the Division Name
    for (int i = 0; i < NUM_DIVISIONS; i++) {
        divList[i].name = divStrings[i];
    }

    // Fill each struct with the sales data, totals, and average
    for (int i = 0; i < NUM_DIVISIONS; i++) {
        cout << "Input each quarter sales for " << divList[i].name << " Division: " << endl;
        divList[i] = inputSales(divList[i]);

        divList[i].total_annual_sales = calcTotal(divList[i].quarter_sales);
        divList[i].average_quarterly_sales = calcAverage(divList[i].total_annual_sales);
    }

    // Display the sales report
    displaySalesReport(divList, NUM_DIVISIONS);
}