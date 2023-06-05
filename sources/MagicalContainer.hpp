#pragma once

#include <vector>

namespace ariel {
    class MagicalContainer {
    private:
        std::vector<int> _elements;
        int _size;
        MagicalContainer& operator=(MagicalContainer&& other) = delete;
    public:
        MagicalContainer();
        ~MagicalContainer() = default;
        void addElement(int element);
        void removeElement(int element);
        int size() const{
            return _size;
        }
        int getElementAt(int index) const;


        class AscendingIterator;
        class SideCrossIterator;
        class PrimeIterator;
    };

    class MagicalContainer::AscendingIterator {
    private:
        MagicalContainer& _container;
        int _currentIndex;

    public:
        AscendingIterator(MagicalContainer& container);
        AscendingIterator(const AscendingIterator& other);
        ~AscendingIterator() = default;
    
        AscendingIterator& operator=(const AscendingIterator& other) {
            return *this;
        }       
        bool operator==(const AscendingIterator& other) const;
        bool operator!=(const AscendingIterator& other) const;
        bool operator>(const AscendingIterator& other) const;
        bool operator<(const AscendingIterator& other) const;
        int operator*() const{
            return _container.getElementAt(_currentIndex);
        }
        AscendingIterator& operator++(){
            _currentIndex++;
            return *this;
        }
        AscendingIterator begin(){
            return AscendingIterator(_container);
        }
        AscendingIterator end(){
            AscendingIterator itar(_container);
            itar._currentIndex = _container.size();
            return itar;
        }
    };

    class MagicalContainer::SideCrossIterator {
    private:
        MagicalContainer& _container;
        int _currentIndex;
        bool _forwardDirection;

    public:
        SideCrossIterator(MagicalContainer& container);
        SideCrossIterator(const SideCrossIterator& other);
        ~SideCrossIterator() = default;
        SideCrossIterator& operator=(const SideCrossIterator& other) {
            return *this;
        }
        bool operator==(const SideCrossIterator& other) const;
        bool operator!=(const SideCrossIterator& other) const;
        bool operator>(const SideCrossIterator& other) const;
        bool operator<(const SideCrossIterator& other) const;
        int operator*() const{
            return _container.getElementAt(_currentIndex);
        }
        SideCrossIterator& operator++(){
            if(_container.size() % 2 == 0 && _currentIndex == (_container.size()/2)){
                _currentIndex = _container.size();
                return *this;
            }
            else if(_currentIndex == (_container.size()-1)/2){
                _currentIndex = _container.size();
                return *this;
            }
            if(_forwardDirection == true){
                _forwardDirection = false;
                _currentIndex = (_container.size()-1) - _currentIndex;
            }
            else{
                _forwardDirection = true;
                _currentIndex = _container.size() - _currentIndex;
            }
            return *this;
        }
        SideCrossIterator begin(){
            return SideCrossIterator(_container);
        }
        SideCrossIterator end(){
            SideCrossIterator itar(_container);
            itar._currentIndex =  _container.size();
            return itar;
        }
    };

    class MagicalContainer::PrimeIterator {
    private:
        MagicalContainer& _container;
        int _currentIndex;

    public:
        PrimeIterator(MagicalContainer& container);
        PrimeIterator(const PrimeIterator& other);
        ~PrimeIterator() = default;
        PrimeIterator& operator=(const PrimeIterator& other) {
            return *this;
        }        bool operator==(const PrimeIterator& other) const;
        bool operator!=(const PrimeIterator& other) const;
        bool operator>(const PrimeIterator& other) const;
        bool operator<(const PrimeIterator& other) const;
        int operator*() const{
            return _container.getElementAt(_currentIndex);
        }
        PrimeIterator& operator++(){
            _currentIndex++;
            return *this;
        }
        PrimeIterator begin(){
            return PrimeIterator(_container);
        }
        PrimeIterator end(){
            PrimeIterator itar(_container);
            itar._currentIndex = _container.size();
            return itar;
        }

    private:
        bool isPrime(int number);
    };
}
