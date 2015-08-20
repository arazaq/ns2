# ns2
GridLab-D And ns-2

--Introduction--

This is a fork to ns2 to demonstrate co-simualtion of Power and Communications.

--How To Test--

Directory 'ns-2.35/examples/scripts' contains scripts to run the simulations in three different settings:

1) ns2 Only 

2) GridLab-D Only 

3) ns2 and GridLab-D combined



--How To Setup--

1) Download GridLab-D and do local installtion. Binaries should be in your terminal's path or edit the 'ns-2.35/examples/scripts' with gridlbd path.

2) Clone this repository and compile. How to compile and setup ns2 is explained in 'Readme-ns2-gridlabd' file.

3) Run the test scripts.


--Background--

There are a number of Power and Network simulators with open and commercial licenses. However, recently there
has been a trend for a proven and open-source co-simulator which combines power and communication technologies in a single interface with proven solutions.

A basic prototype of co-simulation based on GridLab-D and ns2 is presented. Integration of GridLab-D and ns-2 was accomplished at very early stages while coupling both the independent and whole
applications in a single parent process. ns-2 provides an entry point to start the co-simulation. A new agent called 'AgentGL' was
developed which is a bare-bone agent derived from ns-2's agent class. AgentGL is a C++ application which issues
‘exec’ system call in newly forked process and wait for its return. The forked process executes GridLab-D with GLM file as
input which is provided by TCL script at the beginning of simulation. AgentGL has the capability to be called from
TCL script and capable to invoke all available ns-2’s functionalities. AgentGL offers published methods that are
visible from TCL scope. In order to run GridLab-D simulator, the user should create a GridLab-D's GLM script file, and invoke the
method 'callexecute-gl' within TCL script.


This attempt should be considered as a proof of concept rather a complete solution.

