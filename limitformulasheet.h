#ifndef LIMITFORMULASHEET_H
#define LIMITFORMULASHEET_H
#include "FormulaSheet.h"
#include <string>
using namespace std;

/*
 * LimitFormulaSheet:
 *  - Formula sheet for limit rules and special limits.
 */
class LimitFormulaSheet : public FormulaSheet {
public:
   string getTopic() const override;
};

#endif
