
#ifndef TREE_h
#define TREE_h

#include <vector>
#include <string>
#include <ostream>

class Branch
{
public:
    Branch(float length, float radius);
    float branch_volume();
private:
    float length;
    float radius;
};


class Tree 
{
public:
    Tree(std::string name);
    float volume()const;
    void print(std::ostream &os)const;
    void add_branch(Branch new_branch);

private:
    std::string name;
    std::vector<Branch> branches;
};






#endif