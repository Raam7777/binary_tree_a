#include <ostream>

using namespace std;
namespace ariel{
    template <typename T> class BinaryTree{
        
        private:
        class Node{
            public:
            T value;
            Node* right;
            Node* left;
            Node(const T& v, Node* r , Node* l): value(v), right(r), left(l){}
        };
        
        Node* root;

        public:
        
        BinaryTree& add_root(const T& new_root){return *this;}
        BinaryTree& add_left(const T& exist_in_tree, const T& add_new_left_child){return *this;}
        BinaryTree& add_right(const T& exist_in_tree, const T& add_new_right_child){return *this;}


        friend ostream& operator<<(ostream& out, BinaryTree const& b){
            return out;
        }


        class iterator{

            private:
            Node* n_node;
            
            public:

            iterator(Node* pointer = nullptr): n_node(pointer){}
            
            iterator& operator++() {
                return *this;
            }

            iterator operator++(int) {
                iterator tmp= *this;
                return tmp;
            }

            T* operator->() const {
                return &(n_node->value);
            }

            T& operator*() const {
			    return n_node-> value;
		    }            

            bool operator==(const iterator& it) const {
                return n_node == it.n_node;
            }

            bool operator!=(const iterator& it) const {
                return n_node != it.n_node;
            }
        
        };

        iterator begin_preorder() {
		    return iterator{root};
	    }
        iterator end_preorder() {
		    return iterator{root};
	    }
        iterator begin_inorder(){
            return iterator{root};
        }
        iterator end_inorder(){
            return iterator{root};
        }
        iterator begin_postorder(){
            return iterator{root};
        }
        iterator end_postorder(){
            return iterator{root};
        }

        iterator begin(){ return iterator{root};}
        iterator end() {return iterator{root};}
    };
    
}