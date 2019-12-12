#include <iostream>
#include <memory>
#include <vector>

/* * Exo 1 :
{
  T a; // a is constructed
  f1(a); // a is passed by reference, no copy happens
  f2(a); // the argument of f2 is constructed by copy; it is destructed
when f2 returns
  T b = a; // b is constructed by copy
  T c = f3(); // f3 constructs c (all the copies are elided by RVO)
  T d = f4(); // f4 constructs d (all the copies are elided by NRVO)
  f5(d); // f5 constructs a temporary value, copies it into d, then
destructs it
  U e(a); // e.v1 is constructed, e.v2 is constructed by copy
  // e.v2, e.v1, d, c, b, a are destructed
} */

//* Exo 2 et 3 :
struct file {
  FILE *c_file; // opened by the constructor, set to null if moved to
                // another object, closed by the destructor if non-null
  file(char const *f): c_file(fopen(f, "w")) {}
  ~file() { if (c_file) fclose(c_file); }
  file(file const &) = delete;
  file &operator=(file &&f) = delete;
  file(file &&f): c_file(f.c_file) { f.c_file = nullptr; }
  void write(std::string const &s) { fwrite(s.c_str(), 1, s.size(),
c_file); }
};

int main() {
  file f("bli.txt");
  f.write("toto\n");
  // file g = f; // construction by copy is forbidden, only move is allowed
  file g = std::move(f);
  g.write("titi\n");
  // f.write("tutu\n"); // uncomment to crash, as a moved object should
    //no longer be accessed
}

/* * Exo 4, 5 et 6 :

- Si children ne contenait pas des pointeurs, un noeud ne pourrait avoir
plus d'un parent. On serait alors limité à des arborescences (arbre
orienté ayant une racine). */

class node;
typedef std::shared_ptr<node> node_ptr;

class node : public std::enable_shared_from_this<node> {
  std::string name;
  std::vector<std::weak_ptr<node>> parents;
  std::vector<node_ptr> children;
public:

  void add_child(node_ptr n) {
    children.push_back(n);
    n->parents.push_back(shared_from_this());
  }

  std::vector<node_ptr> get_parents() const {
    std::vector<node_ptr> p;
    for (const auto& n: parents) {
      node_ptr m = n.lock();
      if (m) p.push_back(m);
    }
    return p;
  }

  node(std::string const &n): name(n) {}
  ~node() { std::cout << "Destructed " << name << '\n'; }
};

int main() {
  node_ptr a(new node("a"));
  node_ptr b(new node("b"));
  node_ptr c(new node("c"));
  node_ptr d(new node("d"));
  a->add_child(b);
  a->add_child(c);
  d->add_child(b);
  a.reset();
  std::vector<node_ptr> parents = b->get_parents();
  std::cout << "Number of parents: " << parents.size() << '\n';
}