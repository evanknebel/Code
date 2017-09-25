#pragma once

#include <string>

class Television
{
private:
	int channel = 3;
	int volume = 10;

public:
	void printVolume();
	void printChannel();
	void volumeUp();
	void volumeDown();
	void channelUp();
	void channelDown();
};