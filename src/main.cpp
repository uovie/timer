#include <iostream>
#include <iomanip>
#include "timer.h"

using namespace std;
using namespace uovie;

int main()
{
    int ts;
    timer::duration p{};
    timer::duration q{};

    cout << "Please set the time span (s): ";
    cin >> ts;

    timer u(ts);
    u.start();
    cout << q.count() << endl;
    do {
        q = u.elapse();
        if (q != p) {
            cout << q.count() << endl;
            p = q;
        }
        
    } while (!u.is_end());

    cout << "Timer ends." << endl;
    return 0;
}