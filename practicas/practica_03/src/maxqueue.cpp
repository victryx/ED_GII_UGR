/**
 * @file maxqueue.cpp
 * @brief  Archivo de implementación del TDA MaxQueue
 * @author []
 * @author []
 */

#include "maxqueue.h"

void MaxQueue::updateMax(int max) {
    std::list<element>::iterator iter = queue.begin();
    while (iter != queue.end()) {
        iter->maximum = max;
        iter++;
    }
}

int MaxQueue::findMax() {
    std::list<element>::iterator iter = queue.begin();
    int newMax = iter->value;
    while (++iter != queue.end()) {
        newMax = iter->value > newMax ? iter->value : newMax;
    }
    return newMax;
}

element & MaxQueue::front() {
    return queue.front();
}

const element & MaxQueue::front() const {
    return queue.front();
}

void MaxQueue::pop() {
    element removed = queue.front();

    queue.pop_front();

    if (removed.maximum == removed.value && !queue.empty()) {
        updateMax(findMax());
    }
}

void MaxQueue::push(int val) {
    element e;
    e.value = val;

    if (!queue.empty() && val > front().maximum) {
        updateMax(val);
    }
    
    if (queue.empty()) {
        e.maximum = val;
    } else {
        e.maximum = front().maximum;
    }

    queue.push_back(e);
}

int MaxQueue::size() const {
    return queue.size();
}

bool MaxQueue::empty() const {
    return queue.empty();
}

std::ostream& operator<<(std::ostream& outStream, const element& e) {
    return (outStream << e.value << "," << e.maximum);
}