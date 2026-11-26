# Running the Python examples / 运行 Python 示例

Build the `pymodule` target using the Python interpreter that will import it. In VS Code, select that interpreter with **Python: Select Interpreter**. To check the active interpreter and version, run the following command.

使用同一个 Python 解释器配置、构建和加载 `pymodule`。在 VS Code 中通过 **Python: Select Interpreter** 选择该解释器。可运行以下命令核对当前解释器及其版本。

```sh
python -c "import sys; print(sys.executable, sys.version)"
```

Run the examples from the directory containing the built `.pyd` or `.so`, or add that directory to `PYTHONPATH`. For a MinGW build on Windows, put the matching compiler's binary directory on `PATH`. The wrapper locates the runtime beside that compiler. This PowerShell example assumes the current directory contains the extension and `$Examples` holds the path to this folder.

从生成的 `.pyd` 或 `.so` 所在目录运行示例，或将该目录加入 `PYTHONPATH`。在 Windows 上使用 MinGW 构建时，将配套编译器的可执行目录加入 `PATH`，包装模块会在此找到运行库。以下 PowerShell 示例假定当前目录包含扩展模块，`$Examples` 是本示例文件夹的路径。

```powershell
python (Join-Path $Examples test.py)
python (Join-Path $Examples example_usage.py)
```

The first script checks that `pymodule.add(1, 2)` returns `3`. The second prints the sum of 10 and 20. Scripts in this folder can also use `from pymodule_wrapper import pymodule` directly.

第一个脚本验证 `pymodule.add(1, 2)` 的返回值为 `3`。第二个脚本输出 10 与 20 的和。本目录中的其他脚本也可以直接使用 `from pymodule_wrapper import pymodule`。
