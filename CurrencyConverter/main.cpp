#include <iostream>
#include <fstream>
#include <map>
// #include <string>
using namespace std;

class CurrencyConverter
{
    map<string, double> exchangeRates;

public:
    // member function to set exchange rates
    void setExchangeRate(const string &currencyCode, double rate)
    {
        exchangeRates[currencyCode] = rate;
    }
    double getExchangeRate(const string &currencyCode) const
    {
        auto it = exchangeRates.find(currencyCode);
        if (it != exchangeRates.end())
            return it->second;
        else
        {
            cerr << "Currency not found: " << currencyCode << endl;
            return 0;
        }
    }
    double convert(const string &fromCurrency, const string &toCurrency, double amount) const
    {
        if (isValidCurrency(fromCurrency) && isValidCurrency(toCurrency))
        {
            double rateFrom = exchangeRates.at(fromCurrency);
            double rateTo = exchangeRates.at(toCurrency);
            // 1 USD = 85 INR
            // INR to USD: (170 / 85) * 1 = 2
            // USD to INR: (2 / 1) * 85 = 170
            return (amount / rateFrom) * rateTo;
        }
        else
        {
            cout << "Invalid currency" << endl;
            return 0;
        }
    }
    bool isValidCurrency(const string &currencyCode) const
    {
        auto it = exchangeRates.find(currencyCode);
        if (it != exchangeRates.end())
            return true;
        else
            return false;
    }
    void displayAllRates() const
    {
        cout << "Exchange Rates:\n";
        for (const auto &p : exchangeRates)
        {
            cout << p.first << " : " << p.second << endl;
        }
    }
    void loadExchangeRates(const string &);
    
};

void CurrencyConverter :: loadExchangeRates(const string &fileNmae)
{
    ifstream readFile(fileNmae);

    if(!readFile){
        cout << "File didn't open" << endl;
        return;
    }
    string currencyCode;
    float rate;
    while(readFile >> currencyCode){
        readFile >> rate;
        exchangeRates[currencyCode] = rate;
    }
}

int main()
{

    CurrencyConverter c;
    int choice;
    string currencyCode;
    double rate;
    double amount;
    string fromCurrency, toCurrency;
    string fileName = "currency.txt";
    c.loadExchangeRates(fileName);
    do
    {
        cout << endl;
        cout << "Menu:\n";
        cout << "1. Set Exchange Rate\n";
        cout << "2. Get Exchange Rate\n";
        cout << "3. Convert Currency\n";
        cout << "4. Display All Rates\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter currency code : ";
            cin >> currencyCode;
            cout << "Enter rate : ";
            cin >> rate;
            c.setExchangeRate(currencyCode, rate);
            break;
        case 2:
            cout << "Enter currency code: ";
            cin >> currencyCode;
            cout << "Exchange rate for " << currencyCode << ": " << c.getExchangeRate(currencyCode) << endl;
            break;
        case 3:
            cout << "Enter from currency : ";
            cin >> fromCurrency;
            cout << "Enter to currency : ";
            cin >> toCurrency;
            cout << "Enter amount : ";
            cin >> amount;
            cout << amount << " " << fromCurrency << " = " << c.convert(fromCurrency, toCurrency, amount) << " " << toCurrency << endl << endl;
            break;
        case 4:
            c.displayAllRates();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 5);
    
}