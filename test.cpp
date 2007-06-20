

#include "channel.hpp"
#include "agent.hpp"

using namespace std;
using namespace CppAgent;

class TestAgent : public BaseAgent {
public:
	class StopMessage {
	};

	void main () {
		cout << "thread starting!\n";

		anet << "hello world!";	
		
		StopMessage stop;
		anet >> stop;
		
		cout << "thread closing!\n";
	}
};

int main () {

	// TODO: try making TestAgent : public Agent <Test> hide Test as private to TestAgent s.t. only 
	// 	the thread main (which is a friend of the class) can access Test;
	// 	thread main belongs to TestAgent, so Test can be any class at all (pre-existing)


	TestAgent test;
	AgentThread thread (test);

	// tell agent to quit running
	TestAgent::StopMessage stop;
	anet << stop;

	// get last message sent by agent
	string str;
	anet >> str;

	cout << str << endl;
}
