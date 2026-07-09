#include "XBasic/XLog.h"
#include "XBasic/EventSystem/Event.h"


int main(int argc, char** argv) {

    xbasic::xlog::InitLogging(argv[0]);
    xbasic::xlog::XFlags_log_dir = std::string("../log");
    xbasic::Event<int> event;
    // xbasic::xlog::XFlags_log_to_stdout = true;
    // xbasic::xlog::XFlags_log_to_stderr = true;
    //xbasic::xlog::SetLogDestination(xbasic::xlog::XLOG_INFO, "../log/log");
    // xbasic::LogSystem l;
    xbasic::xlog::ShutdownLogging();

    return 0;
}
