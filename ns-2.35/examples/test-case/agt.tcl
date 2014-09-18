
set myagent [new Agent/AgentGLTcl]

# Give a command to MyAgent
puts stdout "Call to execute NS"
$myagent "call-execute-ns" "/home/ali/Downloads/ns2/ns-2.35/examples/test-case/test_ns.tcl"

puts stdout "Call to execute GL"
$myagent "call-execute-gl" "/home/ali/Downloads/ns2/ns-2.35/examples/test-case/test_gl.glm"

