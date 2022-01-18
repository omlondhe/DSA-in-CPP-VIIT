#include <iostream>

using namespace std;

char* getString(string placeholder) {
    char* s;
    cout << placeholder;
    cin >> s;
    return s;
}


int length(char* s) {
    int i = 0;
    while (s[i]) i++;
    return i;
}


void copy(char* s) {
    char* s_copy = getString("Enter a string to override:\t");
    cout << "Initially string was:\t" << s_copy << "\n";

    int len = length(s);
    int i = 0;
    for (; i < len; i++) {
        s_copy[i] = s[i];
    }
    s_copy[i] = (char)0;
    cout << "Copied string is:\t" << s_copy << "\n";
}


void join(char* s) {
    char* s_to_join = getString("Enter a string to join:\t");
    int l = length(s);

    int len = length(s_to_join);
    int i = 0;
    for (; i < len; i++) {
        s[i + l] = s_to_join[i];        
    }
    s[i + l] = (char)0;

    cout << "After concatenation:\t" << s << "\n";
}


void compare(char* s) {
    char* s_to_compare = getString("Enter a string to compare with:\t");

    int l = length(s);

    if (l != length(s_to_compare)) {
        cout << "Strings are not equal\n";
        return;
    }

    while (l--) {
        if (s[l] != s_to_compare[l]) {
            cout << "Strings are not equal\n";
            return;
        }
    }

    cout << "Strings are equal\n";
}

void reverse(char* s) {
    char* s_result = new char[111];
    int i = length(s) - 1;
    int index = 0;

    while (i >= 0) {
        s_result[index] = s[i];
        index++;
        i--;
    }
    s_result[index] = (char)0;

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
