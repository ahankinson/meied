//
//  meiedcommands.h
//  meied
//
//  Created by Alastair Porter on 8/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef MEIED_MEIEDCOMMANDS_H
#define MEIED_MEIEDCOMMANDS_H

#include <string>
#include <list>

#include <mei/mei.h>
#include <mei/meielement.h>

using std::string;
using std::list;

using mei::MeiElement;

/**
 * A single editor command. Acts on an element with 0 or more elements.
 */
class MeiEditorCommand {
public:
    MeiEditorCommand(string name, string usage, string desc);
    virtual void performCommand(MeiElement *element, list<string> args) = 0;
    
    string getCommandName();
    string getCommandDesc();
    string getUsageString();
    string getFormattedDesc();
    
private:
    string commandName;
    string commandDesc;
    string usageString;
};

class ChangeTitleCommand : public MeiEditorCommand {
public:
    ChangeTitleCommand();
    void performCommand(MeiElement *element, list<string> args);
};

class ChangeComposerCommand : public MeiEditorCommand {
public:
    ChangeComposerCommand();
    void performCommand(MeiElement *element, list<string> args);
};

class AddNoteCommand : public MeiEditorCommand {
public:
    AddNoteCommand();
    void performCommand(MeiElement *element, list<string> args);
};

class NoteAccidCommand : public MeiEditorCommand {
public:
    NoteAccidCommand();
    void performCommand(MeiElement *element, list<string> args);
};

class NoteArticCommand : public MeiEditorCommand {
public:
    NoteArticCommand();
    void performCommand(MeiElement *element, list<string> args);
};

class NotePitchCommand : public MeiEditorCommand {
public:
    NotePitchCommand();
    void performCommand(MeiElement *element, list<string> args);
};

class DeleteMeiElement : public MeiEditorCommand {
public:
    DeleteMeiElement();
    
    void performCommand(MeiElement *element, list<string> args);
    
};
#endif // MEIED_MEIEDCOMMANDS_H
