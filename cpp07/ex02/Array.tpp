/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:30:06 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/09 16:40:38 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _size(0) {
	_array = new T[0];
	_instance = 1;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n) {
	_array = new T[n];
	_instance = 1;
}

template <typename T>
Array<T>::~Array(void) {
	if (this->_array != NULL)
		delete [] this->_array;
}

template <typename T>
Array<T>::Array(const Array& copy) {
	_instance = 0;
	*this = copy;
	_instance = 1;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& copy) {
	if (this == &copy) {
		return *this;
	}
	if (this->_instance == 1)
		delete[] this->_array;
	this->_array = new T[copy.size()];
	for (unsigned int i = 0; i < copy.size(); i++) {
		this->_array[i] = copy._array[i];
	}
	this->_size = copy.size();
	return (*this);
}

template <typename T>
unsigned int Array<T>::size(void) const {
	return (this->_size);
}

template <typename T>
T& Array<T>::operator[](const unsigned int i) {
	if (i >= this->_size)
		throw std::out_of_range("Index out of bounds");
	return (this->_array[i]);
}

#endif