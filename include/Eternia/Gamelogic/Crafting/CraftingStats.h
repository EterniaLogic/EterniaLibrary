#ifndef CRAFTING_STATS_H
#define CRAFTING_STATS_H

#include "../../Serialization/SpecificSerializer.h"
#include "../../Data/Protect/PType.hpp"

// Crafting stats
// AIs can be designated later to craft items and skill off of them.

class CraftingStats : public SpecificSerializer {
    public:
        CraftingStats(); // Predefine stats


    private:
        // Defaults normally set to 0.
        // Initial skills +1 can be learned by reading books or searching global net.

        // Applied Mathematics (Stunned; right? Math in a game! D:)
        PType<double> math; // general math
        PType<double> algebra; // did some equations
        PType<double> calculus; // applied some integrals (includes diff-eq)
        PType<double> geometry; // Can be gained by placing triangles or squares
        PType<double> number_theory; // found some new sequences
        PType<double> puzzle_solver; // solved many puzzles!

        // Applying real science in a game! Unbelievable!
        // Note: Only the people who actually have degrees in these fields can apply them in the game. This game is also partly a tool.
        // Science Skills (Above 100 = doctrate & highly applicable in a research team)
        PType<double> physics; // General Physics knowledge
        PType<double> astronomy; // Cosmology: Study of the universe
        PType<double> particle_physics; // advanced mechanics of physics
        PType<double> organic_chemistry; // Carbon-based or Silicon-based chemistry
        PType<double> inorganic_chemistry; // polymers / Acids / Advanced chemistry
        PType<double> power; // Class mix of electrical; chemistry and physics to create advanced power designs
        PType<double> computer_science; // Ability to program and to logically adapt new virtualization designs (EterniaGame is a super-computer)
        PType<double> electrical; // Ability to create new circuits and logic behind every wire (Highly useful learning tool)
        PType<double> mechanics; // Ability to design and produce working vehicles or machines.


        // Other?
        PType<double> design; // creation of 3D art; images and textures inside the world (Payments for originality)
        PType<double> music; // creation of music (+tools)




        // Fundamental
        PType<double> armor; // basic armor skill
        PType<double> shields; // basic shields skill
        PType<double> laser; // Laser technology weapons
        PType<double> ballistic; // ballistic weapons
        PType<double> science; // increased interest in complex systems, makes skill-ups go faster
        PType<double> modular; // better modular structures / ships / turrets
        PType<double> buildings; // base skill
        PType<double> gear; // base infantry gear skill

        // Infantry
        PType<double> swords; // overall sword making skill.
        PType<double> rifles; // infantry weapons, basic mount (Laser or ballistic)
        PType<double> pistols; // infantry weapons, basic mount (Laser or ballistic)
        PType<double> power_suit; // skill in making better suits.

        // Bases
        PType<double> emplacements; // base defense
        PType<double> factory; // skill in making more efficient factories. (minigame?)

        // Planetary vehicles
        PType<double> tracks; // better tracks for vehicles
        PType<double> hover; // hovering vehicles

        // Space Ships
        PType<double> engine; // skill in making better, faster engines.
        PType<double> hyperdrive; // skill in making better hyperdrives.
        PType<double> crew_deck; // improves how many men ship can hold and
        PType<double> medical; // medical areas all around the ship.


        // Vehicle weapons
        PType<double> hardpoints; // skill in making bigger hardpoints.
        PType<double> turrets; // skill in making better turrets.
};

#endif
