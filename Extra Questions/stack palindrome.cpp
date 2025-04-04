// Name: Anamay Tripathy
// Code: 230968270

#include<iostream>
#include<string.h>
using namespace std;

char stack[100], top = -1;

int isempty();
int isfull();

void push(char ele)
{
    if (isfull()) {
        cout << "Stack overflow\n";
    } else {
        top++;
        stack[top] = ele;
    }
}

char pop()
{
    if (isempty()) {
        cout << "Stack underflow\n";
    } else {
        char poppedElement = stack[top];
        top--;
        return poppedElement;
    }
}

int isfull()
{
    if (top == 99) {
        return 1;
    } else {
        return 0;
    }
}

int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void display()
{
    int i;
    for (i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
}

void peek()
{
    if (isempty()) {
        cout << "Stack underflow\n";
    } else {
        cout << "The peek element is " << stack[top] << endl;
    }
}

int main()
{
    int count = 0, flag = 1, length = 0;
    char str[100], pali[100];
    cout << "Please enter your string\n";
    cin.getline(str, 100);
    
    for (int i = 0; str[i] != '\0'; i++) {
        push(str[i]);
        length++;
    }
    
    for (int i = 0; i < length; i++) {
        pali[i] = pop();
    }

    for (int i = 0; i < length; i++) {
        if (str[i] != pali[i]) {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
        cout << "The string entered is a palindrome\n";
    else
        cout << "The string entered is not a palindrome\n";

    return 0;
}
