//#include "Iterator.h"
//
// Iterator
//

// Constructor. postfixptr is valid length of the Array.
template <typename T>
Iterator<T>::Iterator(Array <T> & a, int postfixptr): 
a_ (a), 
curr_ (0),
max_(postfixptr)
{
}

// Destructor.
template <typename T>
Iterator<T>::~Iterator(void)
{
}

// Returns true if iteration is complete.
template <typename T>
bool Iterator<T>::is_done (void) 
{
	return this->curr_ >= this->max_;  
}

// Advances the iterator.
template <typename T>
bool Iterator<T>::advance (void) 
{ 
	++this->curr_; 
	return true;
}

// Operator *
template <typename T>
T Iterator<T>::operator * (void)
{
	return this->a_.get(this->curr_); 
}


// Operator ->
template <typename T>
T * Iterator<T>::operator -> (void)
{
	return &this->a_.get(this->curr_); 
}
