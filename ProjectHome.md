This C++ class library provides a simple framework for developing soft real-time systems using an agent-based programming model.  The library is especially geared toward robotics applications.

The library incorporates ideas from [flow-based programming](http://en.wikipedia.org/wiki/Flow-based_programming), [swarm AI](http://en.wikipedia.org/wiki/Swarm_intelligence), [software componentry](http://en.wikipedia.org/wiki/Software_componentry), and [control theory](http://en.wikipedia.org/wiki/Control_theory).

In this context, an agent is a software component which:
  * processes and manipulates data streams,
  * is autonomous, in that it requires no interaction from users or other agents,
  * is entirely decoupled from other system components,
  * has no interface (black-box view),
  * operates in an independent thread of execution.

Data streams consist of well-defined datagrams which:
  * like UDP datagrams, are unreliable,
  * unlike UDP datagrams, are ordered,
  * unlike objects, are not explicitly bound to methods or events.

The agent-based programming model encourages engineers to design complex systems in terms of simple processing components (agents).  Agents are entirely unaware of other agents, making the agent-based model inherently component-based.  The server-client model is entirely dismissed, preventing any wait-for-response behavior.  In fact, since all inter-agent communication is unreliable, it is impractical to implement any hand shaking between agents.  This limitation encourages one-way data streams rather than two-way communication or RPC.