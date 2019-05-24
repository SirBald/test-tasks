/** @file
  * Copyright 2015 Valmet Automation Inc.
  * This document is the exclusive intellectual property of Valmet Automation Inc. and/or its subsidiaries (collectively
  * "Valmet Automation") and is furnished solely for operating and maintaining the supplied equipment and/or software.
  * Use of the document for any other project or purpose is prohibited. All copyrights to the document are reserved by
  * Valmet Automation. Accordingly, the document or the information contained therein shall not (whether partly or entirely) be
  * reproduced, copied or disclosed to a third party without prior written consent of Valmet Automation.
  */
#ifndef POINT_POI_INL_H_INCLUDED
#define POINT_POI_INL_H_INCLUDED


#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


namespace point {
  template<typename System>
  class Poi final {
  public:
    using Container = std::vector<Poi<System>>;

    Poi() : coordinates{},
            description{"<empty>"} {
    }

    Poi(const System &coordinates,
        const std::string &description) : coordinates{coordinates},
                                          description{description} {
    }

    System coordinates;
    std::string description;
  }; // class Poi


  template<typename System>
  std::istream & operator>>(std::istream &input_stream,
                            Poi<System> &poi) {
    std::stringbuf description;
    if (!(input_stream >> poi.coordinates >> &description) && !input_stream.eof()) {
      std::cerr << "FAILED to read Poi from a stream. Check format." << std::endl;
    } else {
      poi.description = description.str();
    }

    return input_stream;
  }


  template<template<typename ...> class Container,
           typename ... Args,
           typename System>
  std::istream & operator>>(std::istream &input_stream,
                            Container<Poi<System>, Args ...> &pois) {
    std::string line{""};
    while (std::getline(input_stream, line) && !line.empty()) {
      std::istringstream stream{line};
      Poi<System> poi;
      stream >> poi;
      pois.emplace_back(poi);
    }

    return input_stream;
  }


  template<typename System>
  std::ostream & operator<<(std::ostream &output_stream,
                            const Poi<System> &poi) {
    output_stream << poi.coordinates << " " << poi.description;

    return output_stream;
  }


  template<template<typename ...> class Container,
           typename ... Args,
           typename System>
  std::ostream & operator<<(std::ostream &output_stream,
                            const Container<Poi<System>, Args ...> &pois) {
    std::for_each(std::begin(pois), std::end(pois), [&](const Poi<System> &poi) {
      output_stream << poi << std::endl;
    });

    return output_stream;
  }
} // namespace point


#endif // #ifndef POINT_POI_INL_H_INCLUDED
