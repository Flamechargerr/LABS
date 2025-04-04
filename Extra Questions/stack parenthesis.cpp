// Name: Anamay Tripathy
// Code: 230968270

#include<iostream>
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

void pop()
{
    if (isempty()) {
        cout << "Stack underflow\n";
    } else {
        cout << "The popped element is " << stack[top] << endl;
        top--;
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
    int count = 0, flag = 0;
    char str[100];
    cout << "Please enter your expression: ";
    cin.getline(str, 100);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(str[i]);
            count++;
        }

        if (str[i] == ')') {
            if (stack[top] == '(') {
                flag = 1;
                count--;
                pop();
            }
        }

        if (str[i] == ']') {
            if (stack[top] == '[') {
                flag = 1;
                count--;
                pop();
            }
        }

        if (str[i] == '}') {
            if (stack[top] == '{') {
                flag = 1;
                count--;
                pop();
            }
        }
    }

    int r = isempty();
    if (r == 1 && flag == 1 && count == 0) {
        cout << "The expression is proper\n";
    } else {
        cout << "The expression is not proper\n";
    }

    return 0;
}
