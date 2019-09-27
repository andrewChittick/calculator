// Honor Pledge:
//
//  I pledge that I have neither given nor received any help
//  on this assignment
//  Andrew Chittick 9/28/18

/**
 * @class Queue
 *
 * Basic queue for arbitrary elements.
 */

#include "Queue.h"

// Default constructor
template <typename T>
Queue <T>::Queue (void):
	arr_ (DEFAULT_SIZE),
	front_ (0),
	back_ (0)
{}

// Copy constructor
template <typename T>
Queue <T>::Queue (const Queue & queue):
	arr_ (queue.arr_),
	front_ (queue.front_),
	back_ (queue.back_)
{}

// Destructor
template <typename T>
Queue <T>::~Queue (void)
{
	this->front_ = 0;
	this->back_ = 0;
}

/**
 * Assignment operator
 *
 * @param[in]      rhs           Right-hand side of operator
 * @return         Reference to self
 */
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
	//check for self assignment
	if (this == &rhs){
		return (*this);
	}
	//make the container the right size
	if (this->arr_.size() != rhs.arr_.size()){
		this->arr_.resize(rhs.arr_.size());
		this->arr_.shrink();
	}
	//copy the data
	for (int i = 0; i < rhs.arr_.size(); i++){
		this->arr_.set(i, rhs.arr_.get(i));
	}
	this->front_ = rhs.front_;
	this->back_ = rhs.back_;
	return (*this);
}

/**
 * Enqueue a new \a element onto the queue. The element is inserted
 * before all the other elements in the list.
 *
 * @param[in]      element       Element to add to the list
 */
template <typename T>
void Queue <T>::enqueue (T element)
{
	if (this->back_ == this->arr_.size()){
		this->arr_.resize(this->arr_.size() * 2);
	}
	this->arr_.set(this->back_, element);
	this->back_++;
}

/**
 * Remove and return the last element from the queue.
 *
 * @exception      empty_exception    The queue is empty.
 */
template <typename T>
T Queue <T>::dequeue (void)
{
	if (is_empty()){
		//exception handling for empty queue
		throw empty_exception();
	}
	else{
		//return and pop
		this->front_++;
		return(arr_.get(this->front_ - 1));
	}
}

// Remove all elements from the queue
template <typename T>
void Queue <T>::clear (void)
{
	//reset the pointers
	this->front_ = 0;
	this->back_ = 0;
	//shrink the queue
	this->arr_.resize(DEFAULT_SIZE);
	this->arr_.shrink();
}
