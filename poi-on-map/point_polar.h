/** @file
  * Copyright 2015 Valmet Automation Inc.
  * This document is the exclusive intellectual property of Valmet Automation Inc. and/or its subsidiaries (collectively
  * "Valmet Automation") and is furnished solely for operating and maintaining the supplied equipment and/or software.
  * Use of the document for any other project or purpose is prohibited. All copyrights to the document are reserved by
  * Valmet Automation. Accordingly, the document or the information contained therein shall not (whether partly or entirely) be
  * reproduced, copied or disclosed to a third party without prior written consent of Valmet Automation.
  */
#ifndef POINT_POLAR_H_INCLUDED
#define POINT_POLAR_H_INCLUDED


#include <ostream>


namespace point {
  class Polar final {
  public:
    Polar();

    Polar(double radius,
          double angle);

    double angle;
    double radius;
  }; // class Polar


  std::ostream & operator<<(std::ostream &output_stream,
                            const Polar &coordinates);
} // namespace point


#endif // #ifndef POINT_POLAR_H_INCLUDED
