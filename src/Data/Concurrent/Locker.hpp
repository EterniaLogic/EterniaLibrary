#ifndef LOCKER_H
#define LOCKER_H

#include <time.h>


#ifdef _WIN64 || _WIN32
   #define WINDOWSXX
   #include <thread>
   #include <mutex>
#else
   #define LINUXX
   #include <thread>
#endif


template<class T>
class Locker{
public:
	T _val;
	bool _lock;
	long _lockedtime;
	Locker(T v){_val=v; _lock=false; _lockedtime=0;}
	Locker(){_val=T(); _lock=false; _lockedtime=0;}



	T get(){
		lockwait();
		return _val;
	}

	T operator =(T val){
		lockwait();
		_val = val;
		return _val;
	}

	bool operator ==(T* val){

		return (_val==val);
	}


	// thread wait until unlocked.
	void lockwait(){
		while(_lock){
			if((time(0x0) - _lockedtime) > 100000000){
				_lockedtime = time(0x0); // reset and wait
				cout << "Thread locked for over 100 seconds, overload?" << endl;
			}
			std::this_thread::sleep_for(std::chrono::microseconds(1000));
		}
	}

	void unlock(){
		_lock = false;
	}

	void lock(){
		_lock = true;
		_lockedtime = time(0x0);
	}

	bool locked(){
		return _lock;
	}
};

#endif
