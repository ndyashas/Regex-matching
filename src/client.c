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
	NFA_STATE *a0, *b0, *c0, *d0, *e0, *f0, *g0, *h0;

	init_nfa_state(&a0);
	init_nfa_state(&b0);
	init_nfa_state(&c0);
	init_nfa_state(&d0);
	init_nfa_state(&e0);
	init_nfa_state(&f0);
	init_nfa_state(&g0);
	init_nfa_state(&h0);

	// 'a'
	a0->number_of_next_states = 1;
	a0->next_states = (NFA_STATE **)malloc(sizeof(NFA_STATE *)
					       *(a0->number_of_next_states));
	a0->next_states[0] = b0;
	a0->nfa_state_char = 'a';


	// 'b'
	b0->number_of_prev_states = 1;
	b0->prev_states = (NFA_STATE **)malloc(sizeof(NFA_STATE *)
					       *(b0->number_of_prev_states));
	b0->prev_states[0] = a0;
	b0->number_of_next_states = 2;
	b0->next_states = (NFA_STATE **)malloc(sizeof(NFA_STATE *)
					       *(b0->number_of_next_states));
	b0->next_states[0] = c0;
	b0->next_states[1] = d0;
	b0->nfa_state_char = 'b';


	// 'c'
	c0->number_of_prev_states = 1;
	c0->prev_states = (NFA_STATE **)malloc(sizeof(NFA_STATE *)
					       *(c0->number_of_prev_states));
	c0->prev_states[0] = b0;
	c0->number_of_next_states = 1;
	c0->next_states = (NFA_STATE **)malloc(sizeof(NFA_STATE *)
					       *(c0->number_of_next_states));
	c0->next_states[0] = e0;
	c0->nfa_state_char = 'c';


	// 'd'
	d0->number_of_prev_states = 1;
	d0->prev_states = (NFA_STATE **)malloc(sizeof(NFA_STATE *)
					       *(d0->number_of_prev_states));
	d0->prev_states[0] = b0;
	d0->number_of_next_states = 1;
	d0->next_states = (NFA_STATE **)malloc(sizeof(NFA_STATE *)
					       *(d0->number_of_next_states));
	d0->next_states[0] = e0;
	d0->nfa_state_char = 'd';


	// 'e'
	e0->number_of_prev_states = 2;
	e0->prev_states = (NFA_STATE **)malloc(sizeof(NFA_STATE *)
					       *(e0->number_of_prev_states));
	e0->prev_states[0] = c0;
	e0->prev_states[1] = d0;
	e0->number_of_next_states = 1;
	e0->next_states = (NFA_STATE **)malloc(sizeof(NFA_STATE *)
					       *(e0->number_of_next_states));
	e0->next_states[0] = f0;
	e0->nfa_state_char = 'e';


	// 'f'
	f0->number_of_prev_states = 1;
	f0->prev_states = (NFA_STATE **)malloc(sizeof(NFA_STATE *)
					       *(f0->number_of_prev_states));
	f0->prev_states[0] = e0;
	f0->number_of_next_states = 1;
	f0->next_states = (NFA_STATE **)malloc(sizeof(NFA_STATE *)
					       *(f0->number_of_next_states));
	f0->next_states[0] = g0;
	f0->nfa_state_char = 'f';


	// 'g'
	g0->number_of_prev_states = 2;
	g0->prev_states = (NFA_STATE **)malloc(sizeof(NFA_STATE *)
					       *(g0->number_of_prev_states));
	g0->prev_states[0] = f0;
	g0->prev_states[1] = g0;
	g0->number_of_next_states = 2;
	g0->next_states = (NFA_STATE **)malloc(sizeof(NFA_STATE *)
					       *(g0->number_of_next_states));
	g0->next_states[0] = g0;
	g0->next_states[1] = h0;
	g0->nfa_state_char = 'g';


	// 'h'
	h0->number_of_prev_states = 1;
	h0->prev_states = (NFA_STATE **)malloc(sizeof(NFA_STATE *)
					       *(h0->number_of_prev_states));
	h0->prev_states[0] = g0;
	h0->nfa_state_char = 'h';
	h0->end_state = 1;

	nfa->init_state = a0;
	nfa->end_state = h0;

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
