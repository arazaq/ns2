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
#include "agent.h"

class AgentMath : public Agent {
public:
        AgentMath();
protected:
        int command(int argc, const char*const* argv);
private:
        double    tsp_var1;
        double tsp_var2;
        double   tsp_result;
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

static class AgentMathClass : public TclClass {
public:
       AgentMathClass() : TclClass("Agent/AgentMathTcl") {}
        TclObject* create(int, const char*const*) {
                return(new AgentMath());
        }
} class_tsp_agent;

AgentMath::AgentMath() : Agent(PT_UDP) {
       bind("tsp_var1_otcl", &tsp_var1);
       bind("tsp_var2_otcl", &tsp_var2);
       bind("tsp_var2_otcl", &tsp_result);


}
int AgentMath::command(int argc, const char*const* argv) {
      if(argc == 2) {
           if(strcmp(argv[1], "call-tsp-priv-func") == 0) {
                  CommandHandler();
                  return(TCL_OK);
           }

	   if(strstr(argv[1], "call-math-opt-")) {
	   			ParseOpt(argv[1] , tsp_var1, tsp_var2);
	   				 return(TCL_OK);
	   		  }
      }
     return(Agent::command(argc, argv));
}

void AgentMath::CommandHandler(void) {

}

float AgentMath::ParseOpt(const char *str , float a, float b){
	Tcl& tcl = Tcl::instance();
	float val = -1;
	if (strstr(str, "add")) val = AgentMath::DoMath(a,b, &AgentMath::Plus);
	if (strstr(str, "minus")) val = DoMath(a,b, &Minus);
	if (strstr(str, "multiply")) val = DoMath(a,b, &Multiply);
	if (strstr(str, "divide")) val = DoMath(a,b, &Divide);
    tsp_result = val;

    tcl.evalf("puts \"  Result is : %f\"", tsp_result);
    return val;
}
