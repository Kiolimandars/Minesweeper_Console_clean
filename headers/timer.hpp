#ifndef _TIMER_H
#define _TIMER_H
#include <chrono>

class Timer {
    private:
    static Timer sInstance;
    std::chrono::system_clock::time_point StartPoint;
    std::chrono::duration<float> mDureeTime;
    float echelle;

    public:
    static Timer Instance();
    void Reset();
    float DureeTime();
    void echelleT(float t= 1.0f); //setteur
    float echelleT(); //getteur
    void calcul();
    Timer();
    ~Timer();
};

#endif