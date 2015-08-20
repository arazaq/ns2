
set glagent [new Agent/AgentGLTcl]

# Pass command to Agent
#puts stdout "Call to execute NS"
#$glagent "call-execute-ns" "/home/ali/apps/ns2-master/ns-2.35/examples/test01/lantest_example.tcl"
$glagent "call-execute-ns" "/home/ali/apps/ns2-master/ns-2.35/examples/test01/01lantest_example.tcl"

#puts stdout "Call to execute GL"
$glagent "call-execute-gl" "/home/ali/apps/ns2-master/ns-2.35/examples/test01/02_test_PMSG_windturb_GCU.glm"

