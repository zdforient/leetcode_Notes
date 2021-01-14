//1. how to create a priority_queue
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{   
    vector<int> vec{1,2,3,4,2,4,57,3,4,};
    std::priority_queue<int> foo,bar;
    foo.push (15); foo.push(30); foo.push(10);
    bar.push (101); bar.push(202);

    swap(foo,bar);
    
    cout<<"foo's top: "<<foo.top()<<endl;
    foo.pop();
    cout<<"foo's top: "<<foo.top()<<endl;
    foo.pop();
    cout<<"foo's size:"<<foo.size() <<"\nfoo's empty:"<<foo.empty()<<endl;
    foo.emplace(4444.44);
    cout<<"foo's top: "<< foo.top()<<endl;
    std::cout << "size of foo: " << foo.size() << '\n';
    std::cout << "size of bar: " << bar.size() << '\n';
    cout<<"Hello World";

    return 0;
}

//2. how to delete an element in priority_queue and time complexity
//here we learn how to inherit from a customized data type and define functions
/*
Member objects
Container c: the underlying container (protected member object)
Compare comp: the comparison function object (protected member object)
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm> 
using namespace std;

template<typename T>
class custom_priority_queue : public std::priority_queue<T, std::vector<T>>
{
  public:

      bool remove(const T& value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
       }
       else {
        return false;
       }
 }
};

int main()
{
   custom_priority_queue<int> queue;

   queue.push(10);
   queue.push(2);
   queue.push(4);
   queue.push(6);
   queue.push(3);

   queue.remove(6);

   while (!queue.empty())
   {
      std::cout << queue.top();
      queue.pop();

      if (!queue.empty())
      {
        std::cout << ", ";
      }
   }
    return 0;
 }
