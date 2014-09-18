
set myagent [new Agent/AgentGLTcl]

# Give a command to MyAgent
puts stdout "Call to execute NS"
$myagent call-execute-ns

puts stdout "Call to execute GL"
$myagent call-execute-gl


