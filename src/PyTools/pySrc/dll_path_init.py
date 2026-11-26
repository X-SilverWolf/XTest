"""Register the active MinGW runtime for Windows extension modules."""

import os
from pathlib import Path
from shutil import which

_dll_directories = {}


def add_mingw_dll_path():
    """Keep the DLL search handle alive for as long as this module is loaded."""
    if os.name != "nt":
        return
    compiler = which("g++.exe")
    if compiler:
        directory = Path(compiler).resolve().parent
        if directory not in _dll_directories:
            _dll_directories[directory] = os.add_dll_directory(str(directory))


add_mingw_dll_path()
