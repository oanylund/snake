/**
* @file mealymachine.h
* @brief this header file will contain all required
* definitions and basic utilities functions to run a mealy statemachine.
*
* @author Morten Bertheussen
*
* @date 03.09.2016
*/
#ifndef _STATEMACHINE_H
#define _STATEMACHINE_H

typedef enum state_code { ERROR, ENTRY, FOO, BAR } state_t;
typedef enum direction_code { SUCCESS, FAIL, REPEAT } direction_t;
typedef struct transition_table { state_t current_state; direction_t direction_code; state_t next_state; } logic_t;

/*prototype*/
state_t get_next_state(state_t current_state, direction_t *direction_code);
#endif /*_STATEMACHINE_H*/
