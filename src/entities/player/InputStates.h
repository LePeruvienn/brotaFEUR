#ifndef INPUTSTATES_H
#define INPUTSTATES_H


namespace Player {

	/**
	 * Basic flag enum to know what are the currents inputs of the user
	 * Added a flag system to it so we can handle multiple states at once
	 */
	enum InputStates {
		IDLE  = 0,      // 000
		UP    = 1 << 0, // 0001  (1)
		DOWN  = 1 << 1, // 0010  (2)
		LEFT  = 1 << 2, // 0100  (4)
		RIGHT = 1 << 3  // 1000  (8)
	};
}

#endif // INPUTSTATES_H
