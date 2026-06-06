//
// Created by XSilver on 2026/5/26.
//
#include <iostream>
#include <thread>

#include "XBasic/XLog/XLogTime.h"
#include <chrono>
#include <iostream>

int main() {
    xbasic::XLogTime st(std::chrono::system_clock::now());
    std::cout <<  st.year() + 1900 << '/' << st.month() + 1 << '/' << st.day()
    << ' ' << st.hour()  << ':' << st.min() << ':' << st.sec() << std::endl;

    return 0;
}
