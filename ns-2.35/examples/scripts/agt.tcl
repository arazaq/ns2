
set glagent [new Agent/AgentGLTcl]

# Pass command to Agent
#puts stdout "Call to execute NS"
#$glagent "call-execute-ns" "/home/apps/ns2-master/ns-2.35/examples/test01/lantest_example.tcl"
$glagent "call-execute-ns" "/home/apps/ns2-master/ns-2.35/examples/test01/01lantest_example.tcl"

#puts stdout "Call to execute GL"
$glagent "call-execute-gl" "/home/apps/ns2-master/ns-2.35/examples/test01/02_test_PMSG_windturb_GCU.glm"

