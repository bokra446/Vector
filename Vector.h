#pragma once
#include "IVector.h"
class Vector : public IVector{
private:
	ValueType* _data = nullptr;
	size_t _size = 0;
	size_t _capacity = 1;
	float _loadFactor = 0;
public:
	Vector();
	Vector(ValueType* data, size_t size);
	~Vector();


	void pushBack(const ValueType& value) override;
	void pushFront(const ValueType& value) override;
	void insert(const ValueType& value, size_t idx) override;

	ValueType& at(size_t idx) override;
	ValueType& operator[](size_t idx);
	const ValueType& at(size_t idx) const override;
	const ValueType& operator[](size_t idx) const;

	void clear() override;
	void erase(size_t i) override;
	void erase(size_t i, size_t len) override;
	void popBack() override;

	size_t size() const override;

	size_t find(const ValueType& value) const override;

	void calculateLoadFactor();
	void resize();
	bool isEmpty();
};