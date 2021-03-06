#include <stdlib.h>
/* treat strings as base-256 integers 
 * with digits in the range 1 to 255*/
#define MULTIPLIER (37)

// compute_hash: computes the hash value of string of chars pointed to by string
size_t compute_hash(const char *string, size_t mod) {
	size_t hash_val;
	unsigned const char *u_string;
	// cast string to unsigned const char*
	// this will ensure that elements of s will be treated as having values >= 0
	u_string = (unsigned const char*)string;

	// initialize h with initial value
	hash_val = 0;
	// go over string and compute hash value
	while(*u_string != '\0') {
		// h_{i} = (h_{i-1}*BASE + string_{i+1}) mod m
		hash_val = hash_val * MULTIPLIER + *u_string;
		u_string++;
	}

	// return computed hash value
	return hash_val;
}

// use small prime base as multiplier and rely on it to break up patterns in the input
// C truncates the result of any operation that exceeds the size of the integer 
// type that holds it (the code contains a "hidden" mod)