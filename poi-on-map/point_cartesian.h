/** @file
  * Copyright 2015 Valmet Automation Inc.
  * This document is the exclusive intellectual property of Valmet Automation Inc. and/or its subsidiaries (collectively
  * "Valmet Automation") and is furnished solely for operating and maintaining the supplied equipment and/or software.
  * Use of the document for any other project or purpose is prohibited. All copyrights to the document are reserved by
  * Valmet Automation. Accordingly, the document or the information contained therein shall not (whether partly or entirely) be
  * reproduced, copied or disclosed to a third party without prior written consent of Valmet Automation.
  */
#ifndef POINT_CARTESIAN_H_INCLUDED
#define POINT_CARTESIAN_H_INCLUDED


#include <cstdint>
#include <iostream>


namespace point {
  class Cartesian final {
  public:
    Cartesian();

    Cartesian(int32_t x,
              int32_t y);

    bool operator==(const Cartesian &other) const;

    int32_t x;
    int32_t y;
  }; // class Cartesian


  std::istream & operator>>(std::istream &input_stream,
                            Cartesian &coordinates);

  std::ostream & operator<<(std::ostream &output_stream,
                            const Cartesian &coordinates);
} // namespace point


#endif // #ifndef POINT_CARTESIAN_H_INCLUDED
