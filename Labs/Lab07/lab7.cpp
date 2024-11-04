#undef debug

#include <iostream>
#include <string>
#include <list> // for listify
#include<map>

using namespace std;


template<typename T>
class BSTNode {

public:
  // Constructors, etc.
  BSTNode() : _data(0), _left(nullptr), _right(nullptr) {} // default constructor
  BSTNode(T data) : _data(data), _left(nullptr), _right(nullptr) {} // value constructor
  BSTNode(const BSTNode& other); // copy constructor
  ~BSTNode(); // destructor
  BSTNode& operator= (const BSTNode& other); // copy assignment operator

  // ***** Your group will define/implement the insert function
  // ***** at about line 89 below...
  void insert(const T& data);

  // Accessor and mutator functions
  BSTNode<T>* getLeft() const { return _left; }
  BSTNode<T>* getRight() const { return _right; }
  T& getData() const { return _data; }
  void setData(const T& data) { _data = data; }

  // Display functions used by operator<<.
  // ***** Your group will define/implement the pre & post display functions
  // ***** at about lines 114 & 127 below...
  void inOrderDisplay(ostream&) const;
  void preOrderDisplay(ostream&) const;
  void postOrderDisplay(ostream&) const;

  // The insertion operator below uses in-order display.
  // ***** Change the implementation of this insertion operator
  // ***** in order to switch to pre- or post-order display
  friend ostream& operator<< (ostream& out, const BSTNode<T>& b)
    { b.postOrderDisplay(out); return out; }

  // Listify
  void listify(list<T>& list_ref) const;

private:
  T _data;
  BSTNode<T>* _left;
  BSTNode<T>* _right;

  // private "helper" functions
  void addLeft(const T& data) { _left = new BSTNode(data); }
  void addRight(const T& data) { _right = new BSTNode(data); }
};


template<typename T>
BSTNode<T>::BSTNode(const BSTNode& other) {
#ifdef debug
  cout << "BSTNode copy constructor called, _data == " << _data << endl;
#endif
  _data = other._data;
  _left = _right = nullptr;
  if (other._left != nullptr) _left = new BSTNode<T>(*other._left);
  if (other._right != nullptr) _right = new BSTNode<T>(*other._right);
}


template<typename T>
BSTNode<T>::~BSTNode() {
#ifdef debug
  cout << "BSTNode destructor called, _data == " << _data << endl;
#endif
    delete _left;
  delete _right;
}


template<typename T>
BSTNode<T>& BSTNode<T>::operator=(const BSTNode& other) {
#ifdef debug
  cout << "BSTNode copy assignment operator: ";
#endif
  _data = other._data;
  _left = _right = nullptr;
  if (other._left != nullptr) _left = new BSTNode<T>(*other._left);
    if (other._right != nullptr) _right = new BSTNode<T>(*other._right);
  return *this;
}


template<typename T>
void BSTNode<T>::insert(const T& data) {
  // comment out the next line when you've completed this function!
  //cout << "BSTNode<T>::insert called with data == " << data << endl;
  if(_data == T()){ // if data has default value
    _data = data;
  } else{

    if(data < _data){ // insert left
      if(_left != nullptr){ // if left exists
        _left->insert(data); // handle recursively
      } else{ // if left doesn't exist
        _left = new BSTNode<T>(data); // define left as new BST with data as its root
      }
    } else{
      if(_right != nullptr){ // if left exists
        _right->insert(data); // handle recursively
      } else{ // if left doesn't exist
        _right = new BSTNode<T>(data); // define left as new BST with data as its root
      }
    }

  }

}


template<typename T>
void BSTNode<T>::inOrderDisplay(ostream& out) const {
  if (_left != nullptr) {
      _left->inOrderDisplay(out);
      out << ", ";
  }
  out << _data;
  if (_right != nullptr) {
      out << ", ";
      _right->inOrderDisplay(out);
  }
}

template<typename T>
void BSTNode<T>::listify(list<T>& list_ref) const {
  if (_left != nullptr) {
    _left->listify(list_ref);
  }
  list_ref.push_back(_data);
  if (_right != nullptr) {
    _right->listify(list_ref);
  }
}

/**
 *  ***** Complete preOrderDisplay and postOrderDisplay below *****
 */
template<typename T>
void BSTNode<T>::preOrderDisplay(ostream& out) const {
  // comment out the next line when you've completed this function!
  //cout << "BSTNode<T>::preOrderDisplay called\n";
  out << _data;
  if (_left != nullptr) {
    out << ", ";
      _left->preOrderDisplay(out);
  }
  if (_right != nullptr) {
    out << ", ";
      _right->preOrderDisplay(out);
  }
}

template<typename T>
void BSTNode<T>::postOrderDisplay(ostream& out) const {
  // comment out the next line when you've completed this function!
  //cout << "BSTNode<T>::postOrderDisplay called\n";
  if (_left != nullptr) {
      _left->postOrderDisplay(out);
      out << ", ";
  }
  if (_right != nullptr) {
      _right->postOrderDisplay(out);
      out << ", ";
  }
  out << _data;
}


int main(void) {
  BSTNode<int> iroot(100);
  iroot.insert(10);
  iroot.insert(20);
  iroot.insert(200);
  iroot.insert(300);
  cout << "iroot == " << iroot << endl;

  BSTNode<string> sroot("Sunday");
  sroot.insert("Monday");
  sroot.insert("Tuesday");
  sroot.insert("Wednesday");
  sroot.insert("Thursday");
  sroot.insert("Friday");
  sroot.insert("Saturday");
  cout << "sroot == " << sroot << endl;

  BSTNode<int> iroot4(1000);
  iroot4.insert(2000);
  iroot4.insert(3000);
  iroot4.insert(4000);
  iroot4.insert(5000);

  list<int> irootList;
  iroot.listify(irootList);

  list<string> srootList;
  sroot.listify(srootList);
  
  list<int> iroot4List;
  iroot4.listify(iroot4List);

  cout<< "iroot List : "<< endl;
  for(auto it = irootList.begin();it != irootList.end();++it)
    {
      cout<<*it<<endl;
    }
  cout<<"iroot List Reverse : "<<endl;
  for(auto rit = irootList.rbegin();rit != irootList.rend();++rit)
    {
      cout<<*rit<<endl;
    }
  cout<<"iroot List using ranged for loop : "<<endl;
  for(auto number :  irootList)
    {
      cout<<number<< " "<<endl;
    }


  cout<<"sroot using forward iterator : "<<endl;
  for(auto it = srootList.begin();it != srootList.end();++it)
    {
      cout<<*it<<endl;
    }
  cout<<"sroot using reverse iterator : "<<endl;
  for(auto rit = srootList.rbegin();rit != srootList.rend();++rit)
    {
      cout<<*rit<<endl;
    }
  cout<<"sroot using ranged for loop : "<<endl;
  for(auto str : srootList)
    {
      cout<<str <<" "<<endl;
    }

  
  cout<<"iroot4 List : "<<endl;
  for(list<int> ::iterator it = iroot4List.begin();it != iroot4List.end();++it)
    {
      cout<<*it<<endl;
    }
  map<string, list<int>> mi;
  mi.insert({"irootList", irootList});
  mi.insert({"iroot4List", iroot4List});


  cout << "Contents of map<string, list<int>> mi (using ranged for loops): " << endl;

  for (auto str : mi) {
    const string& key = str.first;
    const list<int>& values = str.second;
    cout << key << ": ";
    for (const int& value : values) {
        cout << value << " ";
    }
    cout << endl;
}

  cout << "Using map index operator: " << endl;

  for(auto it = mi.begin(); it != mi.end(); it++){
      const string& key = it->first;
      cout << "mi['" << key << "'] == '";
      for(int value : mi[key]){
          cout << value << " ";
      } 
      cout << endl;
  }

  

#ifdef debug	
  BSTNode<int> iroot2(iroot); // use copy constructor
  cout << "\nAfter copy constructor:\n";
  cout << "iroot2 == " << iroot2 << endl;

  BSTNode<int> iroot3;
  iroot3 = iroot2; // use copy assignment operator
  cout << "\nAfter copy assignment operator:\n";
  cout << "iroot3 == " << iroot3 << endl << endl;

  
#endif

  return 0;
}
