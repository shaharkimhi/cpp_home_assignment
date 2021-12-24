//Question 1 - basic STL

//Task 1: improve fill_vector and vecOfVec.push_back performance - execution time can be reduced significantly, please explain the changes you made and how they improve
// the application performance.

//Task 2: Implement count_total_elements without using a "visible" for loop

//Task 3: Implement merge_vec_of_vec

// Make sure you compile the code in "Release" configuration (e.g O2 optimization level).
// Do not modify ELEMENT_COUNT and ITERATIONS and functions fill_vector,count_total_elements and merge_vec_of_vec function signatures

#include <chrono>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

constexpr size_t ELEMENT_COUNT = 1000 * 10000;
constexpr size_t ITERATIONS = 10;
size_t sum = 0;



std::vector<uint64_t> fill_vector(size_t elementCount) {
	std::vector<uint64_t> vec(elementCount);
	std::iota (std::begin(vec), std::end(vec), 0);
	return vec;
}


void sumSizeVector(const std::vector<uint64_t>& vec){
	sum+= vec.size();
}

/// This function should return the total elements in all of the vectors
size_t count_total_elements(const std::vector<std::vector<uint64_t>>& vecOfVec) {
	sum = 0;
	for_each(vecOfVec.begin(), vecOfVec.end(), sumSizeVector);
	return sum;
}

/// This function should return a single vector that contain all of the elements of the vectors in vecOfVec
std::vector<uint64_t> merge_vec_of_vec(std::vector<std::vector<uint64_t>>& vecOfVec) {
	std::vector<uint64_t> mergedVec;
	size_t total_elements = count_total_elements(vecOfVec);
	mergedVec.reserve(total_elements); // requests that the vector capacity be at least total_elements
	for (auto& items: vecOfVec){
		std::move(items.begin(), items.end(), std::back_inserter(mergedVec));
	}
	return mergedVec;
}

int main(int argc, char** argv)
{
	//Create vector of vectors
	std::vector<std::vector<uint64_t>> vecOfVec(ITERATIONS);
	auto start = std::chrono::steady_clock::now();
	std::vector<uint64_t> vec = fill_vector(ELEMENT_COUNT);
	for (size_t i = 0; i < ITERATIONS; i++) {
		//TODO: improve inserting performance
		vecOfVec.push_back(vec);
	}
	auto end = std::chrono::steady_clock::now();
	size_t averageIterationTimeUs = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / ITERATIONS;
	std::cout << "Average iteration duration in microseconds: " << averageIterationTimeUs << std::endl;

	//Count elements
	size_t totalElements = count_total_elements(vecOfVec);
	std::cout << "Total elements in vecOfVec: " << totalElements <<  " " << std::endl;

	//Merge vector of vectors
	std::vector<uint64_t> mergedVec = merge_vec_of_vec(vecOfVec);
	std::cout << "Total elements in merged mergedVec: " << mergedVec.size() << std::endl;

	std::cout << "Press enter to exit" << std::endl;
	getchar();
	return 0;
}