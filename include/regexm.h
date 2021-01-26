#ifndef REGEXM
#define REGEXM


typedef struct NFA_STATE{
        struct NFA_STATE *next_states;   // Array of states that come next.
	int number_of_next_states;       // Number of states that come next.
	char nfa_state_char;             // The current state's char data.
	int end_state;                   // Is this state an 'end' state?: 1 - Yes, 0 - No.
}NFA_STATE;

typedef struct NFA{
	struct NFA_STATE *init_state;    // The initial NFA state.
    	struct NFA_STATE **end_states;   // The final states in the NFA. This will be
	                                 // used for stringing NFAs together.
}NFA;

void init_nfa(NFA **nfa);
void release_nfa(NFA **nfa);
void init_nfa_state(NFA_STATE **nfa_state);
void release_nfa_state(NFA_STATE **nfa_state);

int check_match(NFA **nfa, char *test_string);

#endif
