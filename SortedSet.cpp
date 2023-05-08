#include "SortedSet.h"
#include "SortedSetIterator.h"

//Komplexitat: Theta(n)
SortedSet::SortedSet(Relation r) {
    //TODO - Implementation
    rel = r;
    cap = 10; //INIT_CAPACITY in curs
    elems = new TComp[cap];
    next = new int[cap];
    head = -1;
    firstEmpty = 1;

    // Initialize next array
    for (int i = 0; i < cap - 1; i++)
    {
        next[i] = i + 1;
    }
    next[cap] = -1;

}

//Komplexitat O(n)
//am Anfang der Liste, am Ende der Liste, auf einer
//gegebenen Position, vor/nach einem bestimmten Wert- la mne cu rel gen
//la inceput cand e prob cu head, in mij unde tre sa mut chestii, la final
bool SortedSet::add(TComp elem) {
    //TODO - Implementation
    // Check if the element already exists in the set

    if (search(elem)) {
        return false; // gen il am deja
    }

    // Check if we need to resize the set
    if (firstEmpty == -1) { // head = -1 ??
       resize(); // Double the capacity
    }

    // Find the position where the element should be inserted
    int prev = -1;
    int current = head;
    while (current != -1 && rel(elems[current], elem)) {
        prev = current;
        current = next[current];
    }

    // Insert the element at the appropriate position
    int newPosition = firstEmpty;
    firstEmpty = next[firstEmpty];
    elems[newPosition] = elem;
    next[newPosition] = current;
    if (prev == -1) {
        head = newPosition;
    } else {
        next[prev] = newPosition;
    }

    return true;

}


// Komplexitat: O(n)
bool SortedSet::remove(TComp elem) {
    //TODO - Implementation
    // Find the position of the element in the sorted set
    int prev = -2;
    int current = head;
    while (current != -1 && elems[current] != elem) {
        prev = current;
        current = next[current];
    }

    // If the element doesn't exist in the sorted set, return false
    if (current == -1) {
        return false;
    }

    // Remove the element from the sorted set
    if (prev == -2) { // the element is the head of the sorted set
        head = next[current];
    } else { // the element is in the middle or at the end of the sorted set
        next[prev] = next[current];
    }

    // Add the removed element to the first empty position in the dynamic array
    next[current] = firstEmpty;
    firstEmpty = current;

    return true;
    return false;
}

//Komplexitat: O(n)
bool SortedSet::search(TComp elem) const {
    //TODO - Implementation
    int current = head;
    while (current != -1) {
        if (elems[current] == elem) {
            return true;
        }
        current = next[current];
    }
    return false;
    return true;
}

// Komplexitat: Theta(n)
int SortedSet::size() const {
    //TODO - Implementation
    int count = 0;
    int current = head;
    while (current != -1) {
        count++;
        current = next[current];
    }
    return count;
    return 0;
}


//Komplexitat Theta(1)
bool SortedSet::isEmpty() const {
    //TODO - Implementation
    return head == -1;
    return false;
}
// Theta(1)
SortedSetIterator SortedSet::iterator() const {
    return SortedSetIterator(*this);
}

// Theta(1)
SortedSet::~SortedSet() {
    //TODO - Implementation
    delete[] elems;
    delete[] next;
}

void SortedSet::resize() {

    int newCap = cap * 2; // Double the capacity
    TComp* newElems = new TComp[newCap]; // Allocate a new array for the elements
    int* newNext = new int[newCap]; // Allocate a new array for the next indices

    // Copy the existing elements and next indices into the new arrays
    for (int i = 0; i < cap; i++) {
        newElems[i] = elems[i];
        newNext[i] = next[i];
    }

    // Initialize the next indices for the remaining positions in the new arrays
    for (int i = cap; i < newCap - 1; i++) {
        newNext[i] = i + 1;
    }
    newNext[newCap - 1] = -1;

    // Update the SortedSet's fields with the new arrays and capacity
    delete[] elems;
    elems = newElems;
    delete[] next;
    next = newNext;
    firstEmpty = cap+1;
    cap = newCap;

}


