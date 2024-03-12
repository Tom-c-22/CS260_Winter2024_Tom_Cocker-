#pragma once

#include <string>

#include "node.h"

using std::string;

class Arbitrary_list {
    private:
        //some way to know where the front of the list is (for add, remove, get, and maybe more...?)
        Node *front = nullptr;
        int size = 0;

    public:
        Arbitrary_list();
        int get_size();
        void add(int new_value, int new_position);
        int remove(int old_position);
        int get(int position);
        string to_string();
};