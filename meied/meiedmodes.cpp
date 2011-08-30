//
//  meiedmodes.cpp
//  meied
//
//  Created by Alastair Porter on 8/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include "meiedmodes.h"

using std::cout;
using std::endl;

MeiEditorMode::MeiEditorMode(string modeName, string usage, string description) {
    this->modeName = modeName;
    this->usage = usage;
    this->description = description;
}

string MeiEditorMode::getModeName() {
    return modeName;
}

string MeiEditorMode::getUsage() {
    return usage;
}

string MeiEditorMode::getDescription() {
    return description;
}

list<MeiEditorMode*> MeiEditorMode::getModes() {
    return validModes;
}

list<MeiEditorCommand*> MeiEditorMode::getCommands() {
    return validCommands;
}

MeiEditorMode *MeiEditorMode::findMode(string modeName) {
    for (list<MeiEditorMode*>::iterator i = validModes.begin();
         i != validModes.end();
         i++) {
        if ((*i)->getModeName() == modeName) {
            return *i;
        }
    }
    return NULL;
}

MeiEditorCommand *MeiEditorMode::findCommand(string commandName) {
    for (list<MeiEditorCommand*>::iterator i = validCommands.begin();
         i != validCommands.end();
         i++) {
        if ((*i)->getCommandName() == commandName) {
            return *i;
        }
    }
    return NULL;
}

MeiEditorNewMode::MeiEditorNewMode() :
    MeiEditorMode("new", "", "create a new document")
{
}

void MeiEditorNewMode::enterMode(MeiElement *element) {
    
}

void MeiEditorNewMode::printState() {
    cout << "new mode" << endl;
}

MeiEditorOpenMode::MeiEditorOpenMode() :
    MeiEditorMode("open", "filename", "open a document")
{
}

void MeiEditorOpenMode::enterMode(MeiElement *element) {
    
}

void MeiEditorOpenMode::printState() {
    cout << "open mode" << endl;
}

MeiEditorHeaderMode::MeiEditorHeaderMode() :
    MeiEditorMode("header", "", "edit the document header")
{
}

void MeiEditorHeaderMode::enterMode(MeiElement *element) {
    
}

void MeiEditorHeaderMode::printState() {
    cout << "header mode" << endl;
}