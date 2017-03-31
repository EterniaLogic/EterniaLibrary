#ifndef RELATIONS_H_
#define RELATIONS_H_



/* Relations between two races.
 *	Relations above 50 allow for:
 *		- Border movement without questions
 *		- Free trade, ect. based on governments
 * Relations below 25 deny:
 *		- any border movement (fire on sight)
 */
 
 // War may be declared on anybody. 
 // 	However, there may be micro-wars between planets or corporations to handle disputes.

class Relations{
private:
    float relationLevel; // 100 = allies, -100 = enemies
	bool war; // are both parties at war? (Some races may consider everybody at war with them, true xenophobes)
};

#endif
