#pragma once

#include <vector>
#include <iostream>

namespace ariel {
    class MagicalContainer {
    private:
        std::vector<int> _elements;
        std::vector<int*> _primeElements;
        int _size;
        int _sizeP;
        MagicalContainer(const MagicalContainer&& other) = delete;
        MagicalContainer& operator=(const MagicalContainer& other) = default;
        MagicalContainer& operator=(MagicalContainer&& other) = delete;
    public:
        MagicalContainer();
        MagicalContainer(const MagicalContainer& other);
        ~MagicalContainer() = default;
        void addElement(int element);
        void removeElement(int element);
        int size() const{
            return _size;
        }
        int sizeP() const{
            return _sizeP;
        }
        int getElementAt(int index) const;
        int getPElementAt(int index) const;


        class AscendingIterator;
        class SideCrossIterator;
        class PrimeIterator;
    };
    class MagicalContainer::AscendingIterator {
    private:
        MagicalContainer& _container;
        int _currentIndex;
        AscendingIterator& operator =(AscendingIterator&& other) = delete;
        AscendingIterator(AscendingIterator&& other)noexcept;
    public:
        AscendingIterator(MagicalContainer& container);
        AscendingIterator(const AscendingIterator& other);
        ~AscendingIterator() = default;
    
        AscendingIterator& operator=(const AscendingIterator& other) {
            if(&this->_container != &other._container){
                throw std::runtime_error("diffrent containers");
            }
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
            if(_currentIndex == _container.size()){
                throw std::runtime_error("already in the end");
            }
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
        int _demoIndex;
        bool _forwardDirection;
        SideCrossIterator(SideCrossIterator&& other)noexcept;
        SideCrossIterator& operator=(SideCrossIterator&& other) = delete;
    public:
        SideCrossIterator(MagicalContainer& container);
        SideCrossIterator(const SideCrossIterator& other);
        ~SideCrossIterator() = default;
        SideCrossIterator& operator=(const SideCrossIterator& other) {
            if(&this->_container != &other._container){
                throw std::runtime_error("diffrent containers");
            }
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
            if(_demoIndex == _container.size()){
                throw std::runtime_error("already in the end");
            }
            _demoIndex++;
            if(_container.size() % 2 == 0 && _currentIndex == (_container.size()/2)){
                _currentIndex = _container.size();
                return *this;
            }
            if(_container.size() % 2 != 0 && _currentIndex == (_container.size()-1)/2){
                _currentIndex = _container.size();
                return *this;
            }
            if(_forwardDirection){
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
        PrimeIterator(PrimeIterator&& container)noexcept;
        PrimeIterator& operator=(PrimeIterator&& other) = delete;
    public:
        PrimeIterator(MagicalContainer& container);
        PrimeIterator(const PrimeIterator& other);
        ~PrimeIterator() = default;
        PrimeIterator& operator=(const PrimeIterator& other) {
            if(&this->_container != &other._container){
                throw std::runtime_error("diffrent containers");
            }
            return *this;
        }        
        bool operator==(const PrimeIterator& other) const;
        bool operator!=(const PrimeIterator& other) const;
        bool operator>(const PrimeIterator& other) const;
        bool operator<(const PrimeIterator& other) const;
        int operator*() const{
            return _container.getPElementAt(_currentIndex);
        }
        PrimeIterator& operator++(){
            if(_currentIndex == _container.sizeP()){
                throw std::runtime_error("already in the end");
            }
            _currentIndex++;
            return *this;
        }
        PrimeIterator begin(){
            return PrimeIterator(_container);
        }
        PrimeIterator end(){
            PrimeIterator itar(_container);
            itar._currentIndex = _container.sizeP();
            return itar;
        }
    };
}
