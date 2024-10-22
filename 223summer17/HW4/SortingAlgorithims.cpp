#include "SortingAlgorithims.hpp"


SortAlg::SortAlg()
{
  //constructor
}

SortAlg::~SortAlg()
{
  //destructor
}

SortAlg::SortAlg(SortAlg &copy)
{
  //copy constructor
}

void SortAlg::Set(string inc_val_n_loc){
    string temp_string = inc_val_n_loc;

    int new_start = 0;
    int end_loc = 0;
    int num_of_items = 0;

    for(int j = 0; j < (signed)temp_string.size(); j++) //walk through string to find ; indicating number of items to create
    {
        if (temp_string[j] == ';') {num_of_items++;}
    }
    num_of_items++;//to account for last element not ending with ';'


     vector<Item> working_vector(num_of_items);//vector of size 1, will add dynamically

    for(int i = 0; i < num_of_items;i++)
    {
        end_loc = temp_string.find(";");
        new_start = end_loc;
        new_start++;
        working_vector[i].segment = temp_string.substr(0, end_loc);

        temp_string = temp_string.substr(new_start);// remove segment from temp_string

        working_vector[i].value = stoi(working_vector[i].segment.substr(0,working_vector[i].segment.find(","))); //value from segment to working value
        int index_start = working_vector[i].segment.find(",");
        index_start++;
        working_vector[i].index = stoi(working_vector[i].segment.substr(index_start)); //index from segment to working index
    }

    m_string = working_vector;


}//end set

void SortAlg::insertion(){
    vector<Item> work_vec = this->m_string;//copy m_string to work_vec

    int p = 0;//first iterator for passes
    int j = 0;//second iterator for going back

    int array_size = work_vec.size(); //number of items in work_vec

    for(p = 1; p < array_size; ++p) //pass for number of items
    {
        Item temp = std::move(work_vec[p]); //store value at p to temp

        ///
        //cout << temp.value << "," << temp.index << ";";
        ///

        for(j = p; j > 0 && temp.value < work_vec[j - 1].value; --j) //set j to p ; loop j until it checks all items going back & while current item is less than the prev item
        {
            work_vec[j] = std::move(work_vec[j-1]); //bring prev item forward 1
        }
         work_vec[j] = std::move(temp); //bring current item back 1
    }

    ///print final insertion
           for(int i = 0; (unsigned)i < work_vec.size(); i++)
            cout << work_vec[i].value << "," << work_vec[i].index << ";";
            cout << endl;
    //
}//end insertion

void SortAlg::shell(int gap1, int gap2, int gap3){
    vector<Item> v = m_string;

    //sort by gap
    //use modified insertion sort
    int p, j;

    ///rewrite
  if(gap1 > 0){

    for(p = gap1; p < v.size(); p++){
      Item temp = move(v[p]);//pull out Item to be compared against
      for(j = p; j >= gap1 && temp.value < v[j-gap1].value; j-=gap1)
        v[j] = move(v[j-gap1]);

      v[j] = move(temp);
    }
  }//end gap1 if

  if(gap2 > 0){

    for(p = gap2; p < v.size();p++){
      Item temp = move(v[p]);
      for(j = p; j >= gap2 && temp.value < v[j-gap2].value; j-=gap2)
        v[j] = move(v[j-gap2]);

      v[j] = move(temp);
    }
  }//end gap2 if

    //}

  if(gap3 > 0){

    for(p = gap3; p < v.size(); p++){
      Item temp = move(v[p]);
      for(j = p; j >= gap3 && temp.value < v[j-gap3].value; j-=gap3)
        v[j] = move(v[j-gap3]);

      v[j] = move(temp);
    }

  }//end gap3 if

    ///print final shell
           for(int i = 0; (unsigned)i < v.size(); i++)
            cout << v[i].value << "," << v[i].index << ";";
            cout << endl;
    //

}//end shell

void SortAlg::merge_sort() {

    vector<Item> tempArr1 = this->m_string;
    vector<Item> tempArr2(tempArr1.size());

    merge_sort(tempArr1, tempArr2, 0, tempArr1.size()-1);

    ///print final merge
           for(int i = 0; (unsigned)i < tempArr1.size(); i++)
            cout << tempArr1[i].value << "," << tempArr1[i].index << ";";
            cout << endl;
    //
}//end merge_sort

void SortAlg::merge_sort(vector<Item> & arr1, vector<Item> & arr2, int left, int right){
    if(left < right){
        int center = (left + right) / 2;
        merge_sort(arr1, arr2, left, center);//merge sort left subtree
        merge_sort(arr1, arr2, center+1, right);//merge_sort right subtree
        merge_(arr1,arr2,left,center+1,right); //merges two subarrays together
    }

}

void SortAlg::merge_(vector<Item> & arr1, vector<Item> & arr2, int leftPos, int rightPos, int rightEnd){
    int leftEnd = rightPos -1;
    int tempPos = leftPos;
    int numElements = rightEnd - leftPos +1;

    while(leftPos <= leftEnd && rightPos <= rightEnd){
        if(arr1[leftPos].value <= arr1[rightPos].value){ ///move whichever position is less than
            arr2[tempPos++] = move(arr1[leftPos++]);
        }
        else{
        arr2[tempPos++] = move(arr1[rightPos++]);
        }
    }

    while(leftPos <= leftEnd){ ///exhausted right subarray so add the rest of left array
        arr2[tempPos++] = move(arr1[leftPos++]);
    }

    while(rightPos <= rightEnd){ ///exhausted left subarray so add the rest of right array
        arr2[tempPos++] = move(arr1[rightPos++]);
    }

    for(int i = 0; i < numElements; i++ , --rightEnd){
        arr1[rightEnd] = move(arr2[rightEnd]);
    }
}

void SortAlg::partition_(int pivot){
  std::vector<Item> v = this->m_string;//copy m_string to v

  int left = 0;
  int right = v.size() - 1;
  int end = right;//since right will be iterated
  Item temp;
  //int pivot declared in prototype

  //swap pivot and last element
  std::swap(v[pivot],v[end]);
  right--;//move right iterator inward to look at first elemet to start swapping
  //

  //swapping inward iteratively
  while(left != right){
    while(v[left].value < v[end].value){
      left++;//iterate left inward if value is already less than pivot value
    }
    while(v[right].value > v[end].value){
      right--;
    }
    if(left < right){
      std::swap(v[left], v[right]);
    }
    else
      break;
  }
  //

  //swap pivot back to correct position
  std::swap(v[left],v[end]);
  //###

  //prints partition_
  for(int i = 0; (unsigned)i < v.size(); i++)
   cout << v[i].value << "," << v[i].index << ";";
   cout << endl << endl;


}

int SortAlg::partition_(std::vector<Item> & v, int left, int right, int pivot){
  int end = right;

  //swap pivot and last element
  std::swap(v[pivot],v[end]);
  right--;//move right iterator inward to look at first elemet to start swapping
  //

  //swapping inward iteratively
  while(left != right){
    while(v[left].value < v[end].value){
      left++;//iterate left inward if value is already less than pivot value
    }
    while(v[right].value > v[end].value){
      right--;
    }
    if(left < right){
      std::swap(v[left], v[right]);
    }
    else
      break;
  }
  //

  //swap pivot back to correct position
  std::swap(v[left],v[end]);
  //###

  return left;


/*
  while(left <= right){
    while(v[left].value < v[pivot].value){//move left ptr until a value needs to be swapped
        left++;
    }

    while(v[right].value > v[pivot].value){//move rightPtr left until found value needs to be swapped
        right--;
    }

    if(left <= right){
        //std::swap(v, left, right)
        Item temp = move(v[left]);
        v[left] = move(v[right]);
        v[right] = move(temp);
        left++;
        right--;
    }
  }//end while
  return left; //returns the pivot index of recursive call
  */
}//end partition_

void SortAlg::quick_sort(){ //driving function w/ copy string & print functionality
  std::vector<Item> v = this->m_string; //copy over string to leave original m_string alone

  quick_sort(v, 0, v.size() - 1);

  ///print final quick_sort
         for(int i = 0; (unsigned)i < v.size(); i++)
          cout << v[i].value << "," << v[i].index << ";";
          cout << endl;
  //

}//end quick_sort -- driver

void SortAlg::quick_sort(std::vector<Item> & v, int left, int right){ //begin recursive function
  if(left >= right) //base case for recursive function
    return;

    int pivot;

    //median of 0, n-1, n/2
    if(v[0].value < v[v.size()-1].value && v[0].value < v[v.size()/2].value)
      pivot = 0;
    else if (v[v.size()-1].value < v[0].value && v[v.size()-1].value < v[v.size()/2].value)
      pivot = v.size()-1;
    else if(v[v.size()/2].value < v[0].value && v[v.size()/2].value < v[v.size()-1].value)
      pivot = v.size()/2;


  int index = partition_(v, left, right, pivot);
  quick_sort(v, left, index - 1);//quick_sort left_subarray
  quick_sort(v, index, right);//quick_sort right_subarray

}//end quick_sort -- recursive part
