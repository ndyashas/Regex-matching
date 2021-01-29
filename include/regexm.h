#ifndef REGEXM
#define REGEXM

#define INITIAL_MAX_NUM_ACTIVE_STATES 1

typedef struct NFA_STATE{
        struct NFA_STATE **next_states;  // Array of states that come next.
        struct NFA_STATE **prev_states;  // Array of states that came before.
	int number_of_next_states;       // Number of states that come next.
	int number_of_prev_states;       // Number of states that came before.
	char nfa_state_char;             // The current state's char data.
	int end_state;                   // Is this state an 'end' state?: 1 - Yes, 0 - No.
}NFA_STATE;

typedef struct NFA{
	struct NFA_STATE *init_state;    // The initial NFA state.
	struct NFA_STATE *end_state;     // The final state in the NFA.
}NFA;

void init_nfa(NFA **nfa);
void release_nfa(NFA **nfa);
void init_nfa_state(NFA_STATE **nfa_state);
void release_nfa_state(NFA_STATE **nfa_state);

int check_match(NFA **nfa, char *test_string, int len_test_string);

void _recursive_nfa_state_release(NFA_STATE *nfa_state);
#endif
