#include "timer.hpp"

/*Timer Timer::Instance()
{
    if(sInstance == nullptr)
    sInstance = new Timer;
    return sInstance;

} */
Timer::Timer()
{
    Reset();
    echelle=1.0f;
    mDureeTime = std::chrono::duration<float>(0.0f);
}
Timer::~Timer(){}
void Timer::Reset()
{
    StartPoint = std::chrono::system_clock::now();

}
float Timer::DureeTime(){
    return mDureeTime.count(); // a voirrr !!
}
void Timer::echelleT(float time)
{
    echelle = time;
}
float Timer::echelleT()
{
    return echelle;
}
void Timer::calcul()
{
    mDureeTime = std::chrono::system_clock::now() - StartPoint;
}
