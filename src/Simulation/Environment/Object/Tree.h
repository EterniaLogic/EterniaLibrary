#ifndef ENVTREE_H_
#define ENVTREE_H_

#include "../../../Data/includes.h"
#include "../../../Math/Math.h"

// Trees are factorial when generated.
// Branch size and limbs are randomized, but a seed is needed
//     |  |
//  ---------
//       |


// Tree limbs are branching off randomly
class TreeBranch {
    public:
        double offset = 0.0; // offset along the limb (or parent branch)
        vertex* angle; // angle on the branch from the base
        TreeBranch(int seed); // <-- branch grown from the seed

        TreeBranch *childBranch;
};


// Major tree limb
class TreeLimb {
    public:
        double offset = 0.0; // offset from the bark base
        vertex* angle; // angle on the limb from the base
        TreeLimb(int seed); // <-- seed given from tree, planted here

        LinkedList<TreeBranch> *branches; // list of consecutive branches
};

class Tree {
    private:
        int seed;
        vertex* location; // location on the current world
        vertex* angle;
        LinkedList<TreeLimb> *limbs; // list of consecutive limbs
    public:
        Tree(); // <-- generates random seed and depth level

        // Uses a given seed to generate the same tree again
        // level is for how detailed the fractal is.
        Tree(int seed, int level);

        // Generation methods
};


#endif
