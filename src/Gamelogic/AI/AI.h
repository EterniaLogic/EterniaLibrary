#ifndef AIMain_h_
#define AIMain_h_

enum AIACTION {};
enum AIDECISION {};

// Ah, abstraction!
class AI
{
public:
  AI();
  void decide(); // make a decision to do something
  void addInteractable(); // add an object that the AI can interact with
  
private:
  // back-end tracking variables
  // Order from higher commander
  
  // AI Attributes (Percentages assigned at random to define a personality)
  float stuborness; // does not want to follow orders (100% for true enemy)
  float taint; // how often will this AI betray you? (100% for true enemy)
  float sailor_mouth; // how often will this AI curse?
  float smarts; // this combined with taint will completely obliterate you
  float predictability; // how predictable is this AI? (i.e: randomness of the AI, 0% for insane)
  float strength; // how "Tough" is this AI? (0% for a total wimp, 100% for a Tychus)
};

#endif