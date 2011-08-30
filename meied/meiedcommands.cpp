//
//  meiedcommands.cpp
//  meied
//
//  Created by Alastair Porter on 8/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <string>
#include <list>

#include "meiedcommands.h"

using std::string;
using std::list;

MeiEditorCommand::MeiEditorCommand(string name, string usage, string desc) {
    commandName = name;
    commandDesc = desc;
    usageString = usage;
}


string MeiEditorCommand::getCommandName() {
    return commandName;
}

string MeiEditorCommand::getCommandDesc() {
    return commandDesc;
}

string MeiEditorCommand::getUsageString() {
    return usageString;
}

string MeiEditorCommand::getFormattedDesc() {
    string r = commandName;
    if (usageString.length() > 0) {
        r += " " + usageString;
    }
    if (commandDesc.length() > 0) {
        r += ": " + commandDesc;
    }
    return r;
}

ChangeTitleCommand::ChangeTitleCommand() :
    MeiEditorCommand("title", "t", "set the title of this score")
{
}

void ChangeTitleCommand::performCommand(MeiElement *element, list<string> args) {
    
}

ChangeComposerCommand::ChangeComposerCommand() :
    MeiEditorCommand("composer", "c", "set the composer of the score")
{
}

void ChangeComposerCommand::performCommand(MeiElement *element, list<string> args) {
    
}

AddNoteCommand::AddNoteCommand() :
    MeiEditorCommand("addnote", "pitch oct dur", "add a note")
{
}

void AddNoteCommand::performCommand(MeiElement *element, list<string> args) {
    
}

NoteAccidCommand::NoteAccidCommand() :
    MeiEditorCommand("accid", "a", "set the accidental")
{
}

void NoteAccidCommand::performCommand(MeiElement *element, list<string> args) {
    
}

NoteArticCommand::NoteArticCommand() :
    MeiEditorCommand("artic", "a", "set the articulation")
{
}

void NoteArticCommand::performCommand(MeiElement *element, list<string> args) {
    
}


NotePitchCommand::NotePitchCommand() :
    MeiEditorCommand("pitch", "pitch oct", "set the pitch")
{
}

void NotePitchCommand::performCommand(MeiElement *element, list<string> args) {
    
}

DeleteMeiElement::DeleteMeiElement() :
    MeiEditorCommand("delete", "n", "delete element n from the current element (count from 1)")
{
}

void DeleteMeiElement::performCommand(MeiElement *element, list<string> args) {
    
}