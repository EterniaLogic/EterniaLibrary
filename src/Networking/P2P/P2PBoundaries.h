#ifndef P2PBOUNDARIES_H_
#define P2PBOUNDARIES_H_

class P2PBoundaries
{
public:
	P2PBoundaries();
	virtual ~P2PBoundaries();
	
	long x,y; // x, y coords
	long x1,y1; // other edge of boundary.
	
	long minsectorx = 5; //Min sector boundaries (Prevents P2PLServers from going lower and forces them to Co-server)
	long minsectory = 5;
};

#endif /*P2PBOUNDARIES_H_*/
