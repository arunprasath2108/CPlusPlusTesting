#include <iostream>

class Notification {
    
    public:
    std::string notification;

    Notification(std::string notification) {
        this->notification = notification;
    }

    std::string getNotification() {
        return notification;
    }
};

//abstract class
class Iterator {
    public:
    virtual bool hasNext() = 0;
    virtual Notification* next() = 0;
};

class NotificationIterator : public Iterator {

    std::vector<Notification*> notificationList;
    int position;

    public:
    NotificationIterator(std::vector<Notification*> list) {
        notificationList = list;
    }

    Notification* next() {
        Notification* notify = notificationList[position];
        position++;
        return notify;
    }

    bool hasNext() {
        if (position >= notificationList.size() || notificationList[position] == NULL)
            return false;
        else
            return true;
    }
};

class NotificationCollection {

    public:
    std::vector<Notification*> notificationList;

    NotificationCollection() {

        notificationList.push_back(new Notification("notify 1"));
        notificationList.push_back(new Notification("notify 2"));
        notificationList.push_back(new Notification("notify 3"));
    }

    void addNotification(Notification* message) {
        notificationList.push_back(message);
    }

    Iterator* getIterator() {
        return new NotificationIterator(notificationList);
    }
};

class NotificationBar {

    NotificationCollection collection;
    public:
    NotificationBar(NotificationCollection collection) {
        this->collection = collection;
    }

    void printNotification() {
        Iterator* it = collection.getIterator();

        while(it->hasNext()) {

            Notification* no = it->next();
            std::cout << no->getNotification() << std::endl;
        }
        
    }

};

int main() {

    NotificationCollection notificationCollection;
    NotificationBar note(notificationCollection);
    note.printNotification();
}