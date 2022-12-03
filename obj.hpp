#ifndef OBJ_HPP
#define OBJ_HPP

#include <vector>
#include <fstream>
#include <string>
#include "vec.hpp"

class Model {
	public:
		Model(std::string filename);
		std::vector<std::vector<int>> inds;
		std::vector<Vec3> verts;
};

#endif
