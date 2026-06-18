#include "XBasic/XLog.h"
#include "XBasic/XLog/XLogFlags.h"
#include "XBasic/XLog/XLogExport.h"

int main(int argc, char** argv) {

    xbasic::xlog::InitLogging(argv[0]);
    xbasic::xlog::XFlags_log_dir = std::string("../log");
    xbasic::xlog::XFlags_log_to_stdout = false;
    xbasic::xlog::XFlags_log_to_stderr = false;
    //xbasic::xlog::SetLogDestination(xbasic::xlog::XLOG_INFO, "../log/log");
    // xbasic::LogSystem l;
    LOG(INFO) << "111111111111111111111111111111111111111111111\n";
    LOG_INFO("%d", 1) << 22 << 123;
    for (int i = 0; i < 10; ++i) {

        LOG_EVERY_N(WARNING, 5) << i;
        LOG_EVERY_T(INFO, 5) << i;
        // l.log(xbasic::LogSystem::LogLevel::debug,"111111111");
    }
    xbasic::xlog::ShutdownLogging();

    return 0;
}
