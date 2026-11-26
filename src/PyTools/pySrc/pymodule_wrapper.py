"""Import the extension from the configured Python search path or current build directory."""

from pathlib import Path
import sys

if __package__:
    from . import dll_path_init
else:
    import dll_path_init

build_directory = str(Path.cwd())
if build_directory not in sys.path:
    sys.path.append(build_directory)

try:
    import pymodule
except ImportError as error:
    raise ImportError(
        "Run from the directory containing the built pymodule extension or add it to PYTHONPATH. "
        "Use the Python interpreter and compiler runtime selected at configure time."
    ) from error

__all__ = ["pymodule"]
