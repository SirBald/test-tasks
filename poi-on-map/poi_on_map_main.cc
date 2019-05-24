#include <algorithm>
#include <cmath>
#include <exception>
#include <fstream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

#include "point_cartesian.h"
#include "point_poi-inl.h"
#include "point_polar.h"
#include "shape_circle.h"
#include "shape_rectangle.h"


namespace {
  using CartesianPoi = point::Poi<point::Cartesian>;
  using Distance = double;
  using DistanceContainer = std::vector<Distance>;
  using PolarPoi = point::Poi<point::Polar>;


  Distance findDistance(const point::Cartesian &point_1,
                        const point::Cartesian &point_2) {
    // TODO: Check overflow.
    return sqrt(pow(point_1.x - point_2.x, 2) + pow(point_1.y - point_2.y, 2));
  }


  DistanceContainer findDistances(const CartesianPoi::Container &pois,
                                  const point::Cartesian &to_point) {
    DistanceContainer distances;
    distances.reserve(pois.size());

    std::transform(
      std::begin(pois), std::end(pois), std::back_inserter(distances), [&](const CartesianPoi::Container::value_type &poi) {
        return findDistance(poi.coordinates, to_point);
      });

    return distances;
  }


  shape::Rectangle findRectangle(const CartesianPoi::Container &pois) {
    using Element = CartesianPoi::Container::value_type;

    const auto min_max_x = std::minmax_element(std::begin(pois), std::end(pois), [](const Element &left, const Element &right) {
      return left.coordinates.x < right.coordinates.x;
    });

    const auto min_max_y = std::minmax_element(std::begin(pois), std::end(pois), [](const Element &left, const Element &right) {
      return left.coordinates.y < right.coordinates.y;
    });

    return {{min_max_x.first->coordinates.x, min_max_y.first->coordinates.y},
            {min_max_x.second->coordinates.x, min_max_y.second->coordinates.y}};
  }


  Distance averageDistance(const DistanceContainer &distances) {
    // TODO: Check overflow in each operation.
    const auto sum = std::accumulate(std::begin(distances), std::end(distances), 0.0);

    return sum / static_cast<decltype(sum)>(distances.size());
  }


  Distance averageDistance(const CartesianPoi::Container &pois,
                           const point::Cartesian &to_point) {
    const auto distances = findDistances(pois, to_point);

    return averageDistance(distances);
  }


  point::Polar convertToPolarSystem(const point::Cartesian &point) {
    static const point::Cartesian kSystemCenter{0, 0};

    if (kSystemCenter == point) {
      return {0.0f, 0.0f};
    }

    const auto radius = findDistance(point, kSystemCenter);
    const auto angle = asin(point.y / radius);

    return {radius, angle};
  }


  PolarPoi::Container convertToPolarSystem(const CartesianPoi::Container &pois) {
    PolarPoi::Container polar_pois;
    polar_pois.reserve(pois.size());

    std::transform(
      std::begin(pois), std::end(pois), std::back_inserter(polar_pois), [](const CartesianPoi::Container::value_type &poi) {
        return PolarPoi{convertToPolarSystem(poi.coordinates), poi.description};
      });

    return polar_pois;
  }


  bool isInCircle(const shape::Circle &circle,
                  const CartesianPoi &poi) {
    if (poi.coordinates == circle.center) {
      return true;
    }

    return findDistance(circle.center, poi.coordinates) <= circle.radius;
  }


  void leavePoisInCircle(const shape::Circle &circle,
                         CartesianPoi::Container &pois) {
    const auto remove_from = std::remove_if(
      std::begin(pois), std::end(pois), [&](const CartesianPoi::Container::value_type &poi) {
        return !isInCircle(circle, poi);
      });
    pois.erase(remove_from, std::end(pois));
  }


  Distance sampleVariance(const CartesianPoi::Container &pois,
                          const point::Cartesian &to_point) {
    const auto distances = findDistances(pois, to_point);
    using Element = decltype(distances)::value_type;

    const auto sample_mean = averageDistance(distances);
    const auto sum = std::accumulate(
      std::begin(distances), std::end(distances), 0.0f, [&](const Element &result, const Element &current) {
        return result + pow(current - sample_mean, 2.0f);
      });

    return sum / static_cast<decltype(sum)>(distances.size() - 1);
  }


  void run(CartesianPoi::Container &pois,
           const shape::Circle &circle) {
    leavePoisInCircle(circle, pois);
    std::cout << "Points in a circle " << circle << ":" << std::endl << pois << std::endl;
    std::cout << "Average distance to (" << circle.center << "): " << averageDistance(pois, circle.center) << std::endl;
    std::cout << "Sample variance of distances to (" << circle.center << "): " << sampleVariance(pois, circle.center) << std::endl;
    std::cout << std::endl << "POIs in point::Polar Coordinate System:" << std::endl << convertToPolarSystem(pois) << std::endl;
    std::cout << "Minimal rectangle is " << findRectangle(pois) << std::endl;
  }
} // anonymous namespace


int main(int argc,
         char *argv[]) {
  try {
    if (argc == 2) {
      const std::string file_name{argv[1]};
      std::ifstream file{file_name, std::ios::in};
      if (!file) {
        std::cerr << "FAILED to open file '" << file_name << "'" << std::endl;

        return EXIT_FAILURE;
      }

      CartesianPoi::Container pois;
      shape::Circle circle;
      file >> pois >> circle;
      if (!file && !file.eof()) {
        return EXIT_FAILURE;
      }

      run(pois, circle);
    } else {
      std::cerr << "Usage: " << argv[0] << " FILE" << std::endl;
    }

    return EXIT_SUCCESS;
  } catch (const std::exception &exception) {
    std::cerr << exception.what() << std::endl;

    return EXIT_FAILURE;
  } catch (...) {
    std::cerr << "Unknown exception caught" << std::endl;

    return EXIT_FAILURE;
  }
}
