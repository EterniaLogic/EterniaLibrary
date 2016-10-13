#include "AbstractDB.h"


AbstractDBLinkedDataset::AbstractDBLinkedDataset() {
    changed = false;
    length = 0;
}

AbstractDBLinkedDataset::~AbstractDBLinkedDataset() {
    // remove head until null
    AbstractDBLinkedNode* current = head;
    while (current != NULL) {
        remove(current);
        current = current->next;
    }
}

void AbstractDBLinkedDataset::push_front(void* data) {
    changed = true;
    AbstractDBLinkedNode* node = new AbstractDBLinkedNode();
    node->data = data;
    if (head == NULL) {
        head = tail = node;
    } else {
        head->prev = node;
        node->next = head;
        head = node;
    }

    length++;
}

void AbstractDBLinkedDataset::push_back(void* data) {
    changed = true;
    AbstractDBLinkedNode* node = new AbstractDBLinkedNode();
    node->data = data;
    if (head == NULL) {
        head = tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    length++;
}

void* AbstractDBLinkedDataset::pop_front() {
    changed = true;
    if (head != NULL) {
        AbstractDBLinkedNode* node = head;
        node->next->prev = NULL;
        node->next = head;

        length--;

        void* d = node->data;
        delete(node);
        return d;
    }
    return NULL;
}

void* AbstractDBLinkedDataset::pop_back() {
    changed = true;
    if (tail != NULL) {
        AbstractDBLinkedNode* node = tail;
        node->next->prev = NULL;
        node->next = tail;

        length--;

        void* d = node->data;
        delete(node);
        return d;
    }
    return NULL;
}

void* AbstractDBLinkedDataset::remove(AbstractDBLinkedNode* node) {
    if (node == NULL) return NULL;
    void* data = node->data;
    changed = true; // make sure that frozen must occur
    clearFreeze(); // enforce garbage collection

    if (node != head && node != tail) {
        // a node in-between nodes
        if (node->prev != NULL && node->next != NULL) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->prev = NULL;
            node->next = NULL;
        } else if (node->prev != NULL) {
            // error in list assignment, this is apparently the head
            head = node->next;
            node->next->prev = NULL;
            node->next = NULL;
        } else if (node->prev != NULL) {
            // error in list assignment, this is apparently the tail
            tail = node->prev;
            node->prev->next = NULL;
            node->prev = NULL;
        }
    } else if (node == head && node == tail) {
        // only 1 node
        head = tail = NULL;
    } else if (node == head) {
        // head node
        if (node->next != NULL) {
            head = node->next;
            node->next->prev = NULL;
            node->next = NULL;
        } else head = tail = NULL; // some error occured
    } else if (node == tail) {
        // tail node
        if (node->prev != NULL) {
            head = node->prev;
            node->prev->next = NULL;
            node->prev = NULL;
        } else head = tail = NULL; // some error occured
    }

    delete(node);
    return data;
}

void AbstractDBLinkedDataset::clearAll() {
    while (pop_front() != NULL);
    head = tail = NULL;
    length = 0;
    changed = true;
}

// freezes list for fastest traversal
void AbstractDBLinkedDataset::listFreeze() {
    if (changed) {
        changed = false;

        // reinitialize frozenlist
        clearFreeze();

        // write in to the frozen list
        AbstractDBLinkedNode* current = head;
        int i = 0;
        while (current != NULL) {
            frozenList[i] = current;
            i++;
            current = current->next;
        }
    }
}

void AbstractDBLinkedDataset::clearFreeze() {
    if (frozenList != NULL) free(frozenList);
    frozenList = (AbstractDBLinkedNode**)calloc(length, sizeof(void*));
}

void* AbstractDBLinkedDataset::frozen_get(int index) {
    if (index < 0 || index >= length) return NULL;
    listFreeze();

    return frozenList[index]->data;
}

void AbstractDBLinkedDataset::frozen_set(int index, void* value) {
    if (index < 0 || index >= length) return;
    listFreeze();

    frozenList[index]->data = value;
}

void* AbstractDBLinkedDataset::frozen_remove(int index) {
    if (index < 0 || index >= length) return NULL;
    listFreeze(); // keep frozen

    return remove(frozenList[index]);
}

int AbstractDBLinkedDataset::getSize() {
    return length;
}
