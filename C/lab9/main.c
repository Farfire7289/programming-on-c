#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[256];
    printf("Input: ");
    fgets(input, 256, stdin);
    input[strcspn(input, "\n")] = 0; 
    
   
    char with_spaces[512] = {0}; 
    int idx = 0;  
    int i;
    
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == '+' || input[i] == '-') {
            
            with_spaces[idx++] = ' ';
            with_spaces[idx++] = input[i];
            with_spaces[idx++] = ' ';
        } else {
            
            with_spaces[idx++] = input[i];
        }
    }
    with_spaces[idx] = '\0'; 
    
    
    
    char *tokens[100];
    int token_count = 0;
    
    char *token = strtok(with_spaces, " \t\n");
    while (token != NULL && token_count < 100) {
        tokens[token_count++] = token;
        token = strtok(NULL, " \t\n");
    }
    
    
    for (i = 0; i < token_count; i++) {
        printf("  [%d] = '%s'\n", i, tokens[i]);
    }
    
    
    double result = atof(tokens[0]);
    
	if (tokens[0][0]== '-'){
	
	    for (i = 0; i < token_count; i += 2) {
	        char op = tokens[i][0];  
	        double num = atof(tokens[i + 1]);
	        
	        if (op == '+') {
	            result += num;
	        } else {
	            result -= num;
	        }
	    }
	}
	else{
	    for (i = 1; i < token_count; i += 2) {
		    char op = tokens[i][0];     
		    double num = atof(tokens[i + 1]);
		    
		    if (op == '+') {
		        result += num;
		    } else if (op == '-') {
		        result -= num;
		    }
		}
	}
    printf("Res: %g\n", result);
    
    return 0;
}
