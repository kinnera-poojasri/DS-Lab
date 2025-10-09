#include <stdio.h>
#include <ctype.h>  
#include <stdlib.h> 
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;
void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
int evaluatePostfix(char* expression) {
    int i;
    for (i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        if (ch == ' ')
            continue;
        if (isdigit(ch)) {
            push(ch - '0');  
        }
        else {
            int val2 = pop();
            int val1 = pop();

            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return -1;
            }
        }
    }

    return pop();
}
int main() {
    char expression[100];

    printf("Enter a postfix expression (e.g., 23*54*+9-): ");
    scanf("%s", expression);

    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}
}


