/*
 * ClearGearTrigger.h
 *
 *  Created on: Feb 16, 2017
 *      Author: mriri
 */

#ifndef SRC_TRIGGERS_CLEARGEARTRIGGER_H_
#define SRC_TRIGGERS_CLEARGEARTRIGGER_H_

#include <Buttons/Trigger.h>

class ClearGearTrigger: public frc::Trigger {
public:
	ClearGearTrigger();
	virtual ~ClearGearTrigger();

	bool Get() override;

};

#endif /* SRC_TRIGGERS_CLEARGEARTRIGGER_H_ */
