
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

	// Check if input file path was provided
	if(argc == 1) {
		printf("No file provided\n Usage: main.c [input file name]\n");
		return 1;
	}

	// Try to open file
	FILE* file = fopen(argv[1], "r");
	if(!file) {
		printf("Error opening file '%s'", argv[1]);
		return 1;
	}

	// Iterate through all lines
	char line[500];
	uint32_t sum = 0;
	while(fgets(line, sizeof(line), file)) {
		size_t i = 0;
		int first_digit = -1;
		int last_digit = -1;
		// Iterate through all characters
		while(line[i] != '\n' && i < sizeof(line)) {
			// Check if this character is a digit
			if(isdigit(line[i])) {
				// Determine which digit to set
				if(first_digit == -1) {
					first_digit = line[i] - '0';
				} else {
					last_digit = line[i] - '0';
				}
			}
			i++;
		}
		// There might only be one digit, in which case both digits are the same
		if(last_digit == -1) {
			last_digit = first_digit;
		}
		// Concatenate digits
		char buffer[3]; // Will always have two digits and one null terminator
		sprintf(buffer, "%d%d", first_digit, last_digit);
		int complete_num = atoi(buffer); // Always unsigned
		sum += complete_num;
	}
	printf("Final sum: %d\n", sum);
	return 0;	
}


