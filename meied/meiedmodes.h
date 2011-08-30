//
//  meiedmodes.h
//  meied
//
//  Created by Alastair Porter on 8/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef MEIED_MEIEDMODES_H
#define MEIED_MEIEDMODES_H

#include <string>
#include <list>

#include <mei/mei.h>

#include "meiedcommands.h"

using std::string;

/**
 * A mode in the editor. For example, the mode for editing a header, or doing something to a note.
 * An editor mode has a number of commands that are valid for this mode.
 */
class MeiEditorMode {
public:
    MeiEditorMode(string command, string usage, string description);
    
    // Activate this mode with the given element. Note that the element
    // passed in is the current element of the previous mode.
    virtual void enterMode(MeiElement *element) = 0;
    
    // override to print out the state of the current mode (needs to be entered)
    virtual void printState() = 0;
    // get the name of this command
    string getModeName();
    string getUsage();
    string getDescription();
    
    list<MeiEditorMode*> getModes();
    list<MeiEditorCommand*> getCommands();
    
    MeiEditorMode *findMode(string modeName);
    MeiEditorCommand *findCommand(string commandName);
private:
    MeiElement *currentElement;
    string modeName;
    string usage;
    string description;
    list<MeiEditorCommand*> validCommands;
    list<MeiEditorMode*> validModes;
};

class MeiEditorNewMode : public MeiEditorMode {
public:
    MeiEditorNewMode();
    void enterMode(MeiElement *element);
    void printState();
private:
};

class MeiEditorOpenMode : public MeiEditorMode {
public:
    MeiEditorOpenMode();
    void enterMode(MeiElement *element);
    void printState();
private: 
};

class MeiEditorHeaderMode : public MeiEditorMode {
public:
    MeiEditorHeaderMode();
    void enterMode(MeiElement *element);
    void printState();
private:
    
};

#endif // MEIED_MEIEDMODES_H
