#include <iostream>
#include <vector>

class Light {

    public:
        void turnOn() {
            std::cout << "Light is on" << std::endl;
        }

        void turnOff() {
            std::cout << "Light is off" << std::endl;
        }
};

class Command {
    public:
        virtual void execute() = 0;
};

class TurnOnLightCommand : public Command {

    Light* light;

    public:
    TurnOnLightCommand(Light* light) {
        this->light = light;
    }

    void execute() {
        light->turnOn();
    }
};

class TurnOffLightCommand : public Command {

    Light* light;

    public:
    TurnOffLightCommand(Light* light) { 
        this->light = light;
    }

    void execute() {
        light->turnOff();
    }
};

//invoker
class RemoteControl {

    std::vector<Command*> commands;

    public:
    void setCommand(Command* command) {
        commands.push_back(command);
    }

    void executeCommands() {
        for(Command* command : commands) {
            command->execute();
        }
    }
};

int main() {

    //receiver
    Light light;

    // creating commands
    Command* turnOnCommand = new TurnOnLightCommand(&light);
    Command* turnOffCommand = new TurnOffLightCommand(&light);

    RemoteControl remoteControl;

    remoteControl.setCommand(turnOnCommand);
    remoteControl.setCommand(turnOffCommand);

    remoteControl.executeCommands();
}
