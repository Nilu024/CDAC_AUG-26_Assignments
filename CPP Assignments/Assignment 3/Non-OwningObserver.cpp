//============================================================================
// Name        : Non-OwningObserver.cpp
// Author      : Nilesh Desale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <iomanip>

using namespace std;

class AudioClip {

private:
    string name;
    double duration;

public:

    AudioClip(string name, double duration) {
        this->name = name;
        this->duration = duration;

        cout << "[Audio Clip Loaded]" << endl;
    }

    string getName() const {
        return name;
    }

    void display() const {
        cout << left;
        cout << setw(20) << "Audio Name" << ": " << name << endl;
        cout << setw(20) << "Duration" << ": "
             << duration << " seconds" << endl;
    }

    ~AudioClip() {
        cout << "[Audio Clip Released]" << endl;
    }
};

int main() {

    cout << "========================================" << endl;
    cout << "       GAME ASSET MANAGER" << endl;
    cout << "       Part C - weak_ptr" << endl;
    cout << "========================================" << endl;

    cout << "\nCreating Audio Clip..." << endl;

    auto audio = make_shared<AudioClip>("explosion", 3.5);

    cout << "\n--- Audio Clip Details ---" << endl;
    audio->display();

    weak_ptr<AudioClip> observer = audio;

    cout << "\n--- Event System ---" << endl;
    cout << "Event system is observing the Audio Clip." << endl;

    if (auto clip = observer.lock()) {
        cout << "Clip alive: " << clip->getName() << endl;
    }

    cout << "\n--- Unloading Audio Clip ---" << endl;

    audio.reset();

    if (observer.expired()) {
        cout << "Clip already unloaded." << endl;
    }
    else {
        cout << "Clip is still alive." << endl;
    }

    cout << "\n========================================" << endl;
    cout << "Program Ending..." << endl;
    cout << "========================================" << endl;

    return 0;
}
