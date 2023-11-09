cmake_minimum_required(VERSION 3.16)
project(CppLeetCode)

set(CMAKE_CXX_STANDARD 20)

enable_testing()
# add_test(NAME runBuySellCode COMMAND runBuySellCode)

#Binary Search tests
add_executable(runBinarySearch src/BinarySearch/BinarySearch.cpp)
add_executable(runFindMinSortedArray src/BinarySearch/FindMinRotatedSortedArray.cpp)
add_executable(runSearch2DMatrix.cpp src/BinarySearch/Search2DMatrix.cpp)
add_executable(runSearchRotatedSortedArray src/BinarySearch/SearchRotatedSortedArray.cpp)

#Sliding Window
add_executable(runBuySellCode src/SlidingWindow/BestTimetoBuyAndSell.cpp)
add_executable(runContainsDuplicate2 src/SlidingWindow/ContainsDuplicateII.cpp)
add_executable(runLongestRepeatSubstring src/SlidingWindow/LongestRepeatSubstring.cpp)
add_executable(runLongestSubstring src/SlidingWindow/LongestSubString.cpp)

#TwoPointers
add_executable(runTwoSum2 src/TwoPointers/TwoSumSorted.cpp)
add_executable(runThreeSum src/TwoPointers/ThreeSum.cpp)
add_executable(runContainerWMostWater src/TwoPointers/ContainerWMostWater.cpp)
add_executable(runValidPalindrome src/TwoPointers/ValidPalindrome.cpp)

#Trees
add_executable(runSameTree src/Trees/SameTree.cpp)
add_executable(runSubtreeOfAnotherTree src/Trees/SubTreeOfAnotherTree.cpp)
add_executable(runInvertBinaryTree src/Trees/InvertBinaryTree.cpp)

#Dynamic Programming
add_executable(runClimbingStairs src/DynamicProgramming/ClimbingStairs.cpp)

#Stacks
add_executable(runValidParanthesis src/Stacks/ValidParantheses.cpp)
add_executable(runMinStack src/Stacks/MinStack.cpp)
add_executable(runDailyTemperatures src/Stacks/DailyTemperatures.cpp)

#MultiThreading
add_executable(runFizzBuzz src/MultiThreading/FizzBuzzMultiThreaded.cpp)
add_executable(runPrintFooBar src/MultiThreading/PrintFooBarAlternatively.cpp)
add_executable(runPrintInOrder src/MultiThreading/PrintInOrder.cpp)

#Linked List
add_executable(runMergeSortList src/LinkedList/MergeSortList.cpp)
add_executable(runReverseLinkedList src/LinkedList/ReverseLinkedList.cpp)

#Greedy
add_executable(runJumpGame src/Greedy/JumpGame.cpp)
add_executable(runJumpGame2 src/Greedy/JumpGameII.cpp)

#Graphs
add_executable(runBFSDFS src/Graphs/GraphBfsDfs.cpp)
add_executable(runNumberOfIslands src/Graphs/NumberOfIslands.cpp)

#BitManipulation
add_executable(runNumberOf1Bits src/BitManipulation/NumberOf1Bits.cpp)
add_executable(runReverseBits src/BitManipulation/ReverseBits.cpp)
add_executable(runMissingNumbers src/BitManipulation/MissingNumbers.cpp)

#Arrays
add_executable(runValidAnagram src/Arrays/ValidAnagram.cpp)
add_executable(runContainsDuplicate src/Arrays/ContainsDuplicate.cpp)
add_executable(runProductOfARray src/Arrays/ProductOfArray.cpp)
add_executable(runTopkFrequentElements src/Arrays/TopkFrequentElements.cpp)
add_executable(runTwoSum src/Arrays/TwoSum.cpp)
add_executable(runRemovesDuplicates src/Arrays/RemovesDuplicates.cpp)
add_executable(runSplitStrings.cpp src/Arrays/SplitStrings.cpp)

#Math And Geometry
add_executable(runRotateImage src/MathNGeometry/RotateImage.cpp)
add_executable(runMatrixSum src/MathNGeometry/MatrixSum.cpp)
add_executable(runSetMatrixZero src/MathNGeometry/SetMatrixZero.cpp)


