#include <stdlib.h>
#include "regexm.h"


void init_nfa(NFA **nfa)
{
}

void release_nfa(NFA **nfa)
{
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
