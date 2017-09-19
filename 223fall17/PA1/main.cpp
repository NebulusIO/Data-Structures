/*
 * Binary Search Tree implementation - heavily lifted from https://gist.github.com/mgechev/5911348
 *
 * Simple integer keys and basic operations
 * Now also doing testing & height calculations
 *
 * Aaron Crandall - 2016 - Added / updated:
 *  * Inorder, Preorder, Postorder printouts
 *  * Stubbed in level order printout
 *  * Also doing height calculations
 *
 */

#include <iostream>
#include <queue>
#include <cstring>
#include "BST.h"
#include "TestData.h"

#include <fstream>
#include <math.h>

using namespace std;

/*
 *  Interface to run all tests if --test is passed on command line
 */
void runTests() {
	cout << " [x] Running tests. " << endl;
	TestData *testing = new TestData();			// Create object with testing data and interfaces

  BST<int> *bst_test = new BST<int>;

	/* Should make a tree like this:
              10
         5          14
     1      7           17
                            19
                          18

   */
	int testval = testing->get_next_minitest();
	while( testval >= 0 ){
		bst_test->add( testval );
		testval = testing->get_next_minitest();
	}
	cout << " [x] Should print out in pre order: 10 5 1 7 14 17 19 18 " << endl;
  cout << " [x] Resulting print out test:      ";
	bst_test->printPreOrder();
  cout << endl;

	cout << " [x] Should print a tree height of  : 5" << endl;
  cout << " [x] Currently calculating height of: ";
  cout << bst_test->height();
  cout << endl;
}


/*
 * Generate the CSV file for the project output here
 */
void genCSV() {
	cout << " [x] Generating CSV output file. " << endl;
	//cout << " [!!!] UNIMPLEMENTED - Need to generate the CSV file based on the tree height growth." << endl;

	/*  Sample of how to use the TestData structure for getting the test data sets
	int sorted = testing->get_next_sorted();
	while(sorted >= 0){
		bst_sorted->add( sorted );
		sorted = testing->get_next_sorted();
	}
	cout << "Sorted height: " << bst_sorted->height() << endl;
  */

    // make a file: OutputData-BST.csv
		// make 7 trees (sorted, balanced, scrambled[0..4])
		// fill trees with data from TestData
		//  -- as you fill, get the heights and output to CSV file: log_2 N, height sorted, height balanced, height scrambled[0..4]
    //  -- fill until the get_next_* functions return -1

	ofstream file_;
  file_.open("OutputData-BST.csv");
  file_<< "N,log_2(N),Sorted,Balanced,Scrambled #0,Scrambled #1,Scrambled #2,Scrambled #3,Scrambled #4" << endl;

  TestData *testing_sorted = new TestData();
  TestData *testing_balanced = new TestData();
  TestData *testing_scrambled_0 = new TestData();
  TestData *testing_scrambled_1 = new TestData();
  TestData *testing_scrambled_2 = new TestData();
  TestData *testing_scrambled_3 = new TestData();
  TestData *testing_scrambled_4 = new TestData();

  BST<int> *bst_sorted = new BST<int>;
  BST<int> *bst_balanced = new BST<int>;
  BST<int> *bst_scrambled_0 = new BST<int>;
  BST<int> *bst_scrambled_1 = new BST<int>;
  BST<int> *bst_scrambled_2 = new BST<int>;
  BST<int> *bst_scrambled_3 = new BST<int>;
  BST<int> *bst_scrambled_4 = new BST<int>;

	int sorted_counter = 0;
	int balanced_counter = 0;
  int scrambled_counter_0 = 0;
  int scrambled_counter_1 = 0;
  int scrambled_counter_2 = 0;
	int scrambled_counter_3 = 0;
	int scrambled_counter_4 = 0;

	int N = 0 , log;
	 while(N <= 32483){
/****************************Sorted**************************************/
	while(sorted_counter < N){
 		int sorted = testing_sorted->get_next_sorted();
	 	bst_sorted->add(sorted);
	 	sorted_counter++;
	}

 	if(N == 0)
		log = 0;
 	else
		log = log2(N);

 file_ << N << ","<< log << "," << bst_sorted->height() << ",";

/****************************Balanced**************************************/

 while(balanced_counter < N){
	 int balanced = testing_balanced->get_next_balanced();
	 bst_balanced->add(balanced);
	 balanced_counter++;
	}

 file_ << bst_balanced->height();


/****************************Scrambled#0**************************************/

 while(scrambled_counter_0 < N){
	 int scrambled_0 = testing_scrambled_0->get_next_scrambled(0);
	 bst_scrambled_0->add(scrambled_0);
	 scrambled_counter_0++;
	}

 file_<< "," << bst_scrambled_0->height();


/****************************Scrambled#1**************************************/
 while(scrambled_counter_1 < N){
	 int scrambled_1 = testing_scrambled_1->get_next_scrambled(1);
	 bst_scrambled_1->add(scrambled_1);
	 scrambled_counter_1++;
	}

 file_<< "," << bst_scrambled_1->height();

/****************************Scrambled#2**************************************/
 while(scrambled_counter_2 < N){
	 int scrambled_2 = testing_scrambled_2->get_next_scrambled(2);
	 bst_scrambled_2->add(scrambled_2);
	 scrambled_counter_2++;
	}

 file_<< "," << bst_scrambled_2->height();

/****************************Scrambled#3**************************************/
 while(scrambled_counter_3 < N){
	 int scrambled_3 = testing_scrambled_3->get_next_scrambled(3);
	 bst_scrambled_3->add(scrambled_3);
	 scrambled_counter_3++;
	}

 file_<< "," << bst_scrambled_3->height();


/****************************Scrambled#4**************************************/
 while(scrambled_counter_4 < N){
	 int scrambled_4 = testing_scrambled_4->get_next_scrambled(4);
	 bst_scrambled_4->add(scrambled_4);
	 scrambled_counter_4++;
	}

 file_<< "," << bst_scrambled_4->height() << endl;

 N++;}

	delete testing_sorted;
	delete bst_sorted;
	delete testing_balanced;
	delete bst_balanced;
	delete testing_scrambled_0;
	delete bst_scrambled_0;
	delete testing_scrambled_1;
	delete bst_scrambled_1;
	delete testing_scrambled_2;
	delete bst_scrambled_2;
	delete testing_scrambled_3;
	delete bst_scrambled_3;
	delete testing_scrambled_4;
	delete bst_scrambled_4;
	file_.close();
	std::cin.get();
}

/*
 *   Main function for execution
 */
int main( int argc, char* argv[] ) {
	if( argc > 1 && !strcmp(argv[1], "--test") )
	{
		cout << " [x] Program in test mode, doing simple tests. " << endl;
		runTests();  // testing should just do a simple tree insert set and search
	}
	else
	{
		cout << " [x] Program built and running in full CSV generation mode. " << endl;
		genCSV();
	}
	return 0;
}
