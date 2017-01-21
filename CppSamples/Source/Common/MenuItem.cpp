#include "stdafx.h"
#include "MenuItem.h"
#include <conio.h>
#include "OptionSelector.h"

using namespace std;
using namespace CppSamples::Common;

Plugin* MenuItem::Run(DataModel* dataModel) {

    // Define an instance of OptionSelector class.
    OptionSelector<Plugin*> optionSelector;
    // Heading of menu
    optionSelector.Heading = GetDescription();
    // Clear the screen before start printing
    optionSelector.ClearScreenAlways = true;
    // Print header and footer for menu
    optionSelector.ShowHeaderFooter = true;
    // Ensure to print the menu after user input
    optionSelector.RepeatInput = true;

    // Add all children to the option selector
    for (int i = 0; i < (int)_children.size(); i++)
        optionSelector.AddItem(_children[i]->GetDescription(), _children[i]);

    // Print the menu and accept user input using OptionSelector.
    Plugin* result = nullptr;
    optionSelector.SelectOption(&result);
    return result;
}

void MenuItem::AddBackMenu() {
    // Add a default back menu
    AddChild(new BackMenu());
}

void MenuItem::AddChild(Plugin* plugin) {
    // While adding a child plugin, set the parent-child relationship.
    plugin->SetParent(this);
    // Add child plugin to the collection.
    _children.push_back(plugin);
}

void MenuItem::AddExitMenu() {
    // Add a default exit menu
    AddChild(new ExitMenu());
}
