/*
 * EXT_INT.h
 *
 * Created: 14/02/2022 10:28:48 ص
 *  Author: DELL
 */ 

#ifndef EXT_INT_H_
#define EXT_INT_H_

void EXT_INT_0_INIT(void);
void EXT_INT_0_SET_CALL_BACK(void (*)(void));

// Instructor said that they were not put in *_CFG.h, because they do not change configuration.
#define FALLING_EDGE 1
#define RISING_EDGE 2
#define LOGICAL_CHANGE 3
#define LOW_LEVEL 4

#endif /* EXT_INT_H_ */