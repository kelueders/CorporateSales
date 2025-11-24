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
    const int NUM_COLS = 7;
    const int COL_WIDTH = 10;
    string header[NUM_COLS] = {"Division", "Q1", "Q2", "Q3", "Q4", "Total", "Average"};

    cout << endl;
    cout << "***SALES REPORT***" << endl;
    cout << fixed << setprecision(2);

    // cout << "|   Division      |    Q1      |    Q2      |    Q3      |    Q4      |    Total      |    Average    |" << endl;
    for (int i = 0; i < NUM_COLS; i++) {
        cout << setw(COL_WIDTH) << "|" << setw(COL_WIDTH + 3) << header[i];
    }
    cout << "    |" << endl;

    for (int i = 0; i < num_divisions; i++) {
        cout << setw(COL_WIDTH) << "|" << setw(COL_WIDTH) << divList[i].name;
        for (int y = 0; y < 4; y++) {
            cout << setw(COL_WIDTH) << "|" << setw(COL_WIDTH) << "$ " << divList[i].quarter_sales[y];
        }
        cout << setw(COL_WIDTH) << "|" << setw(COL_WIDTH) << "$ " << divList[i].total_annual_sales;
        cout << setw(COL_WIDTH) << "|" << setw(COL_WIDTH) << "$ " << divList[i].average_quarterly_sales;
        cout << "    |" << endl;
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