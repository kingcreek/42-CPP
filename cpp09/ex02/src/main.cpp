/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:47:04 by imurugar          #+#    #+#             */
/*   Updated: 2024/01/01 21:40:13 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// based on https://iq.opengenus.org/merge-insertion-sort

static int errUsage()
{
	std::cout << "Error: invalid arguments" << std::endl;
	std::cout << "Usage: ./PmergeMe <N numbers>" << std::endl;
	return EXIT_FAILURE;
}

int main(int argc, const char *argv[])
{

	if (argc < 2)
		return errUsage();
	PmergeMe pmerge = PmergeMe();

	try
	{
		pmerge.parseArguments(++argv);
		pmerge.performShort();
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	return EXIT_SUCCESS;
}

/**************************************
1. std::vector:

Characteristics:
- Dynamic array-based container.
- Fast random access to elements.
- Efficient contiguous memory allocation.

Pros:
- Fast random access.
- Efficient for appending elements to the end.
- Good cache locality due to contiguous memory.

Cons:
- Slower insertion in the middle.

Common Use Cases:
- When fast random access is required.
- When elements are frequently accessed and modified.
- When you don't need frequent insertions or deletions in the middle.

**************************************/

/**************************************
2. std::deque (Double-Ended Queue):

Characteristics:
- Double-ended queue-based container.
- Fast insertions and deletions at both ends.

Pros:
- Fast insertion and deletion at both ends.
- Dynamic memory allocation.

Cons:
- Slower random access.
- Slower insertion in the middle.

Common Use Cases:
- When you need efficient insertions and deletions at both ends.
- When implementing a double-ended queue.
- In scenarios with frequent front and back operations, like a sliding window.

**************************************/

/**************************************
3. std::list:

Characteristics:
- Doubly-linked list-based container.
- Fast insertions and deletions anywhere.

Pros:
- Fast insertions and deletions at any position.
- Stable iterators (not invalidated by insertions).

Cons:
- Slow random access.
- Higher memory overhead due to node structure.

Common Use Cases:
- When you need efficient insertions and deletions anywhere in the container.
- When iterators must remain valid after insertions.

**************************************/

/**************************************
4. std::set and std::multiset:

Characteristics:
- Associative containers based on a balanced binary search tree (typically Red-Black Tree).
- Automatically sorted elements.

Pros:
- Elements are automatically sorted.
- Efficient for searching and maintaining a sorted collection.

Cons:
- Slower insertion and deletion compared to vectors and lists.

Common Use Cases:
- When you need to maintain a sorted collection of unique elements (std::set).
- When you need to maintain a sorted collection with duplicate elements allowed (std::multiset).

**************************************/

/**************************************
5. std::map and std::multimap:

Characteristics:
- Associative containers with key-value pairs based on a balanced binary search tree.
- Automatically sorted by keys.

Pros:
- Efficient for key-based searches and maintaining sorted key-value pairs.

Cons:
- Slower insertion and deletion compared to vectors and lists.

Common Use Cases:
- When you need to maintain a sorted collection of key-value pairs with unique keys (std::map).
- When you need to maintain a sorted collection with duplicate keys allowed (std::multimap).

**************************************/

/**************************************
6. std::unordered_set and std::unordered_multiset:

Characteristics:
- Associative containers based on a hash table.
- Elements are not ordered; hashing determines the order.

Pros:
- Fast constant-time average insertion, search, and deletion.
- No sorting overhead.

Cons:
- Elements are not ordered.

Common Use Cases:
- When you need fast lookups and don't require sorted elements (std::unordered_set).
- When you need fast lookups with duplicate elements allowed (std::unordered_multiset).

**************************************/

/**************************************
7. std::unordered_map and std::unordered_multimap:

Characteristics:
- Associative containers with key-value pairs based on a hash table.
- Elements are not ordered; hashing determines the order.

Pros:
- Fast constant-time average operations for key-based lookups, insertions, and deletions.
- No sorting overhead.

Cons:
- Elements are not ordered.

Common Use Cases:
- When you need fast key-based lookups and don't require sorted key-value pairs (std::unordered_map).
- When you need fast key-based lookups with duplicate keys allowed (std::unordered_multimap).

**************************************/