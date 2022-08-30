#include <iostream>

#include <cstdlib>

#include <ctime>

#include<string>

#include <iomanip>

using namespace std;

int main() {
  //Print the header
  cout << "+-------------------------------------------------+" << endl;
  cout << "|          Computer Science and Engineering       |" << endl;
  cout << "|           CSCE 1030 - Computer Science I        |" << endl;
  cout << "|            Paarth Jamdagneya pmj0049            |" << endl;
  cout << "|            paarthjamdagneya@my.unt.edu          |" << endl;
  cout << "+-------------------------------------------------+" << endl;

  //declare variables
  const int ACCOUNT_LENGTH = 6;
  enum {Commercial = 1, Residential = 2};
  string acctName;
  string acctNum;
  int numProperties;
  int typeProperty;
  int propValue;
  double propTax;
  int taxExemption;
  double propTaxTotal;
  srand(time(NULL)); //randomly seed the function
  //ask for the account name input
  cout << "Please enter the account name: ";
  getline(cin, acctName);
  //test for the correct name input
  for (int i = 0; i < acctName.length(); ++i) {
    if ((isalpha(acctName.at(i))) || isspace(acctName.at(i))) {
      acctName.at(i) = toupper(acctName.at(i)); //capitalize the account name
      continue;

    } else {
      cout << "There is an incorrect character in the input. Please reenter the account name: ";
      getline(cin, acctName);
      i = 0;
    }

  }
  //ask for the account number input
  cout << "Please enter the account number: ";
  cin >> acctNum;
  //test if the account number is valid
  for (int i = 0; i < acctNum.length(); ++i) {
    if (acctNum.length() != (ACCOUNT_LENGTH)) {
      cout << "Please enter a valid account number: ";
      cin >> acctNum;
      i = 0;
      if ((isalpha(acctNum.at(i)) || isdigit(acctNum.at(i))) && !(isspace(acctNum.at(i)))) {
        continue;
      } else {
        cout << "Please enter a valid account number: ";
        cin >> acctNum;
        i = 0;
      }
    }

  }
  //ask for number of properties
  cout << "How many properties do you own: ";
  cin >> numProperties;
  //check to see if there are a valid number of properties
  while (numProperties < 0) {
    cout << "Please enter a valid number of properties: ";
    cin >> numProperties;
  }
  //begin asking which type of properties they are 
  for (int i = 1; i <= numProperties; ++i) {

    cout << "Property #" << i << endl;
    cout << "1. Commercial" << endl;
    cout << "2. Residential" << endl;
    cout << "Enter the type of property: ";
    cin >> typeProperty;
    //based on type of property, perform a different property tax calculation
    switch (typeProperty) {

    case Commercial:
      cout << "Please enter the value of the commerical propery: ";
      cin >> propValue;
      if (propValue < 1000000) { //different tax rate for certani values
        propTax = 0.035 * propValue;
        propTaxTotal += propTax; //consistently calculate the total property tax
      } else if (propValue >= 1000000) { //higher tax rate for higher property value
        propTax = (1000000 * 0.035) + (propValue - 1000000) * .05;
        propTaxTotal += propTax;
      }
      cout << "Tax owned for property #" << i << ": " << fixed << setprecision(2) << propTax << endl;
      break; //print out the tax amount with two decimal places
    case Residential: //calculations for residential type properties
      cout << "Please enter the value of the residential property: ";
      cin >> propValue;
      if (propValue <= 100000) {
        propTax = 0;
        propTaxTotal += propTax;
      } else if (propValue >= 100000) {
        propTax = (propValue - 100000) * 0.035;
        propTaxTotal += propTax;
      }
      if (numProperties == 1 && typeProperty == Residential) { //tax exemption if only one residential property type
        taxExemption = rand() % 1001 + 1000;
        if (propTax >= taxExemption) {
          propTax = propTax - taxExemption;
          propTaxTotal += propTax;
        } else {
          propTax = 0;
          propTaxTotal += propTax;
        }
        cout << "The property tax after the tax exemption is: $" << fixed << setprecision(2) << propTax << endl;
      }
      cout << "Tax owned for property #" << i << ": " << fixed << setprecision(2) << propTax << endl;
      break;
    default:
      cout << "Please enter a valid type of property." << endl;
      i -= 1; //reset to the beginning
      break;
    }
  }
  //output all of the proper values 
  cout << "Account name: " << acctName << endl;
  cout << "Account number: " << acctNum << endl;
  cout << "Your total taxes are: $" << fixed << setprecision(2) << propTaxTotal << endl;
  return 0;
}