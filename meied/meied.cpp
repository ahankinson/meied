//
//  meied.cpp
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

#include <mei/mei.h>
#include <mei/shared.h>
#include <mei/meiDocument.h>

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

using mei::MeiDocument;
using mei::Mei;

void MeiEditor::NewDocument() {
    this->document = new MeiDocument("");
    this->currentElement = new Mei();
    document->setRootElement(this->currentElement);
}

void MeiEditor::OpenDocument(std::string docname) {
//    this->document = MeiXmlInputStream::ReadFromXml(docname, "UTF-8");
//    this->currentElement = document->getRootElement();
}

void MeiEditor::Save() {
    if (this->document->getDocName() == "") {
        throw "Cannot save without a name; use save as";
    }
//    MeiXmlOutputStream output;
//    output.WriteToXml(this->document);
}

void MeiEditor::SaveAs(std::string docname) {
    this->document->setDocName(docname);
    Save();
}

void MeiEditor::help() {
    
}

bool MeiEditor::readInput() {
    cout << "Mei Editor " << MEIED_VERSION << endl;
    cout << "command? ('help' for help)" << endl;
    string input = "";
    getline(cin, input);
    istringstream iss(input);
    list<string> tokens;
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter<list<string> >(tokens));
    
    if (tokens.size() > 0) {
        string command = tokens.front();
        tokens.pop_front();
        if (command == "help") {
            help();
        }
        
        
        return true;
    }
    return false;
}

// Go to a new mode
void MeiEditor::pushMode(MeiEditorMode *mode) {
    
}

// Perform a command with the current element
void MeiEditor::performCommand(MeiEditorCommand *command) {
    
}