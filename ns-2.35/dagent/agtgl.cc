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


#include "agent.h"

class AgentGL : public Agent {
public:
        AgentGL();
protected:
        int command(int argc, const char*const* argv);
private:
        double    tsp_var1;
        double tsp_var2;
        double   tsp_result;
        const char *tsp_str;
        int ExecuteGL();
        void   CommandHandler(void);
        float ParseOpt(const char *str , float a, float b);
        static float Plus (float a, float b) { return a+b; }
        static float Minus (float a, float b) { return a-b; }
        static float Multiply(float a, float b) { return a*b; }
        static float Divide(float a, float b) { return a/b; }
        float DoMath(float a, float b, float (*result)(float, float)){
           return result(a, b);    // call using function pointer
        }

};

static class AgentGLClass : public TclClass {
public:
       AgentGLClass() : TclClass("Agent/AgentGLTcl") {}
        TclObject* create(int, const char*const*) {
                return(new AgentGL());
        }
} class_tsp_agent;

AgentGL::AgentGL() : Agent(PT_UDP) {
       bind("tsp_var1_otcl", &tsp_var1);
       bind("tsp_var2_otcl", &tsp_var2);
       bind("tsp_var2_otcl", &tsp_result);
       //bind("tsp_str_otcl", tsp_str);


}
int AgentGL::command(int argc, const char*const* argv) {
      if(argc == 2) {
           if(strcmp(argv[1], "call-executegl") == 0) {
        	   ExecuteGL();
                  return(TCL_OK);
           }

	   if(strstr(argv[1], "call-math-opt-")) {
	   			ParseOpt(argv[1] , tsp_var1, tsp_var2);
	   				 return(TCL_OK);
	   		  }
      }
     return(Agent::command(argc, argv));
}

void AgentGL::CommandHandler(void) {

}

float AgentGL::ParseOpt(const char *str , float a, float b){
	Tcl& tcl = Tcl::instance();
	float val = -1;
	if (strstr(str, "add")) val = AgentGL::DoMath(a,b, &AgentGL::Plus);
	if (strstr(str, "minus")) val = DoMath(a,b, &Minus);
	if (strstr(str, "multiply")) val = DoMath(a,b, &Multiply);
	if (strstr(str, "divide")) val = DoMath(a,b, &Divide);
    tsp_result = val;

    tcl.evalf("puts \"  Result is : %f\"", tsp_result);


    return val;
}


int AgentGL::ExecuteGL(){

	int globalVariable = 2;
	string sIdentifier;
	int iStackVariable = 20;

	pid_t pID = fork();
	if (pID == 0){                // child
		// Code only executed by child process
		sIdentifier = "Child Process: ";
		globalVariable++;
		iStackVariable++;


		FILE *fp;

				//fp = popen("ls -Ralh ../../ > /home/ali/Documents/home_gcu/gridlab-examples/afile.txt", "r");
		fp = popen("gridlabd /home/ali/Documents/home_gcu/gridlab-examples/1b.glm", "r");
		if (fp == NULL) {
					cout<<"\nFailed to run command\n";
					return -1;
				}

				pclose(fp);




	}
	else if (pID < 0){            // failed to fork

		cerr << "Failed to fork" << endl;
		exit(1);
		// Throw exception
	}
	else{                                   // parent

		// Code only executed by parent process

		sIdentifier = "Parent Process:";

		int status;
		printf("Parent process started.n");
		        if ((pID = wait(&status)) == -1)

		           perror("wait error");
		        else {                       /* Check status.                */
		           if (WIFSIGNALED(status) != 0)
		              printf("Child process ended because of signal %d.n",
		                      WTERMSIG(status));
		           else if (WIFEXITED(status) != 0)
		              printf("Child process ended normally; status = %d.n",
		                      WEXITSTATUS(status));
		           else
		              printf("Child process did not end normally.n");
		        }
		        printf("Parent process ended.n");
		        exit(EXIT_SUCCESS);

	}

	// Code executed by both parent and child.

	cout << sIdentifier;
	cout << " Global variable: " << globalVariable;
	cout << " Stack variable: " << iStackVariable << endl;

	return 0;
}
