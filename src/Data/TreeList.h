#ifndef TREELIST_H_
#define TREELIST_H_


class TreeNode {
    public:
        bool isRoot(); // is top node?
        bool isLeaf(); // is leaf (end) node?
        int Depth(); // how far in is this node?
        
        void* data;
        TreeNode *Parent, *Child;
        TreeNode *Sibling, *PrevSibling;
};


class TreeList {
        
    public:
        TreeNode *Root;
        TreeList();
        int Height(); // maximum depth
        int Size(); // total size
        bool Empty(); // is Empty?
};

#endif /*TREELIST_H_*/
