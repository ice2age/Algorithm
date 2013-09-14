@echo off
setlocal EnableDelayedExpansion
set exclude=.cpp.c.bat.
for %%f in (*.*) do (
   if /I "%exclude%" == "!exclude:%%~Xf.=!" del "%%f"
)