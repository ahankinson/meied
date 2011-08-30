/**
 * MeiEd MEI Editor
 * Copyright 2011 Alastair Porter
 */

#ifndef MEIED_MEIED_H
#define MEIED_MEIED_H

#include <mei/mei.h>
#include <mei/meidocument.h>

#include <string>
#include <list>

#include "meiedcommands.h"
#include "meiedmodes.h"

using std::string;
using std::list;

using mei::MeiElement;
using mei::MeiDocument;

#define MEIED_VERSION 0.1

/**
 * The actual editor. Contains a document. Carries state of where the editor is.
 */
class MeiEditor {
public:
    void NewDocument();
    void OpenDocument(std::string docname);
    void Save();
    void SaveAs(std::string docname);
    
    bool readInput();
    
    // Go to a new mode
    void pushMode(MeiEditorMode *mode);
    
    // Perform a command with the current element
    void performCommand(MeiEditorCommand *command);
    
    void help();
    
private:
    MeiDocument *document;
    MeiElement *currentElement;
    
    // A stack of the current editor modes.
    list<MeiEditorMode*> state;
};

#endif
