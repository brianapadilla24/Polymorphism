//Briana Padilla
//Polymorphism


#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel {

private:
	string Name;
	int SubscribersCount;
	list<string> PublishedVideoTitles; //available only in this class

protected:
	string OwnerName; // Available in derived classes
  int ContentQuality;

public: //Base class
	YouTubeChannel(string name, string ownerName) {
		Name = name;
		OwnerName = ownerName;
		SubscribersCount = 0;
    ContentQuality = 0;
	}

	void GetInfo() {  //Writes out information about youtube channel
		cout << "Name: " << Name << endl;
		cout << "OwnerName: " << OwnerName << endl;
		cout << "SubscribersCount: " << SubscribersCount << endl;
		cout << "Videos: " << endl;
		for (string videoTitle : PublishedVideoTitles) {
			cout << videoTitle << endl;
		}
	}

	void Subscribe() {    //Increase the # of Subscribers
		SubscribersCount++;
	}

	void Unsubscribe() {  //Decrease the # of Subscribers
		if (SubscribersCount > 0)
			SubscribersCount--;
	}

	void PublishVideo(string title) {  //Add title of Youtube video
		PublishedVideoTitles.push_back(title);
	}

  void CheckAnalytics() {
    if (ContentQuality<5)
      cout << Name << "This is bad quality." << endl;
    else
      cout << Name << " Has great content" << endl;
  }
};  //That whole sector is the base class

//Specific type of Youtube Channel, that inherites from that base class 
class CookingYouTubeChannel : public YouTubeChannel {
public:
	CookingYouTubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName) { //Own Contructor CookingYoutubeChannel:(Invoked) Constructor from Base Class

	}
	void Practice() { //Method, practice and what it does (cooking)/implementation
		cout << OwnerName << " is practicing cooking, learning new recipes, experimenting with spices..." << endl;
    ContentQuality++;
	}
};

class SingersYouTubeChannel : public YouTubeChannel {
public:
	SingersYouTubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName) { //Own Contructor SingersYoutubeChannel:(Invoked) Constructor from Base Class

	}
	void Practice() { //Method, practice and what it does (singing)/implementation
		cout << OwnerName << " is taking singing classes learning new songs, learning how to dance..." << endl;
    ContentQuality++;
	}
};



int main()
{
	CookingYouTubeChannel cookingYtChannel("Amy's Kitchen", "Amy");
  SingersYouTubeChannel singersYtChannel("JohnSings", "John");

  //Invoke methods, implement practice method, different implementations but same method name:Practice
  cookingYtChannel.Practice();
  singersYtChannel.Practice();
  singersYtChannel.Practice();
  singersYtChannel.Practice();
  singersYtChannel.Practice();
  singersYtChannel.Practice();
  singersYtChannel.Practice();


  //pointers to point to an object in derived class
  YouTubeChannel* yt1=&cookingYtChannel; 
  YouTubeChannel* yt2=&singersYtChannel;

  //invoked check Analytics methods using pointers of base class
  yt1->CheckAnalytics();
  yt2->CheckAnalytics();
  
	system("pause>0");
}