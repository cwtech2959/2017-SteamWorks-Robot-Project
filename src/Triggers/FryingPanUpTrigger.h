/*
 * FryingPanUpTrigger.h
 *
 *  Created on: Feb 25, 2017
 *      Author: mriri
 */

#ifndef SRC_TRIGGERS_FRYINGPANUPTRIGGER_H_
#define SRC_TRIGGERS_FRYINGPANUPTRIGGER_H_

#include <WPILib.h>

class FryingPanUpTrigger: public Trigger
{
public:
	FryingPanUpTrigger();
	virtual ~FryingPanUpTrigger();

	bool Get() override;
};

#endif /* SRC_TRIGGERS_FRYINGPANUPTRIGGER_H_ */
