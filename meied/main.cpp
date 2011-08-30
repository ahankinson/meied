//
//  main.cpp
//  meied
//
//  Created by Alastair Porter on 8/11/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>

#include <mei/meielement.h>

#include "meied.h"


using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::istringstream;
using std::vector;
using std::copy;
using std::istream_iterator;
using std::list;
using std::back_inserter;

MeiEditor *editor;

void command_new(list<string>);
void command_open(list<string>);

void command_new(list<string> params) {
    editor->NewDocument();
}

void command_open(list<string> params) {
    if (params.size() == 0) {
        cerr << "Open requires a filename" << endl;
    }
    editor->OpenDocument(params.front());
}

int main (int argc, const char * argv[])
{
    editor = new MeiEditor();
    std::cout << "Mei Editor " << MEIED_VERSION << std::endl;
    std::cout << "command? ('help' for help)" << std::endl;
    while(true) {
        bool x = editor->readInput();
        if (!x) {
            break;
        }
    }
    return 0;
}

