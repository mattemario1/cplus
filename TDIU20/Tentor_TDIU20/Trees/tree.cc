
using namespace std;

#include "tree.h"

Branch::Branch(float length, float radius) : length{length}, radius{radius}
{}

Tree::Tree(std::string name) : name{name}
{}

float Branch::branch_volume()
{
    return 3.14*length*radius*radius;
}

float Tree::volume()const
{
    float total_volume{0};
    for(auto branch : branches)
    {
        total_volume += branch.branch_volume();
    }
    return total_volume;
}


void Tree::add_branch(Branch new_branch)
{
    branches.push_back(new_branch);
}


void Tree::print(std::ostream &os)const
{
    os << "Trädet har " << branches.size() << " grenar och är av arten " << name << endl;
}