#pragma once
#include "SortedSet.h"

//DO NOT CHANGE THIS PART
class SortedSetIterator
{
    friend class SortedSet;
private:
    const SortedSet& multime; // is a constant reference to a SortedSet object
    // It is initialized in the SortedSetIterator constructor with the SortedSet object
    SortedSetIterator(const SortedSet& m);
    //  is a constructor for the SortedSetIterator class that takes a constant reference to a SortedSet object as a parameter

    //TODO - Representation
    int currentelem;

public:
    void first();
    void next();
    TElem getCurrent();
    bool valid() const;
};

