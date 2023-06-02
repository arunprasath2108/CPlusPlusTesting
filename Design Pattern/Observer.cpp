#include<iostream>

//Observer class
class Subscriber {

    public:
    void updateFromYoutuber() {
        std::cout << "Got a update from youtuber." << std::endl;
    }
};

//Notifier class, notifies all observer
class Youtuber {

    public:
    std::vector<Subscriber*> subscribers;

    void addSubscriber(Subscriber* sub) {
        subscribers.push_back(sub);
    }

    void notifySubscriber() {

        for(Subscriber* sub : subscribers) {
            sub->updateFromYoutuber();
        }
    }

    void addNewContent(std::string content) {
        if(!content.empty()) {
            notifySubscriber();
        }
    }
};

int main() {

    Youtuber* person = new Youtuber();

    Subscriber* sub1 = new Subscriber();
    Subscriber* sub2 = new Subscriber();
    Subscriber* sub3 = new Subscriber();

    person->addSubscriber(sub1);
    person->addSubscriber(sub2);
    person->addSubscriber(sub3);

    person->addNewContent("Added a new Video.");


}