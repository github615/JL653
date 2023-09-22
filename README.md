The JL653 runs on Windows 11 and vs2019.

The user copies the JL653 distribution package JL653-20230912 to the local directory.

Users can set the following two environment variables in Windows 11:
Name: JL653DBG Value: 1 or 0 (1 is to output the JL653 error message to log, 0 is to cancel the output)
Name: JL653LOG Value: directory of the log file. The log file is in the format of jl653dbg-< date >.log

Users develop ARINC653 based applications in vs2019.
The user makes the following Settings in vs2019:
Add :< leading path >\jl653-20230912\include in Project Properties ->C/C++-> General -> Additional Include directory
In Project Properties ->C/C++-> Linker -> General -> Link library dependencies add :< lead path >\jl653-20230912\lib
In Project Properties ->C/C++-> Linker -> Input -> Additional dependencies add :jl653shell.lib

The user copies the dll file in jl653-20190912\lib to the directory where the exe file of the ARINC653-based application resides.
