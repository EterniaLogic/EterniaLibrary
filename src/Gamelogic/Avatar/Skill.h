#ifndef AvatarSkill_h_
#define AvatarSkill_h_

enum AVATAR_SKILLS{
  AVS_air_piloting, // Pilot Skill
  AVS_space_piloting, // Space piloting skill
  AVS_construction, // Creation of the physical world / Physics / Machining
  AVS_destruction, // Ability to demolish with precision (Buildings or territories)
  
  // Applying real science in a game! Unbelievable!
  // Note: Only the people who actually have degrees in these fields can apply them in the game. This game is also partly a tool.
  // Science Skills (Above 100 = doctrate & highly applicable in a research team)
  AVS_physics, // General Physics knowledge
  AVS_astronomy, // Cosmology: Study of the universe
  AVS_particle_physics, // advanced mechanics of physics
  
  AVS_physiology, // Understanding of anatomy and it's applications
  
  AVS_organic_chemistry, // Carbon-based or Silicon-based chemistry
  AVS_inorganic_chemistry, // polymers / Acids / Advanced chemistry
  AVS_power, // Class mix of electrical, chemistry and physics to create advanced power designs
  
  AVS_computer_science, // Ability to program and to logically adapt new virtualization designs (EterniaGame is a super-computer)
  AVS_electrical, // Ability to create new circuits and logic behind every wire (Highly useful learning tool)
  AVS_mechanics, // Ability to design and produce working vehicles or machines.
  
  // Buisness, Economics
  AVS_buisness, // Company management
  AVS_economics, // Trade
  AVS_mining, // ability to extract minerals
  AVS_prospecting, // ability to scan area
  
  // Applied Mathematics (Stunned, right? Math in a game! D:)
  AVS_math, // general math
  AVS_algebra, // did some equations
  AVS_calculus, // applied some integrals (includes diff-eq)
  AVS_geometry, // Can be gained by placing triangles or squares
  AVS_number_theory, // found some new sequences
  AVS_structures, // matricies, trees, ect. (I'm not sure how to actually put this into a game...)
  AVS_puzzle_solver, // solved many puzzles!
  
  // Social
  AVS_talker, // persuasion
  AVS_political, // ability to command the masses
  AVS_cosmetics, // makeup and hair beautification
  AVS_design, // creation of 3D art, images and textures inside the world (Payments for originality)
  AVS_music, // creation of music (+tools)
  
  // Military
  AVS_command, // ability to command with prestiege
  AVS_swordsmanship, // Melee Weaponry
  AVS_shield, // Shielding
  AVS_ranged, // Ranged weaponry
  AVS_technique // Sort of like magic
};

class Skill
{
private:
  AVATAR_SKILLS skilltype;
  float level;
};

#endif