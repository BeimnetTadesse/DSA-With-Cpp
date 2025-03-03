#include <iostream>
#include <cctype>  
using namespace std;

bool isPalindrome(char str[], int len) {
    char stack[100];
    int top = -1;
 
    for (int i = 0; i < len; i++) {
        stack[++top] = tolower(str[i]);
    }

 
    for (int i = 0; i < len; i++) {
        if (stack[top--] != tolower(str[i]))
            return false;
    }
    return true;
}

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;

    int len = 0;
    while (str[len] != '\0') len++;

    if (isPalindrome(str, len))
        cout << "Palindrome\n";
    else
        cout << "Not a palindrome\n";

    return 0;
}
