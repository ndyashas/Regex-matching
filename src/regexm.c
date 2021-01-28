#include <stdio.h>
#include <stdlib.h>
#include "regexm.h"


void init_nfa(NFA **nfa)
{
	*nfa = (NFA *)malloc(sizeof(NFA));
	(*nfa)->init_state = (*nfa)->end_state = NULL;
}

void release_nfa(NFA **nfa)
{
	if (nfa == NULL || *nfa == NULL)
		return;

	_recursive_nfa_state_release((*nfa)->init_state);

	free(*nfa);
}

void _recursive_nfa_state_release(NFA_STATE *nfa_state)
{
	int i, j;

	if (nfa_state == NULL)
		return;

	for (i = 0; i < nfa_state->number_of_next_states; ++i)
		if (nfa_state != nfa_state->next_states[i])
			_recursive_nfa_state_release(nfa_state->next_states[i]);

	for (i = 0; i < nfa_state->number_of_prev_states; ++i) {
		for (j = 0; j < (nfa_state->prev_states[i])->number_of_next_states; ++j) {
			if (nfa_state == (nfa_state->prev_states[i])->next_states[j]) {
				(nfa_state->prev_states[i])->next_states[j] = NULL;
			}
		}
	}

	release_nfa_state(&nfa_state);
}

void init_nfa_state(NFA_STATE **nfa_state)
{
	*nfa_state = (NFA_STATE *)malloc(sizeof(NFA_STATE));
	(*nfa_state)->next_states = NULL;
	(*nfa_state)->prev_states = NULL;
	(*nfa_state)->number_of_next_states = 0;
	(*nfa_state)->number_of_prev_states = 0;
	(*nfa_state)->nfa_state_char = 0;
	(*nfa_state)->end_state = 0;
}

void release_nfa_state(NFA_STATE **nfa_state)
{
	if (nfa_state == NULL || *nfa_state == NULL)
		return;

	if ((*nfa_state)->next_states != NULL)
		free((*nfa_state)->next_states);

	if ((*nfa_state)->prev_states != NULL)
		free((*nfa_state)->prev_states);

	free(*nfa_state);
}

int check_match(NFA **nfa, char *test_string)
{
	return 0;
}
