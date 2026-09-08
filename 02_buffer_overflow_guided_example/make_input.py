#!/usr/bin/env python3
"""Create controlled input for the guided classroom demonstration."""

from pathlib import Path

PAYLOAD_LENGTH = 80
Path("crash_input.txt").write_text("A" * PAYLOAD_LENGTH, encoding="ascii")
print(f"Created crash_input.txt with {PAYLOAD_LENGTH} A characters")
