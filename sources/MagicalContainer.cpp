#include <iostream>
#include <vector>
#include <algorithm>
#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;

// Implementation of MagicalContainer

MagicalContainer::MagicalContainer():
    _elements(),_size(0){}

// MagicalContainer::MagicalContainer(MagicalContainer& other):
//     _elements(),_size(0){}



void MagicalContainer::addElement(int element) {
    _elements.push_back(element);
    _size++;
    sort(_elements.begin(),_elements.end());

}

void MagicalContainer::removeElement(int element) {
    for (auto it = _elements.begin(); it != _elements.end(); ++it) {
        if (*it == element) {
            _elements.erase(it);
            --_size;
            break;
        }
    }
}



int MagicalContainer::getElementAt(int index) const {
    if(index < 0 || _size <=index){
        throw out_of_range("Invalid index");
    }
    return _elements.at(static_cast<std::vector<int>::size_type>(index));  
}

// Implementation of AscendingIterator

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container) :
    _container(container), _currentIndex(0) {}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other) :
    _container(other._container), _currentIndex(other._currentIndex) {}




bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
    return this->_currentIndex == other._currentIndex;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
    return this->_currentIndex != other._currentIndex;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
    return true;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    return true;
}







// Implementation of SideCrossIterator

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container) :
    _container(container), _currentIndex(0), _forwardDirection(true) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) :
    _container(other._container), _currentIndex(other._currentIndex), _forwardDirection(other._forwardDirection) {}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
    return this->_currentIndex == other._currentIndex;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return this->_currentIndex != other._currentIndex;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
    return this->_container.getElementAt(this->_currentIndex) > other._container.getElementAt(other._currentIndex);
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
    return this->_container.getElementAt(this->_currentIndex) < other._container.getElementAt(other._currentIndex);
}






// Implementation of PrimeIterator

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container) :
    _container(container), _currentIndex(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other) :
    _container(other._container), _currentIndex(other._currentIndex) {}




bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
    return this->_currentIndex == other._currentIndex;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
    return this->_currentIndex != other._currentIndex;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
    return this->_container.getElementAt(this->_currentIndex) > other._container.getElementAt(other._currentIndex);
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
    return this->_container.getElementAt(this->_currentIndex) < other._container.getElementAt(other._currentIndex);
}







bool MagicalContainer::PrimeIterator::isPrime(int number) {
    if (number < 2) {
        return false;
    }
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}