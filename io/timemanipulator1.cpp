
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <cstdlib>
using namespace std;

int main ()
{
    // process and print current date and time:
    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);
    tm* nowTM = localtime(&t);
    cout << put_time(nowTM,"date: %x\ntime: %X\n") << endl;

    // read new time (same date)
    tm time(*nowTM);                 // copy date for new time
    cout << "new time [HH:MM]: ";
    cin >> get_time(&time,"%H:%M");  // read new time
    if (!cin) {
        cerr << "invalid format read" << endl;
        exit(EXIT_FAILURE);
    }

    // process difference in minutes:
    auto tp = chrono::system_clock::from_time_t(mktime(&time));
    auto diff = chrono::duration_cast<chrono::minutes>(tp-now);
    cout << "difference: " << diff.count() << " minutes" << endl;
}
