
// C program to convert infix expression to postfix 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
struct Stack 
{ 
	int top; 
	unsigned capacity; 
	int* array; 
}; 
struct Stack* createStack( unsigned capacity ) 
{ 
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 

	if (!stack) 
		return NULL; 

	stack->top = -1; 
	stack->capacity = capacity; 

	stack->array = (int*) malloc(stack->capacity * sizeof(int)); 

	return stack; 
} 
int isEmpty(struct Stack* stack) 
{ 
	return stack->top == -1 ; 
} 
char peek(struct Stack* stack) 
{ 
	return stack->array[stack->top]; 
} 
char pop(struct Stack* stack) 
{ 
	if (!isEmpty(stack)) 
		return stack->array[stack->top--] ; 
	return '$'; 
} 
void push(struct Stack* stack, char op) 
{ 
	stack->array[++stack->top] = op; 
} 

int isOperand(char ch) 
{ 
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
} 

int Prec(char ch) 
{ 
	switch (ch) 
	{ 
	case '+': 
	case '-': 
		return 1; 

	case '*': 
	case '/': 
		return 2; 

	case '^': 
		return 3; 
	} 
	return -1; 
} 


int infixToPostfix(char* exp) 
{ 
	int j, m; 
	struct Stack* stack = createStack(strlen(exp)); 
	if(!stack) 
		return -1 ; 

	for (j = 0, m = -1; exp[j]; ++j) 
	{ 
		if (isOperand(exp[j])) 
			exp[++m] = exp[j]; 
		else if (exp[j] == '(') 
			push(stack, exp[j]); 
		
		else if (exp[j] == ')') 
		{ 
			while (!isEmpty(stack) && peek(stack) != '(') 
				exp[++m] = pop(stack); 
			if (!isEmpty(stack) && peek(stack) != '(') 
				return -1; 			 
			else
				pop(stack); 
		} 
		else  
		{ 
			while (!isEmpty(stack) && Prec(exp[j]) <= Prec(peek(stack))) 
				exp[++m] = pop(stack); 
			push(stack, exp[j]); 
		} 

	} 
	while (!isEmpty(stack)) 
		exp[++m] = pop(stack ); 

	exp[++m] = '\0'; 
	printf( "%s", exp ); 
} 
int main() 
{ 
	char exp[] = "a+b*(c^d-e)^(f+g*h)-i"; 
	infixToPostfix(exp); 
	return 0; 
}