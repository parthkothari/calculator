// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//
template <typename T>
Stack <T>::Stack (void):
data_(Array<T>()),
cur_size_(0),
alloc_size_(0)
{

}

//

// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack):
data_(Array<T>(stack.alloc_size_)),
cur_size_(stack.cur_size_),
alloc_size_(stack.alloc_size_)
{
	//making a deep copy, calling = operator of array
	this->data_ = stack.data_;
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
	//data_ is a stack allocated structure, no need to deallocate
	//the destructor of array will take care of inherent deallocation
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
  // Parth, you should try to minimize your calls to the
  // resize method, and grow the underlying array more
  // efficiently. Even if your array is growing its memory
  // in chunks, you should not be calling resize every time!
  //
  // Dr. Hill, I have changed to push method such that it only 
  // needs to call resize method if the stack has reached its maximum 
  // allocation memory, and this cost is amortized with normal push.
	
	
	// is this the first push operation on stack OR,
	// have we ran out of allocated memory?
	// then allocate more memory before pushing the element
	if (this->cur_size_ == this->alloc_size_)
	{
		this->data_.resize(this->alloc_size_ + 10);
		this->alloc_size_+=10;
	}

	//now put the element on the stack and update the current size
	this->data_[this->cur_size_] = element;
	++this->cur_size_;
}

//
// pop
//

template <typename T>
void Stack <T>::pop (void)
{
	if (this->cur_size_ == 0)
	{
		throw empty_exception();
	}
	else
	{
		--this->cur_size_;	//top most element now not accessible
	}
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	if (this != &rhs)
	{
		//if we have enough extra memory allocated
		if (this->alloc_size_ > rhs.cur_size_)
		{
			this->data_ = rhs.data_;
			this->cur_size_ = rhs.cur_size_;
		}
		// if not, allocate extra memory and then copy
		else
		{
			this->data_.resize(rhs.cur_size_+10);
			this->alloc_size_ = (rhs.cur_size_+10);
			this->data_ = rhs.data_;
			this->cur_size_=rhs.cur_size_;
		}
	}
	return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
  // Parth, there is no need to call pop() mutiple times
  // to clear the array. Just reset the markers. This should
  // be an O(1) method, and not an O(n) method.
  //
  // Dr. Hill, I have addressed this issue by directly setting 
  // the current size marker to 0.
 
	this->cur_size_=0;
}


//
// printit
//
/*-----------------------------------------------------------------------------------
@@@	function to view elements for diagnostic purposes
------------------------------------------------------------------------------------*/
template <typename T>
void Stack<T>::printit(void)
{
	if (cur_size_ != 0)
	{
		std::cout << "#Printing Stack" << std::endl;
		std::cout << "Current Size of the Stack : " << cur_size_ << std::endl;
		std::cout << "Total slots allocated: " << alloc_size_ << std::endl;
		int i=0;
		while(i<cur_size_)
		{
			std::cout << "Index " << i << " : " << this->data_[i] << std::endl;
			++i;
		}
		std::cout << "#printing complete" << std::endl;
	}
	else
	{
		std::cout << "The Stack doesn't have any elements!" << std::endl;
	}
}

template <typename T>
const T Stack<T>::get_element(size_t index)
{
	return this->data_[index];
}