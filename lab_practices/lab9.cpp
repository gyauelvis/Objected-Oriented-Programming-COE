#include <iostream>
#include <string>
using namespace std;

class YouTubeChannel{ 

    friend ostream& operator<<(ostream& osObj,YouTubeChannel yt);

    private:
    int videos, likes;

    public:
    string Name;
    int SubscribersCount;

    YouTubeChannel(string name, int subscribersCount){
    Name = name;
    SubscribersCount = subscribersCount;
    }
    YouTubeChannel operator + (YouTubeChannel yt2){
        YouTubeChannel yt3("dev101",100);
        yt3.videos = videos + yt2.videos;
        yt3.likes = likes + yt2.likes;
        return yt3;
    }

YouTubeChannel operator++(){
    likes++;
    videos++;
    return *this; 
};

ostream& operator<<(ostream& osObj,YouTubeChannel yt){
    osObj <<Name;
    return osObj;
};

bool operator == (YouTubeChannel yt){
    if(videos == yt.videos && likes = yt.likes && Name = yt.Name && SubscribersCount == yt.SubscribersCount){

}
};

int main () {
    YouTubeChannel op1 = YouTubeChannel("Grade A Under A", 3680000); 
    YouTubeChannel op2("Grade A Under A",100);
    YouTubeChannel op3("Grade A Under A",100);
    
    
    cout << yt1;
    return 0;
}