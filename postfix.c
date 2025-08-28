#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePostfix(char* expr) {
    int i;
    for (i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == ' ' || ch == '\t')
            continue;

        if (isdigit(ch)) {
            int num = 0;

            // Handle multi-digit numbers
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--; // to offset the extra increment
            push(num);
        } else {
            int val2 = pop();
            int val1 = pop();

            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    exit(1);
            }
        }
    }
    return pop();
}

int main() {
    char expression[MAX];
    
    printf("Enter a postfix expression (tokens separated by space): ");
    fgets(expression, MAX, stdin);

    int result = evaluatePostfix(expression);
    printf("Result = %d\n", result);

    return 0;
}

