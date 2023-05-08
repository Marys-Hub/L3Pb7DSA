#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
    //TODO - Implementation
    currentelem = multime.head;

}


void SortedSetIterator::first() {
    //TODO - Implementation
    currentelem = multime.head;
}


void SortedSetIterator::next() {
    //TODO - Implementation
    if (valid())
    {
        currentelem = multime.next[currentelem];
    }else
        throw exception();
}


TElem SortedSetIterator::getCurrent()
{
    //TODO - Implementation
    if (valid())
    {
        return multime.elems[currentelem];
    }
    else
    {
        throw exception();
    }
    return NULL_TELEM;
}

bool SortedSetIterator::valid() const {
    //TODO - Implementation
    //return currentelem != -1 && currentelem != multime.firstEmpty;
    return currentelem >= 0 && currentelem < multime.cap && currentelem != -1 && currentelem != multime.firstEmpty;
    return false;
}

