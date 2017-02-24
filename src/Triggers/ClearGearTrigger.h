/*
 * ClearGearTrigger.h
 *
 *  Created on: Feb 16, 2017
 *      Author: mriri
 */

#ifndef SRC_TRIGGERS_CLEARGEARTRIGGER_H_
#define SRC_TRIGGERS_CLEARGEARTRIGGER_H_

#include "WPILib.h"

class ClearGearTrigger: public Trigger
{
public:
	ClearGearTrigger();
	virtual ~ClearGearTrigger();

	bool Get() override;
};

#endif /* SRC_TRIGGERS_CLEARGEARTRIGGER_H_ */
