
set myagent [new Agent/AgentMathTcl]

# Set configurable parameters of MyAgent
$myagent set tsp_var1_otcl 2
$myagent set tsp_var2_otcl 6.5
$myagent set tsp_result 0

# Give a command to MyAgent
#$myagent call-tsp-priv-func
puts stdout "Calling Add"
$myagent call-math-opt-add

puts stdout "Calling Minus"
$myagent call-math-opt-minus
