
#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h> 

namespace CppAgent {
	
	class BaseChannel {
	public:
		virtual void send (const void *message) = 0;
		virtual void recv (void *message) = 0;
	};

	template <class TMessage>
	class Channel : public BaseChannel {
		TMessage _message;
		bool _messageValid;
		pthread_mutex_t _mutex;


	protected:
		int get_NextID () {
			static int count = 0;

			return ++count;
		}

		void lock () {
			pthread_mutex_lock (&_mutex);
		}

		void unlock () {
			pthread_mutex_unlock (&_mutex);
		}
	
	public:
		Channel () : _messageValid (false) {
			pthread_mutex_t minit = PTHREAD_MUTEX_INITIALIZER;

			_mutex = minit;
		}

		int get_ID () {
			static int id = get_NextID ();

			return id;
		}

		virtual void send (const void *message) {
			lock ();
			_messageValid = true;
			_message = *static_cast <const TMessage *> (message);
			unlock ();
		}

		virtual void recv (void *message) {
			while (true) {
				lock ();
				if (!_messageValid) {
					unlock ();
					sleep (0);
				}
				else {
					*static_cast <TMessage *> (message) = _message;
					_messageValid = false;
					unlock ();
					return;
				}
			}
		}
	};

	class Network {

		template <class TMessage>
		BaseChannel &get_Channel () {
			static Channel <TMessage> ch;

			return ch;
		}

	public:
		template <class TMessage>
		BaseChannel &operator << (const TMessage &message) {
			BaseChannel &ch = get_Channel <TMessage> ();

			ch.send (&message);

			std::cout << "sent to channel\n";
		}

		template <class TMessage>
		BaseChannel &operator >> (TMessage &message) {
			BaseChannel &ch = get_Channel <TMessage> ();

			ch.recv (&message);

			std::cout << "recv'd from channel\n";
		}

		BaseChannel &operator << (const char *message) {
			BaseChannel &ch = get_Channel <std::string> ();

			std::string str (message);

			ch.send (&str);
		}
	};

	Network anet;	// standard agent network
}
