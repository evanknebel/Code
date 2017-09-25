#pragma once

#include <iostream>
#include "television.h"

void Television::printVolume()
{
	std::cout << "Volume: " << volume << std::endl;
}
void Television::printChannel()
{
	std::cout << "Channel: " << channel << std::endl;
}
void Television::volumeUp()
{
	volume++;
	std::cout << "Volume: " << volume << std::endl;
}
void Television::volumeDown()
{
	volume--;
	std::cout << "Volume: " << volume << std::endl;
}
void Television::channelUp()
{
	channel++;
	std::cout << "Channel: " << channel << std::endl;
}
void Television::channelDown()
{
	channel--;
	std::cout << "Channel: " << channel << std::endl;
}