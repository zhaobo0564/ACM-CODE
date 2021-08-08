#include <iostream>
#include <memory>
 
class Node {
  int value;
 public:
  std::shared_ptr<Node> leftPtr;
  std::shared_ptr<Node> rightPtr;
  std::shared_ptr<Node> parentPtr;
  Node(int val) : value(val) {
    std::cout << "Constructor" << std::endl;
  }
  ~Node() {
    std::cout << "Destructor" << std::endl;
  }
};
 
int main() {
  
    std::shared_ptr<Node> ptr = std::make_shared<Node>(4);
    ptr->leftPtr = std::make_shared<Node>(2);
  //  ptr->leftPtr->parentPtr = ptr;
    ptr->rightPtr = std::make_shared<Node>(5);
   // ptr->rightPtr->parentPtr = ptr;
    std::cout << "ptr reference count = " << ptr.use_count() << std::endl;
    std::cout << "ptr->leftPtr reference count = " << ptr->leftPtr.use_count() << std::endl;
    std::cout << "ptr->rightPtr reference count = " << ptr->rightPtr.use_count() << std::endl;
  
  return 0;
}
