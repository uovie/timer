// Timer
#ifndef TIMER_H_
#define TIMER_H_

// standard C++ headers
#include <chrono>
#include <ratio>

namespace uovie {

    class timer {
    public:
        using time_point = std::chrono::time_point<std::chrono::_V2::system_clock, std::chrono::nanoseconds>;
        using duration = std::chrono::duration<int, std::ratio<1, 1>>;

        timer() = default;
        timer(int s) { span = duration{ s }; }

        void start() { ti = std::chrono::system_clock::now(); }

        duration elapse() {
            tf = std::chrono::system_clock::now();
            pass = std::chrono::duration_cast<std::chrono::seconds>(tf - ti);
            return pass; 
        }

        bool is_end() const {
            if (pass >= span)
                return true;
            else
                return false;
        }

    private:
        time_point ti;
        time_point tf;
        duration span;
        duration pass;
    };

} // !uovie
#endif // !TIMER_H_