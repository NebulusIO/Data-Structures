/**
*Francis Troy Kirinhakone
CS223 - Summer 2017
HW5
**/

#ifndef TREES223_H
#define TREES223_H

struct Node{
  Node* leftChild;
  Node* rightChild;
  <T> data;
}

//<template>class BST
template<class T>
class BST
{
    public:
        BST(){
          //implement!
        }

        virtual ~BST(){
          //implement!
        }

        virtual bool Add(const T& value, std::function<int(const T& first, const T& second)> compare){
          //duplicate values not allowed in tree, return false if value already exists
          //if not duplicate add to BST and return true

          //compare function that is 2nd paramater
          //returns 0 if(first == second)
          //returns >0 if(first > second)
          //returns <0 if(first < second)

          

        }

        int count() const{

        }

        int CountLevels() const;

        int GetLevel(std::function<int(const T& existing)> compare) const;

        void InOrder(std::function<void(const T& value)> visitCallBack) const;

        virtual bool Remove(std::function<int(const T&existing>compare);


    private:

    protected:

}

#endif //TREES223_H
