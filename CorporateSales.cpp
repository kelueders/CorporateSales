/*
Corporate Sales Program
Description: Calculates total and average sales for multiple divisions in a company
Author: Kate Lueders
Date: 11/20/2025
*/

#include <iostream>
#include <fstream>
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

// Function to calculate the total sales for a division
double calcTotal(double quarter_sales[], int num_divisions) {
    double total = 0;
    for (int i = 0; i < num_divisions; i++) {
        total += quarter_sales[i];
    }
    return total;
}

// Function to calculate the average sales for a division
double calcAverage(double total_annual_sales, int num_divisions) {
    return total_annual_sales / num_divisions;
}

// Function to display the Sales Report
void displaySalesReport(Division divList[], int num_divisions) {
    const int NUM_COLS = 7;
    const int COL_WIDTH = 12;
    const int BORDER_WIDTH = 3;
    string header[NUM_COLS] = {"Division", "Q1", "Q2", "Q3", "Q4", "Total", "Average"};

    cout << endl;
    cout << endl;
    cout << "***SALES REPORT***" << endl;
    cout << fixed << setprecision(2);
    cout << left;

    // Print the HEADER
    for (int i = 0; i < NUM_COLS; i++) {
        cout << setw(BORDER_WIDTH) << "|" << setw(COL_WIDTH) << header[i];
    }
    cout << endl;

    // Print the DATA
    for (int i = 0; i < num_divisions; i++) {
        // Division Name Column
        cout << setw(BORDER_WIDTH) << "|" << setw(COL_WIDTH) << divList[i].name;

        // Quarter Sales Column
        for (int y = 0; y < 4; y++) {
            cout << setw(BORDER_WIDTH) << "|" << "$ " << setw(COL_WIDTH - 2) << divList[i].quarter_sales[y];
        }

        // Total Sales Column
        cout << setw(BORDER_WIDTH) << "|" << "$ " << setw(COL_WIDTH - 2) << divList[i].total_annual_sales;

        // Average Sales Column
        cout << setw(BORDER_WIDTH) << "|" << "$ " << setw(COL_WIDTH - 2) << divList[i].average_quarterly_sales;

        cout << endl;
    }
    cout << endl;
}

int main()
{
    // Declare constants and create an empty array to hold the Division structs
    const int NUM_DIVISIONS = 4;
    const int DATA_COLS = 5;
    Division divList[NUM_DIVISIONS];

    // Display instructions to the user
    string filename;
    cout << "***Sales Report Program***" << endl;
    cout << "This program will take in a csv file formatted as below, and return a Sales Report containing Total Earnings" << endl;
    cout << " for each division and the Average Quarterly Earnings." << endl;
    cout << endl;
    cout << "The file must be formatted as below with a header, row names, quarterly sales data, commas, and spacing." << endl;
    cout << "Division,Q1,Q2,Q3,Q4" << endl;
    cout << "East,100,100,100,100" << endl;
    cout << "West,200,200,200,100" << endl;
    cout << "North,300,300,300,300" << endl;
    cout << "South,400,400,400,400" << endl;
    cout << endl;
    cout << "Enter the name of the file you want to extract data from: ";
    getline(cin, filename);

    // Open the file
    ifstream file(filename);

    // If the file doesn't open, return an error
    if (file.fail()) {
        cout << "ERROR: Could not open file " << filename << ". Check file name and run again." << endl;
        return 0;
    }

    // Establish counters to cycle through the file
    int lineNumber = 1;
    int divIndex = 0;
    
    // While the end of the file has not been reached, read each line of the file
    while (!file.eof()) {
        // Ignore the header line
        if (lineNumber == 1) {
            string header;
            getline(file, header);
            lineNumber++;
            continue;
        }

        // Loop through the line of data
        for (int n = 0; n < DATA_COLS; n++) {
            // Fill the name for the division
            if (n == 0) {
                getline(file, divList[divIndex].name, ',');
            } else {
                string sales;
                // If it's the last column, use the getline() default of \n as delimiter
                if (n == DATA_COLS - 1) {
                    getline(file, sales);
                } 
                // If it's not hte last column, use the , as the delimiter
                else {
                    getline(file, sales, ',');
                }
                // Add the sales data to the struct
                divList[divIndex].quarter_sales[n - 1] = stod(sales);
            }
        }
        // Move to the next division
        divIndex++;
    }

    // Fill each struct with the totals and average
    for (int i = 0; i < NUM_DIVISIONS; i++) {
        divList[i].total_annual_sales = calcTotal(divList[i].quarter_sales, NUM_DIVISIONS);
        divList[i].average_quarterly_sales = calcAverage(divList[i].total_annual_sales, NUM_DIVISIONS);
    }

    // Display the sales report
    displaySalesReport(divList, NUM_DIVISIONS);
}