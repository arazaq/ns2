
set glagent [new Agent/AgentGLTcl]

$glagent "call-prlexecute" "/home/ali/Downloads/ns2/ns-2.35/examples/test-case/test_ns.tcl"
# Set configurable parameters of MyAgent
#$glagent set tsp_var1_otcl 2
#$glagent set tsp_var2_otcl 6.5
#$glagent set tsp_result 0
#$glagent set tsp_str_otcl "This is a string"


# Give a command to MyAgent
#puts stdout "call to execute NS"
#$glagent "call-execute-ns" "/home/ali/Downloads/ns2/ns-2.35/examples/test-case/test_ns.tcl"

#puts stdout "call to execute GL"
#$glagent "call-execute-gl" "/home/ali/Downloads/ns2/ns-2.35/examples/test-case/test_gl.glm"

#puts stdout "Calling Add"
#$glagent call-math-opt-add

#puts stdout "Calling Minus"
#$glagent call-math-opt-minus
