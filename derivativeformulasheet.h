#ifndef DERIVATIVEFORMULASHEET_H
#define DERIVATIVEFORMULASHEET_H
#include "FormulaSheet.h"
#include <string>
using namespace std;

/*
 * DerivativeFormulaSheet:
 *  - Formula sheet for derivative rules.
 - Inherits from FormulaSheet (base class).
 * - Only needs to override getTopic() so the system knows
 *   which formulas belong to which math category.
 */
class DerivativeFormulaSheet : public FormulaSheet {
public:
    // Returns the topic name (“Derivative”)
   string getTopic() const override;
};

#endif
