#include "netpmp.h"
#include <time.h>

using namespace std;

netpmp::netpmp()
{
	localport=-1;
}

netpmp::~netpmp()
{
}

int timesec(){
	time_t seconds;
	seconds = time (NULL);
	return seconds;
}

void netpmp::redirect()
{
	uint16_t privateport=3000;
	uint16_t publicport=3000;
  int r;
  natpmpresp_t response;
  cout << "Init Port Forwarding...\n";
  initnatpmp(&natpmp,0,NATPMP_RESPTYPE_UDPPORTMAPPING);
  sendnewportmappingrequest(&natpmp, NATPMP_PROTOCOL_UDP, privateport, publicport, 3600);
  int timex = timesec();
  
      do {
	    /*if(timesec()-timex >= 5){
		    sendnewportmappingrequest(&natpmp, NATPMP_PROTOCOL_UDP, privateport, publicport, 3600);
		    cout << "Request Port Forward again...\n";
		    timex = timesec();
	    }*/
        fd_set fds;
        struct timeval timeout;
        FD_ZERO(&fds);
        FD_SET(natpmp.s, &fds);
        getnatpmprequesttimeout(&natpmp, &timeout);
        select(FD_SETSIZE, &fds, NULL, NULL, &timeout);
        r = readnatpmpresponseorretry(&natpmp, &response);
      } while(r==NATPMP_TRYAGAIN);
      
      cout << "mapped public port "<<response.pnu.newportmapping.mappedpublicport<<
      			" to localport "<<response.pnu.newportmapping.privateport<<" liftime "<<
      			response.pnu.newportmapping.lifetime << endl;
      //cout << response.pnu.publicaddress.addr << endl;
      cout << response.type << " ";
      cout << response.resultcode << " ";
      cout << response.epoch << endl;
      localport=response.pnu.newportmapping.privateport;
  
}

void netpmp::advancedRedirect(){
    /*uint16_t privateport=32000;
	uint16_t publicport=32000;
	bool finished_all_init_stuff = false;
  natpmpresp_t response;
  enum { Sinit=0, Ssendpub, Srecvpub, Ssendmap, Srecvmap, Sdone, Serror=1000 } 
  natpmpstate = Sinit;
  int r;
  if(initnatpmp(&natpmp)<0){
    natpmpstate = Serror;
  }
  else{
    natpmpstate = Ssendpub;
  }
    
  while(!finished_all_init_stuff) {
    switch(natpmpstate) {
        case Ssendpub:
          if(sendpublicaddressrequest(&natpmp)<0){
            natpmpstate = Serror;
          }
          else{
            natpmpstate = Srecvpub;
          }
          break;
        case Srecvpub:
          r = readnatpmpresponseorretry(&natpmp, &response);
          if(r<0 && r!=NATPMP_TRYAGAIN){
            natpmpstate = Serror;
          }
          else if(r!=NATPMP_TRYAGAIN) {
            copy(publicaddress, response.publicaddress.addr);
            natpmpstate = Ssendmap;
          }
          break;
        case Ssendmap:
          if(sendnewportmappingrequest(&natpmp, protocol, privateport, publicport, lifetime)<0){
            natpmpstate = Serror;
          }
          else{
            natpmpstate = Srecvmap;
          }
          break;
        case Srecvmap:
          r = readnatpmpresponseorretry(&natpmp, &response);
          if(r<0 && r!=NATPMP_TRYAGAIN){
            natpmpstate = Serror;
          }
          else if(r!=NATPMP_TRYAGAIN) {
            copy(publicport, response.pnu.newportmapping.mappedpublicport);
            copy(privateport, response.pnu.newportmapping.privateport);
            copy(mappinglifetime, response.pnu.newportmapping.lifetime);
            natpmpclose(&natpmp);
            natpmpstate = Sdone;
          }
          break;
        }
  }
  cout << "mapped public port "<<response.pnu.newportmapping.mappedpublicport<<
  			" to localport "<<response.pnu.newportmapping.privateport<<" liftime "<<
  			response.pnu.newportmapping.lifetime<<"\n";*/
}

void netpmp::close(){
	closenatpmp(&natpmp);
}
