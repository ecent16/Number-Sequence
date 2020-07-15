// Header File Sort_Sequence_Centeno.h

#ifndef Sort_Sequence_Centeno_H
#define Sort_Sequence_Centeno_H
#include <cstdlib>

class sort_sequence {
	public:
		// MEMBER CONSTANTS AND TYPEDEF
		typedef double v_type;				// v_type becomes type double.
		typedef std::size_t s_type;			// size_type has no set data type.
		static const s_type CAPACITY = 30;	// Max capacity of sequence.

		// CONSTUCTORS
		sort_sequence();							// Default Constructor.

		void start();						// First item becomes the current.
		void advance();						// The item after the current item becomes the new current.
		void insert_sort(const v_type& entry);	// Inserts a new value in ascending order.
		void remove_current();				// Removes the value that is current.

		void operator +=(const sort_sequence& addend);

		// CONSTANT MEMBER FUNCTIONS
		s_type size() const;
		bool is_item() const;
		v_type current() const;				// Assigns a value as current.

	private:
		v_type data[CAPACITY];
		s_type used;
		s_type current_index;

};
// NONMEMBER FUNCTIONS
sort_sequence operator +(const sort_sequence& x, const sort_sequence& y);

#endif