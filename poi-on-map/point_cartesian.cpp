/** @file
  * Copyright 2015 Valmet Automation Inc.
  * This document is the exclusive intellectual property of Valmet Automation Inc. and/or its subsidiaries (collectively
  * "Valmet Automation") and is furnished solely for operating and maintaining the supplied equipment and/or software.
  * Use of the document for any other project or purpose is prohibited. All copyrights to the document are reserved by
  * Valmet Automation. Accordingly, the document or the information contained therein shall not (whether partly or entirely) be
  * reproduced, copied or disclosed to a third party without prior written consent of Valmet Automation.
  */
#include "point_cartesian.h"


namespace point {
  Cartesian::Cartesian() : x{0},
                           y{0} {
  }


  Cartesian::Cartesian(int32_t x,
                       int32_t y) : x{x},
                                    y{y} {
  }


  bool Cartesian::operator==(const Cartesian &other) const {
    return (other.x == x)
           && (other.y == y);
  }


  std::istream & operator>>(std::istream &input_stream,
                            Cartesian &coordinates) {
    if (!(input_stream >> coordinates.x >> coordinates.y) && !input_stream.eof()) {
      std::cerr << "FAILED to read Cartesian Coordinates from a stream. Check format." << std::endl;
    }

    return input_stream;
  }


  std::ostream & operator<<(std::ostream &output_stream,
                            const Cartesian &coordinates) {
    output_stream << "(" << coordinates.x << ", " << coordinates.y << ")";

    return output_stream;
  }
} // namespace point
