#ifndef NETPMP_H_
#define NETPMP_H_
//#include "../../../Lib/libnatpmp/natpmp.h"
#include <natpmp.h>
#include <iostream>


class netpmp
{
	natpmp_t natpmp;
	public:
		netpmp();
		virtual ~netpmp();
		void redirect();
		void advancedRedirect();
		void close();
		
		int localport;
	
};

#endif /*NETPMP_H_*/
