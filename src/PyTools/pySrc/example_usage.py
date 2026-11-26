"""Use the XTest Python extension from the current build or PYTHONPATH."""

from pymodule_wrapper import pymodule

if __name__ == "__main__":
    print(f"pymodule.add(10, 20) = {pymodule.add(10, 20)}")
