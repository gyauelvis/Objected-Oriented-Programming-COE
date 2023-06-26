#include <iostream>
#include <list>

using namespace std;
class YoutubeChannel
{
private:
    string Name;
    string OwnerName;
    int SubscriberCount;
    list<string> PublishedVideoTitles;

public:
    YoutubeChannel(string name, string ownerName)
    {
        Name = name;
        OwnerName = ownerName;
        SubscriberCount = 0;
    }
    void GetInfo() const
    {
        cout << "Name: " << Name << endl;
        cout << "Owner Name: " << OwnerName << endl;
        cout << "Number of Subscribers: " << SubscriberCount << endl;
        cout << "Videos: " << endl;
        for (string videoTitle : PublishedVideoTitles)
        {
            cout << videoTitle << endl;
        }
    }
    void Subscribe()
    {
        SubscriberCount++;
    }
    void Unsubscribe()
    {
        if (SubscriberCount > 0)
        {
            SubscriberCount--;
        }
    }
    void setName(string new_Name)
    {
        Name = new_Name;
    }
    void getName()
    {
        cout << Name << endl;
    }
    void PublishedVideo(string video1) 
    {
        PublishedVideoTitles.push_back(video1);
    }
};
int main()
{
    YoutubeChannel ytChannel("Makeup studio", "Agnes");
    ytChannel.PublishedVideo("Makeup videos");
    ytChannel.Unsubscribe();
    ytChannel.GetInfo();
    for (int i = 0; i < 20; i++)
    {
        ytChannel.Subscribe();
    }
    ytChannel.GetInfo();

    return 0;
}