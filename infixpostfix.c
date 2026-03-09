#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h> 
#include <math.h> 
#define MAX 100 
char stack[MAX]; 
int top = -1; 
void push(char ch) { 
 if (top >= MAX - 1) { 
 printf("Stack Overflow\n"); 
 return; 
 } 
 stack[++top] = ch; 
} 
char pop() { 
 if (top == -1) return '\0'; 
 return stack[top--]; 
} 
char peek() { 
 if (top == -1) return '\0'; 
 return stack[top]; 
 
} 
int precedence(char op) { 
 switch (op) { 
 case '^': return 3; 
 case '*': 
 case '/': 
 case '%': return 2; 
 case '+': 
 case '-': return 1; 
 default: return 0; 
 } 
} 
int isOperator(char ch) { 
 return ch == '+' || ch == '-' || ch == '*' || 
 ch == '/' || ch == '%' || ch == '^'; 
} 
int isRightAssociative(char op) { 
 return op == '^'; 
} 
void infixToPostfix(const char* infix, char* postfix) { 
 int i = 0, j = 0; 
 char ch; 
 while ((ch = infix[i++]) != '\0') { 
 if (isspace(ch)) continue; 
 if (isalnum(ch)) { 
 postfix[j++] = ch; 
 } 
 
 else if (ch == '(') { 
 push(ch); 
 } 
 
 else if (ch == ')') { 
 while (top != -1 && peek() != '(') { 
 postfix[j++] = pop(); 
 } 
 if (peek() == '(') 
 pop(); 
 } 

 else if (isOperator(ch)) { 
 while (top != -1 && isOperator(peek()) && 
 ((precedence(peek()) > precedence(ch)) || 
 (precedence(peek()) == precedence(ch) && !isRightAssociative(ch)))) {  
 postfix[j++] = pop(); 
 } 
 push(ch); 
 } 
 else { 
 printf("Invalid character: %c\n", ch); 
 exit(1); 
 } 
 } 
 
 while (top != -1) { 
 if (peek() == '(' || peek() == ')') { 
 printf("Mismatched parentheses\n"); 
 exit(1); 
 } 
 postfix[j++] = pop(); 
 } 
 postfix[j] = '\0'; 
} 
 
int main() { 
 char infix[MAX], postfix[MAX]; 
 printf("Enter an infix expression:\n"); 
 fgets(infix, MAX, stdin); 
 infix[strcspn(infix, "\n")] = '\0';  
 infixToPostfix(infix, postfix); 
 printf("Postfix expression:\n%s\n", postfix); 
 return 0; 
} 
