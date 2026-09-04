#include "XBasic/XLog.h"
#include "XBasic/App/AppBase.h"
#include "XBasic/App/GLWindow.h"
#include "XBasic/App/MainLoop.h"
#include "XBasic/EventSystem/Event.h"


int main(int argc, char** argv) {

    xbasic::xlog::InitLogging(argv[0]);
    xbasic::xlog::XFlags_log_dir = std::string("../../../Log");
    xbasic::GLWindowSettings settings;
    settings.setSize(1024, 768);
    settings.windowMode = xbasic::eWindowMode_Window;
    std::shared_ptr<xbasic::MainLoop> mainLoop = std::shared_ptr<xbasic::MainLoop>(new xbasic::MainLoop);
    auto window = mainLoop->createWindow(settings);
    mainLoop->run(window, std::make_shared<xbasic::AppBase>());
    mainLoop->loop();
    xbasic::xlog::ShutdownLogging();

    return 0;
}
