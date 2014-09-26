#include <stdio>
#include <ctype.h>
#include <stdlib.h>

typdef enum {start, stop, build_id, build_num, integer, floatpointnumber,
	identifier, addop, minusop, multop, divop, assignop, stmttermop} state;

state current_state;

FILE *input *output;

/**
 * Predeclaration of function transition
 */
state transition(state state, char transition_char);

int main(int argc, char* argv[] ) {
	current_state=start;
	char transition_char;

	//attempt to open and read file and set outputfile
	if (argc=2){
		input = fopen(argv[1], "r");
		output = fopen(argv[2], "w");
	}
	else {
		printf("Please specify input and output file in program arguements.");
		exit(1);
	}

	if (input == null) {
		printf("The input file you specified does not exist");
		exit(1);
	}


	do{
		if (current_state == identifier) {
			printf(" - Identifier\n" );
			current_state = start;
		}
		else if (current_state == integer) {
			printf(" - Integer\n");
			current_state = start;
		}
		else if (current_state = floatpointnumber) {
			printf(" - float point number\n");
			current_state = start;
		}
		scanf("%c", &transition_char);
		if (transition_char != ' ') {
			printf("%c\n", transition_char);
		}
		current_state = transition(current_state, transition_char);
	}
	while (current_state != stop);
}


/**
 * Transition
 * @param state - current FMS state
 * @para transition_char - next char read from the input
 */
 state transition(state state, char transition_char) {
 	if (transition_char == ' ') {
 		switch (state) {
 			case build_num:
 					return number; // need to designate int and float
 					return;

 			case build_id:
 					return identifier;

 			default:
 				return start;
 		}
 	}


 	if (!isDigit(transition_char) || current_state = build_id) {
 		switch (transition_char) {
 			case '+': 
 				return addop;

 			case '-': 
 				return minusop;

 			case '*': 
 				return multop;

 			case '/':
 				return divop;

 			case '=':
 				return assignop;

 			case ';':
 				return stmttermop;

 			case '.':
 				return stop;

 			default:
 				return build_id;
 		}
 	}
 	
 	return build_num;

 	
 }
