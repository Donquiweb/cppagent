
#include <exception>

#include <pthread.h>

namespace CppAgent {

	class BaseAgent {
	public:
		virtual void main () = 0;
	};

	class AgentThread {
		pthread_t _thread;	
		BaseAgent &_agent;
	public:
		AgentThread (BaseAgent &agent) : _agent (agent) {
			void *start_main (void *);
			//launch thread
			
			pthread_create (&_thread, NULL, start_main, &agent);
		}

		~AgentThread () {
			//wait for thread to terminate
			std::exception *err;
			pthread_join (_thread, reinterpret_cast <void **> (&err));

			//propagate errors that occur in thread
			if (err != NULL) {
				throw *err;
			}	
		}

	};

	void *start_main (void *agent) {
		try {
			static_cast <BaseAgent *> (agent)->main ();
		}
		catch (std::exception &err) {
			pthread_exit (&err);
		}
		catch (...) {
			std::exception err;
			pthread_exit (&err);
		}

		pthread_exit (NULL);
	}



}
