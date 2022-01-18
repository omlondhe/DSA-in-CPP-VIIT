#include <iostream>

using namespace std;

string getString(string placeholder) {
    string s;
    cout << placeholder;
    cin >> s;
    return s;
}


int length(string s) {
    int i = 0;
    while (s[i]) i++;
    return i;
}


void copy(string s) {
    string s_copy = getString("Enter a string to override:\t");
    cout << "Initially string was:\t" << s_copy << "\n";
    int len = s_copy.length();

    s_copy = "";
    for (int i = 0; i < s.length(); i++) {
        s_copy += s[i];
    }
    cout << "Copied string is:\t" << s_copy << "\n";
}


void join(string s) {
    string s_to_join = getString("Enter a string to join:\t");
    int len = s_to_join.length();

    for (int i = 0; i < len; i++) {
        s += s_to_join[i];        
    }

    cout << "After concatenation:\t" << s << "\n";
}


void compare(string s) {
    string s_to_compare = getString("Enter a string to compare with:\t");

    if (s != s_to_compare) {
        cout << "Strings are not equal\n";
        return;
    }

    cout << "Strings are equal\n";
}

void reverse(string s) {
    string s_result = "";
    int i = s.length() - 1;
    
    while (i >= 0) {
        s_result += s[i];
        i--;
    }

    cout << "Reverse of string is: " << s_result << "\n";
}

int main() {
    int choice;
    
    while (1) {
        cout << "---------------------------------------\n";
        cout << "Enter your choice: \n";        
        cout << "|---|\n";
        cout << "| 1 | Find length\n";
        cout << "| 2 | Copy into other\n";
        cout << "| 3 | Concatenate with other\n";
        cout << "| 4 | Compare with other\n";
        cout << "| 5 | Reverse a string\n";
        cout << "| 0 | Exit\n";
        cout << "|---|\n";
        cout << "|\n";
        cout << "V\n";
        cin >> choice;

        switch (choice) {
            case 0:
                exit(0);
                break;
            case 1:
                cout << "Length of the string is: " << length(getString("Enter a string to start with:\t")) << "\n\n";
                break;
            case 2:
                copy(getString("Enter a string to start with:\t"));
                break;
            case 3:
                join(getString("Enter a string to start with:\t"));
                break;
            case 4:
                compare(getString("Enter a string to start with:\t"));
                break;
            case 5:
                reverse(getString("Enter a string to start with:\t"));
                break;
            default:
                cout << "Choose an option from 1 to 5 to proceed or 0 to exit\n\n";
                break;
        }
    }
}
