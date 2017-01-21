#pragma once

#include "MenuItem.h"

namespace CppSamples {
    namespace Common {

        /// <summary>
        /// Controller class handles the business logic of this application.
        /// </summary>
        class Controller {
        public:
            Controller(MenuItem* root) : _root(root), _selectedPlugin(nullptr) { }
            ~Controller() { }

            /// <summary>
            /// Run the selected plugin continously untill it gets a null reference from any plugin.
            /// </summary>
            void Run();

        private:
            DataModel* Initialize();

            MenuItem* _root; // Refer the root menu
            Plugin* _selectedPlugin; // The current plugin
        };
    }
}
