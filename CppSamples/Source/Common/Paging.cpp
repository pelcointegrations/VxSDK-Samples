#include "stdafx.h"
#include "Paging.h"

using namespace CppSamples::Common;

// Create an instance of Paging class.
Paging::Paging(int count, int numberInPage) {
    // Initialize the default variables
    _count = count;
    _numberInPage = numberInPage;
    _currentPage = 1;

    // Calculate total number of pages from given input
    _pageCount = (count - 1) / numberInPage + 1;
}

// Current page number. It gives 1 for first page.
int Paging::GetCurrentPage() const {
    // Get current page number
    return _currentPage;
}

// Zero based index of last item in the current page.
int Paging::GetEndIndex() const {
    // Calculate end index
    int endIndex = _currentPage *_numberInPage - 1;
    // Ensure the index is not crossing the limit.
    if (endIndex >= _count)
        endIndex = _count - 1;
    return endIndex;
}

// Zero based index of first item in the current page.
int Paging::GetStartIndex() const {
    // Calculate start index
    return (_currentPage - 1)*_numberInPage;
}

void Paging::NextPage() {
    // Move to next page
    _currentPage++;
    // Ensure the page number is not crossing the limit.
    if (_currentPage > _pageCount)
        _currentPage = _pageCount;
}

void Paging::PreviousPage() {
    // Move back to previous page
    _currentPage--;
    // Ensure the page number is not crossing the limit.
    if (_currentPage <= 0)
        _currentPage = 1;
}
