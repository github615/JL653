JL653 is an ARINC653-based application emulation debugging tool presented as a DLL. It can truly simulate the functional behavior stipulated by the ARINC653 standard, so that developers can efficiently and quickly develop and debug applications based on ARINC653 in the PC Windows environment.

JL653 provides the following services as required by ARINC 653 Part 1:

Communication within partitions, including buffers, blackboard, semaphore, and events.
Process management, including process creation, start, suspend, resume, stop, etc.
Time management, including timing wait and periodic wait.

JL653 does not provide inter-partition communication, including queuing messages and sampling messages.

Arinc653-based applications developed with JL653 can be ported to any ARINC653-compliant target machine platform without any changes.

The core of JL653 is implemented in Ada language.
