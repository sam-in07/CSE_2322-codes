#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

// Function to convert a number from base b to decimal (base 10)
int baseToDecimal(const string& num, int base) {
    int decimalValue = 0;
    int length = num.length();

    for (int i = 0; i < length; i++) {
        char digit = num[i];
        int digitValue;

        // Handle digits 0-9 and A-F (for base 16)
        if (digit >= '0' && digit <= '9') {
            digitValue = digit - '0';
        } else if (digit >= 'A' && digit <= 'F') {
            digitValue = digit - 'A' + 10;
        } else if (digit >= 'a' && digit <= 'f') {
            digitValue = digit - 'a' + 10;
        } else {
            throw invalid_argument("Invalid character in the number.");
        }

        // Check if the digit is valid in the given base
        if (digitValue >= base) {
            throw invalid_argument("Invalid digit for the given base.");
        }

        decimalValue += digitValue * pow(base, length - i - 1);
    }

    return decimalValue;
}

// Function to convert a decimal (base 10) number to any base d
string decimalToBase(int num, int base) {
    if (num == 0) {
        return "0";
    }

    string result = "";
    while (num > 0) {
        int remainder = num % base;
        if (remainder < 10) {
            result += (char)(remainder + '0');
        } else {
            result += (char)(remainder - 10 + 'A');
        }
        num /= base;
    }

    // Reverse the string to get the correct order of digits
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    string num;
    int baseB, baseD;

    // Input base b and base d
    cout << "Enter the base of the number (2 <= b <= 16): ";
    cin >> baseB;
    cout << "Enter the base to convert to (2 <= d <= 16): ";
    cin >> baseD;

    // Validate the base values
    if (baseB < 2 || baseB > 16 || baseD < 2 || baseD > 16) {
        cout << "Invalid base values. Base must be between 2 and 16." << endl;
        return 1;
    }

    // Input the number in base b
    cout << "Enter the number in base " << baseB << ": ";
    cin >> num;

    try {
        // Step 1: Convert the input number from base b to decimal
        int decimalValue = baseToDecimal(num, baseB);

        // Step 2: Convert the decimal value to base d
        string result = decimalToBase(decimalValue, baseD);

        // Output the result
        cout << "The number in base " << baseD << " is: " << result << endl;
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}
/*

Input:

csharp
Copy code
Enter the base of the number (2 <= b <= 16): 16
Enter the base to convert to (2 <= d <= 16): 10
Enter the number in base 16: A3F
Output:

csharp
Copy code
The number in base 10 is: 2623
*/
