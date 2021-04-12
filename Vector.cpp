#include "Vector.h"
#include <algorithm>
#include <stdexcept>

Vector::Vector() {
}

Vector::Vector(ValueType* data, size_t size){
	if (size != 0) {
		_size = size;
		_capacity = size * 2;
		_loadFactor = 0, 5;
		_data = new ValueType(_capacity);
		memcpy(_data, data, size);
	}
}

Vector::~Vector() {
	delete[] _data;
}

///

void Vector::calculateLoadFactor() {
	_loadFactor = _size / _capacity;
}

void Vector::resize() {
	calculateLoadFactor();
	if ((_loadFactor == 1) || (_loadFactor <= 0, 25)) {
		_capacity = _size / _loadFactor;
		if (!_capacity) {
			_capacity = 1;
		}
		ValueType* newdata = new ValueType(_capacity);
		for (int i = 0; i < _size; ++i) {
			newdata[i] = _data[i];
		}
		std::swap(newdata, _data);
		delete[] newdata;
	}
}

bool Vector::isEmpty() {
	if (_data == nullptr) {
		return 1;
	}
	else {
		return 0;
	}
}

///

void Vector::pushBack(const ValueType& value) {
	insert(value, _size);
}

void Vector::pushFront(const ValueType& value) {
	insert(value, 0);
}

void Vector::insert(const ValueType& value, size_t idx) {
	++_size;
	if (isEmpty) {
		_data = new ValueType(1);
	}
	ValueType prevValue, curValue;
	prevValue = _data[idx];
	_data[idx] = value;
	for (int i = idx + 1; i <= _size; ++i) {
		curValue = _data[i];
		_data[i] = prevValue;
		prevValue = value;
	}
	resize();
}

ValueType& Vector::at(size_t idx) {
	if (idx > _size) {
		throw std::out_of_range("Out of range");
	}
	return _data[idx];
}

ValueType& Vector::operator[](size_t idx) {
	return at(idx);
}

const ValueType& Vector::at(size_t idx) const {
	if (idx > _size) {
		throw std::out_of_range("Out of range");
	}
	return _data[idx];
}

const ValueType& Vector::operator[](size_t idx) const{
	return at(idx);
}

void Vector:: clear() {
	_capacity = 1;
	_size = 0;
	delete[] _data;
	_loadFactor = 0;
}

void Vector::erase(size_t i) {
	if (!isEmpty) {
		for (int j = i + 1; j < _size; ++j) {
			_data[j - 1] = _data[j];
		}
		--_size;
		resize();
	}
}

void Vector::erase(size_t i, size_t len) {
	for (int j = 0; j < len; ++j) {
		erase(i);
	}
}

void Vector::popBack() {
	erase(_size - 1);
}

size_t Vector::size() const {
	return _size;
}

size_t Vector::find(const ValueType& value) const {
	for (int i = 0; i < _size; ++i) {
		if (_data[i] == value) {
			return i;
		}
	}
	throw std::exception("Not found");
}