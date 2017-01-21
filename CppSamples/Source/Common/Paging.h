#pragma once

namespace CppSamples {
    namespace Common {

        /// <summary>
        /// Paging class helps to divide a collection into pages of given number of lines.
        /// </summary>
        class Paging {
        public:

            /// <summary>
            /// Create an instance of Paging class.
            /// </summary>
            /// <param name="count">Total number of items in the collection.</param>
            /// <param name="numberInPage">Required number of items per page.</param>
            Paging(int count, int numberInPage);

            ~Paging() { }

            /// <summary>
            /// Current page number. It gives 1 for first page.
            /// </summary>
            int GetCurrentPage() const;

            /// <summary>
            /// Zero based index of last item in the current page.
            /// </summary>
            int GetEndIndex() const;

            /// <summary>
            /// Total number of pages.
            /// </summary>
            int GetPageCount() const { return _pageCount; }

            /// <summary>
            /// Zero based index of first item in the current page.
            /// </summary>
            int GetStartIndex() const;

            /// <summary>
            /// Move to the next page.
            /// </summary>
            void NextPage();

            /// <summary>
            /// Move to the previous page.
            /// </summary>
            void PreviousPage();

        private:
            int _count; // Total number of items in the collection.
            int _currentPage; // Current page number. It gives 1 for first page.
            int _numberInPage; // The number of items per page.
            int _pageCount; // Total number of pages.
        };
    }
}
