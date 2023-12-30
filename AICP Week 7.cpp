#include <iostream>
#include <string>

using namespace std;

void bubbleSort(string charities[], double totals[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (totals[j] < totals[j + 1]) {
                double tempTotal = totals[j];
                totals[j] = totals[j + 1];
                totals[j + 1] = tempTotal;
                swap(charities[j], charities[j + 1]);
            }
        }
    }
}

void displayCharityList(string charities[], double totals[], int n) {
    cout << "\nList of Charities and Collected Donations:\n";
    for (int i = 0; i < n; ++i) {
        cout << charities[i] << ": $" << totals[i] << endl;
    }
}

int main() {
    string charities_name[3];
    double charity_totals[3] = {0};
    double grand_total = 0;
    double display_totals[3] = {0};  // Separate array for display

    // Task 1: Set up the donation system
    for (int i = 0; i < 3; ++i) {
       cout << "Enter the charities(Kherate Idary ) " << i + 1 << " Name: ";
        getline(cin, charities_name[i]);
    }

    cout << "\nList of Charities:\n";
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << ". " << charities_name[i] << endl;
    }

    char addMore;
    do {
        int donationChoice = 1;

        while (true) {
            cout << "Choose a charity (1, 2, or 3) or enter -1 to show the list: ";
            cin >> donationChoice;

            if (donationChoice == -1) {
                // Display the list of charities and their collected donations
                displayCharityList(charities_name, display_totals, 3);
                continue; // Continue the loop to prompt for the next input
            }

            // Validate the user's choice
            if (donationChoice >= 1 && donationChoice <= 3) {
                break; // Exit the loop if the choice is valid
            }

            cout << "Invalid choice. Please choose a valid charity or enter -1 to show the list.\n";
        }

        double shopping_bill;
        cout << "Enter the customer's shopping bill: $";
        cin >> shopping_bill;

        // Calculate the donation (1% of the shopping bill)
        double donation_percentage = 0.01;
        double donation = shopping_bill * donation_percentage;
        charity_totals[donationChoice - 1] += donation;
        grand_total += donation;

        // Update the display_totals array with the ongoing total for display purposes
        display_totals[donationChoice - 1] = charity_totals[donationChoice - 1];

        cout << "\nDonation for " << charities_name[donationChoice - 1] << ": $" << donation << endl;
        cout << "Total donation for " << charities_name[donationChoice - 1] << ": $" << display_totals[donationChoice - 1] << endl;

        cout << "\nDo you want to add more customer donations? (y/n): ";
        cin >> addMore;

    } while (addMore == 'y' || addMore == 'Y');

    // Task 3: Calculate and show the grand total donations for each charity
    bubbleSort(charities_name, charity_totals, 3);

    cout << "\nGrand Total Donations (Descending Order):\n";
    for (int i = 0; i < 3; i++) {
        cout << charities_name[i] << ": $" << charity_totals[i] << endl;
    }

    cout << "\nGRAND TOTAL DONATED TO CHARITY: $" << grand_total << endl;

    return 0;
}

