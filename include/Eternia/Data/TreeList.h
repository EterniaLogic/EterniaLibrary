//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef TREELIST_H_
#define TREELIST_H_


class TreeNode
{
public:
	bool isRoot(); // is top node?
	bool isLeaf(); // is leaf (end) node?
    int Depth(); // how far in is this node?
	
	TreeNode *Parent, *Child;
	TreeNode *Sibling, *PrevSibling;
};


class TreeList
{
    TreeNode *Root;
public:
	TreeList();
	int Height(); // maximum depth
	int Size(); // total size
	bool Empty(); // is Empty?
};

#endif /*TREELIST_H_*/
