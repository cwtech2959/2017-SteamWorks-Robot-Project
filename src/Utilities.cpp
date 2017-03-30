/*
 * Utilities.cpp
 *
 *  Created on: Feb 25, 2017
 */

double SecondsFromMilliSeconds(double timeInMilliSeconds)
{
	return timeInMilliSeconds * 0.001;
}

double Limit(double input, double min, double max)
{
	if (input > max)
	{
		input = max;
	}
	else if (input < min)
	{
		input = min;
	}

	return input;
}
