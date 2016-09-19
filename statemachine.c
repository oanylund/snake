#include "statemachine.h"
//TODO: create a method to generate the transition table for use in multiple state machines.
logic_t transition_table[] =
{
	{ ENTRY, SUCCESS,	FOO },
	{ ENTRY, FAIL,		ERROR },
	{ ENTRY, REPEAT,	ENTRY },
	{ FOO,   SUCCESS,	BAR },
	{ FOO,   FAIL,		ERROR },
	{ FOO,   REPEAT,	FOO },
	{ BAR,   SUCCESS,	FOO },
	{ BAR,   FAIL,		ERROR },
	{ BAR,   REPEAT,	BAR }
};

/*! \brief
* \param current_state		- the statemachines current state.
* \param direction_code		- the statemachines direction code.
* \return next_state		- statemachines next state.
*/
state_t get_next_state(state_t current_state, direction_t *direction_code)
{
	unsigned char i = 0;
	while('\0' != transition_table[i].current_state)
	{
		if (transition_table[i].current_state == current_state && transition_table[i].direction_code == *direction_code)
		{
			*direction_code = REPEAT;
			return transition_table[i].next_state;
		}
		i++;
	}
	return ERROR;
}
