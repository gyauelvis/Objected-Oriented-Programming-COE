#include <iostream>
using namespace std;

class TV
{
    int channel, volumeLevel;
    bool on;

public:
    TV();
    void turnOn();
    void turnOff();
    void setChannel(int newChannel);
    void setVolume(int newVolumeLevel);
    void channelUp();
    void channelDown();
    void volumeUp();
    void volumeDown();
};

TV::TV() : channel(1), volumeLevel(1), on(false){};
void TV::turnOn() { on = true; };
void TV::turnOff() { on = false; }
void TV::setChannel(int newChannel)
{
    (newChannel <= 120 && newChannel > 0) ? channel = newChannel : channel;
}
void TV::setVolume(int newVolumeLevel)
{
    (newVolumeLevel <= 120 && newVolumeLevel > 0) ? volumeLevel = newVolumeLevel : volumeLevel;
}
void TV::channelUp()
{
    (channel < 120 && channel > 0) ? channel++ : channel;
}

void TV::channelDown()
{
    (channel < 120 && channel > 0) ? channel-- : channel;
}
void TV::volumeUp()
{
    (volumeLevel >= 1 && volumeLevel < 7) ? volumeLevel++ : volumeLevel;
}
void TV::volumeDown()
{
    (volumeLevel > 1 && volumeLevel < 7) ? volumeLevel-- : volumeLevel;
};
