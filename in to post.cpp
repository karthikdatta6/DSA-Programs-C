#include <stdio.h>
#include <ctype.h>
#define MAX 100

int top = -1;
char stack[MAX];

void push(char x){
	stack[++top] = x;
}

char pop(){
	return stack[top--];
}

char peek(){
	return stack[top];
}

int precedence(char c){
	if(c=='^'){
		return 3;
	}
	if(c=='*'||c=='/'){
		return 2;
	}
	if(c=='+'||c=='-'){
		return 1;
	}
	return 0;
}

int main(){
	char in[MAX];
	char post[MAX];
	int k=0;
	
	printf("Enter infix exp: ");
	scanf("%s",in);
	
	for(int i=0;in[i]!='\0';i++){
		char c = in[i];
		
		if(isalnum(c)){
			post[k++] = c;
		}
		else if(c=='('){
			push(c);
		}
		else if(c==')'){
			while(top!=-1&&peek()!='('){
				post[k++] = pop();
			}
			pop();
		}
		else{
			while(top!=-1&&precedence(stack[top])>=precedence(c)){
				post[k++] = pop();
			}
			push(c);
		}
	}
	while(top!=-1){
		post[k++] = pop();
	}
	post[k] = '\0';
	printf("Result is : %s\n",post);
	return 0;
}
