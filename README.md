# cppagent by Ryanne Dolan
Automatically exported from https://code.google.com/p/cppagent/ 

This C++ class library provides a simple framework for developing soft real-time systems using an agent-based programming model. The library is especially geared toward robotics applications.

The library incorporates ideas from <a href="http://en.wikipedia.org/wiki/Flow-based_programming" target="_blank">flow-based programming</a>, <a href="http://en.wikipedia.org/wiki/Swarm_intelligence" target="_blank">swarm AI</a>, <a href="http://en.wikipedia.org/wiki/Software_componentry" target="_blank">software componentry</a>, and <a href="http://en.wikipedia.org/wiki/Control_theory" target="_blank">control theory</a>.

In this context, an agent is a software component which:

<ul>
<li>processes and manipulates data streams,</li>
<li>is autonomous, in that it requires no interaction from users or other agents,</li>
<li>is entirely decoupled from other system components,</li>
<li>has no interface (black-box view),</li>
<li>operates in an independent thread of execution.</li>
</ul>
Data streams consist of well-defined datagrams which:
<ul>
<li>like UDP datagrams, are unreliable,</li>
<li>unlike UDP datagrams, are ordered,</li>
<li>unlike objects, are not explicitly bound to methods or events.</li>
</ul>

The agent-based programming model encourages engineers to design complex systems in terms of simple processing components (agents). Agents are entirely unaware of other agents, making the agent-based model inherently component-based. The server-client model is entirely dismissed, preventing any wait-for-response behavior. In fact, since all inter-agent communication is unreliable, it is impractical to implement any hand shaking between agents. This limitation encourages one-way data streams rather than two-way communication or RPC.
