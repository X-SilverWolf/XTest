"""Check the exported Python function against the built extension."""

from pymodule_wrapper import pymodule

if __name__ == "__main__":
    result = pymodule.add(1, 2)
    if result != 3:
        raise RuntimeError(f"Expected 3, received {result}")
    print(result)
