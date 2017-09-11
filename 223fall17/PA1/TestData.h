/*
 * TestData.h - Library of testing data for the BST project
 *  Copyright 2017 - Aaron S. Crandall (acrandal@wsu.edu)
 *
 * This class implements a way to query for test data
 *  to test Binary search trees (and other trees)
 *
 */

#ifndef _TESTDATA_H
#define _TESTDATA_H

//#define MAXVALS 50
#define MAXVALS 32767   // 2^15 - 1
#define RANDSETS 10
#define MAXMINITEST 8

#include "balancedArray.h"
#include <iostream>
#include <array>
#include <algorithm>   // std::random_shuffle
#include <ctime>       // std::time
#include <cstdlib>     // std::rand, std::srand


class TestData {
	private:
		int _next_sorted_val = 0;

		int _next_balanced_val = 0;
		int _next_scrambled_vals[RANDSETS];
		array< array<int, MAXVALS>, RANDSETS> _scrambled_data;

		int _next_minitest_val = 0;

		/***************************************************************/
		void _build_scrambled_datasets() {
			cout << "  [x] Building scrambled datasets. " << endl;

			for( int set = 0; set < RANDSETS; set++ ) {			// Initialize counters for output
				_next_scrambled_vals[set] = 0;
			}

			for(int i = 0; i < MAXVALS; i++) {							// Fill sets with ordered data
				for( int set = 0; set < RANDSETS; set++ ) {
					_scrambled_data[set][i] = i;
				}
			}

			srand ( unsigned ( std::time(0) ) );						// Initialize the random seed
			for( int set = 0; set < RANDSETS; set++ ) {			// Scramble each set differently
				random_shuffle( _scrambled_data[set].begin(), _scrambled_data[set].end() );
			}
		}



	public:
		TestData()
		{
			cout << " [x] Initializing TestData." << endl;
			_build_scrambled_datasets();
		}

		/***************************************************************/
		int get_next_minitest() {
			int minivals[MAXMINITEST] = {10, 5, 1, 7, 14, 17, 19, 18};
			if( _next_minitest_val < MAXMINITEST ){
      	return( minivals[ _next_minitest_val++ ] );
			}else{
				return( -1 );
			}
		}


		/***************************************************************/
		int get_next_sorted() {
			if(_next_sorted_val < MAXVALS)
				{ return(_next_sorted_val++); }
			else
				{ return(-1); }
		}


		/***************************************************************/
		int get_next_balanced() {
			if(_next_balanced_val < MAXVALS)
			{ 
				return( balancedArray[ _next_balanced_val++ ] );  // balancedArray defined in balancedArray.[cpp,h]
			}
			else
			{
				return(-1);
			}
		}


		/***************************************************************/
		int get_next_scrambled( int setNum ) {
			int curr_val = _next_scrambled_vals[setNum];
			if( curr_val < MAXVALS ) {
				_next_scrambled_vals[setNum]++;               // Track next data to get
				return( _scrambled_data[setNum][curr_val] ); // Grab current data and return
			}else{
				return( -1 );		// Done with this data set
			}
		}
};



#endif
