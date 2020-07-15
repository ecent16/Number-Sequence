// Implement_Sort_Sequence.cpp
// Ervin Centeno
// Sequence Assignment 
// February 25, 2019

#include "pch.h"
#include <algorithm>
#include <cassert>
#include "Sort_Sequence_Centeno.h"

using namespace std;

sort_sequence::sort_sequence() {

	current_index = 0;		// Sets the index to 0 at the beginning of the program.
	used = 0;				// The number of elements in an array;

}
// MODIFICATION MEMBER FUNCTIONS
void sort_sequence::start() {

	current_index = 0;	// First item becomes the current_index.

}
void sort_sequence::advance() {

	if (is_item() == true) {
		current_index++;	// Assigns current_index to the next index in the sequence.
	}
}

void sort_sequence::insert_sort(const v_type& entry) {

	assert(size() < CAPACITY);

	if (!is_item()) {
		current_index = 0;
	}
	for (s_type i = 0; i < used + 1; i++) {
		for (s_type j = i + 1; j < used + 1; j++) {

			if (data[i] > data[j]) {	// If the 

				s_type temp = data[i];
				data[i] = data[j];
				data[j] = temp;

			}

		}

	}
	data[current_index] = entry;	// Assigns entry as the new current.
	used++;							// Increases the total item count by one.

}
void sort_sequence::remove_current() {

	assert(is_item() == true);		// Assumes that their is a current_index/

	for (s_type i = current_index; i < used - 1; i++) {
		data[i] = data[i + 1];
	}
	--used;
}
void sort_sequence::operator +=(const sort_sequence& addend) {

	assert(size() + addend.size() <= CAPACITY);

	copy(addend.data, addend.data + addend.used, data + used);
	used += addend.used;		// Copies the number of items in data into addend.used.

}
// CONSTANT MEMBER FUNCTIONS
sort_sequence::s_type sort_sequence::size() const {

	return used;

}
bool sort_sequence::is_item() const {

	if (current_index < used) {
		return true;			// Returns true if the item is assigned as current_index.
	}
	else
		return false;

}
sort_sequence::v_type sort_sequence::current() const {

	return data[current_index];	// Assigns the item in the sequence as current_index.

}
// NONMEMBER FUNCTIONS
sort_sequence operator +(const sort_sequence& x, const sort_sequence& y) {

	sort_sequence answer;
	assert(x.size() + y.size() <= sort_sequence::CAPACITY);

	answer += x;
	answer += y;
	return answer;		// Contains values from x and y.

}