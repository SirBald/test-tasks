/** @file
  * Copyright 2015 Valmet Automation Inc.
  * This document is the exclusive intellectual property of Valmet Automation Inc. and/or its subsidiaries (collectively
  * "Valmet Automation") and is furnished solely for operating and maintaining the supplied equipment and/or software.
  * Use of the document for any other project or purpose is prohibited. All copyrights to the document are reserved by
  * Valmet Automation. Accordingly, the document or the information contained therein shall not (whether partly or entirely) be
  * reproduced, copied or disclosed to a third party without prior written consent of Valmet Automation.
  */
#include "point_polar.h"


namespace point {
  Polar::Polar() : angle{0.0f},
                   radius{0.0f} {
  }


  Polar::Polar(double radius,
               double angle) : angle{angle},
                               radius{radius} {
  }


  std::ostream & operator<<(std::ostream &output_stream,
                            const Polar &coordinates) {
    output_stream << "(" << coordinates.radius << ", " << coordinates.angle << ")";

    return output_stream;
  }
} // namespace point
