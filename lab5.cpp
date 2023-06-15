#include <iostream>
#include <list>
// List are containers that store a set of elements at unrelated locations
// <list>.push_back(value) adds values to the back of our list
// <list>.push_front(value) adds values to the front of our list

using namespace std;
class YoutubeChannel
{
private:
    string Name;
    string OwnerName;
    int SubscriberCount;
    list<string> PublishedVideoTitles; // Declaring the list

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
    void subscribe()
    {
        SubscriberCount++;
    };
    void unsubscribe()
    {
        (SubscriberCount > 0) ? SubscriberCount-- : SubscriberCount;
    };
    void getName() const
    {
        cout << "Name: " << Name << endl;
    };
    void setName(string newName)
    {
        Name = newName;
    }
    void publishVideos(string newTitle)
    {
        PublishedVideoTitles.push_back(newTitle);
    }
};

int main()
{
    YoutubeChannel ytChannel("dev12", "g.elvis");
    ytChannel.publishVideos("Learn JavaScript in 2hours");
    ytChannel.unsubscribe();
    ytChannel.GetInfo();
    for (int i = 0; i < 20; i++)
    {
        ytChannel.subscribe();
    }
    ytChannel.GetInfo();
};