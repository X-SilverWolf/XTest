#include "XBasic/XLog.h"

int main(int argc, char** argv) {

    xbasic::xlog::InitLogging(argv[0]);
    LOG(INFO) << "111111111111111111111111111111111111111111111\n";
    for (int i = 0; i < 10; ++i) {

        LOG_EVERY_N(INFO, 5) << i;
        LOG_EVERY_T(INFO, 5) << i;
    }


    return 0;
}
