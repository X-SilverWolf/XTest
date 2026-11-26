# XTest

TBasic opens an XGui window. TRunTime calls the XRunTime build tool and exits. Configure XTest to build both programs, or run the same commands from either program's directory to build it alone. Each enabled program's `cmake/Dependencies.cmake` requests its releases from `X_RELEASE_BASE_URL`. The standalone build stores first-party libraries in `intern/` and third-party packages in `extern/` under the project root. Set `XTEST_BUILD_TBASIC` or `XTEST_BUILD_TRUNTIME` to `OFF` to omit the corresponding program and its dependencies. In XGitRoot, the targets use the workspace versions.

TBasic 打开 XGui 窗口，TRunTime 调用 XRunTime 构建工具后退出。在 XTest 中配置可构建两个程序，也可以进入其中任一程序的目录执行相同的命令，单独构建该程序。独立构建时，每个启用的程序通过自己的 `cmake/Dependencies.cmake` 从 `X_RELEASE_BASE_URL` 取得发布包。自研库放在本工程的 `intern/`，第三方包放在 `extern/`。可将 `XTEST_BUILD_TBASIC` 或 `XTEST_BUILD_TRUNTIME` 设为 `OFF` 以跳过对应程序及其依赖。从 XGitRoot 构建时使用工作区提供的库版本。

```sh
cmake -S . -B build/intermediate/local -G Ninja -DCMAKE_BUILD_TYPE=Debug "-DX_RELEASE_BASE_URL=<release-location>"
cmake --build build/intermediate/local
```

LibTest builds a shared library with an `add` function. Enable `XTEST_BUILD_PYTHON` for the `pymodule` Python extension, `XTEST_BUILD_GUI` for the Qt Widgets TestTool, or `XTEST_BUILD_IMGALGO` for the ImgAlgo headers. Each also has its own CMake entry. ImgAlgo's nearest-neighbor routine is a placeholder.

LibTest 生成提供 `add` 函数的动态库。`XTEST_BUILD_PYTHON` 启用 Python 扩展 `pymodule`，`XTEST_BUILD_GUI` 启用 Qt Widgets 测试工具 TestTool，`XTEST_BUILD_IMGALGO` 启用 ImgAlgo 头文件。这些模块也都有独立的 CMake 入口。ImgAlgo 的最近邻算法目前只有占位实现。

`XTEST_BUILD_CUDA_DEMO` builds the interactive `Tests` program in `src/Tests`. It starts GoogleTest, queries the installed CUDA runtime and opens an OpenGL window. Its standalone entry downloads the GoogleTest, GLFW, GLAD and CUDA runtime packages. The older XPlat test fixtures still require unavailable XPlat APIs. In a workspace build, CMake uses `XThirdParty/<name>/` for vendor source and `XThirdParty/<name>-<version>/` for the OpenCV and CUDA SDKs. Qt and Python come from the selected development environment.

`XTEST_BUILD_CUDA_DEMO` 构建 `src/Tests` 中的交互式程序 `Tests`。它启动 GoogleTest、查询本机 CUDA 运行时并打开 OpenGL 窗口。独立入口会获取 GoogleTest、GLFW、GLAD 和 CUDA 运行库发布包。旧版 XPlat 测试用例仍依赖当前缺失的 XPlat 接口。工作区将第三方源码放在 `XThirdParty/<名称>/`，从 `XThirdParty/<名称>-<版本>/` 读取 OpenCV 与 CUDA SDK。Qt 和 Python 由所选开发环境提供。

Use `X::LibTest` or `X::ImgAlgo` when linking those libraries from another target. For workspace CTest runs, use a matching root configure/build/test preset. `Tests` is an interactive CUDA/OpenGL application.

其他目标通过 `X::LibTest` 或 `X::ImgAlgo` 链接对应的库。在工作区运行 CTest 时，依次使用根工程的同名配置、编译与测试预设。`Tests` 是交互式 CUDA/OpenGL 应用。
