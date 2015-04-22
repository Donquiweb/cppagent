# Introduction #

This code excerpt illustrates the use of the CppAgent API.

```

class Test {
public:
   void do_something_useful () {
      std::cout << "such utility!" << std::endl;
   }
};

class TestAgent : public CppAgent::Agent <Test> {

   void main () {
      // throw a datagram
      CppAgent::anet << "simple string datagram";    

      std::string signal;

      try {  
         // try to catch a datagram
         CppAgent::anet >> signal;

         // throw back the datagram so other agents can catch it
         CppAgent::anet << signal;
      }
      catch (CppAgent::NoMatchingDatagram &err) {
         CppAgent::anet << "I didn't catch a datagram so I'm terminating...";

         return;
      }

      if (signal == "do something useful!") {
         // this will run only after matching signal is caught
         do_something_useful ();
      }

      // agent terminates
   }
};

int main () {
   // spawn a new thread and begin running agent
   TestAgent test;

   // send a datagram, which may or may not be caught by agent
   CppAgent::anet << "do something useful!";

   // program will terminate only after all agents have terminated
   return 0;
}

```