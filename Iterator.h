#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include "Array.h"

/*-----------------------------------------------------------------------
//	Iterator to Iterate over Array<T>
/------------------------------------------------------------------------*/

template <typename T>
class Iterator
{
public:
	
	typedef T type;
	
	// Constructor.	postfixptr is valid length of the Array.
	Iterator (Array<T> & s, int postfixptr);

	// Destructor.
	~Iterator (void);

	// Returns true if iteration is complete.
	bool is_done (void);

	// Advances the iterator.
	bool advance (void);

	// Operator *
	T operator * (void);

	// Operator ->
	T * operator -> (void);

private:

Array <T> a_;
size_t curr_;
size_t max_;

};

#include "Iterator.cpp"

#endif   // ! _ITERATOR_H_