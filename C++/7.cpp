#include <iostream>
using namespace std;

void testMe();

class Car {
    private:
        bool isRunning = false;
        int gear = 0;
        int velocity = 0;

    public:
        Car() {
            cout << "Car: Constructor here!" << endl;
        }

        ~Car() {
            cout << "Car: Destructor here - Off to the junkyard: goodbye cruel world!" << endl;
        }

        bool setEngineOn() {
            isRunning = true;

            return true;
        }

        bool setEngineOff() {
            if (gear != 0) {
                return false;
            }
            isRunning = false;

            return true;
        }

        bool getIsEngineRunning() {
            return isRunning;
        }

        bool setGear(int newGear) {
            if (gear == 0) {
                gear = newGear;

                return true;
            } else if (newGear == 0 && velocity == 0) {
                gear = newGear;

                return true;
            }

            return false;
        }

        int getGear() {
            return gear;
        }

        bool setVelocity(int newVelocity) {
            if (gear != 0) {
                velocity = newVelocity;

                return true;
            }

            return false;
        }

        int getVelocity() {
            return velocity;
        }
};

int main() {
    testMe();
}

void testMe() {
    int errorCount= 0;
    int testCount = 1;

    cout << "\nTest #" << testCount++ << ": Creating a new car..." << endl;
    Car c;
    cout << "OK!" << endl;
    cout << "\nTest #" << testCount++ << ": Starting the car..." << endl;
    if (!c.setEngineOn()) {
        cout << "Error: I could not start the engine in a new instance of the car. Abort" << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Is the engine running ok?" << endl;
    if (!c.getIsEngineRunning()) {
        cout << "Error: The engine should be running. Abort." << endl;
        errorCount++;

    return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Putting the car in drive..." << endl;
    if (!c.setGear(1)) {
        cout << "Error: I could not put the car in drive. Abort" << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Is the car in drive?..." << endl;
    if (!c.getIsEngineRunning()) {
        cout << "Error: The engine should be running. Abort" << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }
    cout << "\nTest #" << testCount++ << ": Can I put the car in REVERSE while driving...." << endl;
    if (c.setGear(-1)) {
        cout << "Error: I should not be able to put the car in reverse while driving. Abort" << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Are we still in DRIVE?" << endl;
    if (c.getGear() != 1) {
        cout << "Error: We should still be in DRIVE. Abort" << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Accelerating while driving to 10 MPH...." << endl;
    if (!c.setVelocity(10)) {
        cout << "Error: The accelerator failed. Abort" << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Are we driving at 10 MPH?...." << endl;
    if (c.getVelocity() != 10) {
        cout << "Error: The getAccelerator failed to return 10. Abort" << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Can we put the car in PARK while driving 10 MPH?....that would be very bad..." << endl;
    if (c.setGear(0)) {
        cout << "Error: The car was put into PARK while driving!!! There goes the transmission.Abort." << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Are we still in DRIVE?" << endl;
    if (c.getGear() != 1) {
        cout << "Error: We should still be in DRIVE. Abort" << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Are we still driving at 10MPH? (we should be) ?" << endl;
    if (c.getVelocity() != 10) {
        cout << "Error: We should be travelling at 10 MPH. Abort" << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Can we reduce speed to zero MPH while driving?...." << endl;
    if (!c.setVelocity(0)) {
        cout << "Error: The car would not let us decelerate to zero from 10 MPH.Brace for Impact!Abort." << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Are we stopped (we should have zero velocity) ?" << endl;
    if (c.getVelocity() != 0) {
        cout << "Error: We should be travelling at zero MPH. Abort" << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Are we in still in DRIVE (we should be)?" << endl;
    if (c.getGear() != 1) {
        cout << "Error: We should be in DRIVE. Abort" << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": While we are in moving forward in DRIVE, can we turn the engine OFF?...." << endl;
    if (c.setEngineOff()) {
        cout << "Error: The car should NOT let us turn the engine off while we are in DRIVE.We must be in PARK to turn off the engine.Abort." << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Is the engine still RUNNING (it should be)?" << endl;
    if (c.getIsEngineRunning() != true) {
        cout << "Error: The engine should still be RUNNING! Abort" << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Now that we have stopped, can we put the car in PARK?...." << endl;
    if (!c.setGear(0)) {
        cout << "Error: The car would not let us switch the gear to PARK after we stopped.Abort." << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Are we in PARK?" << endl;
    if (c.getGear() != 0) {
        cout << "Error: We should be in PARK. Abort" << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Now that we are in PARK, can we put the car in REVERSE?...." << endl;
    if (!c.setGear(-1)) {
        cout << "Error: The car would not let us switch the gear to REVERSE after we had been in park.Abort." << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Are we in REVERSE?" << endl;
    if (c.getGear() != -1) {
        cout << "Error: We should be in REVERSE. Abort" << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Now that we are in REVERSE, can we accelerate to 10 MPH (backwards)?...." << endl;
    if (!c.setVelocity(10)) {
        cout << "Error: The car would not let us increase velocity while in REVERSE.Abort." << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Are we driving backwards at 10 MPH?...." << endl;
    if (c.getVelocity() != 10) {
        cout << "Error: The getAccelerator failed to return 10. Abort" << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Now that we are moving backwards in REVERSE, we should NOT be able to put the car in DRIVE...." << endl;
    if (c.getVelocity() >0 && c.setGear(1)) {
        cout << "Error: The car should NOT let us switch the gear to DRIVE unless we are in PARK.Abort." << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Are we still in REVERSE (we should be)?" << endl;
    if (c.getGear() != -1) {
        cout << "Error: We should still be in REVERSE. Abort" << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": While we are in moving backwards in REVERSE, can we turn the engine OFF (let's hope not)?...." << endl;
    if (c.setEngineOff()) {
        cout << "Error: The car should NOT let us turn the engine off while we are driving backwards in REVERSE.We must be in PARK.Abort." << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Is the engine still ON (it should be)?" << endl;
    if (c.getGear() != -1) {
        cout << "Error: The engine should still be ON. Abort" << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": While we are in moving backwards in REVERSE, can we change gears to PARK (let's hope not)?...." << endl;
    if (c.getVelocity() > 0 && c.setGear(0)) {
        cout << "Error: The car should NOT let us switch to PARK while we aer moving in REVERSE.We must come to a stop first.Abort." << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Are we still in REVERSE (we should be)?" << endl;
    if (c.getGear() != -1) {
        cout << "Error: We should still be in REVERSE. Abort" << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": While we are in moving backwards in REVERSE, can we change speed to zero MPH (let's hope so)?...." << endl;
    if (!c.setVelocity(0)) {
        cout << "Error: The car would not let us reduce speed to zero MPH while moving in REVERSE.Close your eyes and hope.Abort." << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Are we finally stopped (we should be)?" << endl;
    if (c.getVelocity() != 0) {
        cout << "Error: We should be stopped (zero velocity). Abort" << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Are we still in REVERSE (we should be)?" << endl;
    if (c.getGear() != -1 ) {
        cout << "Error: We should still be in REVERSE (even though we have zero velocity). Abort" << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Now that we have come to a stop, while in REVERSE, can we change gears to PARK?...." << endl;
    if (!c.setGear(0)) {
        cout << "Error: The car would not let us switch to PARK now that we are stopped, in REVERSE.Abort." << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Are we back in PARK (we should be)?" << endl;
    if (c.getGear() != 0) {
        cout << "Error: We should still be in PARK. Abort" << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Now that we have come to a stop, and we are in PARK, can we turn off the engine?...." << endl;
    if (!c.setEngineOff()) {
        cout << "Error: The car engine would not turn off now that we are stopped, in PARK.Abort." << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Is the engine RUNNING (it should be off)?" << endl;
    if (c.getIsEngineRunning()) {
        cout << "Error: The engine should be OFF. Abort" << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Now that the engine is off and we are stopped, in PARK, can we change velocity? (that would be magical) ?...." << endl;
    if (c.setVelocity(10) == true) {
        cout << "Error: The car engine is off and we are in PARK, but we can change the speed?.Humans are not ready for this feature yet.Abort." << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    cout << "\nTest #" << testCount++ << ": Is the velocity still zero (it should be zero)?" << endl;
    if (c.getVelocity() != 0) {
        cout << "Error: The velocity should be zero. Abort" << endl;
        errorCount++;

        return;
    } else {
        cout << "OK!" << endl;
    }

    if (errorCount == 0) {
        cout << "\n****** Congradulations! You have passed your driving test with distinction!" << endl;
    } else {
        cout << "Hmm... there are a few things you will need add to your car to pass your driving test... " << endl;
    }
}
