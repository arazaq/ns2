/*
 TCL Example to use AgentMath


 set myagent [new Agent/AgentMathTcl]

 $myagent set tsp_var1_otcl 2
 $myagent set tsp_var2_otcl 6.5
 $myagent set tsp_result 0

 puts stdout "Calling Add"
 $myagent call-math-opt-add

 puts stdout "Calling Minus"
 $myagent call-math-opt-minus
 */

#include <stdio.h>
#include <string.h>

#include <iostream>

// Required by for routine
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

#include <sys/timeb.h>

#include "agent.h"
const int PATH_LEN = 255;

class AgentGL: public Agent {
public:
	AgentGL();
protected:
	int command(int argc, const char* const * argv);
private:
	double tsp_var1;
	double tsp_var2;
	double tsp_result;
	const char *tsp_str;
	char cmdflag;
	char Ns_Path[PATH_LEN];
	char Gl_Path[PATH_LEN];
	int ExecuteGL();
	int PrlExecuteGL();
	void CommandHandler(void);
	float ParseOpt(const char *str, float a, float b);
	static float Plus(float a, float b) {
		return a + b;
	}
	static float Minus(float a, float b) {
		return a - b;
	}
	static float Multiply(float a, float b) {
		return a * b;
	}
	static float Divide(float a, float b) {
		return a / b;
	}
	float DoMath(float a, float b, float (*result)(float, float)) {
		return result(a, b);    // call using function pointer
	}

};

static class AgentGLClass: public TclClass {
public:
	AgentGLClass() :
			TclClass("Agent/AgentGLTcl") {
	}
	TclObject* create(int, const char* const *) {
		return (new AgentGL());
	}
} class_tsp_agent;

AgentGL::AgentGL() :
		Agent(PT_UDP) {
	bind("tsp_var1_otcl", &tsp_var1);
	bind("tsp_var2_otcl", &tsp_var2);

}
int AgentGL::command(int argc, const char* const * argv) {

	if (argc >= 2) {
		if (strcmp(argv[1], "call-execute-ns") == 0) {
			memset(Ns_Path, 0, PATH_LEN);
			strcpy(Ns_Path, "/home/ali/Downloads/ns2/ns-2.35/ns");
			strcat(Ns_Path, " ");
			strcat(Ns_Path, argv[2]);
			strcat(Ns_Path, " > /dev/null &");
			cmdflag = 'n';
			ExecuteGL();
			return (TCL_OK);
		}
		if (strcmp(argv[1], "call-execute-gl") == 0) {

			memset(Gl_Path, 0, PATH_LEN);
			strcpy(Gl_Path, "gridlabd");
			strcat(Gl_Path, " ");
			strcat(Gl_Path, argv[2]);
			cmdflag = 'g';
			ExecuteGL();
			return (TCL_OK);
		}

		if (strstr(argv[1], "call-math-opt-")) {
			ParseOpt(argv[1], tsp_var1, tsp_var2);
			return (TCL_OK);
		}
		if (strstr(argv[1], "call-prlexecute")) {
		PrlExecuteGL();	
			return (TCL_OK);
		}
	}
	return (Agent::command(argc, argv));
}

void AgentGL::CommandHandler(void) {

}

float AgentGL::ParseOpt(const char *str, float a, float b) {
	Tcl& tcl = Tcl::instance();
	float val = -1;
	if (strstr(str, "add"))
		val = AgentGL::DoMath(a, b, &AgentGL::Plus);
	if (strstr(str, "minus"))
		val = DoMath(a, b, &Minus);
	if (strstr(str, "multiply"))
		val = DoMath(a, b, &Multiply);
	if (strstr(str, "divide"))
		val = DoMath(a, b, &Divide);
	tsp_result = val;

	tcl.evalf("puts \"  Result is : %f\"", tsp_result);

	return val;
}

int AgentGL::ExecuteGL() {

	string identifier;

	pid_t pid = fork();
	if (pid == 0) {

		identifier = "Child Process: ";

		struct timeb start, end;
		int diff;
		int i = 0;
		ftime(&start);

		FILE *fp;


		if (cmdflag == 'g')
			fp = popen(Gl_Path, "r");

		if (cmdflag == 'n')
			fp = popen(Ns_Path, "r");

		if (fp == NULL) {
			cout << "\nFailed to run command\n";
			return -1;
		}

		pclose(fp);

		ftime(&end);
		diff = (int) (1000.0 * (end.time - start.time)
				+ (end.millitm - start.millitm));

		if (cmdflag == 'n')
			printf("\nNS time to execute in milliseconds : '%u'\n", diff);
		if (cmdflag == 'g')
			printf("\nGL time to execute in milliseconds : '%u'\n", diff);

	} else if (pid < 0) {

		cerr << "Failed to fork" << endl;
		exit(1);

	} else {

		// parent process

		identifier = "Parent Process:";

		int status;

		if ((pid = wait(&status)) == -1)

			perror("\nwait error");
		else {
			if (WIFSIGNALED(status) != 0)
				printf("\nChild process ended because of signal %d.n",
						WTERMSIG(status));

			else if (WIFEXITED(status) != 0) {
				//printf("\nChild process ended normally; status = %d.n",		WEXITSTATUS(status));
			} else
				printf("Child process did not end normally.n");
		}
		//printf("\nParent process ended.n");
		exit(EXIT_SUCCESS);

	}

	// both parent and child.

	return 0;
}

int AgentGL::PrlExecuteGL() {

printf("\n%d) Parent process Started", getpid());

return 0;
}

