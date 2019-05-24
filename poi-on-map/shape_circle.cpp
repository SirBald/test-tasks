/** @file
  * Copyright 2015 Valmet Automation Inc.
  * This document is the exclusive intellectual property of Valmet Automation Inc. and/or its subsidiaries (collectively
  * "Valmet Automation") and is furnished solely for operating and maintaining the supplied equipment and/or software.
  * Use of the document for any other project or purpose is prohibited. All copyrights to the document are reserved by
  * Valmet Automation. Accordingly, the document or the information contained therein shall not (whether partly or entirely) be
  * reproduced, copied or disclosed to a third party without prior written consent of Valmet Automation.
  */
#include "shape_circle.h"


namespace shape {
  Circle::Circle() : center{},
                     radius{0.0f} {
  }


  Circle::Circle(const point::Cartesian &center,
                 double radius) : center{center},
                                  radius{radius} {
  }


  std::istream & operator>>(std::istream &input_stream,
                            Circle &circle) {
    if (!(input_stream >> circle.center >> circle.radius) && !input_stream.eof()) {
      std::cerr << "FAILED to read Circle from a stream. Check format." << std::endl;
    }

    return input_stream;
  }


  std::ostream & operator<<(std::ostream &output_stream,
                            const Circle &circle) {
    output_stream << circle.center << ", " << circle.radius;

    return output_stream;
  }
} // namespace shape
