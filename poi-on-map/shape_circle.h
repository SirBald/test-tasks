/** @file
  * Copyright 2015 Valmet Automation Inc.
  * This document is the exclusive intellectual property of Valmet Automation Inc. and/or its subsidiaries (collectively
  * "Valmet Automation") and is furnished solely for operating and maintaining the supplied equipment and/or software.
  * Use of the document for any other project or purpose is prohibited. All copyrights to the document are reserved by
  * Valmet Automation. Accordingly, the document or the information contained therein shall not (whether partly or entirely) be
  * reproduced, copied or disclosed to a third party without prior written consent of Valmet Automation.
  */
#ifndef SHAPE_CIRCLE_H_INCLUDED
#define SHAPE_CIRCLE_H_INCLUDED


#include <iostream>

#include "point_cartesian.h"


namespace shape {
  class Circle final {
  public:
    Circle();

    Circle(const point::Cartesian &center,
           double radius);

    point::Cartesian center;
    double radius;
  }; // class Circle


  std::istream & operator>>(std::istream &input_stream,
                            Circle &circle);

  std::ostream & operator<<(std::ostream &output_stream,
                            const Circle &circle);
} // namespace shape


#endif // #ifndef SHAPE_CIRCLE_H_INCLUDED
