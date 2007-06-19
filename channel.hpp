
#include <iostream>

namespace CppAgent {
	
	class BaseChannel {
	public:
		virtual void send (const void *message) = 0;
		virtual void recv (void *message) = 0;
	};

	template <class TMessage>
	class Channel : public BaseChannel {
		TMessage _Message;

	protected:
		int get_NextID () {
			static int count = 0;

			return ++count;
		}
	
	public:
		int get_ID () {
			static int id = get_NextID ();

			return id;
		}

		virtual void send (const void *message) {
			_Message = *static_cast <const TMessage *> (message);
		}

		virtual void recv (void *message) {
			*static_cast <TMessage *> (message) = _Message;
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
	};

	Network anet;
}
