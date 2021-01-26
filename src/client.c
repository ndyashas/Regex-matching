/*
 * Example client file.
 * This client file constructs a simple NFA, and uses it to compare if a simple string
 * matches the Regex which the NFA represents.
 * The example regex here is: ab(c|d)ef(g)*h
 */

#include <stdlib.h>
#include <stdio.h>
#include "regexm.h"

int main()
{
	NFA *nfa = NULL;
	char *test_string = "abdefggh";

	// Initialize the nfa
	init_nfa(&nfa);

	// Construct the nfa

	// check if a given string matches a regex
	if (check_match(&nfa, test_string)) {
		printf("The test string matches the regex.\n");
	}
	else {
		printf("The test string does not match the regex.\n");
	}

	// Release the NFA
	release_nfa(&nfa);

	return 0;
}
