
set glagent [new Agent/AgentGLTcl]

# Pass command to Agent
puts stdout "Call to execute NS"
$glagent "call-execute-ns" "/home/ali/Downloads/ns2/ns-2.35/examples/test-case/test_ns.tcl"

puts stdout "Call to execute GL"
$glagent "call-execute-gl" "/home/ali/Downloads/ns2/ns-2.35/examples/test-case/test_gl.glm"

