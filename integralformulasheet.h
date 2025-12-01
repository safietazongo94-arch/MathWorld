#ifndef INTEGRALFORMULASHEET_H
#define INTEGRALFORMULASHEET_H
#include "FormulaSheet.h"
#include <string>
using namespace std;

/*
 * IntegralFormulaSheet:
 *  - Just tells the base class that the topic is "Integral".
 */
class IntegralFormulaSheet : public FormulaSheet {
public:
    string getTopic() const override;
};

#endif


