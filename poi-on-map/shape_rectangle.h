/** @file
  * Copyright 2015 Valmet Automation Inc.
  * This document is the exclusive intellectual property of Valmet Automation Inc. and/or its subsidiaries (collectively
  * "Valmet Automation") and is furnished solely for operating and maintaining the supplied equipment and/or software.
  * Use of the document for any other project or purpose is prohibited. All copyrights to the document are reserved by
  * Valmet Automation. Accordingly, the document or the information contained therein shall not (whether partly or entirely) be
  * reproduced, copied or disclosed to a third party without prior written consent of Valmet Automation.
  */
#ifndef SHAPE_RECTANGLE_H_INCLUDED
#define SHAPE_RECTANGLE_H_INCLUDED


#include <ostream>

#include "point_cartesian.h"


namespace shape {
  class Rectangle final {
  public:
    Rectangle();

    Rectangle(const point::Cartesian &left_bottom,
              const point::Cartesian &right_top);

    point::Cartesian left_bottom;
    point::Cartesian right_top;
  }; // class Rectangle


  std::ostream & operator<<(std::ostream &output_stream,
                            const Rectangle &rectangle);
} // namespace shape


#endif // #ifndef SHAPE_RECTANGLE_H_INCLUDED
