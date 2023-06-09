#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;

bool isPrime(int number) {
    if(number == 2){
        return true;
    }
    if(number % 2 == 0 || number < 2){
        return false;
    }
    for (int i = 2; i <= sqrt(number); ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}


// Implementation of MagicalContainer
MagicalContainer::MagicalContainer():
    _elements(),_size(0),_sizeP(0),_primeElements(){}

MagicalContainer::MagicalContainer(const MagicalContainer& other):
    _elements(other._elements),_size(other._size),_primeElements(other._primeElements),_sizeP(other._sizeP){}

void MagicalContainer::addElement(int element) {
    _elements.push_back(element);
    _size++;
    sort(_elements.begin(),_elements.end());
    _primeElements.clear();
    _sizeP = 0;
    for(auto it = _elements.begin();it != _elements.end(); ++it){
        if(isPrime(*it)){
            _sizeP++;
            int * ans = &(*it);
            _primeElements.push_back(ans);
        }
    }
}

void MagicalContainer::removeElement(int element) {
    bool check = true;
    for (auto it = _elements.begin(); it != _elements.end(); ++it) {
        if (*it == element) {
            _elements.erase(it);
            --_size;
            check = false;
            break;
        }
    }
    if(isPrime(element)){
        for(auto it = _primeElements.begin(); it != _primeElements.end(); ++it){
            if(**it == element){
                _primeElements.erase(it);
                --_sizeP;
                break;
            }
        }
    }
    if(check){
        throw runtime_error("The element is not in the vector");
    }
}

int MagicalContainer::getElementAt(int index) const {
    if(index < 0 || _size <=index){
        throw out_of_range("Invalid index");
    }
    return _elements.at(static_cast<std::vector<int>::size_type>(index));  
}

int MagicalContainer::getPElementAt(int index) const {
    if(index < 0 || _size <=index){
        throw out_of_range("Invalid index");
    }
    return *(_primeElements.at(static_cast<std::vector<int*>::size_type>(index)));  
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
    return this->_currentIndex > other._currentIndex;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    return this->_currentIndex < other._currentIndex;
}


// Implementation of SideCrossIterator

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container) :
    _container(container), _currentIndex(0), _forwardDirection(true),_demoIndex(0) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) :
    _container(other._container), _currentIndex(other._currentIndex), _forwardDirection(other._forwardDirection),_demoIndex(other._demoIndex) {}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
    return this->_currentIndex == other._currentIndex;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return this->_currentIndex != other._currentIndex;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
    return this->_demoIndex > other._demoIndex;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
    return this->_demoIndex < other._demoIndex;
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
    return this->_currentIndex > other._currentIndex;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
    return this->_currentIndex < other._currentIndex;
}

