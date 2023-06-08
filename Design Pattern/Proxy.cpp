#include <iostream>

class InternetProtocol {

    public:
    virtual void connectInternet(std::string) = 0;
};

class Internet : public InternetProtocol {

    public:
    void connectInternet(std::string requestedSite) {
        if(!requestedSite.empty()) {
            std::cout << "You are accessing...  " << requestedSite << std::endl;
        }
    }
};

class ProxyInternet : public InternetProtocol {

    Internet connection;
    std::vector<std::string> blockedWebsite;

    public:
    void connectInternet(std::string requestedSite) {

        for(std::string url : blockedWebsite) {
            if(url == requestedSite) {
                std::cout << "You don't have access for " << requestedSite << std::endl;
                return;
            }
        }
        connection.connectInternet(requestedSite);
    }

    void deniedWebsite(std::vector<std::string> blockedURLs) {
        blockedWebsite = blockedURLs;
    }
};

int main() {

    ProxyInternet proxy;
    std::vector<std::string> blockedUrl;
    blockedUrl.push_back("whatsapp.com");
    blockedUrl.push_back("instagram.com");
    blockedUrl.push_back("twitter.com");

    proxy.deniedWebsite(blockedUrl);

    proxy.connectInternet("instagram.com");
    proxy.connectInternet("abc.com");
}