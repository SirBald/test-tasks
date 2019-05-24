/** @file
  * Copyright 2015 Valmet Automation Inc.
  * This document is the exclusive intellectual property of Valmet Automation Inc. and/or its subsidiaries (collectively
  * "Valmet Automation") and is furnished solely for operating and maintaining the supplied equipment and/or software.
  * Use of the document for any other project or purpose is prohibited. All copyrights to the document are reserved by
  * Valmet Automation. Accordingly, the document or the information contained therein shall not (whether partly or entirely) be
  * reproduced, copied or disclosed to a third party without prior written consent of Valmet Automation.
  */
#include "shape_rectangle.h"


namespace shape {
  Rectangle::Rectangle() : left_bottom{},
                           right_top{} {
  }


  Rectangle::Rectangle(const point::Cartesian &left_bottom,
                       const point::Cartesian &right_top) : left_bottom{left_bottom},
                                                            right_top{right_top} {
  }


  std::ostream & operator<<(std::ostream &output_stream,
                            const Rectangle &rectangle) {
    output_stream << rectangle.left_bottom << ", " << rectangle.right_top;

    return output_stream;
  }
} // namespace shape
