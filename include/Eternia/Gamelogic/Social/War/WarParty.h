#ifndef WARParty_H_
#define WARParty_H_

// War can be between two parties.
// This can of course include pirates or other governments.

enum WARPARTYType {WPT_None, WPT_Player, WPT_Colony, WPT_Government, WPT_Alliance, WPT_Planet, WPT_Race, WPT_Faction};

class WarParty {
    public:
        WarParty();

        WARPARTYType faction;
};

#endif /* WARParty_H_ */