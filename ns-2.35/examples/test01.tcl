
set myagent [new Agent/AgentGLTcl]

# Set configurable parameters of MyAgent
$myagent set tsp_var1_otcl 2
$myagent set tsp_var2_otcl 6.5
$myagent set tsp_result 0
$myagent set tsp_str_otcl "This is a string"


# Give a command to MyAgent
puts stdout "call to execute NS"
$myagent "call-execute-ns" "/home/ali/Downloads/ns2/ns-2.35/examples/test-case/test_ns.tcl"

puts stdout "call to execute GL"
$myagent "call-execute-gl" "/home/ali/Downloads/ns2/ns-2.35/examples/test-case/test_gl.glm"
#$myagent call-execute-gl somehintmore

#puts stdout "Calling Add"
#$myagent call-math-opt-add

#puts stdout "Calling Minus"
#$myagent call-math-opt-minus
